#include <iostream>
#include <string>
#include <random>
#include <ctype.h>
#include <vector>

using namespace std;

size_t random(size_t number1, size_t number2);

class Person {
    string name;
    size_t age;
    size_t pesel;
    int key1;
public:
    Person() : name("Default"), age(0), pesel(0), key1(0) {}
    ~Person() {}

    string getName() const;
    size_t getAge() const;
    size_t getPesel() const;
    size_t getKey() const;

    void setName(string name);
    void setAge(size_t age);
    void setPesel(size_t pesel);
    void setKey(size_t key);

};

void menu();
void random(Person* person);
void create(Person**& person, const size_t size);
void show(Person** person, const size_t size);
void add(Person**& person, size_t& size);
void delete_(Person**& person, size_t& size, size_t index);
void edit(Person** person, const size_t size, const size_t index);
void find(Person** const person, const size_t size);