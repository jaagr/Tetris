#include <SFML/Graphics.hpp>
#include <iostream>
#include "misc/logger.hpp"

#include "gui/sfml/window.hpp"

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

std::shared_ptr<sf::Drawable> window::create_box(int r, int g, int b, int x, int y)
{
    std::shared_ptr<sf::Sprite> sprite = std::make_shared<sf::Sprite>();
    sprite->setTexture(textures_.get(textures::Box));
    sprite->setColor(sf::Color(r,g,b));
    sprite->setScale(0.45f, 0.45f);
    sprite->move(x,y);
    return sprite;
}

void window::update_layer(const layer& key, std::vector<std::shared_ptr<sf::Drawable>>& value)
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
    
    for(auto& layer :layers_)
    {
        for(auto& graphics: layer.second)
        {
            window_.draw(*graphics);
        }
    }
    
    window_.display();
}

void window::clear_window()
{
    window_.clear();
}

} // namespace sfml
} // namespace tetris