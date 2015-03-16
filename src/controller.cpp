#include <SFML/Window/Event.hpp>
#include "controller.hpp"

namespace tetris {

template<>
int controller<sf::Event>::get_key_code(const sf::Event& evt)
{
    return evt.key.code;
}

template<>
int controller<sf::Event>::get_event_type(const sf::Event& evt)
{
    return evt.type;
}

} // namespace tetris