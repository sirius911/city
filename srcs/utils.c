#include "../includes/city.h"

int 	power_2(int x)
{
	if(x == 0)
		return(1);
	return(2 * power_2(x - 1));
}

void	init(t_led *led)
{
	int 	i;

	i = 0;
	while(i < NB_LED)
	{
		led[i].on = OFF;
		i++;
	}
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
