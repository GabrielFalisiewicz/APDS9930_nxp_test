/*
 * APDS9930.h
 *
 *  Created on: 9 lut 2024
 *      Author: Gabriel
 */

#ifndef APDS9930_H_
#define APDS9930_H_

#include "fsl_i2c.h"
#include <stdint.h>
#include <stdlib.h>

void APD_Init_proximity(I2C_Type *base);
void APD_byte(uint8_t adress, uint8_t data);
void APD_read_8(uint8_t address);

#endif /* APDS9930_H_ */
