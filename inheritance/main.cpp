#include <iostream>

class Entity
{
public:
    float X, Y;

    Entity(float x, float y)
    {
        X = x;
        Y = y;
    }

    void Move(float x, float y)
    {
        X += x;
        Y += y;
    }
};

class Player : public Entity
{
public:
    const char* Name;

    Player() : Entity(0.0, 0.0), Name("Player") {}

    Player(float x, float y) : Entity(x,y), Name("Player") {}


    void PrintName()
    {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Position: " << "X=>" << X << ", Y=>" << Y << std::endl;
    }
};

int main()
{
    Player p1(2.1,3.2);
    p1.PrintName();

    Player p2;
    p2.PrintName();

    return 0;
}