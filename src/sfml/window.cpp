#include "sfml/window.hpp"
#include <iostream>
namespace tetris {
namespace sfml {

window::window(int w, int h) 
{
    std::cout << w;
}

window::~window(){
}

void window::clear_window()
{

}

} // namespace sfml
} // namespace tetris