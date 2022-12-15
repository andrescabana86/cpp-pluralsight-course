#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <iostream>

struct Person
{
    float height;
    float weight;
    float age;
    std::string name;
};

struct PersonBMI
{
    float bmi;
    std::string name;
};

void printv(std::vector<PersonBMI> & v) {
    if(v.empty()) return;
    for(PersonBMI &i : v) std::cout << i.name << ": bmi  " << i.bmi << " " << std::endl;
    std::cout << std::endl;
}

// print a simple message
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s, const int n) { std::cout << s << ": " << n << std::endl; }

int main()
{
    const std::array<Person, 5> people
    {{
        { 1.7f, 60.2f, 24, "Andres" },
        { 1.6f, 70.1f, 34, "Jose" },
        { 1.5f, 58.2f, 32, "Bruno" },
        { 1.4f, 63.5f, 28, "Julian" },
        { 1.9f, 68.7f, 25, "Marco" }
    }};

    // transform array into vector calculating BMI
    std::vector<PersonBMI> peopleBMI;

    std::transform(
        std::begin(people),
        std::end(people),
        std::back_inserter(peopleBMI),
        [](auto const& person) // here the lambda, this could also be a class constructor or a functor
        {
            return PersonBMI
            {
                person.weight/(person.height*person.height),
                person.name
            };
        });

    message("final vector size: ", peopleBMI.size());
    message("vector:");
    printv(peopleBMI);

    return 0;
}