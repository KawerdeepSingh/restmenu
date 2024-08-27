#include <iostream>
#include <vector>
#include <string>
#include <limits> 
#include <algorithm>
#include <iomanip> 

using namespace std;

//To store menu item details
struct MenuItem {
    string name;
    double price;
};

//To display the menu
void displayMenu(const vector<MenuItem>& menu) {
    cout << "Menu:\n";
    cout << "--------------------------------\n";
    cout << "Item Name\tPrice\n";
    cout << "--------------------------------\n";
    for (const auto& item : menu) {
        cout << item.name << "\t\t$" << fixed << setprecision(2) << item.price << endl;
    }
    cout << "--------------------------------\n";
}

//To add a new item in the menu
void addItem(vector<MenuItem>& menu) {
    int  pas,password;
    pas=123456;
    cout << "enter password:";
    cin >> password ;
    if(pas==password){
        MenuItem newItem;
        cout << "Enter item name: ";
        cin >> newItem.name;
        cout << "Enter item price: $";
        cin >> newItem.price;
        menu.push_back(newItem);
        cout << "Item added to the menu!\n";
    }
    else{
        cout<<"WRONG PASSWORD";
    }
}


//To take customer orders and calculate total bill
void takeOrder(const vector<MenuItem>& menu) {
    vector<string> order;
    char choice;
    do {
        displayMenu(menu);
        cout << "Enter item name to order: ";
        string itemName;
        cin >> itemName;

        bool found = false;
        for (const auto& item : menu) {
            if (item.name == itemName) {
                order.push_back(itemName);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in the menu. Please enter a valid item.\n";
        }

        cout << "Do you want to order another item? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    //To Calculate total bill
    double totalBill = 0.0;
    for (const auto& itemName : order) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                totalBill += item.price;
                break;
            }
        }
    }

    //To Display total bill
    cout << "--------------------------------\n";
    cout << "Total Bill: $" << fixed << setprecision(2) << totalBill << endl;
    cout << "Thank you for visiting!\n";
}

int main() {
    vector<MenuItem> menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.49},
        {"Fries", 2.49},
        {"Soda", 1.99}
    };

    cout << "Welcome to Restaurant Management System\n";

    int choice;
    do {
        cout << "--------------------------------\n";
        cout << "1. Display Menu\n";
        cout << "2. Administrator Access to add items\n";
        cout << "3. Place Order\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                displayMenu(menu);
                break;
            case 2:
                addItem(menu);
                break;
            case 3:
                takeOrder(menu);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}
