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
* @brief A template class to make easier smart pointer cast
* @tparam T Type of object
*/
template<typename T>
/**
* @class RefCast
*/
class RefCast : std::enable_shared_from_this<T>
{
public:
    virtual ~RefCast() = default;
    /**
    * @tparam T Type of object to cast to
    */
    template<typename U>
    /**
    * @brief Cast the object to the desired type
    */
    Ref<U> Cast() 
    {
        return std::dynamic_pointer_cast<U>(this->shared_from_this());
    }
};
