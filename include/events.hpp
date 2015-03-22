#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <SFML/Window/Event.hpp>
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

template<class T, int Id, int Key>
struct key_event : event<T, Id>
{
    typedef boost::mpl::int_<Key> key;
};

struct window_close : event<window_close, sf::Event::Closed> 
{
    window_close() {}

    window_close(const sf::Event& event){
    }
};

struct window_moved : event<window_moved, sf::Event::GainedFocus> 
{
    window_moved() {}

    window_moved(const sf::Event& event){
    }
};

struct one_second_tick : event<one_second_tick, __LINE__> 
{
    one_second_tick() {}

    one_second_tick(const sf::Event& event){
    }
};


struct button_esc : key_event<button_esc, sf::Event::KeyPressed, sf::Keyboard::Key::Escape> 
{
    button_esc() {}

    button_esc(const sf::Event& event){
    }
};

} // namespace tetris
#endif