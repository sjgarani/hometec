#include "statemachine.hpp"
#include <iostream>

#define BUTTON 0
#define LIGHT 1

using namespace std;

Active::Active() { cout << "Active" << endl; }

ButtonPressed::ButtonPressed(my_context ctx) : my_base(ctx) {
  cout << "ButtonPressed" << endl;
  post_event(EvToggle());
}

ButtonReleased::ButtonReleased() { cout << "ButtonReleased" << endl; }

LightOn::LightOn(my_context ctx) : my_base(ctx) {
  cout << "* LightOn *" << endl;
}

LightOff::LightOff(my_context ctx) : my_base(ctx) {
  cout << "* LightOff *" << endl;
}
