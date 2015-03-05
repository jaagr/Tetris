#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "interfaces/iboard.hpp"
#include <boost/msm/front/euml/euml.hpp>

namespace tetris {

template<class T>
class action : public boost::msm::front::euml::euml_action<T> 
{
public: 
    action() {}
    action(std::shared_ptr<iboard> board):board_(board) {}
    
protected:
    void show_board();
    
    std::shared_ptr<iboard> board_;
};

class init_board : public action<init_board> {
public:
    using action::action;
    
};

} // namespace tetris

#endif
