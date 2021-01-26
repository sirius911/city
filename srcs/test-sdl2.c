#include "../includes/city.h"
 
void    load_out(t_out out[32])
{
    printf("load ...");
    out[0].add = 20;
    out[0].bank = 'a';
    out[0].o = 0;
    out[0].state = LOW;
    out[0].x = XA20;
    out[0].y = 298;
    out[0].led_x = 296;
    out[0].led_y = YA20;
    
    out[1].add = 20;
    out[1].bank = 'a';
    out[1].o = 1;
    out[1].state = LOW;
    out[1].x = XA20;
    out[1].y = 277;
    out[1].led_x = 269;
    out[1].led_y = YA20;
        
    out[2].add = 20;
    out[2].bank = 'a';
    out[2].o = 2;
    out[2].state = LOW;
    out[2].x = XA20;
    out[2].y = 258;
    out[2].led_x = 240;
    out[2].led_y = YA20;
        
    out[3].add = 20;
    out[3].bank = 'a';
    out[3].o = 3;
    out[3].state = LOW;
    out[3].x = XA20;
    out[3].y = 233;
    out[3].led_x = 212;
    out[3].led_y = YA20;
        
    out[4].add = 20;
    out[4].bank = 'a';
    out[4].o = 4;
    out[4].state = LOW;
    out[4].x = XA20;
    out[4].y = 210;
    out[4].led_x = 185;
    out[4].led_y = YA20;
        
    out[5].add = 20;
    out[5].bank = 'a';
    out[5].o = 5;
    out[5].state = LOW;
    out[5].x = XA20;
    out[5].y = 188;
    out[5].led_x = 157;
    out[5].led_y = YA20;
        
    out[6].add = 20;
    out[6].bank = 'a';
    out[6].o = 6;
    out[6].state = LOW;
    out[6].x = XA20;
    out[6].y = 165;
    out[6].led_x = 130;
    out[6].led_y = YA20;
        
    out[7].add = 20;
    out[7].bank = 'a';
    out[7].o = 7;
    out[7].state = LOW;
    out[7].x = XA20;
    out[7].y = 143;
    out[7].led_x = 99;
    out[7].led_y = YA20;
    
// bank 20 B
    out[8].add = 20;
    out[8].bank = 'b';
    out[8].o = 0;
    out[8].state = LOW;
    out[8].x = XB20;
    out[8].y = 298;
    out[8].led_x = 296;
    out[8].led_y = YB20;
    
    out[9].add = 20;
    out[9].bank = 'b';
    out[9].o = 1;
    out[9].state = LOW;
    out[9].x = XB20;
    out[9].y = 277;
    out[9].led_x = 269;
    out[9].led_y = YB20;
        
    out[10].add = 20;
    out[10].bank = 'b';
    out[10].o = 2;
    out[10].state = LOW;
    out[10].x = XB20;
    out[10].y = 258;
    out[10].led_x = 240;
    out[10].led_y = YB20;
        
    out[11].add = 20;
    out[11].bank = 'b';
    out[11].o = 3;
    out[11].state = LOW;
    out[11].x = XB20;
    out[11].y = 233;
    out[11].led_x = 212;
    out[11].led_y = YB20;
        
    out[12].add = 20;
    out[12].bank = 'b';
    out[12].o = 4;
    out[12].state = LOW;
    out[12].x = XB20;
    out[12].y = 210;
    out[12].led_x = 185;
    out[12].led_y = YB20;
        
    out[13].add = 20;
    out[13].bank = 'b';
    out[13].o = 5;
    out[13].state = LOW;
    out[13].x = XB20;
    out[13].y = 188;
    out[13].led_x = 157;
    out[13].led_y = YB20;
        
    out[14].add = 20;
    out[14].bank = 'b';
    out[14].o = 6;
    out[14].state = LOW;
    out[14].x = XB20;
    out[14].y = 165;
    out[14].led_x = 130;
    out[14].led_y = YB20;
        
    out[15].add = 20;
    out[15].bank = 'b';
    out[15].o = 7;
    out[15].state = LOW;
    out[15].x = XB20;
    out[15].y = 143;
    out[15].led_x = 99;
    out[15].led_y = YB20;
 /*   
    // 21 Bank a
    out[16].add = 21;
    out[16].bank = 'a';
    out[16].o = 0;
    out[16].state = LOW;
    out[16].x = XA20;
    out[16].y = 256;
    out[16].led_x = 296;
    out[16].led_y = YA20;
    
    out[17].add = 21;
    out[17].bank = 'a';
    out[17].o = 1;
    out[17].state = LOW;
    out[17].x = XA20;
    out[17].y = 233;
    out[17].led_x = 269;
    out[17].led_y = YA20;
        
    out[18].add = 21;
    out[18].bank = 'a';
    out[18].o = 2;
    out[18].state = LOW;
    out[18].x = XA20;
    out[18].y = 210;
    out[18].led_x = 240;
    out[18].led_y = YA20;
        
    out[19].add = 21;
    out[19].bank = 'a';
    out[19].o = 3;
    out[19].state = LOW;
    out[19].x = XA20;
    out[19].y = 187;
    out[19].led_x = 212;
    out[19].led_y = YA20;
        
    out[20].add = 21;
    out[20].bank = 'a';
    out[20].o = 4;
    out[20].state = LOW;
    out[20].x = XA20;
    out[20].y = 164;
    out[20].led_x = 185;
    out[20].led_y = YA20;
        
    out[21].add = 21;
    out[21].bank = 'a';
    out[21].o = 5;
    out[21].state = LOW;
    out[21].x = XA20;
    out[21].y = 142;
    out[21].led_x = 157;
    out[21].led_y = YA20;
        
    out[22].add = 21;
    out[22].bank = 'a';
    out[22].o = 6;
    out[22].state = LOW;
    out[22].x = XA20;
    out[22].y = 119;
    out[22].led_x = 130;
    out[22].led_y = YA20;
        
    out[23].add = 21;
    out[23].bank = 'a';
    out[23].o = 7;
    out[23].state = LOW;
    out[23].x = XA20;
    out[23].y = 97;
    out[23].led_x = 99;
    out[23].led_y = YA20;
    
// bank 21 B
    out[24].add = 21;
    out[24].bank = 'b';
    out[24].o = 0;
    out[24].state = LOW;
    out[24].x = XB20;
    out[24].y = 256;
    out[24].led_x = 296;
    out[24].led_y = YB20;
    
    out[25].add = 21;
    out[25].bank = 'b';
    out[25].o = 1;
    out[25].state = LOW;
    out[25].x = XB20;
    out[25].y = 233;
    out[25].led_x = 269;
    out[25].led_y = YB20;
        
    out[26].add = 21;
    out[26].bank = 'b';
    out[26].o = 2;
    out[26].state = LOW;
    out[26].x = XB20;
    out[26].y = 210;
    out[26].led_x = 240;
    out[26].led_y = YB20;
        
    out[27].add = 21;
    out[27].bank = 'b';
    out[27].o = 3;
    out[27].state = LOW;
    out[27].x = XB20;
    out[27].y = 187;
    out[27].led_x = 212;
    out[27].led_y = YB20;
        
    out[28].add = 21;
    out[28].bank = 'b';
    out[28].o = 4;
    out[28].state = LOW;
    out[28].x = XB20;
    out[28].y = 164;
    out[28].led_x = 185;
    out[28].led_y = YB20;
        
    out[29].add = 21;
    out[29].bank = 'b';
    out[29].o = 5;
    out[29].state = LOW;
    out[29].x = XB20;
    out[29].y = 142;
    out[29].led_x = 157;
    out[29].led_y = YB20;
        
    out[30].add = 21;
    out[30].bank = 'b';
    out[30].o = 6;
    out[30].state = LOW;
    out[30].x = XB20;
    out[30].y = 119;
    out[30].led_x = 130;
    out[30].led_y = YB20;
        
    out[31].add = 21;
    out[31].bank = 'b';
    out[31].o = 7;
    out[31].state = LOW;
    out[31].x = XB20;
    out[31].y = 97;
    out[31].led_x = 99;
    out[31].led_y = YB20;*/
    printf("ok\n");
}
 
