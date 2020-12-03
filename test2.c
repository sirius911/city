#include <wiringPi.h>
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
	printf("init()\n");
	pinMode(MOSI, OUTPUT);
	pinMode(RCLK1, OUTPUT);
	pinMode(RCLK2, OUTPUT);
	pinMode(SCLK, OUTPUT);
	digitalWrite(MOSI, 0);
	digitalWrite(RCLK1, 0);
	digitalWrite(RCLK2, 0);
	digitalWrite(SCLK, 0);
}

void	delayMS(int x)
{
 	usleep(x * 1000);
}


int	main(void)
{
	int 	i;
	int	num_led;
	char	ligne[25];

	i = 0;
	if(wiringPiSetup() == -1)
	{
		ft_printf("Setup wiringPi failed!\n");
		return (-1);
	}
	init();
	printf("\nEnter num of LED : ");
	while(fgets(ligne, 80, stdin) != NULL)
	{
		if(sscanf(ligne, "%d", &num_led) != 1)
		{
			fprintf(stderr, "integer value expected\n");
			continue;
		}
		num_led;
		if(num_led >= 0 && num_led < NB_LED)
		{
			printf("\nLED #%d = %x\t", num_led, power_2(num_led));
			if(num_led < 16)
			{
				SIPO(power_2(num_led));
				pulse(RCLK1);
				SIPO(0x0);
				pulse(RCLK2);
			}
			else
			{
				num_led -= 16;
				SIPO(power_2(num_led));
				pulse(RCLK2);
				SIPO(0x0);
				pulse(RCLK1);
			}

		}
		else
			printf(" Error : NB_LED = %d\n",NB_LED);
		printf("\nEnter num of LED : ");
	}		
/*
	while(i < NB_LED)
	{
		printf("\nLED[%2d]=%x\t", i, LED[i]);
		SIPO(LED[i]);
		pulse(RCLK);
		i++;
		delayMS(500);
	}*/
	digitalWrite(SCLK, 1);
	return(0);
}

void	SIPO (int byte)
{
	int	i;

	//printf("byte=%x\t", byte);
	for(i = 0; i < 16; i++)
	{
		printf("%0x",((byte &(0x8000 >> i)) > 0));
		digitalWrite(MOSI,((byte & (0x8000 >> i)) > 0));
		pulse(SCLK);
	}
}

void	pulse(int pin)
{
	digitalWrite(pin, 1);

	digitalWrite(pin, 0);
}

