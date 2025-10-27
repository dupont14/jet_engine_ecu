#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWMPIN 0
#define SLICENUM 0

void setupPWM()
{
    gpio_set_function(PWMPIN, GPIO_FUNC_PWM);

    //uint slice_num = pwm_gpio_to_slice_num(PWMPIN);

    pwm_set_wrap(SLICENUM, 255);
    
    pwm_set_enabled(SLICENUM, true);
}

void updatePWM(char percent)
{
    //uint slice_num = pwm_gpio_to_slice_num(PWMPIN);
    pwm_set_chan_level(SLICENUM, PWM_CHAN_A, ((percent)*255)/100);
}

int main()
{
    stdio_init_all();

    setupPWM();
    //updatePWM(35);

    while (true) {
        for(int i = 0; i <= 100; i+=10)
        {
            updatePWM(i);
            printf("%d%",i);
            sleep_ms(2500);
        }
    }
}
