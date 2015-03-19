#ifndef TIMER_HPP
#define TIMER_HPP

#include <memory>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"
#include "controller.hpp"

namespace tetris{

template<typename TEvent>
class timer : public iclient {
public:    
    timer(std::shared_ptr<icontroller<controller>> state_machine, int period): 
        state_machine_(state_machine), period_(period) {}
    virtual ~timer(){}
    
    virtual void run();

private:
    std::shared_ptr<icontroller<controller>> state_machine_;
    int period_;
};

} // namespace tetris
#endif