#ifndef ACTIONS_HPP
#define ACTIONS_HPP

#include <boost/msm/front/euml/euml.hpp>

namespace tetris {

template<class T>
class action : public boost::msm::front::euml::euml_action<T> {};

class init_board : public action<init_board> {};

} // namespace tetris

#endif
