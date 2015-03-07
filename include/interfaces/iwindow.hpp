#ifndef IWINDOW_HPP
#define IWINDOW_HPP

namespace tetris {

class iwindow
{
public:
    virtual ~iwindow() {}
    virtual void clear_window() {};
};
    
}   //  namespace tetris

#endif