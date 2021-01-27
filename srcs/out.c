#include "../includes/city.h"

void            print_all(t_city *city)
{
    int         i;
    SDL_Rect    pos;
    
    i = 0;
    pos.x = 0;
    pos.y = 0;
    SDL_BlitSurface(city->back, NULL, city->screen, &pos);
    while (i < NB_OUT)
    {
        if (city->out[i].state == HIGH)
        {
            pos.x = city->out[i].pos_led.x;
            pos.y = city->out[i].pos_led.y;
            SDL_BlitSurface(city->led, NULL, city->screen, &pos);
            pos.x = city->out[i].pos_button.x;
            pos.y = city->out[i].pos_button.y;
            SDL_BlitSurface(city->button, NULL, city->screen, &pos);
        }
        i++;       
    }
    SDL_Flip(city->screen);    
}

void            switch_button(t_out *out)
{
    out->state = !out->state;
}

int             find_out(int x, int y, t_out tab[NB_OUT])
{
    int         i;
    
    i = 0;
    while (i < NB_OUT)
    {
        if (x >= tab[i].pos_button.x && x <= (tab[i].pos_button.x + TILE_BUTTON)
        && y >= tab[i].pos_button.y && y <= (tab[i].pos_button.y + TILE_BUTTON))
            return (i);
        i++;
    }
    return (-1);
}

enum master     find_master(int x, int y)
{
    if (x >= 570 && x <= 580 && y >= 120 && y <= 136)
        return (A20);
    if (x >= 593 && x <= 606 && y >= 120 && y <= 136)
        return (B20);
    if (x >= 163 && x <= 176 && y >= 55 && y <= 66)
        return (A21);
    if (x >= 163 && x <= 176 && y >= 32 && y <= 44)
        return (B21);
    return (-1);
}

void            all_state(t_out tab[NB_OUT], int bank, int state)
{
    int         i;
    int         j;
    
    if (bank == A20 || bank == ALL)
        i = 0;
    else if (bank == B20)
        i = 8;
    else if (bank == A21)
        i = 16;
    else if (bank == B21)
        i = 24;
    else
        return;
    if (bank == ALL)
        j = NB_OUT;
    else
        j = i + 8;
    while (i < j)
    {
        tab[i].state = state;
        put_card(tab[i]);
        i++;
    }
}

