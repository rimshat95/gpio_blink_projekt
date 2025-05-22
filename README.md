# GPIO LED Blink Project

This project demonstrates basic GPIO control to blink an LED on an Arduino Uno.

## Platform

- **Arduino Uno R3** (ATmega328P, AVR-based)

## Hardware Setup

- Connect an LED to pin 13 (PB5) with a current-limiting resistor (~220-330 ohms)
- Alternatively, use the built-in LED on pin 13

## Project Structure

- `gpio_driver.h` - GPIO driver header file
- `gpio_driver.c` - GPIO driver implementation
- `main.c` - Main application code
- `Makefile` - Build script

## Building and Flashing

### Prerequisites

- AVR-GCC toolchain
- AVRDUDE programmer
- Make utility

### Build Instructions

1. Connect your Arduino Uno to your computer
2. Update the PORT in the Makefile to match your system (e.g., COM3 on Windows, /dev/ttyACM0 on Linux)
3. Build the project:
4. Flash the project to the Arduino:## Functionality

The program blinks an LED at a configurable interval using timer interrupts. Available blink intervals include:
- 20ms
- 100ms
- 500ms
- 1sec
- 2sec

To change the blink interval, modify the `max_ticks` value in `main.c`.

## Implementation Details

- Uses Timer1 with CTC mode for precise 1ms timing
- Implements a clean GPIO driver abstraction
- Uses interrupt-based approach for consistent timing

## Demo

![Blinking LED Demo](link-to-your-photo-or-gif)

*The LED blinks at the configured interval with consistent timing.*