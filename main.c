#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "arrows.h"
#include "blankscreen.h"
#include "songs.h"

#define ArrowLocationLeft 14
#define ArrowLocationRight 2
#define ArrowCutoutLocationY 1
#define ArrowLocationY 17
uint8_t gamemode = 2;
uint8_t bankLength = 0;
uint8_t bankDelay = 0;
uint16_t i = 0;
BOOLEAN chkLeft;
BOOLEAN chkDown;
BOOLEAN chkUp;
BOOLEAN chkRight;
// gm 0 - title screen
// gm 1 - song selection
// gm 2 - GAming!?!?!?!? oooooooHH!!!
// gm 3 - looserer!! S K I L L ISSUE!



void clearScreen()
{
}

void songsetup(uint8_t songNum) // inits all stuff needed for arrows (NOT SCROLLING!!)
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

    switch (songNum)
    {
    case 1:
        for (uint16_t p = 0; p < Sg1Lenght; p++)
        {
            songBank1a[p] = song11a[p];
            songBank2a[p] = song12a[p];
            songBank3a[p] = song13a[p];
            songBank4a[p] = song14a[p];
            songBank1b[p] = song11b[p];
            songBank2b[p] = song12b[p];
            songBank3b[p] = song13b[p];
            songBank4b[p] = song14b[p];
        }
        bankLength = Sg1Lenght;
        bankDelay = S1delay;
        break;

    default:
    for (uint16_t p = 0; p < Sg1Lenght; p++)
        {
            songBank1a[p] = song11a[p];
            songBank2a[p] = song12a[p];
            songBank3a[p] = song13a[p];
            songBank4a[p] = song14a[p];
            songBank1b[p] = song11b[p];
            songBank2b[p] = song12b[p];
            songBank3b[p] = song13b[p];
            songBank4b[p] = song14b[p];
        }
        bankLength = Sg1Lenght;
        bankDelay = S1delay;
        break;
    }
}

void SongHandler(uint16_t i)
{

       // *(uint8_t*)0xFF42 = 20;
        if (songBank1a[i] != 0 && i < bankLength) // left
        {
            set_bkg_tile_xy(ArrowLocationLeft, ArrowLocationY, songBank1a[i] + 8);
        }
        if (songBank2a[i] != 0 && i < bankLength) // dwon
        {
            set_bkg_tile_xy(ArrowLocationLeft + 1, ArrowLocationY, songBank2a[i] + 8);
        }
        if (songBank3a[i] != 0 && i < bankLength)
        {
            set_bkg_tile_xy(ArrowLocationLeft + 2, ArrowLocationY, songBank3a[i] + 8);
        }
        if (songBank4a[i] != 0 && i < bankLength)
        {
            set_bkg_tile_xy(ArrowLocationLeft + 3, ArrowLocationY, songBank4a[i] + 8);
        }
        // under this line is the right side
        if (songBank1b[i] != 0 && i < bankLength) // left
        {
            set_bkg_tile_xy(ArrowLocationRight, ArrowLocationY, songBank1b[i] + 8);
        }
        if (songBank2b[i] != 0 && i < bankLength) // dwon
        {
            set_bkg_tile_xy(ArrowLocationRight + 1, ArrowLocationY, songBank2b[i] + 8);
        }
        if (songBank3b[i] != 0 && i < bankLength)
        {
            set_bkg_tile_xy(ArrowLocationRight + 2, ArrowLocationY, songBank3b[i] + 8);
        }
        if (songBank4b[i] != 0 && i < bankLength)
        {
            set_bkg_tile_xy(ArrowLocationRight + 3, ArrowLocationY, songBank4b[i] + 8);
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
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft, l - 1, 15);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationLeft, l - 1, 8);
                            }
                        }
                        else
                        {
                            chkLeft = TRUE;
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft, l, 22);
                        }
                        else if (temp2 != 0 && temp2 != 90)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft, l - 1, 15);
                        }
                        else if (temp2 != 90)
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
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 37);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 30);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 1, l, 43);
                        }
                        else if (temp2 != 0 && temp2 != 91)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 1, l - 1, 37);
                        }
                        else if (temp2 != 91)
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
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 59);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 52);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 2, l, 66);
                        }
                        else if (temp2 != 0 && temp2 != 92)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 59);
                        }
                        else if (temp2 != 92)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 2, l - 1, 52);
                        }
                    }
                    else if (temp == 53)
                    {
                        set_bkg_tile_xy(ArrowLocationLeft + 2, l, 45);
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
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 81);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 74);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 3, l, 88);
                        }
                        else if (temp2 != 0 && temp2 != 93)
                        {
                            set_bkg_tile_xy(ArrowLocationLeft + 3, l - 1, 81);
                        }
                        else if (temp2 != 93)
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

