#ifndef IEVENT_PROVIDER_HPP
#define IEVENT_PROVIDER_HPP

namespace tetris {

template<typename TEvent>
class ievent_provider
{
public:
    virtual bool pollEvent(TEvent&) = 0;
};
    
}   //  namespace tetris

#endif