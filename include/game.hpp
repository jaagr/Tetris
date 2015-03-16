#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {

template<typename TEvent>    
class game {
public:
    game(std::shared_ptr<icontroller<TEvent>> msm, std::shared_ptr<iclient> client):msm_(msm), client_(client) {}
    void start()
    {
        msm_->start();
        client_->run();
    }
    
private:
    std::shared_ptr<icontroller<TEvent>> msm_;
    std::shared_ptr<iclient> client_;
};

}// namespace tetris

#endif