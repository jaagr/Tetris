#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "actions.hpp"
#include "events.hpp"

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/euml/euml.hpp>
#include <boost/di.hpp>

namespace mpl   = boost::mpl;
namespace back  = boost::msm::back;
namespace front = boost::msm::front;
namespace euml  = boost::msm::front::euml;

namespace tetris {
    
class controller_ : public front::state_machine_def<controller_> 
{
    struct idle                 : front::state<>, euml::euml_state<idle> {};
    struct board_scrolling      : front::state<>, euml::euml_state<board_scrolling> {};
  
    struct move_left            : front::state<>, euml::euml_state<move_left> {};
    struct move_right           : front::state<>, euml::euml_state<move_right> {};
    struct try_round            : front::state<>, euml::euml_state<try_round> {};
    struct let_round            : front::state<>, euml::euml_state<let_round> {};
    
    struct game_over            : front::state<>, euml::euml_state<game_over>
    {
        typedef mpl::vector1<flag_game_over> flag_list;
    };
    
public:
    
    typedef mpl::vector<idle> initial_state;
    
    BOOST_MSM_EUML_DECLARE_TRANSITION_TABLE((
        board_scrolling() == idle() [anonymous()] / (init_board()),
        game_over() == board_scrolling() + window_close()
        
    ), transition_table)
    
};

using controller = back::state_machine<
    controller_,
    back::use_dependency_injection
    >;
    
} // namespace tetris

#endif