#ifndef ICLIENT_HPP
#define ICLIENT_HPP

namespace tetris {

class iclient
{
public:
    virtual ~iclient() {}
    virtual void run() = 0;
};
    
}   //  namespace tetris

#endif