#include "chk/common/error.hpp"
#include <chk/common/logging.hpp>

int main(int argc, char *argv[]) {
    chk::log::info("Testing logging... {}", 420);
    chk::log::warn("... {}!", 69);

    try {
        throw chk::Error("Testing an error");
    } catch (const chk::Error &e) { chk::log::error("{}", e.what()); }

    return 0;
}
