#ifndef IWINDOW_MOCK_HPP
#define IWINDOW_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/iwindow.hpp"

namespace tetris {
namespace ut {
namespace mocks {
    
class iwindow_mock : public iwindow
{
public:
    virtual ~iwindow_mock() {}
    MOCK_METHOD0(clear_window, void());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif