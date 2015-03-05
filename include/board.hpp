#ifndef BOARD_HPP
#define BOARD_HPP

#include "interfaces/iboard.hpp"

namespace tetris {

class board : public iboard
{
public:
    virtual void init_board() {}
    virtual ~board() {}
};
    
}   //  namespace tetris

#endif