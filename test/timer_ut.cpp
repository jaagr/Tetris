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
    const int timer_period = 1;
    
    //  given
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut =  
        std::make_shared<timer<event, mocks::controller_mock, timer_period>>(controler);
    
    //  expect
    EXPECT_CALL(*controler, is_active()).WillOnce(GT::Return(false));
    
    //  when
    EXPECT_FALSE(sut->is_running());
    sut->run();
    do
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(1)
        );
    }while(sut->is_running());
}

TEST(timer_test, one_event)
{
    const int timer_period = 1;
    
    //  given
    auto controler = std::make_shared<GT::StrictMock<mocks::controller_mock>>();
    
    std::shared_ptr<iclient> sut = 
        std::make_shared<timer<event, mocks::controller_mock, timer_period>>(controler);
    
    //  expect
    using ::testing::Sequence;
    Sequence game_time;
    
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(true));
    EXPECT_CALL(*controler, is_active()).InSequence(game_time).WillOnce(GT::Return(false));
    EXPECT_CALL(*controler, process_event(GT::_));
    
    //  when
    sut->run();
    do
    {
        std::this_thread::sleep_for(
            std::chrono::milliseconds(1)
        );
    }while(sut->is_running());
}


} // namespace ut
} // namespace tetris