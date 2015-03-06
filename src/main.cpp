#include "controller.hpp"
#include "board.hpp"
#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

namespace di = boost::di;

int main() {
    auto sm = di::make_injector(di::bind<tetris::iboard, tetris::board>).create<tetris::controller>();
    
    
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        { 
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
    
    return 0;
}