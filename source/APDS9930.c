/*
 * APDS9930.c
 *
 *  Created on: 9 lut 2024
 *      Author: Gabriel
 */

#include "APDS9930.h"
#include "fsl_debug_console.h"

static I2C_Type *I2C_base=NULL;

uint8_t buff[2];
void APD_byte(uint8_t address, uint8_t data){
	buff[0] = address;
	buff[1] = data;
	if(kStatus_Success == I2C_MasterStart(I2C_base, 0x39, kI2C_Write)){
		PRINTF("Polaczono %u - %u\r\n", address, data);
		I2C_MasterWriteBlocking(I2C_base, &buff, 2, kI2C_TransferDefaultFlag);
		I2C_MasterStop(I2C_base);
	}
}

uint8_t read_buff[2];
void APD_read_8(uint8_t address){
	read_buff[0] = address;
	read_buff[1] = 0;
	if(kStatus_Success == I2C_MasterStart(I2C_base, 0x39, kI2C_Write)){
		PRINTF("Polaczono_write\r\n");
		I2C_MasterWriteBlocking(I2C_base, &read_buff, 1, kI2C_TransferDefaultFlag);
	}
	I2C_MasterStop(I2C_base);
	if(kStatus_Success == I2C_MasterStart(I2C_base, 0x39, kI2C_Read)){
		PRINTF("Polaczono_read\r\n");
		I2C_MasterReadBlocking(I2C_base, &read_buff, 2, kI2C_TransferDefaultFlag);
	}
	I2C_MasterStop(I2C_base);
	PRINTF("Wynik: %u\r\n", read_buff[1]);
	//return read_buff[1];
}

void APD_Init_proximity(I2C_Type *base){
	I2C_base=base;
	APD_byte(0x80, 0);
	APD_byte(0x8F, 0x20);
	APD_byte(0x80, 0x05);
}
