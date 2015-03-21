#ifndef INJECTOR_HPP
#define INJECTOR_HPP

#include <boost/di.hpp>

#include "config.hpp"
#include "board.hpp"
#include "controller.hpp"

#include "gui/sfml/window.hpp"
#include "gui/user.hpp"
#include "gui/timer.hpp"
#include "gui/viewer.hpp"

namespace di = boost::di;

namespace boost {
namespace di {

using namespace tetris;

template<>
struct ctor_traits<game<controller>>
{
    BOOST_DI_INJECT_TRAITS(
        std::shared_ptr<icontroller<controller>>,
        (named = named_timer)  std::shared_ptr<iclient>,
        (named = named_player) std::shared_ptr<iclient>
    );
};

} // namespace di
} // namespace boost

namespace tetris{



template<typename TEvent>
class injector
{
public:
    auto configure() const 
    {
        return di::make_injector(
                        
                        di::bind<iclient,  user<TEvent, controller>>.named(named_player),
                        di::bind<iclient,  timer<time_tick, controller>>.named(named_timer),

                        di::bind<icontroller<controller>, controller>,
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