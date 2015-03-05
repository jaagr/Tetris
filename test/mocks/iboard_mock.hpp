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
    MOCK_METHOD0(init_board, void());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif