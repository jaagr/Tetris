#ifndef VIEWER_HPP
#define VIEWER_HPP

#include <memory>

#include "interfaces/iviewer.hpp"

namespace tetris {

class iwindow;

class viewer : public iviewer
{
public:
    viewer(std::shared_ptr<iwindow> window);
    virtual ~viewer() {}
    virtual void clear();
    virtual void render();
    
private:
    std::shared_ptr<iwindow> window_;
};
    
}   //  namespace tetris

#endif