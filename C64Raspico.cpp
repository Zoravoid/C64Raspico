#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include "display.h"
#include "button.h"

#define LED_PIN 7
#define BUTTON_PIN 10
#define OLED_PIN 4
#define BUZZER_PIN 20

char ssid[] = "Network Name";
char pass[] = "Password";


int main() 
{
    studio_init_all(); 
    display oled;
    Button input_a(10);
}

class wifi
{

};

class alarm
{
    void Alarm()
    {
        while(true)
        {
        gpio_put(LED_PIN, 1); 
        gpio_put(BUZZER_PIN, 1);
        sleep(50);
        gpio_put(LED_PIN, 0);
        gpio_put(BUZZER_PIN, 0);
        sleep(50);
        }  
    }
};

void Clean()
{
    gpio_init(OLED_PIN);
    gpio_set_dir(OLED_PIN, GPIO_OUT);
    while(true)
    {
        oled._pfrintf("Ready for Cleanup!");
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Sleep()
{
    alarm;
    gpio_init(OLED_PIN);
    gpio_set_dir(OLED_PIN, GPIO_OUT);
    for(int i = 0; i < 3; i++)
    {
        oled._pfrintf("Good Night!");
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Overtime()
{
    gpio_init(OLED_PIN);
    gpio_set_dir(OLED_PIN, GPIO_OUT);
    for(int i = 0; i < 3; i++)
    {
        oled._pfrintf("Overtime Enabled!");
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Changestate()
{
    alarm;
    gpio_init(OLED_PIN);
    gpio_set_dir(OLED_PIN, GPIO_OUT);
    while(true)
    {
        oled._pfrintf("Change Height!");
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}
