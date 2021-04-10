#include <stdlib.h>
#include <celix_api.h>
#include "led_service_impl.h"
#include "remote_constants.h"

struct activator {
    led_t *led;
    led_service_t led_service;
    long svcId;
};

celix_status_t maintecBndStart(struct activator *act, celix_bundle_context_t *ctx) {
    act->svcId = -1L;
    act->led = led_create();
    if (act->led != NULL) {
        celix_status_t status = logHelper_create(ctx, &act->led->log_helper);
        if (status == CELIX_SUCCESS) {
            logHelper_start(act->led->log_helper);
        }
        act->led_service.handle = act->led;
        act->led_service.setState = (void*)led_setState;
        act->led_service.getState = (void*)led_getState;

        celix_properties_t *properties = celix_properties_create();
        celix_properties_set(properties, OSGI_RSA_SERVICE_EXPORTED_INTERFACES, LED_SERVICE);
        celix_properties_set(properties, OSGI_RSA_SERVICE_EXPORTED_CONFIGS, LASER_CONFIGURATION_TYPE);

        act->svcId = celix_bundleContext_registerService(ctx, &act->led_service, LED_SERVICE, properties);
    }
    return CELIX_SUCCESS;
}

celix_status_t maintecBndStop(struct activator *act, celix_bundle_context_t *ctx) {
    celix_bundleContext_unregisterService(ctx, act->svcId);
    if (act->led != NULL) {
        led_destroy(act->led);
    }
    logHelper_stop(act->led->log_helper);
    logHelper_destroy(&act->led->log_helper);
    return CELIX_SUCCESS;
}

CELIX_GEN_BUNDLE_ACTIVATOR(struct activator, maintecBndStart, maintecBndStop);
