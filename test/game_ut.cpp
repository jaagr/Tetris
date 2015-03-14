#include <gtest/gtest.h>
#include <memory>

#include "game.hpp"
#include "iclient_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
class dummy_action {};


TEST(game_test, run_client)
{
    //  given
    auto client_mock = std::make_shared<GT::StrictMock<mocks::iclient_mock>>();
    game sut(client_mock);
    
    //  expected
    EXPECT_CALL(*client_mock, run());
    
    //  when
    sut.start();
}
    
} // namespace ut
} // namespace tetris