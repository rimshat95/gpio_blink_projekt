# Makefile for GPIO LED Blink Project
# Target: Arduino Uno (ATmega328P)

# MCU settings
MCU = atmega328p
F_CPU = 16000000UL

# Compiler settings
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Werror

# Project name
TARGET = led_blink

# Source files
SOURCES = main.c gpio_driver.c

# Programmer settings (for Arduino Uno)
PROGRAMMER = arduino
PORT = /dev/ttyACM0  # Change this to match your system

# Default target
all: $(TARGET).hex

# Compile
$(TARGET).elf: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

# Create hex file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Flash to Arduino
flash: $(TARGET).hex
	$(AVRDUDE) -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -U flash:w:$<:i

# Clean
clean:
	rm -f $(TARGET).elf $(TARGET).hex

.PHONY: all flash clean

