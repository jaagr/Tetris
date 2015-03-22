#include <boost/lexical_cast.hpp>

#include "gui/viewer.hpp"
#include "interfaces/iwindow.hpp"

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

void viewer::show_time(time_tick seconds)
{
     std::string time = boost::lexical_cast<std::string>(seconds);
     window_->show_point(time);
}

} // namespace tetris