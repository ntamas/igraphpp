#pragma once

#include <memory>

namespace igraph {

template <class T>
struct AllocationGuard {
    AllocationGuard() = delete;
    AllocationGuard(AllocationGuard const&) = delete;
    AllocationGuard& operator=(AllocationGuard const&) = delete;

    AllocationGuard(T&& func) noexcept : _func(std::forward<T>(func)), _active(true) {}
    AllocationGuard(AllocationGuard&& other) noexcept(std::is_nothrow_move_constructible<T>::value)
        : _func(std::move_if_noexcept(other._func)), _active(other._active) {
      other.cancel();
    }

    bool active() const noexcept { return _active; }
    void cancel() noexcept { _active = false; }
    void fire() noexcept {
        if (active()) {
            _active = false;
            try {
                _func();
            } catch (...) {
            }
        }
    }

    ~AllocationGuard() noexcept {
        fire();
    }

private:
	T _func;
    bool _active;
};

} // namespace igraph
