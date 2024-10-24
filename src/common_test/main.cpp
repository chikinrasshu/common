#include "chk/common/logging.hpp"
#include <chk/common/common.hpp>

int main(int argc, char* argv[]) {
    chk::log::dbg("This is a debug log");
    chk::log::trace("This is a trace log");
    chk::log::info("This is a info log");
    chk::log::warn("This is a warning log");
    chk::log::error("This is a error log");

    return 0;
}