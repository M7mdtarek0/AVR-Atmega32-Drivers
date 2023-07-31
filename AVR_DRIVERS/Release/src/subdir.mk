################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Adc.c \
../src/Adc_PbCfg.c \
../src/Button.c \
../src/Dio.c \
../src/Eeprom.c \
../src/ExtInt.c \
../src/Gpt.c \
../src/Gpt_PbCfg.c \
../src/I2c.c \
../src/Icu.c \
../src/Keypad.c \
../src/Lcd.c \
../src/Lcd_PbCfg.c \
../src/Led.c \
../src/Pwm.c \
../src/Spi.c \
../src/SpiApp.c \
../src/Ssd.c \
../src/Uart.c \
../src/Wdt.c \
../src/main.c 

OBJS += \
./src/Adc.o \
./src/Adc_PbCfg.o \
./src/Button.o \
./src/Dio.o \
./src/Eeprom.o \
./src/ExtInt.o \
./src/Gpt.o \
./src/Gpt_PbCfg.o \
./src/I2c.o \
./src/Icu.o \
./src/Keypad.o \
./src/Lcd.o \
./src/Lcd_PbCfg.o \
./src/Led.o \
./src/Pwm.o \
./src/Spi.o \
./src/SpiApp.o \
./src/Ssd.o \
./src/Uart.o \
./src/Wdt.o \
./src/main.o 

C_DEPS += \
./src/Adc.d \
./src/Adc_PbCfg.d \
./src/Button.d \
./src/Dio.d \
./src/Eeprom.d \
./src/ExtInt.d \
./src/Gpt.d \
./src/Gpt_PbCfg.d \
./src/I2c.d \
./src/Icu.d \
./src/Keypad.d \
./src/Lcd.d \
./src/Lcd_PbCfg.d \
./src/Led.d \
./src/Pwm.d \
./src/Spi.d \
./src/SpiApp.d \
./src/Ssd.d \
./src/Uart.d \
./src/Wdt.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\embedded\ECLIPSEPROJECTS\AVR_DRIVERS\inc" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


