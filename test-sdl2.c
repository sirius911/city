#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
 
void pause();
 
int main(int argc, char *argv[])
{
    SDL_Surface     *screen;
    SDL_Surface     *back = NULL;
    SDL_Surface     *led = NULL;
    SDL_Surface     *red = NULL;
    SDL_Rect        pos, pos_led, pos_red;
    SDL_Event       event;
    
    screen = NULL;
    pos.x = 0;
    pos.y = 0;

    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Error\n initialisation of SDL fail : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetIcon(SDL_LoadBMP("img/city.bmp"), NULL);
    screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre
    if (!screen)
    {
        fprintf(stderr, "Error\n set video mode fail : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_WM_SetCaption("Lorin's City V0.0", NULL);
    SDL_FillRect(screen, NULL, 0x0000FF);
    back = SDL_LoadBMP("img/fond.bmp");
    SDL_BlitSurface(back, NULL, screen, &pos);

    led = SDL_LoadBMP("img/led.bmp");
    pos_led.x = screen->w / 2 - led->w / 2;
    pos_led.y = screen->h / 2 - led->h / 2;
    
    red = SDL_LoadBMP("img/red_button.bmp");
    SDL_SetColorKey(red, SDL_SRCCOLORKEY, SDL_MapRGB(red->format, 0, 0, 0));
    pos_red.x = 140;
    pos_red.y = 27;

    SDL_Flip(screen);
    //SDL_EnableKeyRepeat(10, 10);
    int             continuer = 1;
    int _led = 1;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    continuer = 0;
                else if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    if (_led)
                        pos_led.x++;
                    else
                        pos_red.x++;
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    if (_led)
                        pos_led.x--;
                    else
                        pos_red.x--;
                }
                else if (event.key.keysym.sym == SDLK_DOWN)
                {
                    if (_led)
                        pos_led.y++;
                    else
                        pos_red.y++;
                }
                else if (event.key.keysym.sym == SDLK_UP)
                {
                    if (_led)
                        pos_led.y--;
                    else
                        pos_red.y--;
                }
                if (_led)
                    printf("coord led = %d,%d\n", pos_led.x, pos_led.y);
                else
                    printf("coord red = %d,%d\n", pos_red.x, pos_red.y);
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_RIGHT)
                {
                    _led = 0;
                    pos_red.x = event.button.x;
                    pos_red.y = event.button.y;
                    printf("coord = %d,%d\n", event.button.x, event.button.y);
                }                   
                else if (event.button.button == SDL_BUTTON_LEFT)
                {
                    _led = 1;
                    pos_led.x = event.button.x;
                    pos_led.y = event.button.y;
                    printf("coord = %d,%d\n", event.button.x, event.button.y);
                }
                break;
        }
        SDL_BlitSurface(back, NULL, screen, &pos);
        SDL_BlitSurface(led, NULL, screen, &pos_led);
        SDL_BlitSurface(red, NULL, screen, &pos_red);
        SDL_Flip(screen);
    }
 
    SDL_FreeSurface(back);
    SDL_FreeSurface(led);
    SDL_FreeSurface(red);
    SDL_Quit(); // Arrêt de la SDL
 
    return EXIT_SUCCESS; // Fermeture du programme
}

