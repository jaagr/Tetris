#include <boost/lexical_cast.hpp>
#include <SFML/Graphics.hpp>

#include "gui/viewer.hpp"
#include "interfaces/iwindow.hpp"

namespace tetris {

template<>    
viewer<sf::Drawable>::viewer(std::shared_ptr<iwindow<sf::Drawable>> window) : window_(window) 
{
}

template<>
void viewer<sf::Drawable>::clear()
{
    window_->clear_window();
}

template<>
void viewer<sf::Drawable>::render()
{
    window_->draw();
}

template<>
void viewer<sf::Drawable>::show_time(time_tick seconds)
{
     time_tick minutes = seconds / 60;
     time_tick remaining_seconds = seconds - 60 * minutes;
     
     window_->update_layer(iwindow< sf::Drawable >::TIME,
                           window_->create_text(boost::lexical_cast<std::string>(minutes) + 
                           "m" + boost::lexical_cast<std::string>(remaining_seconds) + "s")
     );
     window_->draw();
}

template class viewer<sf::Drawable>;

} // namespace tetris