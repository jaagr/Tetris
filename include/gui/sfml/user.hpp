#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <boost/di.hpp>

#include "controller.hpp"
#include "interfaces/iclient.hpp"
#include "interfaces/ievent_provider.hpp"

namespace tetris {
    
namespace sfml {
class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<sf::Event>> event_provider, std::shared_ptr<controller> fsm): 
        event_provider_(event_provider), fsm_(fsm) {}

    virtual ~user() {}
    virtual void run();

private:
    std::shared_ptr<ievent_provider<sf::Event>> event_provider_;
    std::shared_ptr<controller> fsm_;
};

} // namespace sfml
} //  namespace tetris
#endif