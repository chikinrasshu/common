#include <chk/common/logging.hpp>

int main(int argc, char *argv[]) {
    chk::log::info("XD {}", 420);
    chk::log::warn("... {}!", 69);

    return 0;
}
