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
        (named = timer_second)  std::shared_ptr<iclient>,
        //(named = timer_5s)  std::shared_ptr<iclient>,
        (named = player) std::shared_ptr<iclient>
    );
};

} // namespace di
} // namespace boost

namespace tetris{

#define ONE_SECOND   1000
#define FIVE_SECONDS 5000

template<typename TEvent, typename TDrawable>
class injector
{
public:
    auto configure() const 
    {
        return di::make_injector(
                        
                        di::bind<iclient,  user<TEvent, controller>>.named(player),
                        di::bind<iclient,  timer<time_tick, controller, ONE_SECOND>>.named(timer_second),
                        di::bind<iclient,  timer<time_tick, controller, FIVE_SECONDS>>.named(timer_5s),

                        di::bind<icontroller<controller>, controller>,
                        di::bind<di::any_of<iwindow<TDrawable>, ievent_provider<TEvent> >,  sfml::window>,
                        
                        di::bind<iboard, board>, 
                        di::bind<iviewer, viewer<TDrawable>>,
                        
                        di::bind<int>.named(window_width).to(954),
                        di::bind<int>.named(window_height).to(600),
                        di::bind<std::string>.named(window_title).to("Tetris")
        );
    }
};
} // namespace tetris
#endif