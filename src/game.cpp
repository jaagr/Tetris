#include <SFML/Window/Event.hpp>
#include "game.hpp"
#include "interfaces/iclient.hpp"
#include "controller.hpp"

namespace tetris {
    
void game::start()
{
    msm_->start();
    client_->run();
}

game::game(std::shared_ptr<icontroller<controller>> msm, std::shared_ptr<iclient> client):
        msm_(msm), client_(client)
{    
}

} // namespace tetris