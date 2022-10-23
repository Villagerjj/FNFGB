#include <gb/gb.h>
#include <stdint.h>
#include <gb/drawing.h>
#include <stdio.h>
uint8_t songBank1a[100] = {0,0};
uint8_t songBank2a[100] = {0,0};
uint8_t songBank3a[100] = {0,0};
uint8_t songBank4a[100] = {0,0};
uint8_t songBank1b[100] = {0,0};
uint8_t songBank2b[100] = {0,0};
uint8_t songBank3b[100] = {0,0};
uint8_t songBank4b[100] = {0,0};
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
uint8_t song11a[Sg1Lenght] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };    // left
uint8_t song12a[Sg1Lenght] = {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}; // down
uint8_t song13a[Sg1Lenght] = {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45}; // up
uint8_t song14a[Sg1Lenght] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, }; // right
uint8_t song11b[Sg1Lenght] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, };    // left
uint8_t song12b[Sg1Lenght] = {23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23}; // down
uint8_t song13b[Sg1Lenght] = {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45}; // up
uint8_t song14b[Sg1Lenght] = {67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, 67, }; // right