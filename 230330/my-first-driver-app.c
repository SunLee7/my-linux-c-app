#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>        //man 2 open 查看头文件有哪些
#include <unistd.h>
#define FILE	"/dev/my-first-driver" // 刚才mknod创建的设备文件名 双引号不要漏

char str_buff[100];

int main(void)
{
	int fd = -1;
	fd = open(FILE, O_RDWR);
	if (fd < 0){
		printf("open %s error.\n", FILE);
		return -1;
	}
	printf("open %s success..\n", FILE);
	// write
    write(fd, "Hello kernel!\r", 15);
    // read
    read(fd, str_buff, 15);

    printf("data: %s\n", str_buff);
	
	// 关闭文件
	close(fd);	
	return 0;
}