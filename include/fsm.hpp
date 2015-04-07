#ifndef FSM_HPP
#define FSM_HPP

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/euml/euml.hpp>
#include <boost/di.hpp>

#include "actions.hpp"
#include "events.hpp"
#include "guards.hpp"

namespace mpl   = boost::mpl;
namespace back  = boost::msm::back;
namespace front = boost::msm::front;
namespace euml  = boost::msm::front::euml;

namespace tetris {
    
class fsm_ : public front::state_machine_def<fsm_> 
{
    struct idle                 : front::state<>, euml::euml_state<idle> {};
    struct clock                : front::state<>, euml::euml_state<clock> {};
    
    struct wait_for_client      : front::state<>, euml::euml_state<wait_for_client> {};
    struct box_located          : front::state<>, euml::euml_state<box_located> {};
    struct wait_for_box         : front::state<>, euml::euml_state<wait_for_box> {};
    
    struct game_over            : front::state<>, euml::euml_state<game_over>
    {
        typedef mpl::vector1<flag_game_over> flag_list;
    };
    
public:

    typedef mpl::vector<idle, clock> initial_state;
    
    BOOST_MSM_EUML_DECLARE_TRANSITION_TABLE((
        clock()             == clock()              +    one_second_tick()                      / (show_time())         ,
        clock()             == clock()              +    window_moved()                         / (refresh_board())     ,
                                             
        wait_for_box()      == idle()                                       [anonymous()]       / (init_board())        ,               
        wait_for_client()   == wait_for_box()                               [anonymous()]       / (generate_brick())      ,
                                             
        wait_for_client()   == wait_for_client()    +    gravity_touch()    [is_space()]        / (move_brick_down())     ,
        box_located()       == wait_for_client()    +    gravity_touch()    [not is_space()]    / (locate_brick())        ,                                                
        wait_for_box()      == box_located()        +    gravity_touch()                        / (generate_brick())      ,                                   

        wait_for_client()   == wait_for_client()    +    move_left()        [can_move_left()]   / (move_brick_left(),
                                                                                                   refresh_board())     ,                            
        wait_for_client()   == wait_for_client()    +    move_right()       [can_move_right()]  / (move_brick_right(), 
                                                                                                    refresh_board())    ,                            
        wait_for_client()   == wait_for_client()    +    move_round()       [can_round()]       / (round_brick(),
                                                                                                    refresh_board())    ,                            
                                           
        game_over()         == wait_for_client()    +    window_close()                                                 ,
        game_over()         == wait_for_client()    +    button_esc()
    ), transition_table)
    
};

using fsm = back::state_machine<
    fsm_,
    back::use_dependency_injection
    >;
    
} // namespace tetris

#endif