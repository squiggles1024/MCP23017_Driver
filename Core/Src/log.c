/*
 * log.c
 *
 *  Created on: Mar 24, 2022
 *      Author: evanl
 */
#include "log.h"
#include "stm32f4xx_hal.h"
#include "usart.h"
#include <stdio.h>
#include <stdarg.h>

int __io_putchar(int ch){
	uint8_t pchar = ch;
	HAL_UART_Transmit(&huart1, &pchar, 1, HAL_MAX_DELAY);
	return ch;
}

void _log(Log_Subsystem_t subsystem, const char* msg, ...){
    va_list args;
	va_start(args, msg);
	switch(subsystem){
		case(log_i2c):
			printf("Debug Subsystem I2C: ");
				break;
		case(log_lps22hh):
			printf("Debug Subsystem LPS22HH: ");
				break;
		case(log_iis2mdc):
			printf("Debug Subsystem IIS2MDC: ");
				break;
		case(log_hts221):
			printf("Debug Subsystem HTS221: ");
				break;
		case(log_ism330dhcx):
			printf("Debug Subsystem ISM330DHCX: ");
				break;
		case(log_mcp23017):
			printf("Debug Subsystem MCP23017: ");
		        break;
		default:
			printf("Unknown Debug Subsystem: ");
	}
	vfprintf(stdout, msg, args);
	printf("\n");
	va_end(args);
}

void log_init(){
	  MX_USART1_UART_Init();
}
