#include <SFML/Graphics.hpp>
#include <iostream>

#include "gui/window.hpp"

namespace tetris {

window::window(int width, int height, std::string title): 
            window_(std::move(sf::RenderWindow(sf::VideoMode(width, height), title)))
{
    std::cout << "jest";
}

window::~window(){
}

bool window::pollEvent(sf::Event& event) 
{
    return window_.pollEvent(event);
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

} // namespace tetris