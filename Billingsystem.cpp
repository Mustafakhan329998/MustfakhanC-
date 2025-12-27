#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string name, id;
    int units;
    float bill = 0;

    // Input customer details
    cout << "Enter Customer ID: ";
    cin >> id;
    cin.ignore();                 // Ignore leftover newline
    cout << "Enter Customer Name: ";
    getline(cin, name);           // Read full name including spaces

    cout << "Enter Units Consumed: ";
    cin >> units;

    // Bill calculation based on slabs
    int slab1 = 0, slab2 = 0, slab3 = 0;

    if(units <= 100) {
        slab1 = units;
        bill = slab1 * 5;
    }
    else if(units <= 200) {
        slab1 = 100;
        slab2 = units - 100;
        bill = slab1 * 5 + slab2 * 7;
    }
    else {
        slab1 = 100;
        slab2 = 100;
        slab3 = units - 200;
        bill = slab1 * 5 + slab2 * 7 + slab3 * 10;
    }

    // Display professionally formatted bill
    cout << "\n========================================\n";
    cout << "             WAPDA ELECTRICITY BILL\n";
    cout << "========================================\n";
    cout << left << setw(25) << "Customer Name:" << name << endl;
    cout << left << setw(25) << "Customer ID:" << id << endl;
    cout << left << setw(25) << "Units Consumed:" << units << " Units" << endl;

    cout << "\nRate Slabs:" << endl;
    cout << left << setw(25) << "Slab 1 (1-100 units)" 
         << setw(10) << "5/unit" 
         << "-> " << slab1 * 5 << " Rs" << endl;

    if(slab2 > 0)
        cout << left << setw(25) << "Slab 2 (101-200 units)" 
             << setw(10) << "7/unit" 
             << "-> " << slab2 * 7 << " Rs" << endl;

    if(slab3 > 0)
        cout << left << setw(25) << "Slab 3 (201+ units)" 
             << setw(10) << "10/unit" 
             << "-> " << slab3 * 10 << " Rs" << endl;

    cout << "----------------------------------------\n";
    cout << left << setw(25) << "Total Amount:" << "Rs. " << bill << endl;
    cout << "========================================\n";
    cout << "          THANK YOU FOR PAYING\n";
    cout << "========================================\n";

    return 0;
}

