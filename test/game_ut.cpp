#include <gtest/gtest.h>
#include <memory>

#include "game.hpp"
#include "iclient_mock.hpp"

namespace tetris {
namespace ut {

namespace GT = ::testing;
    
class dummy_action {};

namespace mocks {
    
    class fsm_mock : public fsm
    {
    public:
        virtual ~fsm_mock() {}
    };
}

TEST(game_test, run_client)
{
    //  given
    auto client_mock = std::make_shared<GT::StrictMock<mocks::iclient_mock>>();
    auto controller_mock  = std::make_shared<GT::StrictMock<mocks::fsm_mock>>();
    game sut(controller_mock, client_mock);
    
    //  expected
    EXPECT_CALL(*client_mock, run());
    
    //  when
    sut.start();
}
    
} // namespace ut
} // namespace tetris