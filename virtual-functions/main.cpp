#include <iostream>

class Entity
{
public:
    virtual std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
public:
    std::string GetName() override { return "Player"; }
};

class Monster : public Entity
{
public:
    std::string GetName() override { return "Monster"; }
};

void PrintName(Entity* e1)
{
    std::cout << "Name: " << e1->GetName() << std::endl;
}

class Auditor
{
public:
    virtual std::string GetClassName() = 0;
};

class Vigilant : public Auditor
{
public:
    std::string GetClassName() override { return "Moderator"; }
};

void PrintClassName(Auditor* a1)
{
    std::cout << "Class Name: " << a1->GetClassName() << std::endl;
}

int main()
{
    /*
     * Virtual functions allows us to override functions across subclasses
     *
     * In this case, PrintName() parameter is type Entity, which means it will show:
     * - Name: Entity
     * - Name: Entity
     * - Name: Entity
     * because it is following the original implementation
     *
     * By adding the key 'virtual' before GetName() inside Entity class
     * we are allowing overrides ('override' keyword is for clean code purposes)
     * When 'virtual' is activated, it will show:
     * - Name: Entity
     * - Name: Player
     * - Name: Monster
     *
     * caveats:
     * * virtual functions create a vtable with pointers to address calls in runtime, which means more memory usage
     * * vtable is slower than no virtual implementation
     *
     * In both cases, we never found any big performance issue
     */
    Entity* e1 = new Entity();
    PrintName(e1);
    Player* p1 = new Player();
    PrintName(p1);
    Monster* m1 = new Monster();
    PrintName(m1);

    /*
     * Abstract classes are classes that implements virtual functions with no definitions (means = 0)
     * This means, every subclass must implement the virtual method
     */
    // Auditor* a1 = new Auditor(); // this cannot be instantiated since its an abstract class
    Vigilant* v1 = new Vigilant();
    PrintClassName(v1);

    return 0;
}