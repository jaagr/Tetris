#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <memory>

#include "interfaces/iviewer.hpp"
#include "interfaces/iwindow.hpp"

namespace tetris {

template<typename TDrawable>
class viewer : public iviewer
{
public:
    viewer(std::shared_ptr<iwindow<TDrawable>> window);
    virtual ~viewer() {}
    virtual void clear();
    virtual void render();
    virtual void show_time(time_tick seconds);
    
private:
    std::shared_ptr<iwindow<TDrawable>> window_;
};
    
}   //  namespace tetris

#endif