int main(int argc, char *argv[])
{
    SDL_Surface     *screen;
    SDL_Surface     *back = NULL;
    SDL_Surface     *led = NULL;
    SDL_Surface     *red = NULL;
    SDL_Rect        pos, pos_led, pos_red;
    SDL_Event       event;
    
    t_out       out[32];
    
    load_out(out);
    
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
    
    red = SDL_LoadBMP("img/red_button.bmp");
    SDL_SetColorKey(red, SDL_SRCCOLORKEY, SDL_MapRGB(red->format, 0, 0, 0));
    
SDL_BlitSurface(back, NULL, screen, &pos);
int visuel = 1;
int i = 0;
while (i < 32)
{
    pos_led.x = out[i].led_x;
    pos_led.y = out[i].led_y;
    pos_red.x = out[i].x;
    pos_red.y = out[i].y;
    SDL_BlitSurface(led, NULL, screen, &pos_led);
    SDL_BlitSurface(red, NULL, screen, &pos_red);
    i++;
}
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
                if (event.key.keysym.sym == SDLK_v)
                {
                    SDL_BlitSurface(back, NULL, screen, &pos);
                    visuel = !visuel;
                    if (visuel)
                    {
                        i = 0;
                        while (i < 32)
                        {
                            pos_led.x = out[i].led_x;
                            pos_led.y = out[i].led_y;
                            pos_red.x = out[i].x;
                            pos_red.y = out[i].y;
                            SDL_BlitSurface(led, NULL, screen, &pos_led);
                            SDL_BlitSurface(red, NULL, screen, &pos_red);
                            i++;
                        }
                    }
                    SDL_Flip(screen);
                }
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
        //SDL_BlitSurface(back, NULL, screen, &pos);
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

