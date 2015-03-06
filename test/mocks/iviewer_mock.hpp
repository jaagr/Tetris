#ifndef IVIEWER_MOCK_HPP
#define IVIEWER_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/iviewer.hpp"

namespace tetris {
namespace ut {
namespace mocks {
    
class iviewer_mock : public iviewer
{
public:
    virtual ~iviewer_mock() {}
    MOCK_METHOD0(clear, void());
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif