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
                        di::bind<iwindow, sfml::window>,
                        di::bind<int>.named(width).to(755),
                        di::bind<int>.named(height).to(600)
        );
    }
};
} // namespace tetris
#endif