void            load_out(t_city *city)
{
    
    printf("Load ");

// bank 20 a
    city->out[0].add = 20;
    city->out[0].bank = 'a';
    city->out[0].o = 0;
    city->out[0].state = LOW;
    city->out[0].pos_button.x = XA20;
    city->out[0].pos_button.y = 298;
    city->out[0].pos_led.x = 296;
    city->out[0].pos_led.y = YA20;

    city->out[1].add = 20;
    city->out[1].bank = 'a';
    city->out[1].o = 1;
    city->out[1].state = LOW;
    city->out[1].pos_button.x = XA20;
    city->out[1].pos_button.y = 277;
    city->out[1].pos_led.x = 269;
    city->out[1].pos_led.y = YA20;
        
    city->out[2].add = 20;
    city->out[2].bank = 'a';
    city->out[2].o = 2;
    city->out[2].state = LOW;
    city->out[2].pos_button.x = XA20;
    city->out[2].pos_button.y = 258;
    city->out[2].pos_led.x = 240;
    city->out[2].pos_led.y = YA20;
        
    city->out[3].add = 20;
    city->out[3].bank = 'a';
    city->out[3].o = 3;
    city->out[3].state = LOW;
    city->out[3].pos_button.x = XA20;
    city->out[3].pos_button.y = 233;
    city->out[3].pos_led.x = 212;
    city->out[3].pos_led.y = YA20;
        
    city->out[4].add = 20;
    city->out[4].bank = 'a';
    city->out[4].o = 4;
    city->out[4].state = LOW;
    city->out[4].pos_button.x = XA20;
    city->out[4].pos_button.y = 210;
    city->out[4].pos_led.x = 185;
    city->out[4].pos_led.y = YA20;
        
    city->out[5].add = 20;
    city->out[5].bank = 'a';
    city->out[5].o = 5;
    city->out[5].state = LOW;
    city->out[5].pos_button.x = XA20;
    city->out[5].pos_button.y = 188;
    city->out[5].pos_led.x = 157;
    city->out[5].pos_led.y = YA20;
        
    city->out[6].add = 20;
    city->out[6].bank = 'a';
    city->out[6].o = 6;
    city->out[6].state = LOW;
    city->out[6].pos_button.x = XA20;
    city->out[6].pos_button.y = 165;
    city->out[6].pos_led.x = 130;
    city->out[6].pos_led.y = YA20;
        
    city->out[7].add = 20;
    city->out[7].bank = 'a';
    city->out[7].o = 7;
    city->out[7].state = LOW;
    city->out[7].pos_button.x = XA20;
    city->out[7].pos_button.y = 143;
    city->out[7].pos_led.x = 99;
    city->out[7].pos_led.y = YA20;
    
// bank 20 B
    city->out[8].add = 20;
    city->out[8].bank = 'b';
    city->out[8].o = 0;
    city->out[8].state = LOW;
    city->out[8].pos_button.x = XB20;
    city->out[8].pos_button.y = 298;
    city->out[8].pos_led.x = 296;
    city->out[8].pos_led.y = YB20;
    
    city->out[9].add = 20;
    city->out[9].bank = 'b';
    city->out[9].o = 1;
    city->out[9].state = LOW;
    city->out[9].pos_button.x = XB20;
    city->out[9].pos_button.y = 277;
    city->out[9].pos_led.x = 269;
    city->out[9].pos_led.y = YB20;
        
    city->out[10].add = 20;
    city->out[10].bank = 'b';
    city->out[10].o = 2;
    city->out[10].state = LOW;
    city->out[10].pos_button.x = XB20;
    city->out[10].pos_button.y = 258;
    city->out[10].pos_led.x = 240;
    city->out[10].pos_led.y = YB20;
        
    city->out[11].add = 20;
    city->out[11].bank = 'b';
    city->out[11].o = 3;
    city->out[11].state = LOW;
    city->out[11].pos_button.x = XB20;
    city->out[11].pos_button.y = 233;
    city->out[11].pos_led.x = 212;
    city->out[11].pos_led.y = YB20;
        
    city->out[12].add = 20;
    city->out[12].bank = 'b';
    city->out[12].o = 4;
    city->out[12].state = LOW;
    city->out[12].pos_button.x = XB20;
    city->out[12].pos_button.y = 210;
    city->out[12].pos_led.x = 185;
    city->out[12].pos_led.y = YB20;
        
    city->out[13].add = 20;
    city->out[13].bank = 'b';
    city->out[13].o = 5;
    city->out[13].state = LOW;
    city->out[13].pos_button.x = XB20;
    city->out[13].pos_button.y = 188;
    city->out[13].pos_led.x = 157;
    city->out[13].pos_led.y = YB20;
        
    city->out[14].add = 20;
    city->out[14].bank = 'b';
    city->out[14].o = 6;
    city->out[14].state = LOW;
    city->out[14].pos_button.x = XB20;
    city->out[14].pos_button.y = 165;
    city->out[14].pos_led.x = 130;
    city->out[14].pos_led.y = YB20;
        
    city->out[15].add = 20;
    city->out[15].bank = 'b';
    city->out[15].o = 7;
    city->out[15].state = LOW;
    city->out[15].pos_button.x = XB20;
    city->out[15].pos_button.y = 143;
    city->out[15].pos_led.x = 99;
    city->out[15].pos_led.y = YB20;
    
// Bank 21 a
    city->out[16].add = 21;
    city->out[16].bank = 'a';
    city->out[16].o = 0;
    city->out[16].state = LOW;
    city->out[16].pos_button.x = 340;
    city->out[16].pos_button.y = YA21;
    city->out[16].pos_led.x = 297;
    city->out[16].pos_led.y = YA21L;
    
    city->out[17].add = 21;
    city->out[17].bank = 'a';
    city->out[17].o = 1;
    city->out[17].state = LOW;
    city->out[17].pos_button.x = 318;
    city->out[17].pos_button.y = YA21;
    city->out[17].pos_led.x = 270;
    city->out[17].pos_led.y = YA21L;
        
    city->out[18].add = 21;
    city->out[18].bank = 'a';
    city->out[18].o = 2;
    city->out[18].state = LOW;
    city->out[18].pos_button.x = 296;
    city->out[18].pos_button.y = YA21;
    city->out[18].pos_led.x = 240;
    city->out[18].pos_led.y = YA21L;
        
    city->out[19].add = 21;
    city->out[19].bank = 'a';
    city->out[19].o = 3;
    city->out[19].state = LOW;
    city->out[19].pos_button.x = 274;
    city->out[19].pos_button.y = YA21;
    city->out[19].pos_led.x = 213;
    city->out[19].pos_led.y = YA21L;
        
    city->out[20].add = 21;
    city->out[20].bank = 'a';
    city->out[20].o = 4;
    city->out[20].state = LOW;
    city->out[20].pos_button.x = 251;
    city->out[20].pos_button.y = YA21;
    city->out[20].pos_led.x = 185;
    city->out[20].pos_led.y = YA21L;
        
    city->out[21].add = 21;
    city->out[21].bank = 'a';
    city->out[21].o = 5;
    city->out[21].state = LOW;
    city->out[21].pos_button.x = 229;
    city->out[21].pos_button.y = YA21;
    city->out[21].pos_led.x = 158;
    city->out[21].pos_led.y = YA21L;
        
    city->out[22].add = 21;
    city->out[22].bank = 'a';
    city->out[22].o = 6;
    city->out[22].state = LOW;
    city->out[22].pos_button.x = 206;
    city->out[22].pos_button.y = YA21;
    city->out[22].pos_led.x = 130;
    city->out[22].pos_led.y = YA21L;
        
    city->out[23].add = 21;
    city->out[23].bank = 'a';
    city->out[23].o = 7;
    city->out[23].state = LOW;
    city->out[23].pos_button.x = 184;
    city->out[23].pos_button.y = YA21;
    city->out[23].pos_led.x = 101;
    city->out[23].pos_led.y = YA21L;
    
// bank 21 B
    city->out[24].add = 21;
    city->out[24].bank = 'b';
    city->out[24].o = 0;
    city->out[24].state = LOW;
    city->out[24].pos_button.x = 340;
    city->out[24].pos_button.y = YB21;
    city->out[24].pos_led.x = 297;
    city->out[24].pos_led.y = YB21L;
    
    city->out[25].add = 21;
    city->out[25].bank = 'b';
    city->out[25].o = 1;
    city->out[25].state = LOW;
    city->out[25].pos_button.x = 318;
    city->out[25].pos_button.y = YB21;
    city->out[25].pos_led.x = 270;
    city->out[25].pos_led.y = YB21L;
        
    city->out[26].add = 21;
    city->out[26].bank = 'b';
    city->out[26].o = 2;
    city->out[26].state = LOW;
    city->out[26].pos_button.x = 296;
    city->out[26].pos_button.y = YB21;
    city->out[26].pos_led.x = 240;
    city->out[26].pos_led.y = YB21L;
        
    city->out[27].add = 21;
    city->out[27].bank = 'b';
    city->out[27].o = 3;
    city->out[27].state = LOW;
    city->out[27].pos_button.x = 274;
    city->out[27].pos_button.y = YB21;
    city->out[27].pos_led.x = 213;
    city->out[27].pos_led.y = YB21L;
        
    city->out[28].add = 21;
    city->out[28].bank = 'b';
    city->out[28].o = 4;
    city->out[28].state = LOW;
    city->out[28].pos_button.x = 251;
    city->out[28].pos_button.y = YB21;
    city->out[28].pos_led.x = 185;
    city->out[28].pos_led.y = YB21L;
        
    city->out[29].add = 21;
    city->out[29].bank = 'b';
    city->out[29].o = 5;
    city->out[29].state = LOW;
    city->out[29].pos_button.x = 229;
    city->out[29].pos_button.y = YB21;
    city->out[29].pos_led.x = 158;
    city->out[29].pos_led.y = YB21L;
        
    city->out[30].add = 21;
    city->out[30].bank = 'b';
    city->out[30].o = 6;
    city->out[30].state = LOW;
    city->out[30].pos_button.x = 206;
    city->out[30].pos_button.y = YB21;
    city->out[30].pos_led.x = 130;
    city->out[30].pos_led.y = YB21L;
        
    city->out[31].add = 21;
    city->out[31].bank = 'b';
    city->out[31].o = 7;
    city->out[31].state = LOW;
    city->out[31].pos_button.x = 184;
    city->out[31].pos_button.y = YB21;
    city->out[31].pos_led.x = 101;
    city->out[31].pos_led.y = YB21L; 
    printf("ok\n");
}
 
