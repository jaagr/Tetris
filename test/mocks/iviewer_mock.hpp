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
    MOCK_METHOD0(render, void());
    MOCK_METHOD1(show_time, void(time_tick));
    MOCK_METHOD1(show_board, void(const std::vector<std::vector<bool>>&));
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif