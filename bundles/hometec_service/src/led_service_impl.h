#ifndef LED_SERVICE_IMPL_H_
#define LED_SERVICE_IMPL_H_

#include <stdbool.h>
#include "led_service.h"
// #include "log_helper.h"

typedef struct led {
    // log_helper_t *log_helper;
    bool state;
} led_t;

led_t* led_create(void);
void led_destroy(led_t *led);

int led_setState(led_t *led, bool input);
int led_getState(led_t *led, bool *output);

#endif /* LED_SERVICE_IMPL_H_ */
