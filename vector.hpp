#pragma once

#include <utility>
#include <type_traits>
#include <iostream>

// template<typename T, typename A>
// concept Multiplicable = requires (T a, A b)
// {
//     a * b;
// };

template <typename Value_Type, unsigned int N>
class Vector
{
public:
    Vector();
    template <typename... ValueList>
    Vector(ValueList... values);

    template <typename Other_Type>
    auto operator+(Vector<Other_Type, N> const &rhs) -> Vector<decltype(std::declval<Value_Type>() + std::declval<Other_Type>()), N>;

    Value_Type scalar(size_t const& index) const;

    // template <typename Scalar>
    // auto operator*(Scalar const& scalar) requires(Multiplicable<Value_Type, Scalar>);

    template <typename Scalar>
    auto operator*(Scalar const& scalar) -> Vector<decltype(std::declval<Value_Type>() * std::declval<Scalar>()), N>;

    unsigned int size() const;
private:
    Value_Type scalars[N];
};

#include "vector.tpp"




