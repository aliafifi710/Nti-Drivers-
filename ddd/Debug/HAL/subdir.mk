################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Button.c \
../HAL/EEPROM.c \
../HAL/FingerPrint.c \
../HAL/KEYPAD.c \
../HAL/LCD.c \
../HAL/LM35.c \
../HAL/Motor.c \
../HAL/RTC.c \
../HAL/UltraSonic.c \
../HAL/driver_7segment.c 

OBJS += \
./HAL/Button.o \
./HAL/EEPROM.o \
./HAL/FingerPrint.o \
./HAL/KEYPAD.o \
./HAL/LCD.o \
./HAL/LM35.o \
./HAL/Motor.o \
./HAL/RTC.o \
./HAL/UltraSonic.o \
./HAL/driver_7segment.o 

C_DEPS += \
./HAL/Button.d \
./HAL/EEPROM.d \
./HAL/FingerPrint.d \
./HAL/KEYPAD.d \
./HAL/LCD.d \
./HAL/LM35.d \
./HAL/Motor.d \
./HAL/RTC.d \
./HAL/UltraSonic.d \
./HAL/driver_7segment.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\NTI_Workspace\ddd\MCAL\inc" -I"D:\NTI\NTI_Workspace\ddd\HAL\inc" -I"D:\NTI\NTI_Workspace\ddd\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


