#ifndef GAME_HPP
#define GAME_HPP
#include <memory>

#include "interfaces/iclient.hpp"

namespace tetris {
    
class game 
{
public:
    game(std::shared_ptr<iclient> client): client_(client) {}
    void start();
    
private:
    std::shared_ptr<iclient> client_;
};

}// namespace tetris

#endif