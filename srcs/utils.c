#include "../includes/city.h"

int 	power_2(int x)
{
	if(x == 0)
		return(1);
	return(2 * power_2(x - 1));
}

void	init()
{
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

void	SIPO (int byte)
{
	int	i;

	for(i = 0; i < 16; i++)
	{
		//printf("%0x",((byte &(0x8000 >> i)) > 0));
		digitalWrite(MOSI,((byte & (0x8000 >> i)) > 0));
		pulse(SCLK);
	}
}

void	pulse(int pin)
{
	digitalWrite(pin, 1);

	digitalWrite(pin, 0);
}
