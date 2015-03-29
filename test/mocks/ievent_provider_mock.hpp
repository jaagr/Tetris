#ifndef IEVENT_PROVIDER_MOCK_HPP
#define IEVENT_PROVIDER_MOCK_HPP

#include <gmock/gmock.h>
#include "interfaces/ievent_provider.hpp"

namespace tetris {
namespace ut {
namespace mocks {

template<typename TEvent>
class ievent_provider_mock : public ievent_provider<TEvent>
{
public:
    virtual ~ievent_provider_mock() {}
    MOCK_METHOD1_T(poll_event, bool(TEvent&));
};

} // namespace mocks
} // namespace ut
} // namespace tetris

#endif