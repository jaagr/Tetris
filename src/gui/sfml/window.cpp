#include <SFML/Graphics.hpp>
#include <iostream>
#include "misc/logger.hpp"

#include "gui/sfml/window.hpp"
#include "fsm.hpp"

namespace tetris {
namespace sfml {

window::window(int width, int height, std::string title)
{
    window_.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    window_.setFramerateLimit(60);
    window_.setActive(false);
    
    textures_.load(textures::Background, "background.jpg");
    textures_.load(textures::Box, "box.png");
    textures_.get(textures::Box).setSmooth(true);
    
    backgroud_.setTexture(textures_.get(textures::Background));
   
    sf::Vector2f pos = sf::Vector2f(window_.getSize());
    
    sf::Vector2u background_size = backgroud_.getTexture()->getSize();
    sf::Vector2f scale = sf::Vector2f(float(pos.x) / float(background_size.x), float(pos.y) / float(background_size.y));
    backgroud_.scale(scale);
    
    game_view_ = window_.getView();
    font_.loadFromFile("font.ttf");
}

window::~window()
{
}

std::shared_ptr<sf::Drawable> window::create_text(const std::string& value)
{
    std::shared_ptr<sf::Text> text = std::make_shared<sf::Text>();
    text->setString(value);
    text->setFont(font_);
    text->setCharacterSize(50);
    text->setColor(sf::Color::White);
    text->move(40,500);
    return text;
}

void window::update_layer(const layer& key, std::shared_ptr<sf::Drawable> value)
{
    layers_[key] = value;
}

bool window::poll_event(sf::Event& event) 
{
    return window_.pollEvent(event);
}

void window::draw()
{    
    window_.draw(backgroud_);
    for(int x = 0; x < 9; x ++)
    {
        for(int y = 0; y < 11; y ++)
        {
            sf::Sprite sprite;
            sprite.setTexture(textures_.get(textures::Box));
            sprite.setColor(sf::Color(255 - 20 * y, 20 * y, 0));
            sprite.setScale(0.5f, 0.5f);
            sprite.move(240 + x *50, 10 + 50 * y);
            window_.draw(sprite);
        }
    }
    for(auto& k :layers_){
        window_.draw(*k.second);
    }
    
    window_.display();
}

void window::clear_window()
{
    window_.clear();
}

} // namespace sfml
} // namespace tetris