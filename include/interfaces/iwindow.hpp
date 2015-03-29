#ifndef IWINDOW_HPP
#define IWINDOW_HPP

namespace tetris {

template<typename TDrawable>
class iwindow
{
public:
    
    enum layer {
        TIME
    };

    virtual ~iwindow() {}
    virtual void clear_window() = 0;
    virtual void draw() = 0;
    
    virtual std::shared_ptr<TDrawable> create_text(const std::string& text) = 0;
    
    virtual void update_layer(const layer&, std::shared_ptr<TDrawable>) = 0;
};
    
}   //  namespace tetris

#endif