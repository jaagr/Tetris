#include <SFML/Graphics.hpp>
#include "gui/user.hpp"

namespace tetris {

void user::run(){
    sf::Event event;
    while (true){
        while (event_provider_->pollEvent(event))
        {
        }     
    }
}

} // namespace tetris