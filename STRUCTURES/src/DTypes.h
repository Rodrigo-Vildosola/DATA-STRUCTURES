#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;

    Person() : name(""), age(0) {}
    Person(std::string initial_name, int initial_age) : name(initial_name), age(initial_age) {}

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }

    bool operator!=(const Person& other) const {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << " (" << person.age << ")";
    return os;
}
