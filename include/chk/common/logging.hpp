#pragma once

#include "spdlog/common.h"
#include "spdlog/fmt/bundled/core.h"
#include <chk/common/string.hpp>

#include <spdlog/spdlog.h>
// #include <type_traits>

#include <source_location>

namespace chk {
    namespace log {
        using SourceLoc = std::source_location;

        class FormatString {
        public:
            template<class S>
            FormatString(const S& str, const SourceLoc& loc = SourceLoc::current()) 
                : _str(str), _loc(loc) {}

            const StringView& str() const { return _str; }
            const SourceLoc& loc() const { return _loc; }

        private:
            StringView _str;
            SourceLoc _loc;
        };

        namespace impl { 
            template<typename ...Args> auto log(const FormatString& msg, spdlog::level::level_enum lvl, Args&& ...args) -> void {
                auto loc = spdlog::source_loc(msg.loc().file_name(), msg.loc().line(), msg.loc().function_name());
                auto fmt_msg = spdlog::fmt_lib::format(spdlog::fmt_lib::runtime(msg.str()), std::forward<Args>(args)...);
                spdlog::default_logger()->log(loc, lvl, fmt_msg);
            } 
        } // namespace impl

        template<typename ...Args>
        auto trace(const FormatString& msg, Args&& ...args) -> void { impl::log(msg, spdlog::level::trace, std::forward<Args>(args)...); }

        template<typename ...Args>
        auto info(const FormatString& msg, Args&& ...args) -> void { impl::log(msg, spdlog::level::info, std::forward<Args>(args)...); }

        template<typename ...Args>
        auto dbg(const FormatString& msg, Args&& ...args) -> void { impl::log(msg, spdlog::level::debug, std::forward<Args>(args)...); }

        template<typename ...Args>
        auto warn(const FormatString& msg, Args&& ...args) -> void { impl::log(msg, spdlog::level::warn, std::forward<Args>(args)...); }

        template<typename ...Args>
        auto error(const FormatString& msg, Args&& ...args) -> void { impl::log(msg, spdlog::level::err, std::forward<Args>(args)...); }
    } // namespace log
} // namespace chk
