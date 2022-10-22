#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>


void display()
{
    //world view updater
    printf("Hello World!");
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

        }
        else if (cur & J_RIGHT)
        {
            

            
        }

        display();
    }
}
