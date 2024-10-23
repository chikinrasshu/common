#pragma once

#include <vector>

namespace chk {

template<class T, class Alloc = std::allocator<T>> using List = std::vector<T, Alloc>;

} // namespace chk
