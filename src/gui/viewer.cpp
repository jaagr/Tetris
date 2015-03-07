#include "gui/viewer.hpp"

namespace tetris {

viewer::viewer(std::shared_ptr<iwindow> window) : window_(window) 
{
}

void viewer::clear()
{
    window_->clear_window();
}

void viewer::render()
{
    window_->draw();
}

} // namespace tetris