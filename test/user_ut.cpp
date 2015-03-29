#include <gtest/gtest.h>
#include <memory>
#include <SFML/Window/Event.hpp>

#include "gui/user.hpp"
#include "icontroller_mock.hpp"
#include "ievent_provider_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

using event = sf::Event;

namespace mocks {
class controller_mock: public icontroller<controller_mock>
{
public:
    virtual ~controller_mock() {}
    MOCK_METHOD0(is_active, bool());
    MOCK_METHOD0(start, void());    
    MOCK_METHOD1(process_event, void(const event&));
};
}

TEST(user_test, run_for_not_working_controller)
{
    //  given
    auto event_provider_mock = std::make_shared<GT::StrictMock<mocks::ievent_provider_mock<event>>>();
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<user<event, mocks::controller_mock>>(event_provider_mock, controler);
    
    //  expect
    EXPECT_CALL(*controler, is_active()).WillRepeatedly(GT::Return(false));
    
    //  when
    sut->run();
}


TEST(user_test, run)
{
    //  given
    auto event_provider_mock = std::make_shared<GT::StrictMock<mocks::ievent_provider_mock<event>>>();
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<user<event, mocks::controller_mock>>(event_provider_mock, controler);
    
    //  expect
    using ::testing::Sequence;
    Sequence game_time;
    
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(false));
    
    Sequence possible_events;
    EXPECT_CALL(*event_provider_mock, poll_event(GT::_)).InSequence(possible_events).WillOnce(GT::Return(true));
    EXPECT_CALL(*event_provider_mock, poll_event(GT::_)).InSequence(possible_events).WillOnce(GT::Return(false));
    
    EXPECT_CALL(*controler, process_event(GT::_));
    
    //  when
    sut->run();
}

} // namespace ut
} // namespace tetris