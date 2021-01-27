#include "../includes/city.h"

int				init_city(t_city *city)
{
	write(1, "Init city ", 10);

	city->back = NULL;
	city->button = NULL;
	city->led = NULL;

	SDL_WM_SetIcon(SDL_LoadBMP("img/city.bmp"), NULL);
		write(1, "...", 3);
    city->screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre
    write(1, "...", 3);
    if (!city->screen)
    {
        fprintf(stderr, "Error\n set video mode fail : %s\n", SDL_GetError());
        return (FALSE);
    }
    SDL_WM_SetCaption("Lorin's City V1.0", NULL);
    write(1, "...", 3);
    city->back = SDL_LoadBMP("img/fond.bmp");
    write(1, "...", 3);

    city->led = SDL_LoadBMP("img/led.bmp");
    if (!city->led)
		write(2, "Error\n", 6);
    write(1, "...", 3);
    city->button = SDL_LoadBMP("img/red_button.bmp");
    if (!city->button)
		write(1, "Error\n", 6);
    write(1, "...", 3);
    SDL_SetColorKey(city->button, SDL_SRCCOLORKEY, SDL_MapRGB(city->button->format, 0, 0, 0));
       
    city->a20 = FALSE;
    city->b20 = FALSE;
    city->a21 = FALSE;
    city->b21 = FALSE;
    write(1, " ok\n", 4);
    return (TRUE);
}

void			close_city(t_city *city)
{
	SDL_FreeSurface(city->back);
    SDL_FreeSurface(city->led);
    SDL_FreeSurface(city->button);
    SDL_Quit(); // Arrêt de la SDL
}
