#include "vector.hpp"

#include <iostream>

using namespace std;

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
    Vector<double, 4> vec2{2.5, 3.0, 4.0, 5.0};

    auto result = vec + vec2;

    for (size_t i{}; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}