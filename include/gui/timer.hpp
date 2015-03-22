#ifndef TIMER_HPP
#define TIMER_HPP

#include <memory>
#include <thread>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"
#include "controller.hpp"

namespace tetris{

        
template<typename TEvent, typename TController, int TPeriod>
class timer : public iclient {
public:    
    timer(std::shared_ptr<icontroller<TController>> state_machine): 
        state_machine_(state_machine){
        }
    
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
    
    void sleep()
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(TPeriod)
        );
    }
};

} // namespace tetris
#endif