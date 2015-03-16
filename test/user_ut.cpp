#include <gtest/gtest.h>
#include <memory>

#include "gui/user.hpp"
#include "icontroller_mock.hpp"
#include "ievent_provider_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

class dummy_event {};
TEST(user_test, run_for_not_working_controller)
{
    //  given
    auto event_provider_mock = std::make_shared<GT::StrictMock<mocks::ievent_provider_mock<dummy_event>>>();
    auto controler_mock = std::make_shared<GT::StrictMock<mocks::icontroller_mock<dummy_event>>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<user<dummy_event>>(event_provider_mock, controler_mock);
    
    //  expect
    EXPECT_CALL(*controler_mock, is_active()).WillRepeatedly(GT::Return(false));
    
    //  when
    sut->run();
}

TEST(user_test, run)
{
    //  given
    auto event_provider_mock = std::make_shared<GT::StrictMock<mocks::ievent_provider_mock<dummy_event>>>();
    auto controler_mock = std::make_shared<GT::StrictMock<mocks::icontroller_mock<dummy_event>>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<user<dummy_event>>(event_provider_mock, controler_mock);
    
    //  expect
    using ::testing::Sequence;
    Sequence game_time;
    
    EXPECT_CALL(*controler_mock, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler_mock, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler_mock, is_active()).InSequence(game_time).WillOnce(GT::Return(false));
    
    Sequence possible_events;
    EXPECT_CALL(*event_provider_mock, pollEvent(GT::_)).InSequence(possible_events).WillOnce(GT::Return(true));
    EXPECT_CALL(*event_provider_mock, pollEvent(GT::_)).InSequence(possible_events).WillOnce(GT::Return(false));
    
    EXPECT_CALL(*controler_mock, process_event(GT::_));
    
    //  when
    sut->run();
}

} // namespace ut
} // namespace tetris