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
    
} // namespace ut
} // namespace tetris