#pragma once

#include <chk/common/source_loc.hpp>
#include <chk/common/string.hpp>
#include <chk/common/types.hpp>

#include <format>
#include <type_traits>
#include <utility>

namespace chk::log {

enum class Severity { Debug, Trace, Info, Warning, Error, Fatal };

template <typename... Args> class FormatString {
  public:
    consteval FormatString(const char *msg)
        : FormatString(std::format_string<Args...>(msg)) {}
    consteval FormatString(const std::format_string<Args...> msg)
        : _msg(msg), _loc(chk::SourceLoc::current()) {}

    constexpr auto msg() const { return _msg; }
    constexpr auto loc() const { return _loc; }

  private:
    std::format_string<Args...> _msg;
    chk::SourceLoc              _loc;
};

namespace impl {

void vlog(StringView base, chk::log::Severity sev, chk::StringView msg,
          const chk::SourceLoc &loc);

template <class... Args>
void log(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
         chk::log::Severity sev, Args &&...args) {
#ifdef CHK_PROJECT_BASE
    auto base = CHK_PROJECT_BASE;
#else
    auto base = "/";
#endif
    auto formatted = std::format(msg.msg(), std::forward<Args>(args)...);
    chk::log::impl::vlog(base, sev, formatted, msg.loc());
}

} // namespace impl

template <class... Args>
void debug(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
           Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Debug,
                        std::forward<Args>(args)...);
}

template <class... Args>
void trace(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
           Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Trace,
                        std::forward<Args>(args)...);
}

template <class... Args>
void info(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
          Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Info,
                        std::forward<Args>(args)...);
}

template <class... Args>
void warn(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
          Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Warning,
                        std::forward<Args>(args)...);
}

template <class... Args>
void error(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
           Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Error,
                        std::forward<Args>(args)...);
}

template <class... Args>
void fatal(const chk::log::FormatString<std::type_identity_t<Args>...> &msg,
           Args &&...args) {
    chk::log::impl::log(msg, chk::log::Severity::Fatal,
                        std::forward<Args>(args)...);
}

} // namespace chk::log
