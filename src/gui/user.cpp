#include <SFML/Graphics.hpp>

#include "gui/user.hpp"

namespace tetris {
namespace sfml {

void user::run()
{
    sf::Event event;
    while (not state_machine_->is_flag_active<flag_game_over>())
    {
        while (event_provider_->pollEvent(event))
        {
            state_machine_->process_event(event);
        }     
    }
}

} // namespace sfml
} // namespace tetris