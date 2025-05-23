#pragma once

#include <iostream>



// SHARED PTR
template<typename T>
using Ref = std::shared_ptr<T>;

template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

// UNIQUE PTR
template<typename T>
using Scope = std::unique_ptr<T>;

template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

// Relatively safe cast for interface -> override (example : Instance.Cast<MyOverrideTypeInstance>())
template<typename T>
class RefCast : std::enable_shared_from_this<T>
{
public:
    template<typename U>
    Ref<U> Cast() 
    {
        return std::dynamic_pointer_cast<U>(this->shared_from_this());
    }
};
