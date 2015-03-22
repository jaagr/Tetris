#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include <X11/Xlib.h>

#include "game.hpp"
#include "injector.hpp"
#include "controller.hpp"

namespace di = boost::di;

int main() 
{
    typedef typename sf::Event TEvent;
    XInitThreads();
    auto injector = di::make_injector(tetris::injector<TEvent>());
    injector.create<tetris::game<tetris::controller>>().start();

    return 0;
}