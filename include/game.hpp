#ifndef GAME_HPP
#define GAME_HPP
#include <memory>

#include "interfaces/iclient.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {

template<typename TController>
class game {
public:    
    template<typename ...TClient>
    explicit game(std::shared_ptr<icontroller<TController>> msm, TClient... clients)
        :   msm_(msm), clients_{ std::forward<TClient>(clients)...} {}
        
    void start()
    {
        msm_->start();
        for(auto& client : clients_)
        {
            client->run();
        }
    }
    
private:
    std::shared_ptr<icontroller<TController>> msm_;
    std::vector<std::shared_ptr<iclient>> clients_;
};

}// namespace tetris

#endif