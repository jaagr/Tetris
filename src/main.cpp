#include "controller.hpp"
#include <SFML/Graphics.hpp>

#include <boost/di.hpp>
#include "game.hpp"
#include "injector.hpp"

namespace di = boost::di;

int main() {
    auto injector = di::make_injector(tetris::injector());
    injector.create<tetris::game>().start();
    
    /**
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
*/
    return 0;
}