#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#define LED_PIN 7
#define BUTTON_PIN 10
#define OLED_PIN 4
#define BUZZER_PIN 20

char ssid[] = "Network Name";
char pass[] = "Password";


int main() 
{
     studio_init_all();
     
}


class display
{

};

class wifi
{

};

void Clean()
{

}

void Sleep()
{

}

void Overtime()
{

}

void Changestate()
{
    gpio_init(OLED_PIN);
     gpio_set_dir(OLED_PIN, GPIO_OUT);
     while (true) {
         gpio_put(BUZZER_PIN, 1); sleep_ms(250);
         
    }
}
