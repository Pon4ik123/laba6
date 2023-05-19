#include "car.h"

void menu() {
    cout << "1. Create people\n2. Show created person\n3. Add person\n4. Delete person\n5. Edit person\n6. Find person by his first name's letter\n7. Create cars\n8. Show cars\n9. Add one\n10. Delete one car\n11. Edit one car\n12. Find car by his first name's letter\n13. Buy car\n14. Open car\n15. Exit\n";
}

size_t random(size_t number1, size_t number2) {
    random_device rd;
    default_random_engine dfe(rd());
    uniform_int_distribution<size_t> numberDist(number1, number2);
    return numberDist(dfe);
}

void random(Person* person) {
    random_device rd;
    default_random_engine dfe(rd());
    string sPerson[] = { "Lukash", "Anna", "James", "Igor", "Konrad", "Michal", "Tomas", "Marcin", "Kamil" };
    uniform_int_distribution<size_t> ageDist(10, 90);
    uniform_int_distribution<size_t> peselDist(10000000, 999999999);

    person->setAge(ageDist(dfe));
    person->setPesel(peselDist(dfe));
    person->setName(sPerson[dfe() % (sizeof(sPerson) / sizeof(string))]);
}

void create(Person**& person, const size_t size) {
    person = new Person * [size];
    for (size_t i = 0; i < size; i++) {
        person[i] = new Person;
        random(person[i]);
    }
    cout << "Person with data was created" << endl;
}

void show(Person** person, const size_t size) {
    cout << "========== Person ==========\n" << endl;
    for (size_t i = 0; i < size; i++) {
        cout << "Name: " << person[i]->getName() << endl;
        cout << "Age: " << person[i]->getAge() << endl;
        cout << "PESEL: " << person[i]->getPesel() << endl;
        if (person[i]->getKey() != 0) {
            cout << "Key: " << person[i]->getKey() << endl;
        }
        else {
            cout << "This person doesn't have car" << endl;
        }
        cout << "\n";
    }
    cout << "======================" << endl;
}

void add(Person**& person, size_t& size) {
    Person** temp = new Person * [size + 1];
    if (size == 0) {
        temp[size] = new Person;
    }
    else {
        for (size_t i = 0; i < size; ++i) {
            temp[i] = person[i];
        }
        temp[size] = new Person;
        random(temp[size]);
        delete[] person;
        person = temp;
        ++size;
        cout << "The person was added" << endl;
    }
}

void delete_(Person**& person, size_t& size, size_t index) {
    --index;
    Person** temp = new Person * [size - 1];
    short int j = -1;
    cout << "========== Person ==========" << endl;
    if (index < size) {
        for (size_t i = 0; i < size; ++i) {
            if (i != index) {
                ++j;
                temp[j] = person[i];
            }
        }
        cout << index + 1 << " person was deleted" << endl;
        cout << "======================" << endl;
        delete[] person;
        person = temp;
        --size;
    }
    else {
        cout << "ERROE: Index is wrong!" << endl;
    }
}

void edit(Person** person, const size_t size, const size_t index) {
    string name, age, pesel;
    if (index <= size && index != 0) {
        cin.ignore();
        cout << "Type new name, age and PESEL over SPACE-BAR: ";
        getline(cin, name, ' ');
        getline(cin, age, ' ');
        getline(cin, pesel);
        person[index - 1]->setName(name);
        person[index - 1]->setAge(atoi(age.c_str()));
        person[index - 1]->setPesel(atoi(pesel.c_str()));
    }
}

void find(Person** const person, const size_t size) {
    char ch{};
    cout << "Enter a letter: ";
    cin >> ch;
    if (islower(ch)) {
        ch = toupper(ch);
    }
    cout << "========== Person ==========\n" << endl;
    for (size_t i = 0; i < size; i++) {
        if (!(person[i]->getName().find_first_of(ch))) {
            cout << "Name: " << person[i]->getName() << endl;
            cout << "Age: " << person[i]->getAge() << endl;
            cout << "PESEL: " << person[i]->getPesel() << endl;
            cout << "\n";
        }
    }
    cout << "======================" << endl;
}

void create(Manufacturer**& manufacturer, const size_t size) {
    manufacturer = new Manufacturer * [size];
    for (size_t i = 0; i < size; i++) {
        manufacturer[i] = new Manufacturer;
        int number;
        cout << "Enter the number of manufacturers for car " << i + 1 << ": ";
        cin >> number;
        manufacturer[i]->setNumberOfCars(number);
        manufacturer[i]->random();
    }
    cout << "Cars with data were created" << endl;

    ofstream file("test1.txt");
    if (file.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                file << manufacturer[i][j];
                break;
            }
        }
    }
    file.close();
}

void show(Manufacturer** manufacturer, const size_t size) {
    cout << "========== Cars ==========" << endl;
    cout << "Manufacturer\t" << "Speed\t" << "Year" << endl;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            //manufacturer[i][j].print();
            cout << manufacturer[i][j];
            break;
        }

    }
    cout << "======================" << endl;
}

