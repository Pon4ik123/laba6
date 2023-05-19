#include "car.h"

Manufacturer &Manufacturer::operator=(const Manufacturer &other) {
    if (this->model != nullptr) {
        for (int i = 0; i < number_of_cars; i++) {
            delete this->model[i];
        }
        delete[] this->model;

        this->model = new Model *[number_of_cars];
        for (int i = 0; i < number_of_cars; i++) {
            this->model[i] = new Model;
            model[i] = other.model[i];
        }
    }
    return *this;
}

istream &operator>>(istream &in, Manufacturer &manufacturer) {
    string manuf, speed, year, key;
//    in >> car.number;

    for (int i = 0; i < manufacturer.number_of_cars; i++) {
        getline(in, manuf, '\t');
        getline(in, speed, '\t');
        getline(in, year, '\t');
        getline(in, key);

        manufacturer.model[i]->setManuf(manuf);
        manufacturer.model[i]->setSpeed(atoi(speed.c_str()));
        manufacturer.model[i]->setYear(atoi(year.c_str()));
        manufacturer.model[i]->setKey(atoi(key.c_str()));


    }
    return in;
}

ostream &operator<<(ostream &out, const Manufacturer &manufacturer) {
    for (size_t j = 0; j < manufacturer.getNumberOfCars(); ++j) {
        out << left << setw(17) << manufacturer.model[j]->getManuf();
        out << left << setw(7) << manufacturer.model[j]->getSpeed();
        out << left << setw(7) << manufacturer.model[j]->getYear();
        out << left << setw(7) << manufacturer.model[j]->getKey() << endl;
    }

    return out;
}
//<< left << setw(17)
//<< left << setw(7)
//<< left << setw(7)
//<< left << setw(7)

size_t Manufacturer::getNumberOfCars() const { return number_of_cars; }

void Manufacturer::setNumberOfCars(int num) { this->number_of_cars = num; }

void Manufacturer::random() {
    random_device rd;
    default_random_engine dfe(rd());
    string manufacturers[] = {"Mazda", "Toyota", "Honda", "Chevrolet", "Volkswagen"};
    uniform_int_distribution<int> speedDist(220, 300);
    uniform_int_distribution<int> yearDist(1999, 2020);
    uniform_int_distribution<int> keyDist(1000, 9999);
    for (int i = 0; i < number_of_cars; i++) {
        string manuf = manufacturers[dfe() % (sizeof(manufacturers) / sizeof(string))];
        int speed = speedDist(dfe);
        int year = yearDist(dfe);
        int key = keyDist(dfe);
        model[i] = new Model(manuf, speed, year, key);
    }
}