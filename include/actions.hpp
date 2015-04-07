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
        show_board();
    }
};

class locate_brick : public action<locate_brick>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
    }
};

class generate_brick : public action<generate_brick>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        board_->add_brick();
        viewer_->show_board(board_->to_matrix());
        show_board();
    }
};

class move_brick_left : public action<move_brick_left>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        board_->move_brick_left();
        viewer_->show_board(board_->to_matrix());
        show_board();
    }
};

class move_brick_right : public action<move_brick_right>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        board_->move_brick_right();
        viewer_->show_board(board_->to_matrix());
        show_board();
    }
};

class move_brick_down : public action<move_brick_down>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
        board_->move_brick_down();
        viewer_->show_board(board_->to_matrix());
        show_board();
    }
};

class round_brick : public action<round_brick>
{
public:
    using action::action;
    
    template<typename Event>
    void operator()(const Event&)
    {
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
        show_board();
    }
    
private:
    std::shared_ptr<time_tick> time_;     
};


} // namespace tetris

#endif