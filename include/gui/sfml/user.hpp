#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <boost/di.hpp>

#include "controller.hpp"
#include "interfaces/iclient.hpp"
#include "interfaces/ievent_provider.hpp"

namespace tetris {

class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<sf::Event>> event_provider, std::shared_ptr<controller> msm): 
        event_provider_(event_provider), msm_(msm) {}

    virtual ~user() {}
    virtual void run();

private:
    std::shared_ptr<ievent_provider<sf::Event>> event_provider_;
    std::shared_ptr<controller> msm_;
};

}   //  namespace tetris

#endif