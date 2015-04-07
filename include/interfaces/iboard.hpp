#ifndef IBOARD_HPP
#define IBOARD_HPP

#include <vector>

namespace tetris {

class iboard
{
public:
    typedef std::vector<bool> row;
     
    virtual ~iboard() {}

    virtual void add_brick() = 0;
    virtual void move_brick_left() = 0;
    virtual void move_brick_right() = 0;
    virtual void move_brick_down() = 0;
   
    virtual std::vector<row> to_matrix() = 0;
};
    
} // namespace tetris

#endif