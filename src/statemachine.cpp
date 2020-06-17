#include "statemachine.hpp"

using namespace std;

Active::Active() { syslog(LOG_INFO, "Hometec State Machine is actived."); }

ButtonPressed::ButtonPressed(my_context ctx) : my_base(ctx) {
  syslog(LOG_INFO, "Button pressed");
  post_event(EvToggle());
}

ButtonReleased::ButtonReleased() { syslog(LOG_INFO, "Button released"); }

LightOn::LightOn(my_context ctx) : my_base(ctx) {
  syslog(LOG_INFO, "* LightOn *");
}

LightOff::LightOff(my_context ctx) : my_base(ctx) {
  syslog(LOG_INFO, "* LightOff *");
}
