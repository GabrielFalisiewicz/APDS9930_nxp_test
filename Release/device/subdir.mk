################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device/system_LPC55S69_cm33_core0.c 

C_DEPS += \
./device/system_LPC55S69_cm33_core0.d 

OBJS += \
./device/system_LPC55S69_cm33_core0.o 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.c device/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_LPC55S69JBD100 -DCPU_LPC55S69JBD100_cm33 -DCPU_LPC55S69JBD100_cm33_core0 -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -DSERIAL_PORT_TYPE_UART=1 -D__MCUXPRESSO -D__USE_CMSIS -DNDEBUG -D__REDLIB__ -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\board" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\source" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\utilities" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\drivers" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\component\uart" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\component\serial_manager" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\device" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\CMSIS" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\component\lists" -I"C:\Users\Gabriel\MCUXpressoIDE\workspace\pro_sensor\startup" -Os -fno-common -g -gdwarf-4 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m33 -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-device

clean-device:
	-$(RM) ./device/system_LPC55S69_cm33_core0.d ./device/system_LPC55S69_cm33_core0.o

.PHONY: clean-device

