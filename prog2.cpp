#include <bits/stdc++.h>
using namespace std;
class Car {
public:
        string brandName;
        string modelName;
        string launchDate;


   
    void inputCarDetails() {
        cout << "Enter Brand Name: ";
        cin >> brandName;
        
        cout << "Enter Model Name: ";
        cin >> modelName;

        cout << "Enter Launch Date (YYYY-MM-DD): ";
        cin >> launchDate;
    }

    
    void displayCarDetails() const {
        cout << "Brand: " << brandName << "\n"
             << "Model: " << modelName << "\n"
             << "Launch Date: " << launchDate << "\n";
    }
};

int main() {
    
    Car car1, car2, car3;

    std::cout << "Enter details for Car 1:\n";
    car1.inputCarDetails();

    std::cout << "\nEnter details for Car 2:\n";
    car2.inputCarDetails();

    std::cout << "\nEnter details for Car 3:\n";
    car3.inputCarDetails();

    // Displaying the details of each car
    std::cout << "\nDetails of Car 1:\n";
    car1.displayCarDetails();

    std::cout << "\nDetails of Car 2:\n";
    car2.displayCarDetails();

    std::cout << "\nDetails of Car 3:\n";
    car3.displayCarDetails();

    return 0;
}
