#ifndef IBOARD_HPP
#define IBOARD_HPP

namespace tetris {

class iboard
{
public:
    virtual void init_board() = 0;
    virtual ~iboard() {}
};
    
}   //  namespace tetris

#endif