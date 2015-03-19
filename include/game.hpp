#ifndef GAME_HPP
#define GAME_HPP
#include <memory>

#include "controller.hpp"

namespace tetris {
    
class iclient;

class game {
public:
    game(std::shared_ptr<icontroller<controller>> msm, std::shared_ptr<iclient> client);
    void start();
    
private:
    std::shared_ptr<icontroller<controller>> msm_;
    std::shared_ptr<iclient> client_;
};

}// namespace tetris

#endif