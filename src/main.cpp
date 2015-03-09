#include <boost/di.hpp>
#include "game.hpp"
#include "injector.hpp"

namespace di = boost::di;

int main() {
    auto injector = di::make_injector(tetris::injector());
    injector.create<tetris::game>().start();

    return 0;
}