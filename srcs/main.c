#include "../includes/city.h"

int	main(void)
{
	char	ligne[25];
	int		num_led;
	t_led	led[NB_LED];

	num_led = 0;
	if(wiringPiSetup() == -1)
	{
		ft_printf("Setup wiringPi failed!\n");
		return (-1);
	}
	init(led);
	printf("\nEnter num of LED : ");
	while(fgets(ligne, 80, stdin) != NULL)
	{
		if(sscanf(ligne, "%d", &num_led) != 1)
		{
			fprintf(stderr, "integer value expected\n");
			continue;
		}
		if(num_led >= 0 && num_led < NB_LED)
		{
			led[num_led].on = !led[num_led].on;
			send(led);
			printf("\nLED #%d = %x\n", num_led, power_2(num_led));
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
		print_led(led);
		printf("\nEnter num of LED : ");
	}		
	digitalWrite(SCLK, 1);
	return(0);
}
