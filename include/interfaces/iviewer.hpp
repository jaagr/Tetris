#ifndef IVIEWER_HPP
#define IVIEWER_HPP

namespace tetris {

class iviewer
{
public:
    virtual ~iviewer() {}
    virtual void clear() = 0;
    virtual void render() = 0;
};
    
}   //  namespace tetris

#endif