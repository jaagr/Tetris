#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <memory>
#include <boost/msm/front/euml/euml.hpp>

#include "time_tick.hpp"
#include "events.hpp"
#include "interfaces/iboard.hpp"
#include "interfaces/iviewer.hpp"

namespace tetris {

template<class T>
class action : public boost::msm::front::euml::euml_action<T> 
{
public: 
    action() {}
    action(std::shared_ptr<iboard> board, std::shared_ptr<iviewer> viewer):
            board_(board), viewer_(viewer) {}
    
protected:
    void show_board()
    {     
        viewer_->clear();
        viewer_->render();
    }
    
    std::shared_ptr<iboard> board_;
    std::shared_ptr<iviewer> viewer_;
};


class init_board : public action<init_board> 
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        board_->init_board();
        show_board();
    }
};

class refresh_board : public action<refresh_board> 
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        show_board();
    }
};

class show_time : public action<show_time> 
{
public:
     show_time() {}
     show_time(std::shared_ptr<iboard> board, 
               std::shared_ptr<iviewer> viewer, 
               std::shared_ptr<time_tick> time):
        action(board, viewer), time_(time){}
    
    template<typename Event>
    void operator()(const Event&)
    {
        (*time_)++;
        viewer_->show_time(*time_);
    }
    
private:
    std::shared_ptr<time_tick> time_;     
};


} // namespace tetris

#endif