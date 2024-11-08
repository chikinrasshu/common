#pragma once

#include <functional>

namespace chk {

template <typename Signature> using Function = std::function<Signature>;

} // namespace chk
