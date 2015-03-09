#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include <boost/di.hpp>

#include "config.hpp"
#include "board.hpp"

#include "gui/sfml/window.hpp"
#include "gui/sfml/user.hpp"
#include "gui/viewer.hpp"

namespace tetris{

namespace di = boost::di;

class injector{
public:
    auto configure() const {
        return di::make_injector(
                        di::bind<iboard, board>, 
                        di::bind<iviewer, viewer>,
                        di::bind<di::any_of<iwindow, ievent_provider<sf::Event>>,  sfml::window>,
                        di::bind<iclient,  sfml::user>,
                        di::bind<int>.named(window_width).to(1000),
                        di::bind<int>.named(window_height).to(1000),
                        di::bind<std::string>.named(window_title).to("Hello")
        );
    }
};
} // namespace tetris
#endif