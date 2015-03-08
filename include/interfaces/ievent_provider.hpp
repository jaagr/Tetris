#ifndef IEVENT_PROVIDER_HPP
#define IEVENT_PROVIDER_HPP

namespace tetris {

template<typename Event>
class ievent_provider
{
public:
    virtual bool pollEvent(Event&) = 0;
};
    
}   //  namespace tetris

#endif