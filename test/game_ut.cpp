#include <gtest/gtest.h>
#include <memory>
#include <SFML/Window/Event.hpp>

#include "game.hpp"
#include "icontroller_mock.hpp"
#include "iclient_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

class dummy_event {};

TEST(game_test, run_client)
{
    //  given
    auto controller_mock  = std::make_shared<GT::StrictMock<mocks::icontroller_mock>>();
    auto client_mock = std::make_shared<GT::StrictMock<mocks::iclient_mock>>();
    
    game sut = game(controller_mock, client_mock);
    
    //  expected
    EXPECT_CALL(*controller_mock, start());
    EXPECT_CALL(*client_mock, run());
    
    //  when
    sut.start();
}
    
} // namespace ut
} // namespace tetris