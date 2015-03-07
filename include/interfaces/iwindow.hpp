#ifndef IWINDOW_HPP
#define IWINDOW_HPP

namespace tetris {

class iwindow
{
public:
    virtual ~iwindow() {}
    virtual void clear_window() = 0;
    virtual void draw() = 0;
};
    
}   //  namespace tetris

#endif