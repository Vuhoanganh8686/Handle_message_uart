/*
 * Array_Lib.c
 *
 *  Created on: Jul 21, 2023
 *      Author: Acer
 */
#include "Array_Lib.h"
#include "stdint.h"

/* Skip all alphabet characters*/
static void Array_Alphabet_Ignore_Char(uint8_t *Array_Address, uint32_t* Array_Length)
{
    uint32_t array_index = 0; 
    for (array_index = 0; array_index < Array_Length; array_index++)
    {
        /* If character is not the number then mark as undefined value*/
        if(Array_Address[array_index] < 48 || Array_Address[array_index] > 57)
        {
            Array_Address[array_index] = 0xFF;
        }
    }
}

/*Find Max value in a array*/
uint32_t Array_Find_Max_Value(uint8_t* Array_Address, uint32_t* Array_Length)
{
    uint32_t array_index = 0;
    uint32_t max = 0;

    Array_Alphabet_Ignore_Char(Array_Address, Array_Length);

    for (array_index = 0; array_index < Array_Length; array_index++)
    {
        if(max < Array_Address[array_index] && Array_Address[array_index] != 0xFF)
        {
            max = Array_Address[array_index];
        }
    }
}


