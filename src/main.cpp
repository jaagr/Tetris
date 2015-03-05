#include "controller.hpp"
#include "board.hpp"
#include <boost/di.hpp>

namespace di = boost::di;

int main() {
    auto sm = di::make_injector(di::bind<tetris::iboard, tetris::board>).create<tetris::controller>();
    return 0;
}