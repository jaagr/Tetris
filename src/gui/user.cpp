#include <SFML/Graphics.hpp>

#include <type_traits>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/transform.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/has_xxx.hpp>

#include "gui/user.hpp"

namespace tetris {
namespace sfml {

struct event_mapper{

    event_mapper(std::shared_ptr<controller> state_machine): state_machine_(state_machine) {}
    
    BOOST_MPL_HAS_XXX_TRAIT_DEF(id)
        
    template<typename T>
    struct event
    {
        typedef typename T::Evt type; // transition_event
    };
    
    template<typename T>
    using events = typename mpl::transform<T, event<mpl::_1>>::type;
    
    void process_event(const sf::Event& event){
        typedef typename controller::transition_table transition_table;
        for_events<typename events<transition_table>::type>(event);
    }
    
    template<typename Seq>
    void for_events(const sf::Event&, typename std::enable_if<mpl::empty<Seq>::value>::type* = 0){
    }
    
    template<typename Seq>
    void for_events(const sf::Event& evt, typename std::enable_if<!mpl::empty<Seq>::value>::type* = 0){
        typedef typename mpl::front<Seq>::type event_t;
        
        if(is_same_id<event_t>(evt.type)){
             process_event<event_t>(evt);
        }else{
            for_events<typename mpl::pop_front<Seq>::type>(evt);
        }
    }
    
    template<typename TEvent>
    void process_event(const sf::Event& evt){
        state_machine_->process_event(TEvent(evt));        
    }
    
    template<typename TEvent>
    bool is_same_id(int value, typename std::enable_if_t<has_id<TEvent>::value>* = 0){
        return value == TEvent::id::value;
    }
    
    template<typename TEvent>
    bool is_same_id(int value, typename std::enable_if_t<!has_id<TEvent>::value>* = 0){
        return false;
    }
    
    std::shared_ptr<controller> state_machine_;
};

void user::run()
{
    sf::Event event;
    event_mapper mapper(fsm_);
    while (!fsm_->is_flag_active<flag_game_over>())
    {
        while (event_provider_->pollEvent(event))
        {
            mapper.process_event(event);
        }     
    }
}

} // namespace sfml
} // namespace tetris