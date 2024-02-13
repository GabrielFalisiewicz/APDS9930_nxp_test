/*
 * APDS9930.c
 *
 *  Created on: 9 lut 2024
 *      Author: Gabriel
 */

#include "APDS9930.h"
#include <stdio.h>
#include "fsl_debug_console.h"

#define ADDR 0x39
#define ATIME 0xFF;
#define WTIME 0xFF;
#define PTIME 0xFF;
#define PPULSE 1;

static I2C_Type *I2C_base=NULL;

uint8_t buff[2];
void APD_byte(uint8_t data, uint8_t address){
	buff[0] = 0x80 | address;
	buff[1] = data;
	if(kStatus_Success == I2C_MasterStart(I2C_base, ADDR, kI2C_Write)){
		//PRINTF("Polaczono %u - %u\r\n", address, data);
		I2C_MasterWriteBlocking(I2C_base, &buff, 2, kI2C_TransferDefaultFlag);
		I2C_MasterStop(I2C_base);
	}
}

uint8_t read_buff[3];
uint16_t APD_read_8(uint8_t address){
	read_buff[0] = 0xA0 | address;
	read_buff[1] = 0;
	read_buff[2] = 0;
	if(kStatus_Success == I2C_MasterStart(I2C_base, ADDR, kI2C_Read)){
		//PRINTF("Polaczono_read\r\n");
		I2C_MasterReadBlocking(I2C_base, &read_buff, 3, kI2C_TransferDefaultFlag);
	}
	I2C_MasterStop(I2C_base);
	uint16_t result = read_buff[1] << 8 | read_buff[2];
	return result;
}


void APD_Init_proximity(I2C_Type *base){
	I2C_base=base;
	APD_byte(1, 0xFF);
	APD_byte(2, 0xFF);
	APD_byte(3, 0xFF);
	APD_byte(0xE, 1);
	APD_byte(0xF, 0 | 0x20 | 0 | 0);
	APD_byte(0, 8 | 4 | 2 | 1);
	APD_byte(0, 0x0F);
}
