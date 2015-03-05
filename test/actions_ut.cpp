#include <gtest/gtest.h>
#include <memory>
#include "iboard_mock.hpp"
#include "actions.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
TEST(action_test, init_board)
{
    //  given
    auto board_mock = std::make_shared<GT::StrictMock<mocks::iboard_mock>>();
    init_board sut(board_mock);
    
    //  when
    
}
    
} // namespace ut
} // namespace tetris