#include "vector.hpp"

#include <iostream>



struct Bar
{
public:
    int x = 0;
};

class Foo
{
public:
    Foo() = default;
    Foo(int x)
        : x(x)
    {}

    friend Bar operator*(Foo const& lhs, int val)
    {
        Bar foo{};
        foo.x = lhs.x;

        foo.x *= val;

        return foo;
    }
    int x;
};

int main()
{
    Vector<int, 4> vec{1, 2, 3, 4};
    Vector<double, 4> vec2{2.0, 3.0, 4.0, 5.0};

    auto result = vec + vec;

    std::cout << "Result type is: " << result.scalar(2) << std::endl;

    return 0;
}