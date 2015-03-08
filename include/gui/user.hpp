#ifndef USER_HPP
#define USER_HPP

#include <memory>
#include <SFML/Graphics.hpp>
#include <boost/di.hpp>

#include "interfaces/iclient.hpp"
#include "interfaces/ievent_provider.hpp"

namespace tetris {

class user : public iclient
{
public:
    user(std::shared_ptr<ievent_provider<sf::Event>> event_provider): event_provider_(event_provider) {}
    virtual ~user() {}
    virtual void run();

private:
    std::shared_ptr<ievent_provider<sf::Event>> event_provider_;
};

}   //  namespace tetris

#endif