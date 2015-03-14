#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <memory>
#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include "interfaces/iwindow.hpp"
#include "interfaces/ievent_provider.hpp"
#include "config.hpp"

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
    
    virtual bool pollEvent(sf::Event&);
    
private:
    std::shared_ptr<sf::RenderWindow> window_;
};
    
} // namespace sfml
} // namespace tetris

#endif