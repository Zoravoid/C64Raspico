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

//Edit these parameters to fit your local network
//still need to fix CYW43_ARCH for wifi to work
char ssid[] = "Network Name";
char pass[] = "Password";
char request = (char *)p->payload; //error

int main() 
{
    studio_init_all(); //error
    display oled;
    Button button(BUTTON_PIN, debounce_time, true, true, true); //error
    const unit32_t debounce_time = 50; //error

    oled.clear();
    oled._printf("Initializing WiFi...\n"); //error
    if(cyw43_arch_init())
    {
        oled.render();
        oled._printf("Failed to initialize CYW43!\n"); //error
        return -1;
    }
    
    oled.render();
    oled._printf("Connecting to Network:\n", ssid); //error
    if(cyw43_arch_wifi_connect_blocking(ssid, pass, CYW43_AUTH_WPA2_MIXED_PSK))
    {
        oled.render();
        oled._printf("Failed to connect to Wifi!\n"); //error
        return -1;
    }

    oled.render();
    oled._printf("Connected to WiFi!\n"); //error

    while(true)
    {
        cyw43_arch_poll();
        if(button.is_pressed())
        {
            Overtime();
            while(button.is_pressed())
            {
                sleep_ms(10);
            }
        }

        //Add corect http request
        switch(request)
        {
            case "Clean request": //error
                Clean();
                break;
            case "Sleep request": //error
                Sleep();
                break;
            case "Overtime request": //error
                Overtime();
                break;
            case "Changestate request": //error
                Changestate();
                break;
        }
    }

    cyw43_arch_deinit();
    return 0;
}

class wifi
{
    //if pico needs more http
};


void Alarm()
{
    gpio_init(LED_PIN, BUZZER_PIN); //error
    gpio_set_dir(LED_PIN, BUZZER_PIN, GPIO_OUT) //error
    while(true) //error
    {
    gpio_put(LED_PIN, 1); 
    gpio_put(BUZZER_PIN, 1);
    sleep(50);
    gpio_put(LED_PIN, 0);
    gpio_put(BUZZER_PIN, 0);
    sleep(50);
    }  
}


void Clean()
{
    for(int i = 0; i < 10; i++)
    {
        oled._pfrintf("Ready for Cleanup!"); //error
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Sleep()
{
    Alarm();
    for(int i = 0; i < 3; i++)
    {
        oled._pfrintf("Good Night!"); //error
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Overtime()
{
    for(int i = 0; i < 3; i++)
    {
        oled._pfrintf("Overtime Enabled!"); //error
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}

void Changestate()
{
    Alarm();
    for(int i = 0; i < 10; i++)
    {
        oled._pfrintf("Change Height!"); //error
        sleep_ms(100);
        oled.clear(false);
        sleep_ms(100);
    }
}