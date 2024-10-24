#pragma once

#include <memory>

namespace chk {

template<class T, class DefDelete = std::default_delete<T>> using UniquePtr = std::unique_ptr<T, DefDelete>;
template<class T> using SharedPtr = std::shared_ptr<T>;
template<class T> using WeakPtr = std::weak_ptr<T>;

} // namespace chk
