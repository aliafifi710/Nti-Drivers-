################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/RTOS_Task5_GiveandTake/RTOS_Task5_GiveandTake.c \
../RTOS/RTOS_Task5_GiveandTake/croutine.c \
../RTOS/RTOS_Task5_GiveandTake/heap_1.c \
../RTOS/RTOS_Task5_GiveandTake/list.c \
../RTOS/RTOS_Task5_GiveandTake/port.c \
../RTOS/RTOS_Task5_GiveandTake/queue.c \
../RTOS/RTOS_Task5_GiveandTake/tasks.c \
../RTOS/RTOS_Task5_GiveandTake/timers.c 

OBJS += \
./RTOS/RTOS_Task5_GiveandTake/RTOS_Task5_GiveandTake.o \
./RTOS/RTOS_Task5_GiveandTake/croutine.o \
./RTOS/RTOS_Task5_GiveandTake/heap_1.o \
./RTOS/RTOS_Task5_GiveandTake/list.o \
./RTOS/RTOS_Task5_GiveandTake/port.o \
./RTOS/RTOS_Task5_GiveandTake/queue.o \
./RTOS/RTOS_Task5_GiveandTake/tasks.o \
./RTOS/RTOS_Task5_GiveandTake/timers.o 

C_DEPS += \
./RTOS/RTOS_Task5_GiveandTake/RTOS_Task5_GiveandTake.d \
./RTOS/RTOS_Task5_GiveandTake/croutine.d \
./RTOS/RTOS_Task5_GiveandTake/heap_1.d \
./RTOS/RTOS_Task5_GiveandTake/list.d \
./RTOS/RTOS_Task5_GiveandTake/port.d \
./RTOS/RTOS_Task5_GiveandTake/queue.d \
./RTOS/RTOS_Task5_GiveandTake/tasks.d \
./RTOS/RTOS_Task5_GiveandTake/timers.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/RTOS_Task5_GiveandTake/%.o: ../RTOS/RTOS_Task5_GiveandTake/%.c RTOS/RTOS_Task5_GiveandTake/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\NTI_Workspace\ddd\MCAL\inc" -I"D:\NTI\NTI_Workspace\ddd\HAL\inc" -I"D:\NTI\NTI_Workspace\ddd\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


