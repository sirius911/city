#ifndef CITY_H
# define CITY_H

# define NB_LED 32

# define MOSI	12
# define SCLK	14
# define RCLK1	10 
# define RCLK2	11
# define ON 	1
# define OFF 	0

#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

typedef struct	s_led
{
	int		on;
}				t_led;

void	SIPO (int byte);
void	pulse (int pin);
int 	power_2(int x);
void	init(t_led *led);
void	print_led(t_led *led);
void	send(t_led *led);

#endif
