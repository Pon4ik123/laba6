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
        Model(Model& other) : manuf(other.manuf), speed(other.speed), year(other.year), key2(other.key2){}
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

        virtual void print() const{
            cout << left << setw(17) << manuf << left << setw(7) << speed << left << setw(7) << year << left << setw(7);
        }

//        Model& operator=(const Model& other){
//
//        }
    };

    size_t number_of_cars;
    //Model** model{nullptr};
    vector<Model* >model;

    class ElectricCar : public Model{
        int battery;
    public:
        ElectricCar() : battery(0), Model(){}
        ElectricCar(const string manuf, int speed, int year, int key, int cm) : Model(manuf, speed, year, key), battery(cm) {}
        ElectricCar(ElectricCar& other) : battery(other.battery), Model(other){}
        ~ElectricCar() {}

        int getCarModel() const { return battery; }
        void setCarModel(int s) { battery = s; }

        void print() const override{
            Model::print();
            cout << left << setw(7) << battery << endl;
        }
    };
    class GazCar : public Model{
        int gaz;
    public:
        GazCar() : gaz(0), Model(){}
        GazCar(const string manuf, int speed, int year, int key, int g) : Model(manuf, speed, year, key), gaz(g) {}
        GazCar(GazCar& other) : gaz(other.gaz), Model(other) {}
        ~GazCar() {}

        int getMotoModel() const { return gaz; }
        void setMotoModel(int s) { gaz = s; }

        void print() const override{
            Model::print();
            cout << left << setw(7) << gaz << endl;
        }
    };
public:
    Manufacturer() : number_of_cars{::random(1, 5)}, model{pu} {
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
    void setCarByIndex(Model *other, int index){
        model[index] = other;
    };

    Manufacturer& operator= (const Manufacturer& other);
    friend istream& operator>>(istream& in, Manufacturer& manufacturer);
    friend ostream& operator<<(ostream&out, const Manufacturer& manufacturer);

    Model * operator[](const size_t index){
        return model[index];
    }

    size_t getNumberOfCars() const;
    void setNumberOfCars(int num);
    static Model * random();

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