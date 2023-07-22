/*
 * Array_Lib.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Acer
 */
#include "stdint.h"
#ifndef ARRAY_LIB_ARRAY_LIB_H_
#define ARRAY_LIB_ARRAY_LIB_H_

/**
 * @brief Find max value in a array, skip all alphabet characters
 * 
 * @param Array_Address 
 * @param Array_Length 
 * @return unit32_t max value of the array and skill all alphabet characters
 */

uint32_t Array_Find_Max_Value(uint8_t* Array_Address, uint32_t* Array_Length);


#endif /* ARRAY_LIB_ARRAY_LIB_H_ */
