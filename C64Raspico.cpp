#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/cyw43_arch.h"
#include "display.h"
#include "button.h"
#include "lwipopts.h"

#define LED_PIN 7
#define BUTTON_PIN 10
#define OLED_PIN 4
#define BUZZER_PIN 20

char ssid[] ="Network Name";
char pass[] ="Password";

Button button(BUTTON_PIN);
display oled;


int main()
{
    stdio_init_all();
    
    oled.clear();
    oled._printf(1, true, "Initialize WiFi...\n");
    if(cyw43_arch_init())
    {
        oled.render();
        oled._printf(2, true, "Failed to initialize cyw43!\n");
        return -1;
    }

    oled.render();
    oled._printf(3, true, "Connecting to Network:\n", ssid);
    if(cyw43_arch_wifi_connect_blocking(ssid, pass, CYW43_AUTH_WPA2_MIXED_PSK))
    {
        oled.render();
        oled._printf(4, true, "Failed to connect to Wifi!\n");
        return -1;
    }

    oled.render();
    oled._printf(5, true, "Connected to WiFi!");
    sleep_ms(1000);
    oled.clear(false);

    while(true)
    {
        cyw43_arch_poll();
        if(button.is_pressed())
        {

        }
    }
}

void Overtime()
{
    for(int i=0; i<3; i++)
    {
        oled._printf(1, true, "Overtime Enabled!");
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Alarm()
{
    
}

void Clean()
{

}

void Sleep()
{

}

void Changestate()
{

}