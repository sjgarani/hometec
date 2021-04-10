#include <stdlib.h>
#include "led_service_impl.h"

led_t* led_create(void) {
    struct led *tmp = calloc(1, sizeof(*tmp));
    tmp->state = false;
    return tmp;
}

void led_destroy(led_t *led) {
    free(led);
}

int led_setState(led_t *led, bool input) {
    int status = CELIX_SUCCESS;

    led->state = input;
    logHelper_log(led->log_helper, OSGI_LOGSERVICE_INFO, "Set Led State: %i", led->state);

    return status;
}

int led_getState(led_t *led, bool *output) {
    int status = CELIX_SUCCESS;

    *output = led->state;
    logHelper_log(led->log_helper, OSGI_LOGSERVICE_INFO, "Get Led State: %i", *output);

    return status;
}