// right


for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // left note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationRight, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationRight, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationRight, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationRight, l - 2);
                if (temp != 0)
                {
                    if (temp == 1)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationRight, l - 1, 15);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationRight, l - 1, 8);
                            }
                        }
                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationRight, l, 22);
                        }
                        else if (temp2 != 0 && temp2 != 90)
                        {
                            set_bkg_tile_xy(ArrowLocationRight, l - 1, 15);
                        }
                        else if (temp2 != 90)
                        {
                            set_bkg_tile_xy(ArrowLocationRight, l - 1, 8);
                        }
                    }
                    else if (temp == 9)
                    {
                        set_bkg_tile_xy(ArrowLocationRight, l, 1);
                    }
                    else if (temp == 16)
                    {
                        set_bkg_tile_xy(ArrowLocationRight, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationRight, l, temp - 1);
                    }
                }
            }
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // down note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationRight + 1, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationRight + 1, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationRight + 1, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationRight + 1, l - 2);
                if (temp != 0)
                {
                    if (temp == 23)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 1, l - 1, 37);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 1, l - 1, 30);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 1, l, 43);
                        }
                        else if (temp2 != 0 && temp2 != 91)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 1, l - 1, 37);
                        }
                        else if (temp2 != 91)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 1, l - 1, 30);
                        }
                    }
                    else if (temp == 31)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 1, l, 23);
                    }
                    else if (temp == 38)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 1, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 1, l, temp - 1);
                    }
                }
            }
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // up note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationRight + 2, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationRight + 2, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationRight + 2, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationRight + 2, l - 2);
                if (temp != 0)
                {
                    if (temp == 45)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 2, l - 1, 59);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 2, l - 1, 52);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 2, l, 66);
                        }
                        else if (temp2 != 0 && temp2 != 92)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 2, l - 1, 59);
                        }
                        else if (temp2 != 92)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 2, l - 1, 52);
                        }
                    }
                    else if (temp == 53)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 2, l, 45);
                    }
                    else if (temp == 60)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 2, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 2, l, temp - 1);
                    }
                }
            }
            for (uint8_t l = ArrowCutoutLocationY + 1; l < 18; l++) // right note
            {
                uint8_t temp = get_bkg_tile_xy(ArrowLocationRight + 3, l);
                uint8_t temp2 = get_bkg_tile_xy(ArrowLocationRight + 3, l - 1);
                uint8_t temp3 = get_bkg_tile_xy(ArrowLocationRight + 3, l + 1);
                uint8_t temp4 = get_bkg_tile_xy(ArrowLocationRight + 3, l - 2);
                if (temp != 0)
                {
                    if (temp == 67)
                    {
                        if (l != ArrowCutoutLocationY + 1)
                        {
                            if (temp2 != 0)
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 3, l - 1, 81);
                            }
                            else
                            {
                                set_bkg_tile_xy(ArrowLocationRight + 3, l - 1, 74);
                            }
                        }

                        if (temp3 == 0)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 3, l, 88);
                        }
                        else if (temp2 != 0 && temp2 != 93)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 3, l - 1, 81);
                        }
                        else if (temp2 != 93)
                        {
                            set_bkg_tile_xy(ArrowLocationRight + 3, l - 1, 74);
                        }
                    }
                    else if (temp == 75)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 3, l, 67);
                    }
                    else if (temp == 82)
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 3, l, 0);
                    }
                    else
                    {
                        set_bkg_tile_xy(ArrowLocationRight + 3, l, temp - 1);
                    }
                }
            }


            
        }
    
}

void display()
{
    // world view updater
    switch (gamemode)
    {
    case 1: // song selection
        /* code */
        break;
    case 2: // GAmeing?!?!? (bumpin beats yall!)
    if(i == 0)
    {
        songsetup(1);
    }
    if(i < 100)
    {
        i++;
    }
    else
    {
        i = 0;
    }
    SongHandler(i);
    
        break;
    case 3: // sSKILl ISSUE!?!?!? (lost)
        /* code */
        break;

    default: // titlescreen
        break;
    }
}

void main(void)
{
    SHOW_BKG;
    SHOW_SPRITES;
    
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
            if(gamemode == 2)
            {
                if(chkLeft == TRUE)
                {
                    chkLeft = FALSE;
                }
            }
        }
        else if (cur & J_RIGHT)
        {

        }

        display();
    }
}
