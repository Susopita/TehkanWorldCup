#include "../../include/utility/iomap.hpp"

#include <iostream>

namespace TWC::Utility
{
    template <class... T>
    void printf(const std::format_string<T...> &format, T &&...args)
    {
        std::cout << std::format(format, std::forward<T>(args)...);
    }
}