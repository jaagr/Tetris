#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>
#include <boost/lexical_cast.hpp>
#include <SFML/Graphics.hpp>

#include "gui/viewer.hpp"
#include "interfaces/iwindow.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

namespace mocks{

class iwindow_mock : public iwindow<sf::Drawable>
{
public:
    virtual ~iwindow_mock() {}
    MOCK_METHOD0(clear_window, void());
    MOCK_METHOD0(draw, void());
    MOCK_METHOD2_T(update_layer, void(const layer&, std::shared_ptr<sf::Drawable>));
    MOCK_METHOD1_T(create_text, std::shared_ptr<sf::Drawable>(const std::string&));
};

}

TEST(viewer_test, clean_board)
{
    //  given
    auto window_mock = std::make_shared<GT::StrictMock<mocks::iwindow_mock>>();
    viewer<sf::Drawable> sut(window_mock);
    
    //  expected
    EXPECT_CALL(*window_mock, clear_window());
    
    //  when
    sut.clear();
}

TEST(viewer_test, render_board)
{
    //  given
    auto window_mock = std::make_shared<GT::StrictMock<mocks::iwindow_mock>>();
    viewer<sf::Drawable> sut(window_mock);
    
    //  expected
    EXPECT_CALL(*window_mock, draw());
    
    //  when
    sut.render();
}

TEST(viewer_test, show_time)
{
    //  given
    auto window_mock = std::make_shared<GT::StrictMock<mocks::iwindow_mock>>();
    viewer<sf::Drawable> sut(window_mock);
    time_tick time = 200;
    std::string time_in_min = "3m20s";
    
    //  expected
    std::shared_ptr<sf::Drawable> drawable = std::make_shared<sf::Text>();
    EXPECT_CALL(*window_mock, create_text(time_in_min)).WillOnce(GT::Return(drawable));
    EXPECT_CALL(*window_mock, update_layer(mocks::iwindow_mock::layer::TIME, 
                                           drawable));
    EXPECT_CALL(*window_mock, draw());
    
    //  when
    sut.show_time(time);
}


} // namespace ut
} // namespace tetris