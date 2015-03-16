#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include <boost/di.hpp>

#include "config.hpp"
#include "board.hpp"
#include "controller.hpp"

#include "gui/sfml/window.hpp"
#include "gui/user.hpp"
#include "gui/viewer.hpp"

namespace tetris{

namespace di = boost::di;

template<typename TEvent>
class injector
{
public:
    auto configure() const 
    {
        return di::make_injector(
                        
                        di::bind<iclient,  user<TEvent> >,
                        di::bind<icontroller<TEvent>, controller<TEvent>>,
                        di::bind<di::any_of<iwindow, ievent_provider<TEvent> >,  sfml::window>,
                        
                        di::bind<iboard, board>, 
                        di::bind<iviewer, viewer>,
                        
                        di::bind<int>.named(window_width).to(755),
                        di::bind<int>.named(window_height).to(600),
                        di::bind<std::string>.named(window_title).to("Tetris")
        );
    }
};
} // namespace tetris
#endif