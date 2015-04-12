#ifndef TIMER_HPP
#define TIMER_HPP

#include <memory>
#include <thread>
#include <atomic>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"
#include "controller.hpp"

namespace tetris{

        
template<typename TEvent, typename TController, int TPeriod>
class timer : public iclient {
public:    
    timer(std::shared_ptr<icontroller<TController>> state_machine): 
        state_machine_(state_machine), is_running_(false){   
    }
    
    virtual ~timer(){}
    
    virtual void run()
    {
        is_running_ = true;
        std::thread([&]()
        {
            while(state_machine_->is_active())
            {
                state_machine_->process_event(TEvent());
                sleep();
            }
            is_running_ = false;
        }).detach();
    }
    
    virtual bool is_running() const
    {
        return is_running_;
    }

private:
    std::shared_ptr<icontroller<TController>> state_machine_;
    std::atomic_bool is_running_;    
    
    void sleep()
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(TPeriod)
        );
    }
};

} // namespace tetris
#endif