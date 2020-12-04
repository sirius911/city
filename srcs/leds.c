#include "../includes/city.h"

void	SIPO (int byte)
{
	int	i;

	for(i = 0; i < 16; i++)
	{
		printf("%0x",((byte &(0x8000 >> i)) > 0));
		digitalWrite(MOSI,((byte & (0x8000 >> i)) > 0));
		pulse(SCLK);
	}
	printf("\n");
}

void	pulse(int pin)
{
	(void) pin;
	digitalWrite(pin, 1);

	digitalWrite(pin, 0);
}

void	print_led(t_led *led)
{
	int 	i;

	i = 31;
	while(i >= 0)
	{
		printf("%s", (led[i].on) ? "o" : ".");
		if(i % 8 == 0)
			printf("\n");
		i--;
	}
}

void	send(t_led *led)
{
	int 	i;
	int 	board1;
	int 	board2;

	i = 0;
	board1 = 0;
	board2 = 0;
	while(i < NB_LED/2)
	{
		if(led[i].on)
			board1 = board1 | power_2(i);
		i++;
	}
	while(i < NB_LED)
	{
		if(led[i].on)
			board2 = board2 | power_2(i - 16);
		i++;
	}
	printf("board1 = %x\tboad2 = %x\n", board1, board2);
	SIPO(board1);
	pulse(RCLK1);
	SIPO(board2);
	pulse(RCLK2);
}