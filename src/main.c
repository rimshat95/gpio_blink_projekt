#include <avr/io.h>
#include <avr/interrupt.h>
#include "gpio_driver.h"

// Define LED pin (PB5 = Arduino pin 13)
#define LED_PIN 5

// Define blink intervals in milliseconds
#define BLINK_20MS   20
#define BLINK_100MS  100
#define BLINK_500MS  500
#define BLINK_1SEC   1000
#define BLINK_2SEC   2000

// Timer variables
volatile uint16_t ticks = 0; 
uint16_t max_ticks = 20; // Default to 500ms blink interval

// Function prototype for timer initialization
void timer1_init(void);

// Initialize Timer1 for 1ms interrupts
void timer1_init(void) {
    // Configure Timer1 in CTC mode
    TCCR1A = 0;                       // Set all bits to zero initially
    TCCR1B = (1 << WGM12);           // CTC mode
    OCR1A = 249;                      // Compare value for 1ms at 16MHz / 64 prescaler
    TIMSK1 = (1 << OCIE1A);          // Enable Compare Match Interrupt
    
    // Enable global interrupts
    sei();
    
    // Start timer with 64 prescaler
    TCCR1B |= (1 << CS11) | (1 << CS10);
}

// Timer1 Compare Match A interrupt handler
ISR(TIMER1_COMPA_vect) {
    ticks++;
    if(ticks >= max_ticks) {
        gpio_toggle(LED_PIN);
        ticks = 0;
    }
}

int main(void) {
    // Initialize LED pin as output
    gpio_init(LED_PIN);

    // Set blink interval (uncomment ONE of these lines)
     max_ticks = BLINK_20MS;   // 20ms interval
    //max_ticks = BLINK_100MS;  // 100ms interval
    //max_ticks = BLINK_500MS;  // 500ms interval
    // max_ticks = BLINK_1SEC;   // 1 second interval
    //max_ticks = BLINK_2SEC;   // 2 second interval

    // Initialize and start the timer
    timer1_init();

    // Main loop (everything happens in the interrupt)
    while(1) {
        // Empty - the LED blinking is handled by the timer interrupt
    }

    return 0; // Never reached
}