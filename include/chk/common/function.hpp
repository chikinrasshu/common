#pragma once

#include <functional>

namespace chk {

template<class T> using Function = std::function<T>;
using Callback = Function<void()>;

} // namespace chk
