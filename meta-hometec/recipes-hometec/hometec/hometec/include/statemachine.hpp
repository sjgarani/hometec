#include <boost/mpl/list.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/event.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>
#include <iostream>

#define BUTTON 0
#define LIGHT 1

using namespace std;

namespace sc = boost::statechart;
namespace mpl = boost::mpl;

struct EvPressButton : sc::event<EvPressButton> {};
struct EvReleaseButton : sc::event<EvReleaseButton> {};
struct EvToggle : sc::event<EvToggle> {};

// *** ST
struct Active;
struct Module : sc::state_machine<Module, Active> {};

struct ButtonPressed;
struct ButtonReleased;
struct LightOn;
struct LightOff;
struct Active : sc::simple_state<Active, Module,
                                 mpl::list<ButtonReleased, LightOff> > {
  Active();
};

// *** Pins

struct ButtonPressed
    : sc::state<ButtonPressed, Active::orthogonal<BUTTON> > {
  ButtonPressed(my_context ctx);
  typedef mpl::list< sc::transition<EvReleaseButton, ButtonReleased> > reactions;
};

struct ButtonReleased
    : sc::simple_state<ButtonReleased, Active::orthogonal<BUTTON> > {
  ButtonReleased();
  typedef mpl::list< sc::transition<EvPressButton, ButtonPressed> > reactions;
};

struct LightOn
    : sc::state<LightOn, Active::orthogonal<LIGHT> > {
  LightOn(my_context ctx);
  typedef mpl::list< sc::transition<EvToggle, LightOff> > reactions;
};

struct LightOff
    : sc::state<LightOff, Active::orthogonal<LIGHT> > {
  LightOff(my_context ctx);
  typedef mpl::list< sc::transition<EvToggle, LightOn> > reactions;
};
