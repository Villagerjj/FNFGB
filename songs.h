#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>

/*
0 = no arrow
1 = left arrow
23 = down arrow
45 = up arrow
67 = right arrow
89 = hold thing


song starts on the left most slot in the array...
*/

#define S1delay 1
#define Sg1Lenght 24
uint8_t song11[Sg1Lenght] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };    // left
uint8_t song12[Sg1Lenght] = {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}; // down
uint8_t song13[Sg1Lenght] = {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45}; // up
uint8_t song14[Sg1Lenght] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, }; // right