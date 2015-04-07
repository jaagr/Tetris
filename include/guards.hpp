#ifndef GUARDS_HPP
#define GUARDS_HPP

#include <boost/msm/front/euml/euml.hpp>

namespace tetris {

namespace euml = boost::msm::front::euml;

class is_space : public euml::euml_action<is_space> 
{
public:
    
    template<typename Event>
    bool operator()(const Event&) const
    {
        return true;
    }
};

class can_move_left : public euml::euml_action<can_move_left> 
{
public:
    
    template<typename Event>
    bool operator()(const Event&) const
    {
        return true;
    }
};

class can_move_right : public euml::euml_action<can_move_right> 
{
public:
    
    template<typename Event>
    bool operator()(const Event&) const
    {
        return true;
    }
};

class can_round : public euml::euml_action<can_round> 
{
public:
    
    template<typename Event>
    bool operator()(const Event&) const
    {
        return true;
    }
};

} // namespace tetris

#endif