#pragma once

#include <chk/common/types.hpp>

#include <string>
#include <string_view>

namespace chk {

template<class T, class Traits = std::char_traits<T>, class Alloc = std::allocator<T>> using TString = std::basic_string<T, Traits, Alloc>;
template<class T, class Traits = std::char_traits<T>> using TStringView = std::basic_string_view<T, Traits>;

using String = TString<Char>;
using StringView = TStringView<Char>;

using WString = TString<WChar>;
using WStringView = TStringView<WChar>;

} // namespace chk
