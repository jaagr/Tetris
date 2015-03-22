#ifndef IVIEWER_HPP
#define IVIEWER_HPP

#include "time_tick.hpp"

namespace tetris {

class iviewer
{
public:
    virtual ~iviewer() {}
    
    virtual void clear() = 0;
    virtual void render() = 0;
    virtual void show_time(time_tick seconds) = 0;
};
    
}   //  namespace tetris

#endif