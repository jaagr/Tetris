#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <type_traits>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/has_xxx.hpp>

#include "fsm.hpp"
#include "interfaces/icontroller.hpp"

namespace tetris {

template<typename TEvent>
class controller : public fsm, public icontroller<TEvent> 
{
    BOOST_MPL_HAS_XXX_TRAIT_DEF(id)
    BOOST_MPL_HAS_XXX_TRAIT_DEF(key)
        
    template<typename T>
    struct event
    {
        typedef typename T::Evt type; // transition_event
    };
    
    template<typename T>
    using events = typename mpl::transform<T, event<mpl::_1>>::type;
    
    template<typename Seq>
    void for_events(const TEvent&, typename std::enable_if<mpl::empty<Seq>::value>::type* = 0)
    {
    }
    
    template<typename Seq>
    void for_events(const TEvent& evt, typename std::enable_if<!mpl::empty<Seq>::value>::type* = 0)
    {
        typedef typename mpl::front<Seq>::type event_t;
        
        if(is_same_id<event_t>(get_event_type(evt)) && is_same_key<event_t>(get_key_code(evt))){
             process_event<event_t>(evt);
        }else{
            for_events<typename mpl::pop_front<Seq>::type>(evt);
        }
    }
    
    int get_key_code(const TEvent& evt);
    int get_event_type(const TEvent& evt);
    
    template<typename UEvent>
    void process_event(const TEvent& evt){
        fsm::process_event(UEvent(evt));        
    }
    
    template<typename UEvent>
    bool is_same_id(int value, typename std::enable_if_t<has_id<UEvent>::value>* = 0)
    {
        return value == UEvent::id::value;
    }
    
    template<typename UEvent>
    bool is_same_id(int value, typename std::enable_if_t<!has_id<UEvent>::value>* = 0)
    {
        return false;
    }
    
    template<typename UEvent>
    bool is_same_key(int value, typename std::enable_if_t<has_key<UEvent>::value>* = 0)
    {
        return value == UEvent::key::value;
    }
    
    template<typename UEvent>
    bool is_same_key(int value, typename std::enable_if_t<!has_key<UEvent>::value>* = 0)
    {
        return true;
    }
    
public:
    
    template<typename... Args>
    explicit controller(Args&&... arg): fsm(std::forward<Args>(arg)...) {}
    
    virtual void process_event(const TEvent& event)
    {
        typedef typename fsm::transition_table transition_table;
        for_events<typename events<transition_table>::type>(event);
    }
    
    virtual bool is_active() const
    {
        return not is_flag_active<flag_game_over>();
    }
    
    virtual void start() 
    {
        fsm::start();
    }
        
    ~controller() {}
};

} // namespace tetris
#endif