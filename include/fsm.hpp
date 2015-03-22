#ifndef FSM_HPP
#define FSM_HPP

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/euml/euml.hpp>
#include <boost/di.hpp>

#include "actions.hpp"
#include "events.hpp"

namespace mpl   = boost::mpl;
namespace back  = boost::msm::back;
namespace front = boost::msm::front;
namespace euml  = boost::msm::front::euml;

namespace tetris {
    
class fsm_ : public front::state_machine_def<fsm_> 
{
    struct idle                 : front::state<>, euml::euml_state<idle> {};
    struct board_scrolling      : front::state<>, euml::euml_state<board_scrolling> {};
    
    struct wait_for_client      : front::state<>, euml::euml_state<wait_for_client> {};
    
    struct move_left            : front::state<>, euml::euml_state<move_left> {};
    struct move_right           : front::state<>, euml::euml_state<move_right> {};
    struct try_round            : front::state<>, euml::euml_state<try_round> {};
    struct let_round            : front::state<>, euml::euml_state<let_round> {};
    
    struct game_over            : front::state<>, euml::euml_state<game_over>
    {
        typedef mpl::vector1<flag_game_over> flag_list;
    };
    
public:
    
    typedef mpl::vector<idle, wait_for_client> initial_state;
    
    BOOST_MSM_EUML_DECLARE_TRANSITION_TABLE((
        board_scrolling()   == idle()                                       [anonymous()] / (init_board())   ,
                               board_scrolling()    +    window_moved()                   / (refresh_board()),
                                             
        wait_for_client()   == wait_for_client()    +    one_second_tick()                / (show_time())    ,
        game_over()         == wait_for_client()    +    window_close()                                      ,
        game_over()         == wait_for_client()    +    button_esc()
    ), transition_table)
    
};

using fsm = back::state_machine<
    fsm_,
    back::use_dependency_injection
    >;
    
} // namespace tetris

#endif