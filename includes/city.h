#ifndef CITY_H
# define CITY_H

# define NB_LED 32

# define MOSI	12
# define SCLK	14
# define RCLK1	10 
# define RCLK2	11

#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"


void	SIPO (int byte);
void	pulse (int pin);
int 	power_2(int x);
void	init();

#endif
