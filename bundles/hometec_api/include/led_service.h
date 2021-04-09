#ifndef LASER_SERVICE_H_
#define LASER_SERVICE_H_

#include <stdbool.h>

#define LED_SERVICE              "com.garani.hometec.api.LedService"
#define LASER_CONFIGURATION_TYPE   "org.amdatu.remote.admin.http"

typedef struct led_service led_service_t;

struct led_service {
    void *handle;
    void (*setState)(void *handle, bool state);
    bool (*getState)(void *handle);
};

#endif /* LASER_SERVICE_H_ */