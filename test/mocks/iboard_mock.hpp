#ifndef IBOARD_MOCK_HPP
#define IBOARD_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/iboard.hpp"

namespace tetris {
namespace ut {
namespace mocks {
    
class iboard_mock : public iboard
{
public:
    virtual ~iboard_mock() {}
    
    MOCK_METHOD0(add_brick, void());
    MOCK_METHOD0(move_brick_left, void());
    MOCK_METHOD0(move_brick_right, void());
    MOCK_METHOD0(move_brick_down, void());
    MOCK_METHOD0(to_matrix, std::vector<row>());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif