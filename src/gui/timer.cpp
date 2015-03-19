#include "gui/timer.hpp"
#include "events.hpp"

namespace tetris {

template<typename TEvent>
void timer<TEvent>::run()
{
    while(state_machine_->is_active())
    {
        state_machine_->process_event(TEvent());
    }
}

template class timer<time_tick>;
} // namespace tetris