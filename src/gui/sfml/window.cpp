#include <SFML/Graphics.hpp>
#include <iostream>
#include "misc/logger.hpp"

#include "gui/sfml/window.hpp"
#include "fsm.hpp"

namespace tetris {
namespace sfml {

window::window(int width, int height, std::string title)
{
    window_.create(sf::VideoMode(width, height), title);
   // window_.setFramerateLimit(60);
    
    textures_.load(textures::Background, "background.jpg");
    backgroud_.setTexture(textures_.get(textures::Background));
   
    sf::Vector2f pos = sf::Vector2f(window_.getSize());
    
    sf::Vector2u background_size = backgroud_.getTexture()->getSize();
    sf::Vector2f scale = sf::Vector2f(float(pos.x) / float(background_size.x), float(pos.y) / float(background_size.y));
    backgroud_.scale(scale);
}

window::~window()
{
}

bool window::pollEvent(sf::Event& event) 
{
    return window_.pollEvent(event);
}

void window::draw()
{    
    window_.clear();
    window_.draw(backgroud_);
    window_.display();
}

void window::clear_window()
{
    window_.clear();
}

} // namespace sfml
} // namespace tetris