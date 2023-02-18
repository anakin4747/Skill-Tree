#include <avr/io.h>
#include <util/delay.h>

int main(void){
    DDRB |= 0b1000; // Turn bit 3 high to set as an output

    while(1){
        PORTB |= 0b1000;
        _delay_ms(1000);
        PORTB &= ~0b1000;
        _delay_ms(1000);
    }

    return 0;
}
