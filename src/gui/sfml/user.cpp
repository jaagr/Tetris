#include <SFML/Graphics.hpp>
#include "gui/sfml/user.hpp"

namespace tetris {
namespace sfml {

void user::run()
{
    sf::Event event;
    while (true){
        while (event_provider_->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                return;
        }     
    }
}

} // namespace sfml
} // namespace tetris