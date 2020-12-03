/* test-spi-rpi-01.c - Programme pour Raspberry Pi */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <linux/types.h>
#include <linux/spi/spidev.h>

#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
	int fd_spi;
	char ligne[80];
	int value;
	unsigned char byte;
        unsigned int speed = 250000;
	fd_spi = open("/dev/spidev0.0", O_RDWR);
	if (fd_spi < 0)
	{
	        perror("dev/spidev0.0");
	        exit(EXIT_FAILURE);
	}
	if (ioctl(fd_spi, SPI_IOC_WR_MAX_SPEED_HZ, & speed) != 0)
	{
	        perror("ioctl");
	        exit(EXIT_FAILURE);
	}
        while (fgets(ligne, 80, stdin) != NULL)
	{
	      if (sscanf(ligne, "%d", &value) != 1)
	      {
		      fprintf(stderr, "integer value expected\n");
		      continue;
	      }
	      byte = (unsigned char) (value & 0xFF);
	      if (write(fd_spi, &byte, 1) != 1)
	      {
	              perror("write");
	              exit(EXIT_FAILURE);
	      }
	}
	close(fd_spi);
	return EXIT_SUCCESS;
}
