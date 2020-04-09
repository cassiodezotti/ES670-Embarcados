################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/lcd.c \
../Sources/main.c \
../Sources/mcg.c \
../Sources/util.c 

OBJS += \
./Sources/lcd.o \
./Sources/main.o \
./Sources/mcg.o \
./Sources/util.o 

C_DEPS += \
./Sources/lcd.d \
./Sources/main.d \
./Sources/mcg.d \
./Sources/util.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -D"CPU_MKL25Z128VLK4" -I"../Sources" -I"../Project_Settings/Startup_Code" -I"../SDK/platform/CMSIS/Include" -I"../SDK/platform/devices" -I"../SDK/platform/devices/MKL25Z4/include" -IC:/Freescale/KSDK_1.2.0/platform/drivers/inc -IC:/Freescale/KSDK_1.2.0/platform/utilities/inc -IC:/Freescale/KSDK_1.2.0/platform/hal/inc -IC:/Freescale/KSDK_1.2.0/platform/system/inc -IC:/Freescale/KSDK_1.2.0/platform/osa/inc -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


