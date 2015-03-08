#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "interfaces/iwindow.hpp"
#include "interfaces/ievent_provider.hpp"
#include "config.hpp"
#include <memory>
#include <boost/di.hpp>

#include <SFML/Graphics.hpp>

namespace tetris {

class window : public iwindow, ievent_provider<sf::Event>
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
    
    virtual bool pollEvent(sf::Event&);
    
private:
    sf::RenderWindow&& window_;
};
    
}   //  namespace tetris
       

#endif