#include <chk/common/logging.hpp>

#include <cstdio>
#include <cstdlib>
#include <filesystem>

namespace chk::log::impl {

void vlog(StringView base, chk::log::Severity sev, chk::StringView msg,
          const chk::SourceLoc &loc) {
    StringView sev_name = "";
    switch (sev) {
    case chk::log::Severity::Debug: sev_name = "\x1b[2mDebug\x1b[0m"; break;
    case chk::log::Severity::Trace: sev_name = "\x1b[1mTrace\x1b[0m"; break;
    case chk::log::Severity::Info: sev_name = "\x1b[36;1mInfo\x1b[0m"; break;
    case chk::log::Severity::Warning:
        sev_name = "\x1b[33;1mWarning\x1b[0m";
        break;
    case chk::log::Severity::Error: sev_name = "\x1b[31;1mError\x1b[0m"; break;
    case chk::log::Severity::Fatal: sev_name = "\x1b[31;1mFatal\x1b[0m"; break;
    }

    auto file = loc.file_name();
    auto line = loc.line();

    auto rel_file = std::filesystem::relative(file, base).string();

    fprintf(stderr, "[%.*s][\x1b[2m%s:%u\x1b[0m]: %.*s\n",
            static_cast<s32>(sev_name.length()), sev_name.data(),
            rel_file.c_str(), static_cast<u32>(line),
            static_cast<s32>(msg.length()), msg.data());

    if (sev == chk::log::Severity::Fatal) { std::exit(1); }
}

} // namespace chk::log::impl
