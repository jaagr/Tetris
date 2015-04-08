#include <boost/lexical_cast.hpp>
#include <SFML/Graphics.hpp>

#include "gui/viewer.hpp"
#include "interfaces/iboard.hpp"
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
void viewer<sf::Drawable>::show_board(const std::vector<std::vector<bool>>& board)
{
    int height = board.size();
    assert(height > 0);
    int width = board.front().size();
    
    std::vector<std::shared_ptr<sf::Drawable>> sprites;
    for(int y = 0; y < height; ++y)
    {
        for(int x = 0; x < width; ++x)
        {
            if(board[y][x])
            {
                sprites.push_back(
                    window_->create_box(255 - 17 * y, 17 * y, 0,
                                        260 + x * 42, 10 + 42 * y)
                );
            }
        }
    }
    
    window_->update_layer(iwindow<sf::Drawable>::BLOCKS,
                          sprites);
}

template<>
void viewer<sf::Drawable>::show_time(time_tick seconds)
{
     time_tick minutes = seconds / 60;
     time_tick remaining_seconds = seconds - 60 * minutes;
     
     std::vector<std::shared_ptr<sf::Drawable>> sprites;
     sprites.push_back(window_->create_text(boost::lexical_cast<std::string>(minutes) + 
                           "m" + boost::lexical_cast<std::string>(remaining_seconds) + "s"));
     
     window_->update_layer(iwindow< sf::Drawable >::TIME,
                           sprites
     );
}

template class viewer<sf::Drawable>;

} // namespace tetris