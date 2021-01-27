#include "../includes/city.h"
 
int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    int                 continuer;
    t_city              city;
    SDL_Event           event;
    int                 button;
    enum master         master_button;  
    
    button = -1;
    continuer = TRUE;
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Error\n initialisation of SDL fail : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    init_city(&city);
    load_out(&city);
    all_state(city.out, ALL, LOW);
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
                break;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    button =find_out(event.button.x, event.button.y, city.out);
                    if (button != -1)
                    {
                        switch_button(&city.out[button]);
                        put_card(city.out[button]);
                    }
                    else
                    {
                        master_button = find_master(event.button.x, event.button.y);
                        switch(master_button)
                        {
                            case A20:
                                city.a20 = !city.a20;
                                all_state(city.out, A20, (city.a20) ? HIGH : LOW);
                                break;
                            case A21:
                                city.a21 = !city.a21;
                                all_state(city.out, A21, (city.a21) ? HIGH : LOW);
                                break;
                            case B20:
                                city.b20 = !city.b20;
                                all_state(city.out, B20, (city.b20) ? HIGH : LOW);
                                break;
                            case B21:
                                city.b21 = !city.b21;
                                all_state(city.out, B21, (city.b21) ? HIGH : LOW);
                                break;
                            default:
                                printf("(%d,%d)\n",event.button.x, event.button.y);
                        }
                        
                    }
                }                   
                break;
        }
        print_all(&city);
    }
    close_city(&city);
    return EXIT_SUCCESS; // Fermeture du programme
}

