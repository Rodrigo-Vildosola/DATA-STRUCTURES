#include <gtest/gtest.h>
#include <Structs.h>
#include <DTypes.h>
#include <iostream>
#include <string>


// Functions for map and traverse
int increment_int(int value) {
    return value + 1;
}

double increment_double(double value) {
    return value + 1.0;
}

std::string add_exclamation(const std::string& value) {
    return value + "!";
}

Person increase_age(Person person) {
    person.age += 1;
    return person;
}

void print_element(int value) {
    std::cout << value << " ";
}

void print_element_double(double value) {
    std::cout << value << " ";
}

void print_element_string(const std::string& value) {
    std::cout << value << " ";
}

void print_element_person(const Person& person) {
    std::cout << person << " ";
}

TEST(ArrayTest, MapFunctionInt) {
    STRUCTS::Array<int> array;
    array.append(1);
    array.append(2);
    array.append(3);

    array.map(increment_int);

    EXPECT_EQ(array.get(0), 2);
    EXPECT_EQ(array.get(1), 3);
    EXPECT_EQ(array.get(2), 4);
}

TEST(ArrayTest, MapFunctionDouble) {
    STRUCTS::Array<double> array;
    array.append(1.1);
    array.append(2.2);
    array.append(3.3);

    array.map(increment_double);

    EXPECT_DOUBLE_EQ(array.get(0), 2.1);
    EXPECT_DOUBLE_EQ(array.get(1), 3.2);
    EXPECT_DOUBLE_EQ(array.get(2), 4.3);
}

TEST(ArrayTest, MapFunctionString) {
    STRUCTS::Array<std::string> array;
    array.append("Hello");
    array.append("World");

    array.map(add_exclamation);

    EXPECT_EQ(array.get(0), "Hello!");
    EXPECT_EQ(array.get(1), "World!");
}

TEST(ArrayTest, MapFunctionPerson) {
    STRUCTS::Array<Person> array;
    array.append(Person{"Alice", 30});
    array.append(Person{"Bob", 25});

    array.map(increase_age);

    EXPECT_EQ(array.get(0).age, 31);
    EXPECT_EQ(array.get(1).age, 26);
}

TEST(ArrayTest, TraverseFunctionInt) {
    STRUCTS::Array<int> array;
    array.append(1);
    array.append(2);
    array.append(3);

    testing::internal::CaptureStdout();
    array.traverse(print_element);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 ");
}

TEST(ArrayTest, TraverseFunctionDouble) {
    STRUCTS::Array<double> array;
    array.append(1.1);
    array.append(2.2);
    array.append(3.3);

    testing::internal::CaptureStdout();
    array.traverse(print_element_double);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1.1 2.2 3.3 ");
}

TEST(ArrayTest, TraverseFunctionString) {
    STRUCTS::Array<std::string> array;
    array.append("Hello");
    array.append("World");

    testing::internal::CaptureStdout();
    array.traverse(print_element_string);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Hello World ");
}

TEST(ArrayTest, TraverseFunctionPerson) {
    STRUCTS::Array<Person> array;
    array.append(Person{"Alice", 30});
    array.append(Person{"Bob", 25});

    testing::internal::CaptureStdout();
    array.traverse(print_element_person);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "Alice (30) Bob (25) ");
}
