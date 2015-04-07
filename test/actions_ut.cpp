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
    
TEST(action_test, generate_brick)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    auto view_mock  = std::make_shared<GT::StrictMock<mocks::iviewer_mock>>();
    generate_brick sut(board_mock, view_mock);
    
    //  expected
    EXPECT_CALL(*board_mock, add_brick());
    
    //  when
    sut(dummy_action());
}

TEST(action_test, move_brick_left)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    auto view_mock  = std::make_shared<GT::StrictMock<mocks::iviewer_mock>>();
    move_brick_left sut(board_mock, view_mock);
    
    //  expected
    EXPECT_CALL(*board_mock, move_brick_left());
    
    //  when
    sut(dummy_action());
}

TEST(action_test, move_brick_right)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    auto view_mock  = std::make_shared<GT::StrictMock<mocks::iviewer_mock>>();
    move_brick_right sut(board_mock, view_mock);
    
    //  expected
    EXPECT_CALL(*board_mock, move_brick_right());
    
    //  when
    sut(dummy_action());
}

} // namespace ut
} // namespace tetris