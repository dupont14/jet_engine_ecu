#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define FREQPIN 5
#define SAMPLEINTERVAL 100.f

// Frequency measured in kHz
float measure_frequency(uint gpio) {
    // Only the PWM B pins can be used as inputs.
    assert(pwm_gpio_to_channel(gpio) == PWM_CHAN_B);
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Count once for every 100 cycles the PWM B input is high
    pwm_config cfg = pwm_get_default_config();
    pwm_config_set_clkdiv_mode(&cfg, PWM_DIV_B_RISING);
    pwm_config_set_clkdiv(&cfg, 1.f); //set by default, increment count for each rising edge
    pwm_init(slice_num, &cfg, false);  //false means don't start pwm
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    
    pwm_set_enabled(slice_num, true);
    sleep_ms(SAMPLEINTERVAL);
    pwm_set_enabled(slice_num, false);
    
    uint16_t counter = (uint16_t) pwm_get_counter(slice_num);
    float freq =   counter / SAMPLEINTERVAL;
    return freq;

}

int main()
{
    stdio_init_all();

    while (true) {
        printf("Freq: %f kHz\n", measure_frequency(FREQPIN));
        //sleep_ms(100);
    }
}
