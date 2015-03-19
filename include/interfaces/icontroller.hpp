#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

namespace tetris {
    
template<typename CRTP>    
class icontroller 
{
public:    
    void start()
    {
        derived().start();
    }
    
    bool is_active()
    {
        return derived().is_active();
    }
    
    template<typename TEvent>    
    void process_event(const TEvent& evt) 
    {
        derived().process_event(evt);
    }
    
    virtual ~icontroller() {}

private:
   CRTP& derived()
   {
       return *static_cast<CRTP*>(this);
   }
};

} // namespace tetris

#endif
