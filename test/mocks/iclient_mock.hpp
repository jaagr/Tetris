#ifndef ICLIENT_MOCK_HPP
#define ICLIENT_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/iclient.hpp"

namespace tetris {
namespace ut {
namespace mocks {
    
class iclient_mock : public iclient
{
public:
    virtual ~iclient_mock() {}
    MOCK_METHOD0(run, void());
    MOCK_CONST_METHOD0(is_running, bool());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif