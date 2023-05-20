#include "person.h"
#include <fstream>
#include <iomanip>


using namespace std;

size_t random(size_t number1, size_t number2);

class Manufacturer {
    class Model {
        friend class Manufacturer;
        bool etap = false;
        string manuf;
        int speed;
        int year;
        int key2;
    public:
        Model() : manuf("Default"), speed(0), year(0), key2(0) {}
        Model(string manuf, int speed, int year, int key) : manuf(manuf), speed(speed), year(year), key2(key) {}
        ~Model() {}

        string getManuf() const { return manuf; }
        int getSpeed() const { return speed; }
        int getYear() const { return year; }
        int getKey() const { return key2; }
        bool getEtap() const { return etap; }

        void setManuf(string s){
            this->manuf = s;
        }
        void setYear(size_t y){
            this->year = y;
        }
        void setSpeed(size_t s){
            this->speed = s;
        }
        void setKey(size_t s){
            this->key2 = s;
        }
        bool setEtap(bool et) { this->etap = et; }

        void print() const{
            cout << manuf << "\t" << speed << "\t" << year << "\n";
        }

    };

    size_t number_of_cars;
    Model** model{nullptr};

    class Car : public Model{
        string car_model;
    public:
        Car() : car_model("Default"), Model(){}
        Car(const string manuf, int speed, int year, int key, string cm) : Model(manuf, speed, year, key), car_model(cm) {}
        ~Car() {}

        string getCarModel() const { return car_model; }
        void setCarModel(string s) { car_model = s; }
    };
    class Motocycle : public Model{
        string moto_model;
    public:
        Motocycle(){}
        Motocycle(const string &manuf, int speed, int year, int key) : Model(manuf, speed, year, key) {}
        ~Motocycle() {}

        string getMotoModel() const { return moto_model; }
        void setMotoModel(string s) { moto_model = s; }
    };
public:
    Manufacturer() : number_of_cars{::random(1, 5)}, model{new Model*[number_of_cars]} {
        for (size_t i = 0; i < number_of_cars; i++){
            model[i] = new Model();
        }
    }
    Manufacturer(Manufacturer &manufacturer) : number_of_cars(manufacturer.number_of_cars){
        model = new Model * [number_of_cars];
        for (int i = 0; i < number_of_cars; i++){
            model[i] = new Model{*manufacturer.model[i]};
        }
    }
    ~Manufacturer() {
        if (model != nullptr){
            for (size_t i = 0; i < number_of_cars; i++){
                delete model[i];
            }
            delete[] model;
        }
    }
    Model* getCarByIndex(int i) const { return model[i]; }

    Manufacturer& operator= (const Manufacturer& other);
    friend istream& operator>>(istream& in, Manufacturer& manufacturer);
    friend ostream& operator<<(ostream&out, const Manufacturer& manufacturer);

    Model * operator[](const size_t index){
        return model[index];
    }

    size_t getNumberOfCars() const;
    void setNumberOfCars(int num);
    void random();

    void print(){
        for(size_t i = 0; i < number_of_cars; i++){
            model[i]->print();
        }
    }
};

void create(Manufacturer**& manufacturer, const size_t size);
void show(Manufacturer** manufacturer, const size_t size);
void move_to_file();
void read_from_file(Manufacturer**& manufacturer, const size_t size);
void add(Manufacturer**& manufacturer, size_t& size);
void delete_(Manufacturer**& manufacturer, size_t& size);
void edit(Manufacturer** manufacturer, const size_t size, const size_t index);
void find(Manufacturer** manufacturer, const size_t size);
void buyCar(Manufacturer** manufacturer, Person** person, const size_t size);
void openCar(Manufacturer** manufacturer, Person** person, const size_t size);