//#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include "includes/ft_printf.h"
#include "includes/libft.h"
#include "includes/city.h"

int	LED[NB_LED];
void	SIPO (int byte);
void	pulse (int pin);

int 	power_2(int x)
{
	if(x == 0)
		return(1);
	return(2 * power_2(x - 1));
}

void	init()
{
	int 	i;

	i = 0;
	while(i < NB_LED)
	{
		LED[i] = power_2(i);
		i++;
	}
	pinMode (SER, OUTPUT);
	pinMode (RCLK, OUTPUT);
	pinMode (SRCLK, OUTPUT);
	digitalWrite (SER, 0);
	digitalWrite (SRCLK, 0);
	digitalWrite (RCLK, 0);
}

// void	delayMS(int x)
// {
// 	usleep(x * 5000);
// }


int	main(void)
{
	int i;

	i = 0;
	init();
	while(i < NB_LED)
	{
		ft_printf("\nLED[%2d]=%08x ==> [%032b]\t", i, LED[i], LED[i]);
		SIPO(LED[i]);
		i++;
	}
	return(0);
}

void	SIPO (int byte)
{
	int	i;

	ft_printf("byte=%x [%032b]\t", byte, byte);
	for(i = 0; i <= 32; i++)
	{
		ft_printf("%x",((byte & (0x80000000 >> i)) > 0));
		digitalWrite(SER,((byte & (0x80 >> i)) > 0));
		pulse(SRCLK);
	}
}

void	pulse(int pin)
{
	digitalWrite(pin, 1);

	digitalWrite(pin, 0);
}

