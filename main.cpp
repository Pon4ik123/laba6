#include "car.h"

using namespace std;

int main() {
    int choice;
    size_t number_of_manufacturer = random(1, 10);
    size_t index;

    Person** person{ nullptr };
    Manufacturer** manufacturer{nullptr };

    do {
        menu();
        cout << "Make your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                create(person, number_of_manufacturer);
                break;
            case 2:
                show(person, number_of_manufacturer);
                break;
            case 3:
                add(person, number_of_manufacturer);
                break;
            case 4:
                cout << "Which one do you want to delete?: ";
                cin >> index;
                delete_(person, number_of_manufacturer, index);
                break;
            case 5:
                cout << "Which one do you want to edit?: ";
                cin >> index;
                edit(person, number_of_manufacturer, index);
                break;
            case 6:
                find(person, number_of_manufacturer);
                break;
            case 7:
                create(manufacturer, number_of_manufacturer);
                break;
            case 8:
                show(manufacturer, number_of_manufacturer);
                break;
            case 9:
                add(manufacturer, number_of_manufacturer);
                break;
            case 10:
                delete_(manufacturer, number_of_manufacturer);
                break;
            case 11:
                cout << "Which one do you want to change?: ";
                cin >> index;
                edit(manufacturer, number_of_manufacturer, index);
                break;
            case 12:
                find(manufacturer, number_of_manufacturer);
                break;
            case 13:
                buyCar(manufacturer, person, number_of_manufacturer);
                break;
            case 14:
                openCar(manufacturer, person, number_of_manufacturer);
                break;
            case 15:
                move_to_file();
                break;
            case 16:
                read_from_file(manufacturer, number_of_manufacturer);
            case 17:
                cout << "Thank you for visit, see you next time" << endl;
                break;
            default:
                cout << "Wrong choice, please try again" << endl;
                continue;
        }

    } while (choice != 17);



    return 0;
}