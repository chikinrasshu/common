#pragma once

#include <memory>

namespace chk {

template <typename T, class Dp = std::default_delete<T>>
using UniquePtr                       = std::unique_ptr<T, Dp>;
template <typename T> using SharedPtr = std::shared_ptr<T>;

} // namespace chk
