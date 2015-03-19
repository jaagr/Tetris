#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

#include "game.hpp"
#include "injector.hpp"

namespace di = boost::di;

int main() 
{
    typedef typename sf::Event TEvent;
    
    auto injector = di::make_injector(tetris::injector<TEvent>());
    injector.create<tetris::game>().start();

    return 0;
}