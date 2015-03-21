#ifndef TIMER_HPP
#define TIMER_HPP

#include <memory>
#include <thread>
#include <boost/concept_check.hpp>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"
#include "controller.hpp"

namespace tetris{

        
template<typename TEvent, typename TController>
class timer : public iclient {
public:    
    timer(std::shared_ptr<icontroller<TController>> state_machine, int period): 
        state_machine_(state_machine), period_(period){}
    
    virtual ~timer(){}
    
    virtual void run()
    {
        std::thread([&]()
        {
            while(true)
            {
                sleep();
                if(not state_machine_->is_active())
                {
                    return;
                }
                state_machine_->process_event(TEvent());
            }
        }).detach();
    }

private:
    std::shared_ptr<icontroller<TController>> state_machine_;
    int period_;
    
    void sleep()
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(period_)
        );
    }
};

} // namespace tetris
#endif