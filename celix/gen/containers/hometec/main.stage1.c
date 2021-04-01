#include <celix_launcher.h>
int main(int argc, char *argv[]) {
    const char * config = "\
CELIX_CONTAINER_NAME=hometec\n\
CELIX_BUNDLES_PATH=bundles\n\
\
\
\
CELIX_AUTO_START_3=/usr/local/share/celix/bundles/shell.zip /usr/local/share/celix/bundles/remote_shell.zip $<TARGET_PROPERTY:hometec_service,BUNDLE_FILE>\n\
\
\
\
";

    celix_properties_t *embeddedProps = celix_properties_loadFromString(config);
    return celixLauncher_launchAndWaitForShutdown(argc, argv, embeddedProps);
}
