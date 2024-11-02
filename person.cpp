#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;
// Base class for common person attributes
class Person {
protected:
    string name;
    string birthday;
    string gender;
    string phone;
    string address;
    string password;
    // status 
public:
    void set_person();
    void display() const;
   // void read_a_person_from_file(const string& line);
};

void Person::set_person() {
    
    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, name);
    
    cout << "Enter birthday d-m-y: ";
    getline(cin, birthday);

    cout << "Enter gender (Male/Female): ";
    getline(cin, gender);
        
    cout << "Enter address: "; 
    getline(cin, address);
        
    cout << "Enter phone (10 digits): ";
    cin >> phone;

    while (phone.length() != 10 || !all_of(phone.begin(), phone.end(), ::isdigit)) {
        cout << "Invalid phone number. Enter again (10 digits): ";
        cin >> phone;
    }
    cin.ignore(); // Clear the input buffer
}
        
void Person::display() const {
    cout << "Name: " << name << ", Birthday: " << birthday 
         << ", Gender: " << gender << ", Phone: " << phone
         << ", Address: " << address;
    }
// void Person::read_a_person_from_file(const string& line) {
//     stringstream ss(line);
//     getline(ss, name, ',');
//     getline(ss, birthday,',');
//     getline(ss, gender, ',');
//     getline(ss, phone, ',');
//     getline(ss, address);
// }




