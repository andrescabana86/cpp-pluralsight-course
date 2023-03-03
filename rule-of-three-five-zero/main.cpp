//
// Created by andrescabana86 on 2/3/2023.
//
#include <iostream>
#include <cstring>
#include <utility>

/**
 * Rule of Three
 *
 * If a class requires a user-defined destructor, a user-defined copy constructor,
 * or a user-defined copy assignment operator, it almost certainly requires all three.
 *
 * Because C++ copies and copy-assigns objects of user-defined types in various situations
 * (passing/returning by value, manipulating a container, etc), these special member functions
 * will be called, if accessible, and if they are not user-defined, they are implicitly-defined by the compiler.
 *
 * Classes that manage non-copyable resources through copyable handles may have to declare copy assignment and
 * copy constructor private and not provide their definitions or define them as deleted. This is another application
 * of the rule of three: deleting one and leaving the other to be implicitly-defined will most likely result in errors.
 */

class RuleOfThree
{
    char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block

    RuleOfThree(const char* s, std::size_t n) // to avoid counting twice
            : cstring(new char[n]) // allocate
    {
        std::memcpy(cstring, s, n); // populate
    }
public:
    RuleOfThree(const char* s = "")
            : RuleOfThree(s, std::strlen(s) + 1) {}

    ~RuleOfThree() // destructor
    {
        delete[] cstring; // deallocate
    }

    RuleOfThree(const RuleOfThree& other) // copy constructor
            : RuleOfThree(other.cstring) {}

    RuleOfThree& operator=(const RuleOfThree& other) // copy assignment
    {
        if (this == &other)
            return *this;

        std::size_t n{std::strlen(other.cstring) + 1};
        char* new_cstring = new char[n];            // allocate
        std::memcpy(new_cstring, other.cstring, n); // populate
        delete[] cstring;                           // deallocate

        cstring = new_cstring;
        return *this;
    }

    operator const char *() const // accessor
    {
        return cstring;
    }
};

/**
 * Rule of Five
 *
 * Because the presence of a user-defined (or = default or = delete declared) destructor, copy-constructor,
 * or copy-assignment operator prevents implicit definition of the move constructor and the move assignment operator,
 * any class for which move semantics are desirable, has to declare all five special member functions:
 *
 * Unlike Rule of Three, failing to provide move constructor and move assignment is usually not an error,
 * but a missed optimization opportunity.
 */

class RuleOfFive
{
    char* cstring; // raw pointer used as a handle to a dynamically-allocated memory block
public:
    RuleOfFive(const char* s = "") : cstring(nullptr)
    {
        if (s)
        {
            std::size_t n = std::strlen(s) + 1;
            cstring = new char[n];      // allocate
            std::memcpy(cstring, s, n); // populate
        }
    }

    ~RuleOfFive()
    {
        delete[] cstring; // deallocate
    }

    RuleOfFive(const RuleOfFive& other) // copy constructor
            : RuleOfFive(other.cstring) {}

    RuleOfFive(RuleOfFive&& other) noexcept // move constructor
            : cstring(std::exchange(other.cstring, nullptr)) {}

    RuleOfFive& operator=(const RuleOfFive& other) // copy assignment
    {
        return *this = RuleOfFive(other);
    }

    RuleOfFive& operator=(RuleOfFive&& other) noexcept // move assignment
    {
        std::swap(cstring, other.cstring);
        return *this;
    }

    // alternatively, replace both assignment operators with
    //  RuleOfFive& operator=(RuleOfFive other) noexcept
    //  {
    //      std::swap(cstring, other.cstring);
    //      return *this;
    //  }
};

/**
 * Rule of Zero
 *
 * Classes that have custom destructors, copy/move constructors or copy/move assignment operators should deal
 * exclusively with ownership (which follows from the Single Responsibility Principle). Other classes should not
 * have custom destructors, copy/move constructors or copy/move assignment operators.
 * This rule also appears in the C++ Core Guidelines as: If you can avoid defining default operations, do.
 *
 * When a base class is intended for polymorphic use, its destructor may have to be declared public and virtual.
 * This blocks implicit moves (and deprecates implicit copies), and so the special member functions have
 * to be declared as defaulted.
 *
 * However, this makes the class prone to slicing, which is why polymorphic classes often define copy as deleted
 * (A polymorphic class should suppress public copy/move in C++ Core Guidelines), which leads to the
 * following generic wording for the Rule of Five:
 * If you define or =delete any default operation, define or =delete them all.
 */

class RuleOfZero
{
    std::string cppstring;
public:
    RuleOfZero(const std::string& arg) : cppstring(arg) {}
};

class BaseOfFiveDefaults
{
public:
    BaseOfFiveDefaults(const BaseOfFiveDefaults&) = default;
    BaseOfFiveDefaults(BaseOfFiveDefaults&&) = default;
    BaseOfFiveDefaults& operator=(const BaseOfFiveDefaults&) = default;
    BaseOfFiveDefaults& operator=(BaseOfFiveDefaults&&) = default;
    virtual ~BaseOfFiveDefaults() = default;
};

int main() {
    RuleOfThree o1{"abc"};
    std::cout << o1 << ' ';
    auto o2{ o1 }; // uses copy constructor
    std::cout << o2 << ' ';
    RuleOfThree o3("def");
    std::cout << o3 << ' ';
    o3 = o2; // uses copy assignment
    std::cout << o3 << ' ';


    return 0; // <- all destructors are called 'here'
}