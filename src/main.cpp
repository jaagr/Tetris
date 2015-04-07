#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include <X11/Xlib.h>

#include "game.hpp"
#include "injector.hpp"

namespace di = boost::di;

int main() 
{
    typedef typename sf::Event TEvent;
    typedef typename sf::Drawable TDrawable;
    
    XInitThreads();
    auto injector = di::make_injector(tetris::injector<TEvent, TDrawable>());
    injector.create<tetris::game<tetris::controller>>().start();

    return 0;
}