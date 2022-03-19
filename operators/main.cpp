#include <iostream>

/*
 * Operators are just functions, they help on having clean and readable code
 * We can overload operators to simplify code
 */

struct CustomVector
{
    float x, y;

    CustomVector(float x, float y)
        : x(x), y(y) {}

    CustomVector operator+(const CustomVector& value) const
    {
        return CustomVector(x + value.x, y + value.y);
    }

    CustomVector operator*(const CustomVector& value) const
    {
        return CustomVector(x * value.x, y * value.y);
    }

    bool operator==(const CustomVector& value)
    {
        return x == value.x && y == value.y;
    }

    bool operator!=(const CustomVector& value)
    {
        return !(*this == value);
    }
};
int main()
{
    CustomVector position(4.0f, 5.0f);
    CustomVector speed(1.0f, 1.0f);
    CustomVector power(1.0f, 1.0f);

    CustomVector result = position + (speed * power);

    if (result == position) {
        std::cout << "result never changed!" << std::endl;
    } else if (result != position) {
        std::cout << "result is different, value has moved!" << std::endl;
    }

    return 0;
}