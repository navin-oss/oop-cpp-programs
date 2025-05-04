#include <iostream>
#include <vector>
using namespace std;

// Yo, this is the Vehicle class for cars, bikes, and trucks!
class Vehicle {
public:
    string id, brand, model, type;
    int year, doors, axles;
    double price_per_day, cargo_space;
    bool is_rented, has_sidecar;
    string fuel_type;

    // Constructor, let's set up a vehicle!
    Vehicle(string vid, string vtype, string vbrand, string vmodel, int vyear, double vprice,
            int vdoors = 0, string vfuel = "", bool vsidecar = false, double vcargo = 0, int vaxles = 0) {
        id = vid;
        type = vtype;
        brand = vbrand;
        model = vmodel;
        year = vyear;
        price_per_day = vprice;
        doors = vdoors;
        fuel_type = vfuel;
        has_sidecar = vsidecar;
        cargo_space = vcargo;
        axles = vaxles;
        is_rented = false;
    }

    // Calculate how much it'll cost to rent
    double getCost(int days) {
        if (type == "Car") {
            return price_per_day * days;
        }
        if (type == "Motorcycle") {
            return price_per_day * days + (has_sidecar ? 20 * days : 0); // Sidecar costs extra!
        }
        if (type == "Truck") {
            return price_per_day * days + cargo_space * 10 * days; // Bigger cargo, more cash
        }
        return 0; // Just in case something weird happens
    }

    // Show off the vehicle's details
    void display() {
        cout << id << ": " << year << " " << brand << " " << model << " (";
        if (is_rented) cout << "Rented)";
        else cout << "Ready to Roll!)";
        cout << "\nType: " << type << " | ?" << price_per_day << "/day\n";
        if (type == "Car") {
            cout << "Doors: " << doors << " | Fuel: " << fuel_type << "\n";
        }
        if (type == "Motorcycle") {
            cout << "Sidecar: " << (has_sidecar ? "Yup!" : "Nope") << "\n";
        }
        if (type == "Truck") {
            cout << "Cargo Space: " << cargo_space << "m³ | Axles: " << axles << "\n";
        }
    }
};

// This is the rental system, the main brain of the operation!
class RentalSystem {
    vector<Vehicle> vehicles; // List of all our sweet rides

public:
    // Add a new vehicle to the system
    void addVehicle(Vehicle v) {
        vehicles.push_back(v);
    }

    // Show all vehicles that aren't rented
    void showFreeVehicles() {
        cout << "\nCheck out these available rides!\n";
        for (auto v : vehicles) {
            if (!v.is_rented) {
                v.display();
                cout << "\n";
            }
        }
    }

    // Rent a vehicle, let's make some money!
    void rent(string vid, int days) {
        for (auto& v : vehicles) {
            if (v.id == vid) {
                if (v.is_rented) {
                    cout << "Oops, that one's already taken!\n";
                } else {
                    cout << "Total cost: ?" << v.getCost(days) << "\n";
                    v.is_rented = true;
                    cout << "Enjoy your ride!\n";
                }
                return;
            }
        }
        cout << "Uh-oh, couldn't find that vehicle!\n";
    }

    // Return a vehicle when the customer is done
    void returnVehicle(string vid) {
        for (auto& v : vehicles) {
            if (v.id == vid) {
                if (!v.is_rented) {
                    cout << "This one wasn't rented, dude!\n";
                } else {
                    v.is_rented = false;
                    cout << "Thanks for returning it!\n";
                }
                return;
            }
        }
        cout << "Vehicle not found, bro!\n";
    }
};

// Let's get this party started!
int main() {
    RentalSystem rentalShop;
    // Adding some cool vehicles to the shop
    rentalShop.addVehicle(Vehicle("CAR1", "Car", "Toyota", "Camry", 2020, 50, 4, "Gas"));
    rentalShop.addVehicle(Vehicle("MOTO1", "Motorcycle", "Harley", "X", 2019, 30, 0, "", true));
    rentalShop.addVehicle(Vehicle("TRUCK1", "Truck", "Ford", "F-150", 2021, 80, 0, "", false, 5, 2));

    // Simple menu to interact with the system
    while (true) {
        cout << "\n=== Rental Shop Menu ===\n";
        cout << "1. See available vehicles\n";
        cout << "2. Rent something cool\n";
        cout << "3. Return a vehicle\n";
        cout << "4. Peace out\n";
        cout << "Pick one: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            rentalShop.showFreeVehicles();
        } else if (choice == 2) {
            string vid;
            int days;
            cout << "Gimme the vehicle ID and how many days: ";
            cin >> vid >> days;
            rentalShop.rent(vid, days);
        } else if (choice == 3) {
            string vid;
            cout << "What's the vehicle ID? ";
            cin >> vid;
            rentalShop.returnVehicle(vid);
        } else if (choice == 4) {
            cout << "Catch ya later!\n";
            break;
        } else {
            cout << "Yo, that's not an option!\n";
        }
    }

    return 0;
}
