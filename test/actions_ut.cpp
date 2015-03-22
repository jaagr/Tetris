#include <gtest/gtest.h>
#include <memory>

#include "iboard_mock.hpp"
#include "iviewer_mock.hpp"
#include "actions.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
class dummy_action {};

TEST(action_test, init_board)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    auto view_mock  = std::make_shared<GT::StrictMock<mocks::iviewer_mock>>();
    init_board sut(board_mock, view_mock);
    
    //  expected
    EXPECT_CALL(*board_mock, init_board());
    EXPECT_CALL(*view_mock, clear());
    EXPECT_CALL(*view_mock, render());
    
    //  when
    sut(dummy_action());
}

TEST(action_test, show_time)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    auto view_mock  = std::make_shared<GT::StrictMock<mocks::iviewer_mock>>();
    auto current_time = std::make_shared<time_tick>(0);
        
    show_time sut(board_mock, view_mock, current_time);
    
    //  expected
    int time = 0;
    EXPECT_CALL(*view_mock, show_time(++time));
    EXPECT_CALL(*view_mock, show_time(++time));
    
    //  when
    sut(dummy_action());
    sut(dummy_action());
}
    
} // namespace ut
} // namespace tetris