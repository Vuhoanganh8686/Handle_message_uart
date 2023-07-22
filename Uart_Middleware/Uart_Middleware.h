/*
 * Uart_Middleware.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Acer
 */

#ifndef UART_MIDDLEWARE_H_
#define UART_MIDDLEWARE_H_
#include "stdint.h"
#include "stdbool.h"

/**
 * @brief Init GPIO and Uart peripheral
 * 
 * @param[in] void
 * @return void
 **/
void Parse_Uart_System_Init(void);

/**
 * @brief Print string from board to PC
 * 
 * @param[in] string
 * @return void
 * */
void Parse_Uart_Print_String(uint8_t* string);

/**
 * @brief Find max value in uart line
 * 
 * @param[in] void
 * @return unit32_t:Max value in a uart line
 * */
uint32_t Parse_Uart_Find_Max_Data_Line(void);

/**
 * @brief Check status internal RX buffer
 * 
 * @param[in] void
 * @return bool:true-RX buffer have one and more uart line data
 * @return bool:false-RX buffer is empty
 * */
bool Parse_Uart_Buffer_Ready(void);


#endif /* UART_MIDDLEWARE_H_ */
