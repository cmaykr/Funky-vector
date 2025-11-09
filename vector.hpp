#pragma once

#include <utility>
#include <type_traits>
#include <iostream>

// template<typename T, typename A>
// concept Multiplicable = requires (T a, A b)
// {
//     a * b;
// };

template <typename Value_Type, typename Other_Type>
using Return_Type_Addition = decltype(std::declval<Value_Type>() + std::declval<Other_Type>());

template <typename Value_Type, typename Scalar>
using Return_Type_Multiplication = decltype(std::declval<Value_Type>() * std::declval<Scalar>());

template <typename Value_Type, unsigned int N>
class Vector
{
public:
    Vector();
    template <typename... ValueList>
    Vector(ValueList... values);

    template <typename Other_Type>
    auto operator+(Vector<Other_Type, N> const &rhs) -> Vector<Return_Type_Addition<Value_Type, Other_Type>, N>;

    // template <typename Scalar>
    // auto operator*(Scalar const& scalar) requires(Multiplicable<Value_Type, Scalar>);

    template <typename Scalar>
    auto operator*(Scalar const& scalar) -> Vector<Return_Type_Multiplication<Value_Type, Scalar>, N>;

    Value_Type& operator[](size_t idx);
    const Value_Type& operator[](size_t idx) const;

    unsigned int size() const;
private:
    Value_Type scalars[N];
};

#include "vector.tpp"




