#pragma once

#include <iostream>

/**
 * @file Memory.hpp
 * @brief Provide easier usage of smart pointers.
 */


/**
* @brief A using for easier use of std::shared_ptr
*
* @tparam T Type of object 
*/
template<typename T>
using Ref = std::shared_ptr<T>;

/**
* @brief A using to create std::shared_ptr
* @tparam T Type of object
*/
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
    return std::make_shared<T>(std::forward<Args>(args)...);
}

/**
* @brief A using for easier use of std::unique_ptr
*
* @tparam T Type of object
*/
template<typename T>
using Scope = std::unique_ptr<T>;

/**
* @brief A using to create std::unique_ptr
* @tparam T Type of object
*/
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

/**
* @class RefCast
*/
template<typename T>
class RefCast : public std::enable_shared_from_this<T>
{
public:
    virtual ~RefCast() = default;

    template<typename U>
    Ref<U> Cast()
    {
        return std::dynamic_pointer_cast<U>(this->shared_from_this());
    }
};
