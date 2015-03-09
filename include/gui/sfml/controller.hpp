#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include <SFML/Window/Event.hpp>

#include "fsm.hpp"
#include "events.hpp"

namespace tetris {
namespace sfml {

class controller : public fsm {
public:    
    template<typename... Args>
    explicit controller(Args&&... args)
        : fsm(std::forward<Args>(args)...)
    { }
    
    template<class TEvent>
    void process_event(TEvent const& evt)
    {
        fsm::process_event(evt);
    }
};

} // namespace sfml
} // namespace tetris

#endif
//TODO remove from "gui" ;p