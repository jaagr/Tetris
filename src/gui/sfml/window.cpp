#include <SFML/Graphics.hpp>
#include <iostream>

#include "gui/sfml/window.hpp"

namespace tetris {
namespace sfml {

window::window(int width, int height, std::string title)
{
    window_ = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(width, height), title));
    std::cout << "jest";
}

window::~window()
{
}

bool window::pollEvent(sf::Event& event) 
{
    return window_->pollEvent(event);
}

void window::draw()
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
     
    window_->draw(shape);
    window_->display();
}

void window::clear_window()
{
    window_->clear();
}

} // namespace sfml
} // namespace tetris