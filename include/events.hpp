#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Graphics.hpp>
#include <boost/mpl/int.hpp>
#include <boost/msm/front/euml/euml.hpp>

namespace tetris {

namespace euml = boost::msm::front::euml;

typedef euml::True_ anonymous;

class flag_game_over { };

template<class T, int Id>
struct event : euml::euml_event<T>
{
    typedef boost::mpl::int_<Id> id;
};

struct window_close : event<window_close, sf::Event::Closed> 
{
    window_close() {}

    window_close(const sf::Event& event){
    }
};

} // namespace tetris
#endif