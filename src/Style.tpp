#include "../include/Style.hpp"

#include <iostream>

namespace TWC::Style
{
    template <class derived>
    void Representation<derived>::print(std::ostream &os) const
    {
        os << style.applyStyle(representation);
    }
    template <class U>
    std::ostream &operator<<(std::ostream &os, const Representation<U> &representation)
    {
        representation.print(os);
        return os;
    }

    template <class derived>
    derived &Representation<derived>::setStyle(const Style &style)
    {
        this->style = style;
        return static_cast<derived &>(*this);
    }

    template <class derived>
    derived &Representation<derived>::setRepresentation(const std::string &representation)
    {
        this->representation = representation;
        return static_cast<derived &>(*this);
    }

    template <class derived>
    void Representation<derived>::draw() const
    {
        std::cout << *this;
    }
};