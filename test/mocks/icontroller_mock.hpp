#ifndef ICONTROLER_MOCK_HPP
#define ICONTROLER_MOCK_HPP

#include <gmock/gmock.h>

#include "interfaces/icontroller.hpp"
#include "controller.hpp"

namespace tetris {
namespace ut {
namespace mocks {

class icontroller_mock : public icontroller<icontroller_mock>
{
public:
    virtual ~icontroller_mock() {}
    MOCK_METHOD0(is_active, bool());
    MOCK_METHOD0(start, void());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif