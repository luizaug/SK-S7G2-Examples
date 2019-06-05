################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../synergy/board/s7g2_sk/bsp_init.c \
../synergy/board/s7g2_sk/bsp_leds.c \
../synergy/board/s7g2_sk/bsp_qspi.c 

OBJS += \
./synergy/board/s7g2_sk/bsp_init.o \
./synergy/board/s7g2_sk/bsp_leds.o \
./synergy/board/s7g2_sk/bsp_qspi.o 

C_DEPS += \
./synergy/board/s7g2_sk/bsp_init.d \
./synergy/board/s7g2_sk/bsp_leds.d \
./synergy/board/s7g2_sk/bsp_qspi.d 


# Each subdirectory must supply rules for building sources it contributes
synergy/board/s7g2_sk/%.o: ../synergy/board/s7g2_sk/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	C:\Renesas\e2_studio\Utilities\\/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -D_RENESAS_SYNERGY_ -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy_cfg\ssp_cfg\driver" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy\ssp\inc" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy\ssp\inc\bsp" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy\ssp\inc\driver\api" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\synergy\ssp\inc\driver\instances" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\src" -I"C:\Users\USUARIO\e2_studio\workspace\Testes\Interrupt\src\synergy_gen" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


