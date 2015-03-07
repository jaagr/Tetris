#include "controller.hpp"
#include "board.hpp"
#include "gui/viewer.hpp"
#include <boost/di.hpp>
#include <SFML/Graphics.hpp>

namespace di = boost::di;

int main() {
    auto sm = di::make_injector(di::bind<tetris::iboard, tetris::board>, di::bind<tetris::iviewer, tetris::viewer>).create<tetris::controller>();
    
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

    return 0;
}