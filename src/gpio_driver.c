#include "gpio_driver.h"

void gpio_init(uint8_t pin){
    DDRB |= (1 << pin); //set pin as output(e.g., PB5 for digital pin 13)
}

void gpio_set(uint8_t pin){
    PORTB |= (1 << pin); //set pin HIGH
}

void gpio_clear(uint8_t pin){
    PORTB &= ~(1 << pin); //set pin LOW
}

void gpio_toggle(uint8_t pin){
    PORTB ^= (1 << pin); //toggle pin
}

