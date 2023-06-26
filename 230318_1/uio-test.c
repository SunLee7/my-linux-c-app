/*
* This application test data reading and interrupt handling via UIO.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAP_SIZE 0x2000

u_int32_t bram_data[1000] = {};

int main(int argc, char *argv[])
{
    char uiod[] = "/dev/uio0";
    int irq_on = 1;
    int fd;
    void *ptr;
    /* Open the UIO device file */
    fd = open(uiod, O_RDWR);
    if (fd < 1) 
    {
        return -1;
    }

    ptr = mmap(NULL, MAP_SIZE, PROT_READ, MAP_SHARED, fd, 0);

    while(1)
    {
        int irq_cnt = 0;
        // write 1 enable irq; 0 disable irq
        /* enable IRQ, trigger the irqcontrol of driver */
        write(fd, &irq_on, sizeof(irq_on));
        // Wait before irq trggled
        read(fd, &irq_cnt, sizeof(irq_cnt));
        // Read data from BRAM
        for(int i = 0; i < 250; i++)
            bram_data[i] = *((u_int32_t*)ptr + i + 1);
        // Print data
        for(int i = 0; i < 250; i++)
            printf("data[%d]: %d\n", i, bram_data[i]);
    }
    return 0;
}
