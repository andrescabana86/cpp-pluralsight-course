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

struct PersonBMIComparison
{
    bool bmi;
    std::string name;
};

void printv(std::vector<PersonBMI> & v) {
    if(v.empty()) return;
    for(PersonBMI &i : v) std::cout << i.name << ": bmi  " << i.bmi << " " << std::endl;
    std::cout << std::endl;
}

void printv(std::vector<PersonBMIComparison> & v) {
    if(v.empty()) return;
    for(PersonBMIComparison &i : v) std::cout << i.name << ": bmi is different?  " << (i.bmi ? "true" : "false") << " " << std::endl;
    std::cout << std::endl;
}

// print a simple message
void message(const char * s) { std::cout << s << std::endl; }
void message(const char * s, const int n) { std::cout << s << ": " << n << std::endl; }

int main()
{

    message("Unary operator mode");
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

    message("Binary operator mode, compare two people array");
    const std::array<Person, 5> people_past
    {{
             { 1.7f, 58.2f, 21, "Andres" },
             { 1.6f, 70.1f, 31, "Jose" },
             { 1.5f, 68.2f, 28, "Bruno" },
             { 1.4f, 63.5f, 24, "Julian" },
             { 1.9f, 61.7f, 21, "Marco" }
     }};
    // comparing if bmi in the past are same
    std::vector<PersonBMIComparison> peopleBMIComparison;
    std::transform(
        std::begin(people),
        std::end(people),
        std::begin(people_past),
        std::back_inserter(peopleBMIComparison),
        [](auto const& person, auto const& person_past)
        {
            PersonBMI present {
                person.weight/(person.height*person.height),
                person.name
            };

            PersonBMI past {
                    person_past.weight/(person_past.height*person_past.height),
                    person_past.name
            };

            return PersonBMIComparison{
                .bmi = present.bmi > past.bmi ? true : false,
                .name = present.name
            };
        });

        message("final vector size: ", peopleBMIComparison.size());
        message("vector:");
        printv(peopleBMIComparison);

    return 0;
}