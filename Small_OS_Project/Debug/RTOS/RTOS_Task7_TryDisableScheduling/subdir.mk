################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/RTOS_Task7_TryDisableScheduling/RTOS_Task7_TryDisableScheduling.c \
../RTOS/RTOS_Task7_TryDisableScheduling/croutine.c \
../RTOS/RTOS_Task7_TryDisableScheduling/heap_1.c \
../RTOS/RTOS_Task7_TryDisableScheduling/list.c \
../RTOS/RTOS_Task7_TryDisableScheduling/port.c \
../RTOS/RTOS_Task7_TryDisableScheduling/queue.c \
../RTOS/RTOS_Task7_TryDisableScheduling/tasks.c \
../RTOS/RTOS_Task7_TryDisableScheduling/timers.c 

OBJS += \
./RTOS/RTOS_Task7_TryDisableScheduling/RTOS_Task7_TryDisableScheduling.o \
./RTOS/RTOS_Task7_TryDisableScheduling/croutine.o \
./RTOS/RTOS_Task7_TryDisableScheduling/heap_1.o \
./RTOS/RTOS_Task7_TryDisableScheduling/list.o \
./RTOS/RTOS_Task7_TryDisableScheduling/port.o \
./RTOS/RTOS_Task7_TryDisableScheduling/queue.o \
./RTOS/RTOS_Task7_TryDisableScheduling/tasks.o \
./RTOS/RTOS_Task7_TryDisableScheduling/timers.o 

C_DEPS += \
./RTOS/RTOS_Task7_TryDisableScheduling/RTOS_Task7_TryDisableScheduling.d \
./RTOS/RTOS_Task7_TryDisableScheduling/croutine.d \
./RTOS/RTOS_Task7_TryDisableScheduling/heap_1.d \
./RTOS/RTOS_Task7_TryDisableScheduling/list.d \
./RTOS/RTOS_Task7_TryDisableScheduling/port.d \
./RTOS/RTOS_Task7_TryDisableScheduling/queue.d \
./RTOS/RTOS_Task7_TryDisableScheduling/tasks.d \
./RTOS/RTOS_Task7_TryDisableScheduling/timers.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/RTOS_Task7_TryDisableScheduling/%.o: ../RTOS/RTOS_Task7_TryDisableScheduling/%.c RTOS/RTOS_Task7_TryDisableScheduling/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\NTI_Workspace\ddd\MCAL\inc" -I"D:\NTI\NTI_Workspace\ddd\HAL\inc" -I"D:\NTI\NTI_Workspace\ddd\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


