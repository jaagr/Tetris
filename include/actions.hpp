#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include "interfaces/iboard.hpp"
#include "interfaces/iviewer.hpp"
#include <boost/msm/front/euml/euml.hpp>
#include <memory>

namespace tetris {

template<class T>
class action : public boost::msm::front::euml::euml_action<T> 
{
public: 
    action() {}
    action(std::shared_ptr<iboard> board, std::shared_ptr<iviewer> viewer):
            board_(board), viewer_(viewer) {}
    
protected:
    void show_board(){
        viewer_->clear();
    }
    
    std::shared_ptr<iboard> board_;
    std::shared_ptr<iviewer> viewer_;
};

class init_board : public action<init_board> {
public:
    using action::action;
    
    template<class Event>
    void operator()(const Event&){
        board_->init_board();
        show_board();
    }
};

} // namespace tetris

#endif