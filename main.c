#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "arrows.h"
#include "blankscreen.h"
#include "songs.h"

#define ArrowLocationLeft 13
#define ArrowLocationRight 3
#define ArrowCutoutLocationY 1
#define ArrowLocationY 17
uint8_t gamemode = 2;

// gm 0 - title screen
// gm 1 - song selection
// gm 2 - GAming!?!?!?!? oooooooHH!!!
// gm 3 - looserer!! S K I L L ISSUE!

void display()
{
    // world view updater
    switch (gamemode)
    {
    case 1: // song selection
        /* code */
        break;
    case 2: // GAmeing?!?!? (bumpin beats yall!)

        break;
    case 3: // sSKILl ISSUE!?!?!? (lost)
        /* code */
        break;

    default: // titlescreen
        break;
    }
}

void clearScreen()
{
}

void songsetup(void) // inits all stuff needed for arrows (NOT SCROLLING!!)
{
    set_bkg_data(0, 100, arrows);
    set_bkg_tiles(0, 0, 18, 20, blankScreen);
    set_bkg_tile_xy(ArrowLocationRight, ArrowCutoutLocationY, 90);
    set_bkg_tile_xy(ArrowLocationRight + 1, ArrowCutoutLocationY, 91);
    set_bkg_tile_xy(ArrowLocationRight + 2, ArrowCutoutLocationY, 92);
    set_bkg_tile_xy(ArrowLocationRight + 3, ArrowCutoutLocationY, 93);

    set_bkg_tile_xy(ArrowLocationLeft, ArrowCutoutLocationY, 90);
    set_bkg_tile_xy(ArrowLocationLeft + 1, ArrowCutoutLocationY, 91);
    set_bkg_tile_xy(ArrowLocationLeft + 2, ArrowCutoutLocationY, 92);
    set_bkg_tile_xy(ArrowLocationLeft + 3, ArrowCutoutLocationY, 93);
}

void Song1Handler()
{

    for (uint8_t i = 0; i < 100; i++)
    {
        if (song11[i] != 0 && i < Sg1Lenght) // left
        {
            set_bkg_tile_xy(ArrowLocationLeft, ArrowLocationY, song11[i] + 8);
        }
        if (song12[i] != 0 && i < Sg1Lenght) // dwon
        {
            set_bkg_tile_xy(ArrowLocationLeft + 1, ArrowLocationY, song12[i] + 8);
        }
        if (song13[i] != 0 && i < Sg1Lenght)
        {
            set_bkg_tile_xy(ArrowLocationLeft + 2, ArrowLocationY, song13[i] + 8);
        }
        if (song14[i] != 0 && i < Sg1Lenght)
        {
            set_bkg_tile_xy(ArrowLocationLeft + 3, ArrowLocationY, song14[i] + 8);
        }
        for (uint8_t o = 0; o < 8; o++)
        {
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // left note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationLeft, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationLeft, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationLeft, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationLeft, l - 2);
                if (temp != 0)
                {
                        if (temp == 1)
                        {
                            if (l != ArrowCutoutLocationY + 1)
                            {
                                if(temp2 != 0)
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft, l - 1, 15);
                                }
                                else
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft, l - 1, 8);
                                }
                                

                            }
                            if(temp3 == 0)
                            {  
                                set_bkg_tile_xy(ArrowLocationLeft, l, 22);
                            }
                            else if(temp2 != 0 && temp2 != 90)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft, l - 1, 15);
                            }
                            else if(temp2 != 90)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft, l - 1, 8);
                            }
                        }
                        else if (temp == 9)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft, l, 1);
                        }
                        else if (temp == 16)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft, l, 0);
                        }
                        else
                        {
                            set_bkg_tile_xy(ArrowLocationLeft, l, temp - 1);
                        }
                    
                    
                }
            }
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // down note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationLeft + 1, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationLeft + 1, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationLeft + 1, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationLeft + 1, l - 2);
                if (temp != 0)
                {
                    if (temp == 23)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                                if(temp2 != 0)
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 37);
                                }
                                else
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 30);
                                }
                                

                        }

                            if(temp3 == 0)
                            {  
                                set_bkg_tile_xy(ArrowLocationLeft + 1, l, 43);
                            }
                            else if(temp2 != 0 && temp2 != 91)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 37);
                            }
                            else if(temp2 != 91)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 30);
                            }
                    }
                    else if (temp == 31)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 1, l, 23);
                    }
                    else if (temp == 38)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 1, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 1, l, temp - 1);
                    }
                }
            }   
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // up note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationLeft + 2, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationLeft + 2, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationLeft + 2, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationLeft + 2, l - 2);
                if (temp != 0)
                {
                    if (temp == 45)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                                if(temp2 != 0)
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 59);
                                }
                                else
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 52);
                                }
                                

                        }

                            if(temp3 == 0)
                            {  
                                set_bkg_tile_xy(ArrowLocationLeft + 2, l, 66);
                            }
                            else if(temp2 != 0 && temp2 != 92)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 59);
                            }
                            else if(temp2 != 92)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 52);
                            }
                    }
                    else if (temp == 53)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft+2, l, 45);  
                        }
                    else if (temp == 60)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 2, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 2, l, temp - 1);
                    }
                }
            }
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // right note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationLeft + 3, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationLeft + 3, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationLeft + 3, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationLeft + 3, l - 2);
                if (temp != 0)
                {
                    if (temp == 67)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                                if(temp2 != 0)
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 81);
                                }
                                else
                                {
                                    set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 74);
                                }
                                

                        }

                            if(temp3 == 0)
                            {  
                                set_bkg_tile_xy(ArrowLocationLeft + 3, l, 88);
                            }
                            else if(temp2 != 0 && temp2 != 93)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 81);
                            }
                            else if(temp2 != 93)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 74); 
                            }
                    }
                    else if (temp == 75)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 3, l, 67);
                    }
                    else if (temp == 82)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 3, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 3, l, temp - 1);
                    }
                }
                
            }
            delay(S1delay); 
        }
    }
}

void main(void)
{
    SHOW_BKG;
    SHOW_SPRITES;
    songsetup();
    Song1Handler();
    while (1)
    {
        uint8_t cur = joypad();

        if (cur & J_A)
        {
        }

        if (cur & J_B)
        {
        }

        if (cur & J_SELECT)
        {
        }

        if (cur & J_START)
        {
        }

        if (cur & J_UP)
        {
        }
        else if (cur & J_DOWN)
        {
        }

        if (cur & J_LEFT)
        {
        }
        else if (cur & J_RIGHT)
        {
        }

        display();
    }
}
