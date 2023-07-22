/*
 * Uart_Middleware.c
 *
 *  Created on: Jul 21, 2023
 *      Author: Acer
 */
#include "Uart_Middleware.h"
#include <stdbool.h>
#include "string.h"
#include "Array_Lib.h"
#include "stm32f3xx_hal_uart.h"
#include "stdint.h"
#include "gpio.h"
#include "usart.h"
/***************************
 * Definition
****************************/
#define RX_BUFFER_LINE 4U
#define RX_BUFFER_SIZE 80U
/***************************
 * Variable
****************************/
static uint8_t RX_BUFFER[RX_BUFFER_LINE][RX_BUFFER_SIZE] = {0};
static uint32_t RX_Tail = 0;
static uint32_t RX_Head = 0;
/***************************
 * Static function
****************************/
static void Parse_Uart_Peripheral_Init(void)
{
    /*Init GPIO*/
    MX_GPIO_Init();
    /*Init Uart2*/
    MX_UART2_UART_Init();
}
/***************************
 * API function
****************************/
void Parse_Uart_System_Init(void)
{
    /*Init Peripheral*/
    Parse_Uart_Peripheral_Init();
    Parse_Uart_Print_String("Init Success");
    Parse_Uart_Print_String("Please input your file");    
}

/*Print String to PC*/
void Parse_Uart_Print_String(uint8_t* string)
{
    HAL_UART_Transmit(&huart2,string, strlen((char*) string), 1000);
}

/*Check RX Buffer has data or not*/
bool Parse_Uart_Buffer_Ready()
{
    return RX_Tail != RX_Head;
}

uint32_t Parse_Uart_Find_Max_Data_Line()
{
    uint32_t max_temp = 0;
    max_temp = Array_Find_Max_Value(&RX_BUFFER[RX_Head][0], 43);
      /*Update RX_Head*/
    RX_Head++;
    if(RX_Head >= RX_BUFFER_LINE)
    {
        RX_Head = 0;
    }

    return max_temp;
}

/*Call Back Function*/
void HAL_UART_RXCpltCallback(UART_HandleTypeDef *huart)
{
    /*Update RX_Tail*/
    RX_Tail++;
    if(RX_Tail >= RX_BUFFER_LINE)
    {
        RX_Tail = 0;
    }


    /*Enable uart receive interrupt*/
    HAL_UART_Receive_IT(&huart2, &RX_BUFFER[RX_Tail][0],43);
}
      
