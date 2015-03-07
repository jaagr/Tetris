#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "interfaces/iwindow.hpp"
#include "config.hpp"

#include <boost/di.hpp>

namespace tetris {
    
namespace sfml {

class window : public iwindow
{
public:
    BOOST_DI_INJECT(window
    ,   (named = window_width) int width
    ,   (named = window_height) int height);
    
    virtual ~window();
    virtual void clear_window();
};
    
}   //  namespace sf
}   //  namespace tetris
       

#endif