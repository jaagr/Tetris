#ifndef VIEWER_HPP
#define VIEWER_HPP

#include "interfaces/iviewer.hpp"

namespace tetris {

class viewer : public iviewer
{
public:
    virtual ~viewer() {}
    virtual void clear() {}
};
    
}   //  namespace tetris

#endif