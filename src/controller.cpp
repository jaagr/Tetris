#include <SFML/Window/Event.hpp>
#include "controller.hpp"

namespace tetris {

template<>
int controller::get_key_code(const sf::Event& evt)
{
    return evt.key.code;
}

template<>
int controller::get_key_code(const time_tick& evt)
{
    return one_second_tick::id::value;
}

template<> // TODO TRAITS !!!!!
int controller::get_event_type(const time_tick& evt)
{
    return one_second_tick::id::value;
}

template<>
int controller::get_event_type(const sf::Event& evt)
{
    return evt.type;
}

} // namespace tetris