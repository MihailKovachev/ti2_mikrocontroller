#include <avr/io.h>

const uint16_t LED0_ON_TIME_MS = 250;  // 2 Hz, 500ms pro Zyklus, 50% Tastgrad -> 250ms an-Zeit
const uint16_t LED1_ON_TIME_MS = LED0_ON_TIME_MS * 3;
const uint16_t LED2_ON_TIME_MS = LED0_ON_TIME_MS * 7;

int main(void) {
  DDRB = (1 << PB5) | (1 << PB4) | (1 << PB3);

  uint8_t elapsed_base_periods_led1 = 0;
  uint8_t elapsed_base_periods_led2 = 0;

  while (1) {

    _delay_ms(LED0_ON_TIME_MS);

    PORTB ^= (1 << PB5);

    elapsed_base_periods_led1++;
    if (elapsed_base_periods_led1 >= 3)
    {
      PORTB ^= (1 << PB4);
      elapsed_base_periods_led1 = 0;
    }

    elapsed_base_periods_led2++;
    if (elapsed_base_periods_led2 >= 7)
    {
      PORTB ^= (1 << PB3);
      elapsed_base_periods_led2 = 0;
    }
  }

  return 0;
}
