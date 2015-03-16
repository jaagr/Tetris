#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <boost/di.hpp>

#include "interfaces/iclient.hpp"
#include "interfaces/ievent_provider.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {
        
template<typename TEvent>
class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<TEvent>> event_provider, 
         std::shared_ptr<icontroller<TEvent>> state_machine): 
                event_provider_(event_provider), state_machine_(state_machine) {}

    virtual ~user() {}
    
    virtual void run()
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

private:
    std::shared_ptr<ievent_provider<TEvent>> event_provider_;
    std::shared_ptr<icontroller<TEvent>> state_machine_;
};

} //  namespace tetris
#endif