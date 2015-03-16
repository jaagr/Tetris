#ifndef IBOARD_HPP
#define IBOARD_HPP

namespace tetris {

class iboard
{
public:
    virtual ~iboard() {}
    virtual void init_board() = 0;
};
    
} // namespace tetris

#endif