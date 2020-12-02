#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include "printf/includes/ft_printf.h"
#include "printf/libft/libft.h"

int	SER	= 12;
int	RCLK	= 10;
int	SRCLK	= 14;
unsigned char	LED[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void	SIPO (unsigned char byte);
void	pulse (int pin);
void	init()
{
	pinMode (SER, OUTPUT);
	pinMode (RCLK, OUTPUT);
	pinMode (SRCLK, OUTPUT);
	digitalWrite (SER, 0);
	digitalWrite (SRCLK, 0);
	digitalWrite (RCLK, 0);
}

void	delayMS(int x)
{
	usleep(x * 5000);
}

int	main(void)
{
	if (wiringPiSetup() == -1)
	{
		printf("Setup wiringPi failed!");
		return(1);
	}
	init();
	int i;
	for(i = 0; i < 8; i++)
	{
		SIPO(LED[i]);
		pulse(RCLK);
		delayMS(100);
		//printf (" i = %d", i);
	}
	digitalWrite(RCLK, 1);
}

void	SIPO (unsigned char byte)
{
	int	i;

	ft_printf("byte=%u [%08b]\n", byte, byte);
	for(i = 0; i < 8; i++)
	{
		digitalWrite(SER,((byte & (0x80 >> i)) > 0));
		pulse(SRCLK);
	}
}

void	pulse(int pin)
{
	digitalWrite(pin, 1);

	digitalWrite(pin, 0);
}

