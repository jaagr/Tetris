#include <gtest/gtest.h>
#include <memory>
#include <thread>

#include "gui/timer.hpp"
#include "mocks/icontroller_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;

using event = time_tick;

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

TEST(timer_test, machine_stopped)
{
    int timer_period = 1;
    int wait_period = 2 * timer_period;
    
    //  given
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut =  
        std::make_shared<timer<event, mocks::controller_mock>>(controler, timer_period);
    
    //  expect
    EXPECT_CALL(*controler, is_active()).WillOnce(GT::Return(false));
    
    //  when
    sut->run();
    std::this_thread::sleep_for(
        std::chrono::milliseconds(wait_period)
    );
}


TEST(timer_test, one_event)
{
    int timer_period = 1;
    int wait_period = 4 * timer_period;
    
    //  given
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<timer<event, mocks::controller_mock>>(controler, timer_period);
    
    //  expect
    using ::testing::Sequence;
    Sequence game_time;
    
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(false));
    EXPECT_CALL(*controler, process_event(GT::_));
    
    //  when
    sut->run();
    std::this_thread::sleep_for(
        std::chrono::milliseconds(wait_period)
    );
}



} // namespace ut
} // namespace tetris