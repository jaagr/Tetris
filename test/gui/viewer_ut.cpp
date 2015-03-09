#include <gtest/gtest.h>
#include <memory>
#include "iwindow_mock.hpp"
#include "gui/viewer.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
class dummy_action {};

TEST(viewer_test, clean_board)
{
    //  given
    auto window_mock = std::make_shared<GT::StrictMock<mocks::iwindow_mock>>();
    viewer sut(window_mock);
    
    //  expected
    EXPECT_CALL(*window_mock, clear_window());
    
    //  when
    sut.clear();
}

TEST(viewer_test, render_board)
{
    //  given
    auto window_mock = std::make_shared<GT::StrictMock<mocks::iwindow_mock>>();
    viewer sut(window_mock);
    
    //  expected
    EXPECT_CALL(*window_mock, draw());
    
    //  when
    sut.render();
}

} // namespace ut
} // namespace tetris