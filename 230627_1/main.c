#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

static int gpio_config(const char *gpio_path, const char *attr, const char *val)
{
    char file_path[100];
    int len;
    int fd;
    sprintf(file_path, "%s/%s", gpio_path, attr);
    if (0 > (fd = open(file_path, O_WRONLY))) {
        perror("open error");
        return fd;
    }
 
    len = strlen(val);
    if (len != write(fd, val, len)) {
        perror("write error");
        close(fd);
    return -1;
    }
 
    close(fd); //¹Ø±ÕÎÄ¼þ
    return 0;
}

void gpio_wirte(char port, char pin, char data)
{
    int fd;
    int len;
    char str_buff[100];
    int port_num = 0;
    switch(port)
    {
        case 0: port_num = 496 + pin; break;
        case 1: port_num = 480 + pin; break;
        case 2: port_num = 464 + pin; break;
        case 3: port_num = 448 + pin; break;
        case 4: port_num = 432 + pin; break;
        case 5: port_num = 416 + pin; break;
        default:
            printf("GPIO NUM ERROR!\n");
            return;
    }
    fd = open("/sys/class/gpio/export", O_WRONLY);
    sprintf(str_buff, "%d", port_num);
    len = strlen(str_buff);
    write(fd, str_buff, len);
    close(fd);

    sprintf(str_buff, "/sys/class/gpio/gpio%d", port_num);
    gpio_config(str_buff, "direction", "out");
    if(data)
        gpio_config(str_buff, "value", "1");
    else
        gpio_config(str_buff, "value", "0");
    
    fd = open("/sys/class/gpio/unexport", O_WRONLY);
    sprintf(str_buff, "%d", port_num);
    len = strlen(str_buff);
    write(fd, str_buff, len);
    close(fd);
}

void seg_display(char data)
{
    const unsigned char sec_tab[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
    unsigned char data_buff;
    data_buff = sec_tab[data / 10];
    gpio_wirte(2, 3, data_buff & (1 << 0));
    gpio_wirte(2, 4, data_buff & (1 << 1));
    gpio_wirte(3, 3, data_buff & (1 << 2));
    gpio_wirte(3, 4, data_buff & (1 << 3));
    gpio_wirte(3, 5, data_buff & (1 << 4));
    gpio_wirte(3, 6, data_buff & (1 << 5));
    gpio_wirte(3, 7, data_buff & (1 << 6));
    gpio_wirte(3, 8, data_buff & (1 << 7));
    gpio_wirte(1, 5, 1);

    data_buff = sec_tab[data % 10];
    gpio_wirte(3, 9,  data_buff & (1 << 0));
    gpio_wirte(3, 10, data_buff & (1 << 1));
    gpio_wirte(5, 9,  data_buff & (1 << 2));
    gpio_wirte(5, 10, data_buff & (1 << 3));
    gpio_wirte(5, 11, data_buff & (1 << 4));
    gpio_wirte(5, 12, data_buff & (1 << 5));
    gpio_wirte(5, 13, data_buff & (1 << 6));
    gpio_wirte(5, 14, data_buff & (1 << 7));
}

void main(void)
{
    int i = 0;
    printf("NUM TEST!\n");
    gpio_wirte(5, 15, 1);
    gpio_wirte(2, 8, 1);
    gpio_wirte(0, 6, 1);

    while(1)
    {
        seg_display(i);
        if(i++ >= 100) i = 0; 
        sleep(1);
    }
}

