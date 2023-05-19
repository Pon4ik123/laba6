#include "person.h"

string Person::getName() const { return name; }
size_t Person::getAge() const { return age; }
size_t Person::getPesel() const { return pesel; }
size_t Person::getKey() const { return key1; }

void Person::setName(string name) { this->name = name; }
void Person::setAge(size_t age) { this->age = age; }
void Person::setPesel(size_t pesel) { this->pesel = pesel; }
void Person::setKey(size_t key) { this->key1 = key; }