void move_to_file() {
    ofstream input("test2.txt");
    ifstream output("test1.txt");

    string line;
    if (input.is_open() && output.is_open()) {
        while (getline(output, line))
            input << line << endl;
    }

    input.close();
    output.close();
}

void read_from_file(Manufacturer**& manufacturer, const size_t size) {
    ifstream input("test2.txt");
    if (input.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                input >> manufacturer[i][j];
                break;
            }
        }
    }
    input.close();
}

void add(Manufacturer**& manufacturer, size_t& size) {
    Manufacturer** temp = new Manufacturer * [size + 1];
    for (size_t i = 0; i < size; i++) {
        temp[i] = manufacturer[i];
    }
    temp[size] = new Manufacturer;
    int number;
    cout << "Enter the number of manufacturers for the new car: ";
    cin >> number;
    temp[size]->setNumberOfCars(number);
    temp[size]->random();
    size++;
    delete[] manufacturer;
    manufacturer = temp;
    cout << "New car with data was added" << endl;
}

void delete_(Manufacturer**& manufacturer, size_t& size) {
    if (size == 0) {
        cout << "No cars to delete" << endl;
        return;
    }
    int index;
    cout << "Enter the index of the car to delete (1-" << size << "): ";
    cin >> index;
    if (index < 1 || index > size) {
        cout << "Invalid index" << endl;
        return;
    }
    index--;
    delete manufacturer[index];
    for (size_t i = index; i < size - 1; i++) {
        manufacturer[i] = manufacturer[i + 1];
    }
    size--;
    Manufacturer** temp = new Manufacturer * [size];
    for (size_t i = 0; i < size; i++) {
        temp[i] = manufacturer[i];
    }
    delete[] manufacturer;
    manufacturer = temp;
    cout << "Car was deleted" << endl;
}

void edit(Manufacturer** manufacturer, const size_t size, const size_t index) {
    string year, speed;
    if (index >= 1 && index <= size) {
        int manufacturerIndex;
        cout << "Enter the manufacturer index you want to edit (1-" << manufacturer[index - 1]->getNumberOfCars() << "): ";
        cin >> manufacturerIndex;
        if (manufacturerIndex >= 1 && manufacturerIndex <= manufacturer[index - 1]->getNumberOfCars()) {
            cin.ignore();
            cout << "Enter the new manufacturer, new year and new speed over SPACE-BAR: ";
            string manuf;
            getline(cin, manuf, ' ');
            getline(cin, year, ' ');
            getline(cin, speed);
            manufacturer[index - 1]->getCarByIndex(manufacturerIndex - 1)->setManuf(manuf);
            manufacturer[index - 1]->getCarByIndex(manufacturerIndex - 1)->setYear(atoi(year.c_str()));
            manufacturer[index - 1]->getCarByIndex(manufacturerIndex - 1)->setSpeed(atoi(speed.c_str()));
            cout << "Manufacturer edited successfully!" << endl;
        }
        else {
            cout << "Invalid manufacturer index!" << endl;
        }
    }
    else {
        cout << "Invalid car index!" << endl;
    }
}

void find(Manufacturer** manufacturer, const size_t size) {
    char ch{};
    cout << "Enter a letter: ";
    cin >> ch;
    if (islower(ch)) {
        ch = toupper(ch);
    }
    cout << "========== Cars ==========" << endl;
    cout << "Manufacturer\t" << "Speed\t" << "Year" << endl;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < manufacturer[i]->getNumberOfCars(); j++) {
            string manuf = manufacturer[i]->getCarByIndex(j)->getManuf();
            if (manuf.find(ch) != string::npos) {
                cout << j + 1 << ". " << manuf << "\t" << manufacturer[i]->getCarByIndex(j)->getSpeed()
                     << "\t" << manufacturer[i]->getCarByIndex(j)->getYear() << endl;
            }
        }
    }
    cout << "======================" << endl;
}

void buyCar(Manufacturer** manufacturer, Person** person, const size_t size) {
    int a, b, c;
    show(person, size);
    cout << "Which person would like to buy car?: ";
    cin >> a;
    show(manufacturer, size);
    cout << "Choose number of car in this list?: ";
    cin >> b;
    cout << "Choose manuf";
    cin >> c;
    if (manufacturer[b - 1]->getCarByIndex(c - 1)->getEtap() == false) {
        cout << "This person bought this car" << endl;
        person[a - 1]->setKey(manufacturer[b - 1]->getCarByIndex(c - 1)->getKey());
        manufacturer[b - 1]->getCarByIndex(c - 1)->setEtap(true);
    }
    else {
        cout << "Sorry, but this car is already sold" << endl;
    }
}

void openCar(Manufacturer** manufacturer, Person** person, const size_t size) {
    int a, b;
    show(person, size);
    cout << "Which person would like to buy choose?: ";
    cin >> a;
    if (person[a - 1]->getKey() != 0) {
        cout << "Enter your KEY: ";
        cin >> b;
        if (b == person[a - 1]->getKey()) {
            cout << "Car is open" << endl;
        }
        else {
            cout << "Car will be exploude now, by-by" << endl;
        }
    }
    else {
        cout << "he is a poor man, don't touch him, run away..." << endl;
    }
}