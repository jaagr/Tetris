#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <boost/di.hpp>

#include "interfaces/iclient.hpp"
#include "controller.hpp"
#include "interfaces/ievent_provider.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {
        
template<typename TEvent>
class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<TEvent>> event_provider, 
         std::shared_ptr<icontroller<controller>> state_machine);

    virtual ~user();
    
    virtual void run();

private:
    std::shared_ptr<ievent_provider<TEvent>> event_provider_;
    std::shared_ptr<icontroller<controller>> state_machine_;
};

} //  namespace tetris
#endif