#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include "interfaces/iclient.hpp"
#include "controller.hpp"

namespace tetris {
    
class game {
public:
    game(std::shared_ptr<controller> msm, std::shared_ptr<iclient> client):msm_(msm), client_(client) {}
    void start();
    
private:
    std::shared_ptr<controller> msm_;
    std::shared_ptr<iclient> client_;
};

}// namespace tetris

#endif