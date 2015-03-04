#include "controller.hpp"

int main() {
    auto sm = boost::di::make_injector().create<tetris::controller>();
    return 0;
}