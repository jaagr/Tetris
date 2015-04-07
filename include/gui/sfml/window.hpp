#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include "config.hpp"
#include "interfaces/iwindow.hpp"
#include "interfaces/ievent_provider.hpp"
#include "gui/sfml/texture_holder.hpp"

namespace tetris {

namespace sfml {

class window : public iwindow<sf::Drawable>, public ievent_provider<sf::Event>
{
public:
    BOOST_DI_INJECT(window,
        (named = window_width) int width,
        (named = window_height) int height,
        (named = window_title) std::string title
    );
    
    virtual ~window();
    virtual void clear_window();
    virtual void draw();  
    virtual bool poll_event(sf::Event&);
    
    virtual std::shared_ptr<sf::Drawable> create_text(const std::string& text);
    virtual std::shared_ptr<sf::Drawable> create_box(int r, int g, int b, int x, int y);
    
    virtual void update_layer(const layer&, std::vector<std::shared_ptr<sf::Drawable>>&);

private:    
    
    std::map<layer, std::vector<std::shared_ptr<sf::Drawable>>> layers_;
    texture_holder textures_;
    sf::Font font_;
    sf::RenderWindow window_;
    sf::Sprite backgroud_;    
};
    
} // namespace sfml
} // namespace tetris

#endif