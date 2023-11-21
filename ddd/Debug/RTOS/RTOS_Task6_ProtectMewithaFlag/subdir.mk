################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTOS/RTOS_Task6_ProtectMewithaFlag/RTOS_Task6_ProtectMewithaFlag.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/croutine.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/heap_1.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/list.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/port.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/queue.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/tasks.c \
../RTOS/RTOS_Task6_ProtectMewithaFlag/timers.c 

OBJS += \
./RTOS/RTOS_Task6_ProtectMewithaFlag/RTOS_Task6_ProtectMewithaFlag.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/croutine.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/heap_1.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/list.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/port.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/queue.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/tasks.o \
./RTOS/RTOS_Task6_ProtectMewithaFlag/timers.o 

C_DEPS += \
./RTOS/RTOS_Task6_ProtectMewithaFlag/RTOS_Task6_ProtectMewithaFlag.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/croutine.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/heap_1.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/list.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/port.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/queue.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/tasks.d \
./RTOS/RTOS_Task6_ProtectMewithaFlag/timers.d 


# Each subdirectory must supply rules for building sources it contributes
RTOS/RTOS_Task6_ProtectMewithaFlag/%.o: ../RTOS/RTOS_Task6_ProtectMewithaFlag/%.c RTOS/RTOS_Task6_ProtectMewithaFlag/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI\NTI_Workspace\ddd\MCAL\inc" -I"D:\NTI\NTI_Workspace\ddd\HAL\inc" -I"D:\NTI\NTI_Workspace\ddd\inc" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


