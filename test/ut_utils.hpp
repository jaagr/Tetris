#ifndef UT_UTILS_HPP
#define UT_UTILS_HPP

#include <gmock/gmock.h>
#include <memory>

namespace tetris{
namespace ut{

namespace GT = ::testing;

template<typename T>
auto create_mock()
{
    return std::make_shared<GT::StrictMock<T>>();
}

} // namespace ut
} // namespace tetris

#endif