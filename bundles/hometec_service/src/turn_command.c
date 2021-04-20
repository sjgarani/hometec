#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "celix_api.h"
#include "celix_utils.h"

#include "led_service.h"

struct led_callback_data {
    int state;
    int result;
    int rc;
};

static void led_callback(void *handle, void *svc) {
    struct led_callback_data *data = handle;
    led_service_t *led = svc;
    data->rc = led->setState(led->handle, data->state, &data->result);
}

bool turn_on_command_execute(void *handle, const char *const_line, FILE *out, FILE *err) {
    celix_bundle_context_t *context = handle;

    struct led_callback_data data;
    data.state = 255;

    bool called = celix_bundleContext_useService(context, LED_SERVICE, &data, led_callback);
    if (called) {
        fprintf(out, "OK! Rc=%d\n", data.rc);
    } else {
        fprintf(out, "Fail!\n");
    }
}

bool turn_off_command_execute(void *handle, const char *const_line, FILE *out, FILE *err) {
    celix_bundle_context_t *context = handle;

    struct led_callback_data data;
    data.state = 0;

    bool called = celix_bundleContext_useService(context, LED_SERVICE, &data, led_callback);
    if (called) {
        fprintf(out, "OK! Rc=%d\n", data.rc);
    } else {
        fprintf(out, "Fail!\n");
    }
}