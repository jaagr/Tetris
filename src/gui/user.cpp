#include <SFML/Window/Event.hpp>
#include "gui/user.hpp"

namespace tetris {

template<typename TEvent>
void user<TEvent>::run()
{
    TEvent event;
    while (state_machine_->is_active())
    {
        if (event_provider_->pollEvent(event))
        {
            state_machine_->process_event(event);
        }     
    }
}

template<typename TEvent>
user<TEvent>::~user()
{
}

template<typename TEvent>
user<TEvent>::user(std::shared_ptr<ievent_provider<TEvent>> event_provider, 
         std::shared_ptr<icontroller<controller>> state_machine): 
                event_provider_(event_provider), state_machine_(state_machine) 
{    
}

template class user<sf::Event>;
};