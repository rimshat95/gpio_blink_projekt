#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include <avr/io.h>

//initialize a GPIO pin as output (assumes PORTB for simplicity)
void gpio_init(uint8_t pin);

//sets the GPIO pin HIGH
void gpio_set(uint8_t pin);

//sets the GPIO pin LOW
void gpio_clear(uint8_t pin);

//toggles the GPIO pin
void gpio_toggle(uint8_t pin);

#endif