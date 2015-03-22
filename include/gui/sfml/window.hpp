#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>

#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include "interfaces/iwindow.hpp"
#include "interfaces/ievent_provider.hpp"
#include "config.hpp"
#include "gui/sfml/texture_holder.hpp"

namespace tetris {

namespace sfml {

class window : public iwindow, public ievent_provider<sf::Event>
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
    virtual void show_point(std::string& value);
    
    virtual bool pollEvent(sf::Event&);
    
    enum layer {
        BACKGROUND, POINTS };

private:    
    
    texture_holder textures_;
    sf::RenderWindow window_;
    sf::View point_view_;
    sf::Sprite backgroud_;    
};
    
} // namespace sfml
} // namespace tetris

#endif