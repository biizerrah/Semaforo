#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

const uint led_pin_red = 11;
const uint led_pin_yellow = 12;
const uint led_pin_green = 13;
int led_state = 0;

bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(led_pin_red, led_state == 0);
    gpio_put(led_pin_yellow, led_state == 1);
    gpio_put(led_pin_green, led_state == 2);

    led_state = (led_state + 1) % 3;
    return true;
}

int main() {
    
      gpio_init(led_pin_red);
      gpio_set_dir(led_pin_red,GPIO_OUT);

      gpio_init(led_pin_yellow);
      gpio_set_dir(led_pin_yellow,GPIO_OUT);

      gpio_init(led_pin_green);
      gpio_set_dir(led_pin_green, GPIO_OUT);

      struct repeating_timer timer;

      add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

      while(true){
        sleep_ms(1000);
      }
      
    
   }
