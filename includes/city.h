#ifndef CITY_H
# define CITY_H

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

# define LOW 0
# define HIGH 1
# define YA20 144
# define YB20 190
# define XA20 567
# define XB20 590
typedef struct		s_out
{
	int				add;
	char			bank;
	int				o;
	int				state;
	int				x;
	int				y;
	int				led_x;
	int				led_y;
}					t_out;

#endif
