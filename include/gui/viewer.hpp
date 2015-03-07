#ifndef VIEWER_HPP
#define VIEWER_HPP

#include "interfaces/iviewer.hpp"
#include "interfaces/iwindow.hpp"
#include <memory>

namespace tetris {

class viewer : public iviewer
{
public:
    viewer(std::shared_ptr<iwindow> window);
    virtual ~viewer() {}
    virtual void clear();
    virtual void render() {}
    
private:
    std::shared_ptr<iwindow> window_;
};
    
}   //  namespace tetris

#endif