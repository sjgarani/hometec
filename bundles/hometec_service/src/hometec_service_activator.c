#include "celix_api.h"
#include "celix_shell_command.h"

#include "turn_command.h"

typedef struct hometec_service_activator {
    long turn_on_service_id;
    celix_shell_command_t turn_on_command;
    long turn_off_service_id;
    celix_shell_command_t turn_off_command;
} hometec_service_activator_t;

static celix_status_t hometec_activator_start(hometec_service_activator_t *activator, celix_bundle_context_t *ctx) {
    activator->turn_on_command.handle = ctx;
    activator->turn_on_command.executeCommand = turn_on_command_execute;
    celix_properties_t *propsOn = celix_properties_create();
    celix_properties_set(propsOn, CELIX_SHELL_COMMAND_NAME, "turnOn");
    activator->turn_on_service_id = celix_bundleContext_registerService(ctx, &activator->turn_on_command, CELIX_SHELL_COMMAND_SERVICE_NAME, propsOn);

    activator->turn_off_command.handle = ctx;
    activator->turn_off_command.executeCommand = turn_off_command_execute;
    celix_properties_t *propsOff = celix_properties_create();
    celix_properties_set(propsOff, CELIX_SHELL_COMMAND_NAME, "turnOff");
    activator->turn_off_service_id = celix_bundleContext_registerService(ctx, &activator->turn_off_command, CELIX_SHELL_COMMAND_SERVICE_NAME, propsOff);

    return CELIX_SUCCESS;
}

static celix_status_t hometec_activator_stop(hometec_service_activator_t *activator, celix_bundle_context_t *ctx) {
    celix_bundleContext_unregisterService(ctx, activator->turn_on_service_id);
    celix_bundleContext_unregisterService(ctx, activator->turn_off_service_id);
    return CELIX_SUCCESS;
}

CELIX_GEN_BUNDLE_ACTIVATOR(hometec_service_activator_t, hometec_activator_start, hometec_activator_stop);