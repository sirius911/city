#ifndef CITY_H
# define CITY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>

# define LOW 0
# define HIGH 1
# define TRUE 1
# define FALSE 0

# define YA20 144	// ligne des boutons add20 a
# define YB20 190	// ligne des boutons add20 b

# define YA21 50	// ligne des boutons add21 a
# define YB21 27	// ligne des boutons add21 b

# define YA21L 239	// ligne des leds add21 a
# define YB21L 285	// ligne des leds add21 b

# define XA20 567	// colone des boutons add20 a
# define XB20 590	// colone des boutons add20 b

# define NB_OUT 32

# define TILE_BUTTON 20

typedef struct		s_out
{
	int				add;
	char			bank;
	int				o;
	int				state;
	SDL_Rect		pos_led;
	SDL_Rect		pos_button;
}					t_out;

typedef struct		s_city
{
	SDL_Surface		*screen;
	SDL_Surface		*back;
	SDL_Surface		*led;
	SDL_Surface		*button;
	t_out       	out[NB_OUT];
	int				a20;	// bool pour comander toute la bank
	int				b20;
	int				a21;
	int				b21;
}					t_city;
enum master {A20, B20, A21, B21, ALL};

void    		load_out(t_city *city);
void            print_all(t_city *city);
int				init_city(t_city *city);
void			close_city(t_city *city);
int             find_out(int x, int y, t_out tab[NB_OUT]);
void            switch_button(t_out *out);
void			put_card(t_out out);
enum master     find_master(int x, int y);
void            all_state(t_out tab[NB_OUT], int bank, int state);

#endif
