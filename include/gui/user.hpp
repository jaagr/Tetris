#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <boost/di.hpp>

#include "misc/logger.hpp"

#include "interfaces/iclient.hpp"
#include "interfaces/ievent_provider.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {
        
template<typename TEvent, typename TController>
class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<TEvent>> event_provider, 
         std::shared_ptr<icontroller<TController>> state_machine) :
         event_provider_(event_provider), state_machine_(state_machine) {
             LOG("Hey");
        }

    virtual ~user(){}
    
    virtual void run()
    {
        TEvent event;
        while (state_machine_->is_active())
        {
            if (event_provider_->poll_event(event))
            {
                state_machine_->process_event(event);
            }     
        }
    }

private:
    std::shared_ptr<ievent_provider<TEvent>> event_provider_;
    std::shared_ptr<icontroller<TController>> state_machine_;
};

} //  namespace tetris
#endif