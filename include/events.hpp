#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <boost/msm/front/euml/euml.hpp>

namespace tetris {

namespace euml = boost::msm::front::euml;

typedef euml::True_ anonymous;

template<class T>
using event = euml::euml_event<T>;

struct window_close : event<window_close> {};

} // namespace tetris
#endif