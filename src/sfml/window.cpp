#include "sfml/window.hpp"
#include <SFML/Graphics.hpp>

namespace tetris {
namespace sfml {

window::window(int width, int height, std::string title): 
            window_(std::move(sf::RenderWindow(sf::VideoMode(width, height), title)))
{
    
}

window::~window(){
}

void window::draw()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
     
    window_.draw(shape);
    window_.display();
}

void window::clear_window()
{
    window_.clear();
}

} // namespace sfml
} // namespace tetris