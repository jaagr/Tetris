#include "ut_utils.hpp"

#include "iboard_mock.hpp"
#include "iviewer_mock.hpp"
#include "actions.hpp"
#include <../example/modules/view.hpp>

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
class dummy_action {};

TEST(action_test, init_board)
{
    //  given
    auto board_mock = create_mock<mocks::iboard_mock>();
    auto view_mock  = create_mock<mocks::iviewer_mock>();
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
    auto board_mock = create_mock<mocks::iboard_mock>();
    auto view_mock  = create_mock<mocks::iviewer_mock>();
    
    auto current_time = std::make_shared<time_tick>(0);
        
    show_time sut(board_mock, view_mock, current_time);
    
    //  expected
    int time = 0;
    EXPECT_CALL(*view_mock, show_time(++time));
    EXPECT_CALL(*view_mock, show_time(++time));
    EXPECT_CALL(*view_mock, clear()).Times(2);
    EXPECT_CALL(*view_mock, render()).Times(2);
    
    //  when
    sut(dummy_action());
    sut(dummy_action());
}
    
TEST(action_test, generate_brick)
{
    //  given
    auto board_mock = create_mock<mocks::iboard_mock>();
    auto view_mock  = create_mock<mocks::iviewer_mock>();    
    generate_brick sut(board_mock, view_mock);
    std::vector<std::vector<bool>> board_matrix = {{true, false}};
    
    //  expected
    EXPECT_CALL(*board_mock, add_brick());
    EXPECT_CALL(*board_mock, to_matrix()).WillOnce(GT::Return(board_matrix));
    EXPECT_CALL(*view_mock, show_board(board_matrix));
    
    EXPECT_CALL(*view_mock, clear());
    EXPECT_CALL(*view_mock, render());
    
    //  when
    sut(dummy_action());
}

TEST(action_test, move_brick_left)
{
    //  given
    auto board_mock = create_mock<mocks::iboard_mock>();
    auto view_mock  = create_mock<mocks::iviewer_mock>();
    move_brick_left sut(board_mock, view_mock);
    std::vector<std::vector<bool>> board_matrix = {{true, false}};
    
    //  expected
    EXPECT_CALL(*board_mock, move_brick_left());
    EXPECT_CALL(*board_mock, to_matrix()).WillOnce(GT::Return(board_matrix));
    EXPECT_CALL(*view_mock, show_board(board_matrix));
    
    EXPECT_CALL(*view_mock, clear());
    EXPECT_CALL(*view_mock, render());
    
    //  when
    sut(dummy_action());
}

TEST(action_test, move_brick_right)
{
    //  given
    auto board_mock = create_mock<mocks::iboard_mock>();
    auto view_mock  = create_mock<mocks::iviewer_mock>();
    move_brick_right sut(board_mock, view_mock);
    std::vector<std::vector<bool>> board_matrix = {{true, false}};
    
    //  expected
    EXPECT_CALL(*board_mock, move_brick_right());
    EXPECT_CALL(*board_mock, to_matrix()).WillOnce(GT::Return(board_matrix));
    EXPECT_CALL(*view_mock, show_board(board_matrix));
    
    EXPECT_CALL(*view_mock, clear());
    EXPECT_CALL(*view_mock, render());
    
    //  when
    sut(dummy_action());
}

} // namespace ut
} // namespace tetris