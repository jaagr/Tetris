#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

namespace tetris {
    
template<typename TEvent>    
class icontroller 
{
public:    
    virtual ~icontroller() {}
    virtual void start() = 0;
    virtual bool is_active() const = 0;
    virtual void process_event(const TEvent&) = 0;
};

} // namespace tetris

#endif
