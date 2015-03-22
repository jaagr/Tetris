#include <gtest/gtest.h>
#include <memory>
#include <SFML/Window/Event.hpp>

#include "game.hpp"
#include "icontroller_mock.hpp"
#include "iclient_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

TEST(game_test, run_client)
{
    //  given
    auto controller_mock  = std::make_shared<GT::StrictMock<mocks::icontroller_mock>>();
    auto first_client_mock = std::make_shared<GT::StrictMock<mocks::iclient_mock>>();
    auto second_client_mock = std::make_shared<GT::StrictMock<mocks::iclient_mock>>();
    
    game<mocks::icontroller_mock> sut = game<mocks::icontroller_mock>(controller_mock, 
                                                                      first_client_mock, second_client_mock);

    //  expected
    using ::testing::Sequence;
    Sequence game_time;
    EXPECT_CALL(*controller_mock, start()).InSequence(game_time);
    EXPECT_CALL(*first_client_mock, run()).InSequence(game_time);
    EXPECT_CALL(*second_client_mock, run()).InSequence(game_time);
    
    //  when
    sut.start();
}
 
} // namespace ut
} // namespace tetris