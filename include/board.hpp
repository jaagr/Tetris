#ifndef BOARD_HPP
#define BOARD_HPP

#include "interfaces/iboard.hpp"

namespace tetris {

struct figure{
    int x_ = 0, y_ = 0;
    bool boxes_[4][4] = {{true, false, false, false}, {true, false, false, false}, 
                         {true, false, false, false} ,{true, false, false, false} };
};

class board : public iboard
{
public:
    
    std::vector<row> matrix;
    
    board() 
    {
        matrix = std::vector<row>(14);
        for(int i = 0; i < 14; i++)
        {
            matrix[i] = { false, false, false, false, false,
                          false, false, false, false, false
            };
        }
    }
    
    virtual std::vector<row> to_matrix()
    {
        std::vector<row> tmp = matrix;
        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                tmp[y + current_figure_->y_][x + current_figure_->x_] = current_figure_->boxes_[y][x]; 
            }   
        }        
        return tmp;
    }
    
    virtual void add_brick() 
    {
        current_figure_ = std::make_unique<figure>();
    }
    
    virtual void move_brick_left() 
    {
        current_figure_->x_--;
    }
    
    virtual void move_brick_right() 
    {
        current_figure_->x_++;
    }
    
    virtual void move_brick_down() 
    {
        current_figure_->y_++;
    }


    virtual ~board() {}
    
    std::unique_ptr<figure> current_figure_;
    
private:
};
   
}   //  namespace tetris

#endif