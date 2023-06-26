
/************************************************************/
//文件名：mpu6050.c
//功能:测试linux下iic读写mpu6050程序，再通过TCP发送至上位机

//作者:huangea、sunlee
//日期:2023-04-28
/************************************************************/
 
//包含头文件
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ioctl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<errno.h>

# include<string.h>
# include<assert.h>
# include<sys/socket.h>
# include<netinet/in.h>
# include<arpa/inet.h>

#include <math.h>
 
//宏定义
 
#define	SMPLRT_DIV	0x19	
#define	CONFIG	0x1A	
#define	GYRO_CONFIG	0x1B	
#define	ACCEL_CONFIG	0x1C
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H	0x41
#define	TEMP_OUT_L	0x42
#define	GYRO_XOUT_H	0x43
#define	GYRO_XOUT_L	0x44
#define	GYRO_YOUT_H	0x45
#define	GYRO_YOUT_L	0x46
#define	GYRO_ZOUT_H	0x47
#define	GYRO_ZOUT_L	0x48
#define	PWR_MGMT_1	0x6B
#define	WHO_AM_I	0x75	
#define	SlaveAddress	0xD0	
 
#define Address 0x68                  //MPU6050地址
 
#define I2C_RETRIES   0x0701
#define I2C_TIMEOUT   0x0702
#define I2C_SLAVE     0x0703       //IIC从器件的地址设置
#define I2C_BUS_MODE   0x0780

#define PI 3.14159265
 
typedef unsigned char uint8;
 
int fd = -1;
 
//函数声明
static uint8 MPU6050_Init(void);
static uint8 i2c_write(int fd, uint8 reg, uint8 val);
static uint8 i2c_read(int fd, uint8 reg, uint8 *val);
static uint8 printarray(uint8 Array[], uint8 Num);
 
 
//MPU6050初始化
static uint8 MPU6050_Init(void)
{
	fd = open("/dev/i2c-0", O_RDWR);   // open file and enable read and  write
 
	if(fd < 0)
	{
		perror("Can't open /dev/MPU6050 \n"); // open i2c dev file fail
		exit(1);
	}
	printf("open /dev/i2c-0 success !\n");   // open i2c dev file succes
 
	if(ioctl(fd, I2C_SLAVE, Address)<0) {    //set i2c address 
		printf("fail to set i2c device slave address!\n");
		close(fd);
		return -1;
	}
	printf("set slave address to 0x%x success!\n", Address);
 
	i2c_write(fd,PWR_MGMT_1,0X00);    
	i2c_write(fd,SMPLRT_DIV,0X07); 
	i2c_write(fd,CONFIG,0X06); 
	i2c_write(fd,ACCEL_CONFIG,0X01); 
 
	return(1);
}
 
 
 
//MPU6050 wirte byte
static uint8 i2c_write(int fd, uint8 reg, uint8 val)
{
	int retries;
	uint8 data[2];
 
	data[0] = reg;
	data[1] = val;
	for(retries=5; retries; retries--) {
		if(write(fd, data, 2)==2)
			return 0;
		usleep(1000*10);
	}
	return -1;
}
 
//MPU6050 read byte
static uint8 i2c_read(int fd, uint8 reg, uint8 *val)
{
	int retries;
 
	for(retries=5; retries; retries--)
		if(write(fd, &reg, 1)==1)
			if(read(fd, val, 1)==1)
				return 0;
	return -1;
}
 
//get data
short GetData(unsigned char REG_Address)
{
	char H, L;
	i2c_read(fd, REG_Address, &H);
	i2c_read(fd, REG_Address + 1, &L);
 
	return (H << 8) + L;
}

int sockfd;

void tcp_init()
{
    //AF_INFT表示ipv4  SOCKET_STREAM表示传输层使用tcp协议 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	assert(sockfd!=-1);
	struct sockaddr_in saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(1347);
	saddr.sin_addr.s_addr = inet_addr("192.168.5.144");
	int res = connect(sockfd, (struct sockaddr*)&saddr, sizeof(saddr));
	// assert(res!=-1);
    printf("tcp initialised./n");
}

char str_buff[200];
struct mpu{
	int accel_x;
	int accel_y;
	int accel_z;
	int gyro_x;
	int gyro_y;
	int gyro_z;

	float pitch_accel;
	float pitch_gyro;
}hmpu;

// main
int main(int argc, char *argv[])
{
    tcp_init();
	MPU6050_Init();
	usleep(1000 * 1);
	hmpu.pitch_gyro = 0;
	while(1)
	{
		// MPU数据读取
		hmpu.accel_x = GetData(ACCEL_XOUT_H);
		hmpu.accel_y = GetData(ACCEL_YOUT_H);
		hmpu.accel_z = GetData(ACCEL_ZOUT_H);
		hmpu.gyro_x = GetData(GYRO_XOUT_H);
		hmpu.gyro_y = GetData(GYRO_YOUT_H);
		hmpu.gyro_z = GetData(GYRO_ZOUT_H);

		// MPU数据处理
		// 加速度获取角度
		float z = ((hmpu.accel_x < 0 && hmpu.accel_z < 0) || (hmpu.accel_x > 0 && hmpu.accel_z < 0))? 
					-hmpu.accel_z: hmpu.accel_z;
		hmpu.pitch_accel = (2 * 90 / PI) * atan((float)hmpu.accel_x / z);

		hmpu.pitch_gyro -= hmpu.gyro_y / 10000.0;

        sprintf(str_buff, "%d,%d,%d,%d,%d,%d,%f,%f\n",
                hmpu.accel_x, 
                hmpu.accel_y, 
                hmpu.accel_z, 
                hmpu.gyro_x, 
                hmpu.gyro_y, 
                hmpu.gyro_z,
				hmpu.pitch_accel,
				hmpu.pitch_gyro);
        // printf("%s", str_buff);
        send(sockfd, str_buff, strlen(str_buff), 0);
        usleep(5 * 1000);
	}
 
	close(fd);
}
