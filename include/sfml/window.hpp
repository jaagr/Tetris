#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "interfaces/iwindow.hpp"
#include "config.hpp"
#include <memory>
#include <boost/di.hpp>

#include <SFML/Graphics.hpp>

namespace tetris {
    
namespace sfml {

class window : public iwindow
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
    
private:
    sf::RenderWindow&& window_;
};
    
}   //  namespace sf
}   //  namespace tetris
       

#endif