#include <stdio.h>
#include <errno.h>
#include <mysql.h>
#include <time.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <wiringSerial.h>

static const unsigned char crc8_table[256] =
{
     0,  94, 188, 226,  97,  63, 221, 131, 194, 156, 126,  32, 163, 253,  31,  65,
   157, 195,  33, 127, 252, 162,  64,  30,  95,   1, 227, 189,  62,  96, 130, 220,
    35, 125, 159, 193,  66,  28, 254, 160, 225, 191,  93,   3, 128, 222,  60,  98,
   190, 224,   2,  92, 223, 129,  99,  61, 124,  34, 192, 158,  29,  67, 161, 255,
    70,  24, 250, 164,  39, 121, 155, 197, 132, 218,  56, 102, 229, 187,  89,   7,
   219, 133, 103,  57, 186, 228,   6,  88,  25,  71, 165, 251, 120,  38, 196, 154,
   101,  59, 217, 135,   4,  90, 184, 230, 167, 249,  27,  69, 198, 152, 122,  36,
   248, 166,  68,  26, 153, 199,  37, 123,  58, 100, 134, 216,  91,   5, 231, 185,
   140, 210,  48, 110, 237, 179,  81,  15,  78,  16, 242, 172,  47, 113, 147, 205,
    17,  79, 173, 243, 112,  46, 204, 146, 211, 141, 111,  49, 178, 236,  14,  80,
   175, 241,  19,  77, 206, 144, 114,  44, 109,  51, 209, 143,  12,  82, 176, 238,
    50, 108, 142, 208,  83,  13, 239, 177, 240, 174,  76,  18, 145, 207,  45, 115,
   202, 148, 118,  40, 171, 245,  23,  73,   8,  86, 180, 234, 105,  55, 213, 139,
    87,   9, 235, 181,  54, 104, 138, 212, 149, 203,  41, 119, 244, 170,  72,  22,
   233, 183,  85,  11, 136, 214,  52, 106,  43, 117, 151, 201,  74,  20, 246, 168,
   116,  42, 200, 150,  21,  75, 169, 247, 182, 232,  10,  84, 215, 137, 107,  53
};


/***************************************************************************
리눅스에서 마리아DB 접속

1.mysql 클라이언트 드라이버 설치
 sudo apt-get install libmysqlclient-dev

2.컴파일 방법
 gcc dbtest.c -I/usr/include/mysql -lmysqlclient
->wiringPi도 사용함으로 gcc dbtest.c -I/usr/include/mysql -lmysqlclient -lwiringPi

*****************************************************************************/

#define SPI_CHANNEL 0
#define SPI_SPEED 1000000

#define SN "150042047918"		   //제품 시리얼번호

#define BRIGHT_CHANNEL 0       //밝기 센서    0번에 연결
#define MQ135_ADC_CHANNEL 1    //공기질 센서  1번에 연결
#define MQ5_ADC_CHANNEL 2      //gas 센서     2번에 연결
#define NOISE_CHANNEL 3		   //마이크 	  3번에 연결

#define READ_REPEAT 20			//센서값 1회 측정을 위해서 반복해서 읽어들이는횟수  

int insert_db(int dust, int temperature, int humidity, int lux, int noise, int lpg_gas, int air_quality);
int read_mcp3008_adc(unsigned char adcChannel);
unsigned char crc_8( unsigned char *data , int size );  

int main(void)
{
	int adcChannel=0;
	int adcValue[4];
	int i;
	int fd;
	char data[5],dust;
	int check_crc;
	
	
	if(wiringPiSPISetup(SPI_CHANNEL,SPI_SPEED)==-1)				//SPI 채널 ADC 값을 읽기위하여
	{
		printf("SPI ERROR");
		return 1;
	}
	
	if(wiringPiSetup() == -1)
	{
		printf("GPIO Error"); //GPIO 프로그램 초기화 실패시
		return 1;			  //종료
	}
	
	if ((fd = serialOpen ("/dev/ttyACM0", 115200)) < 0)		//아두이노 전송값을 읽기 위하여 시리얼
	{
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno));
		return -1;
	}

	printf ("\nRaspberry Pi serial OK\n");
	serialFlush(fd);
	//아두이노에 추가로 온도,습도,미세먼지 읽어와서
	delay(2000); //!!!!!딜레이 없는면 첫프레임 문제생긴다. 헐 2초는 있어야함 -_-;
	
	
	while(1)
	{
		for(i=0; i<4; i++)
		{
			adcValue[i]=0;		//0으로 초기화
		}			
		
		//20회 반복측정
		for(i=0; i<READ_REPEAT; i++)
		{
			adcValue[0]+=read_mcp3008_adc(BRIGHT_CHANNEL);
			adcValue[1]+=read_mcp3008_adc(MQ135_ADC_CHANNEL);
			adcValue[2]+=read_mcp3008_adc(MQ5_ADC_CHANNEL);
			adcValue[3]+=read_mcp3008_adc(NOISE_CHANNEL);
		}
		
		for(i=0; i<4; i++)
		{
			adcValue[i]=adcValue[i]/READ_REPEAT;		//평균값으로 계산
		}	
		

		/*****************아두이노 데이터 받기****************************/
		do{
			serialPutchar(fd, 'R');//데이터 요청
			
			for(i=0;i<5;i++)
			{
				data[i] = serialGetchar(fd);
				//printf ("\nPC > RPi = %d", data[i]);
				//printf ("하나받아오고");
			}
			
			if(data[4]==crc_8(data, 4)) 
			{
				printf("\nRecevied data OK\n");
				check_crc=0;
			}
			else
			{
				printf("Recevied data error\n");
				check_crc=-1;
			}
		}while(check_crc==-1);
				
		dust=(data[2]<<8);
		dust+=data[3]; //미세먼지 데이터 만들기
		
		//serialPutchar(fd, data);
		//serialPuts(fd, "\n");
		fflush(stdout);
		/********************************************************************/
		
		
		//DB에 기록
		insert_db(dust, data[0], data[1], adcValue[0], adcValue[3], adcValue[1], adcValue[2]); //테스트 데이터

		
		//출력
		printf("---------------------------------------------------\n");
		printf("Temperature");
		printf(" adc0 value = %u  ",data[0]); //10bit 출력 0~1023
		printf("adc0 Voltage= %f\n",(float)(adcValue[0]*5)/1024);
		
		printf("humidity");
		printf(" adc0 value = %u  ",data[1]); //10bit 출력 0~1023
		printf("adc0 Voltage= %f\n",(float)(adcValue[0]*5)/1024);

		printf("Dust");
		printf(" adc0 value = %u  ",dust); //10bit 출력 0~1023
		printf("adc0 Voltage= %f\n",(float)(adcValue[0]*5)/1024);

		printf("LUX");
		printf(" adc0 value = %u  ",adcValue[0]); //10bit 출력 0~1023
		printf("adc0 Voltage= %f\n",(float)(adcValue[0]*5)/1024);
	
		printf("MQ135_Gas");
		printf(" adc1 value = %u  ",adcValue[1]); //10bit 출력 0~1023
		printf("adc1 Voltage= %f\n",(float)(adcValue[1]*5)/1024);
		
		printf("MQ5_Air");
		printf(" adc2 value = %u  ",adcValue[2]); //10bit 출력 0~1023
		printf("adc2 Voltage= %f\n",(float)(adcValue[2]*5)/1024);
		
		printf("NOISE");
		printf(" adc3 value = %u  ",adcValue[3]); //10bit 출력 0~1023
		printf("adc3 Voltage= %f\n",(float)(adcValue[3]*5)/1024);
		printf("-------------------------------------------------\n");
		
		delay(59000); //반복주기 1분 (60sec) 
	}
	return 0;
}


int insert_db(int dust, int temperature, int humidity, int lux, int noise, int lpg_gas, int air_quality)
{
	MYSQL *connector;
	char query[1024],time_string[20];
	int result=1;
		
	time_t curr; 
	struct tm *d;
	curr=time(NULL); //현재시간 얻기
	d=localtime(&curr);
	sprintf(time_string,"%d-%d-%d %d:%d:%d",d->tm_year+1900,d->tm_mon+1,d->tm_mday,d->tm_hour,d->tm_min,d->tm_sec);
	printf("%s\n",time_string);

	//MYSQL Connection
	connector = mysql_init(NULL);
	if (!mysql_real_connect(connector, "192.168.0.88", "gvodb", "dbdkagh", "db_gvo", 3306, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(connector));
		printf("마리아 DB 연결실패\n");
		return -1;
	}
	
	printf("마리아 DB 연결성공\n");
	
	
	//쿼리(데이터 저장)
	sprintf(query,"INSERT INTO tbl_sensor_data VALUES ('%s', '%s', %d, %d, %d, %d, %d, %d, %d)",
	SN, time_string, dust, temperature, humidity, lux, noise, lpg_gas, air_quality);
	
	result=mysql_query(connector, query);
	

	if(result==0) 
		printf("데이터가 정상적으로 입력되었습니다.\n");
	else
		printf("입력 실패했습니다.결과값=%d\n",result);
	
	mysql_close(connector);
	
	return 0;
}

int read_mcp3008_adc(unsigned char adcChannel)
{
	unsigned char buff[3];
	int adcValue=0;
	
	buff[0]=0x01;
	buff[1]=((adcChannel | 0x08)<<4);
	buff[2]=0x00;
	
	wiringPiSPIDataRW(SPI_CHANNEL,buff,3);
	
	buff[1]=0x3 & buff[1];
	adcValue=(buff[1]<<8)|buff[2];
	
	return adcValue;
}


unsigned char crc_8( unsigned char *data , int size )  
{  
    int lp;
    unsigned char crc8=0;
   
    for( lp = 0; lp < size; lp++ ) crc8 = crc8_table[ crc8 ^ data[lp] ] ;
    return crc8; 
}
