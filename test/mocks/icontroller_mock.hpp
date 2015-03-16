#ifndef ICONTROLER_MOCK_HPP
#define ICONTROLER_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/icontroller.hpp"

namespace tetris {
namespace ut {
namespace mocks {

template<typename TEvent>
class icontroller_mock : public icontroller<TEvent>
{
public:
    virtual ~icontroller_mock() {}
    MOCK_CONST_METHOD0(is_active, bool());
    MOCK_METHOD0(start, void());
    MOCK_METHOD1_T(process_event, void(const TEvent&));
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif