#include "vector.hpp"

#include <concepts>

template <typename Value_Type, unsigned int N>
Vector<Value_Type, N>::Vector()
    : scalars{}
{
}

template <typename Value_Type, unsigned int N>
template <typename Other_Type>
auto Vector<Value_Type, N>::operator+(Vector<Other_Type, N> const &rhs) 
    -> Vector<decltype(std::declval<Value_Type>() + std::declval<Other_Type>()), N>
{
    Vector<Value_Type, N> vec {};
    
    for (size_t i{0}; i < size(); ++i)
    {
        vec.scalars[i] = scalar(i) + rhs.scalar(i);
    }
    return vec;
}

template <typename Value_Type, unsigned int N>
Value_Type Vector<Value_Type, N>::scalar(size_t const &index) const
{
    return scalars[index];
}

template <typename Value_Type, unsigned int N>
unsigned int Vector<Value_Type, N>::size() const
{
    return N;
}

template <typename Value_Type, unsigned int N>
template <typename... ValueList>
Vector<Value_Type, N>::Vector(ValueList... values)
    : scalars{values...}
{
    static_assert((std::is_same<Value_Type, ValueList>::value && ...) == true);
    // static_assert(sizeof...(values) == N);
    // for (auto const& val: scalars)
    // {
    //     std::cout << val << std::endl;
    // }
}

template <typename Value_Type, unsigned int N>
template <typename Scalar>
auto Vector<Value_Type, N>::operator*(Scalar const& scalar) 
    -> Vector<decltype(std::declval<Value_Type>() * std::declval<Scalar>()), N>
{
    using Return_Type = decltype(std::declval<Value_Type>() * std::declval<Scalar>());
    Vector<Return_Type, N> res{};
    for (size_t i{}; i < size(); ++i)
    {
        res.scalar(i) = scalars[i] * scalar;
        // std::cout << res.scalars[i] << " " << scalars[i] * scalar << std::endl;
    }
    return res;
}

// template <typename Value_Type, unsigned int N>
// template <typename Scalar>
// auto Vector<Value_Type, N>::operator*(Scalar const& scalar) requires(Multiplicable<Value_Type, Scalar>)
// {
//     using Return_Type = decltype(std::declval<Value_Type>() * std::declval<Scalar>());
//     Vector<Return_Type, N> res{};
//     for (size_t i{}; i < size(); ++i)
//     {
//         res.scalars[i] = scalars[i] * scalar;
//         std::cout << res.scalars[i] << " " << scalars[i] * scalar << std::endl;
//     }
//     return res;
// }
