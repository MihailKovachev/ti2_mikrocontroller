#include <avr/io.h>

const uint16_t takt_ms = 1000;

int main(void) {
  DDRB = (1 << PB5) | (1 << PB4) | (1 << PB3) | (1 << PB2);  // LED0, LED1, LED2 und LED3.
  PORTB = (1 << PB5) | (1 << PB4) | (1 << PB3) | (1 << PB2);

  uint8_t anzahlSekunden = 0;
  while (1) {
    _delay_ms(takt_ms);

    anzahlSekunden++;

    if (anzahlSekunden >= 1) {
      PORTB &= ~(1 << PB5);
    }

    if (anzahlSekunden >= 2) {
      PORTB &= ~(1 << PB4);
    }

    if (anzahlSekunden >= 3) {
      PORTB &= ~(1 << PB3);
    }

    if (anzahlSekunden >= 4) {
      PORTB &= ~(1 << PB2);
    }

    if (anzahlSekunden >= 5) {
      PORTB = (1 << PB5) | (1 << PB4) | (1 << PB3) | (1 << PB2);
      anzahlSekunden = 0;
    }
  }
}