#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include "config.hpp"
#include "board.hpp"
#include "gui/viewer.hpp"
#include "sfml/window.hpp"

#include <boost/di.hpp>

namespace tetris{

namespace di = boost::di;

class injector{
public:
    auto configure() const {
        return di::make_injector(
                        di::bind<iboard, board>, 
                        di::bind<iviewer, viewer>,
                        di::bind<iwindow, window>,
                        di::bind<ievent_provider<sf::Event>,  window>,
                        di::bind<int>.named(window_width).to(1000),
                        di::bind<int>.named(window_height).to(1000),
                        di::bind<std::string>.named(window_title).to("Hello")
        );
    }
};
} // namespace tetris
#endif