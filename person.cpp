#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <random>
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
    bool is_delete;
public:
    void set_person();
    void update_person();
    void display() const;
    string get_name() const{return name;}
    string get_phone() const{return phone;}
    bool get_is_delete() const{return is_delete;}
    static string generate_random_password(int length);
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
    is_delete = false;

    password = generate_random_password(5);

    //cin.ignore(); // Clear the input buffer
}

void Person::update_person(){
    
}

void Person::display() const {
    cout << "Name: " << name << ", Birthday: " << birthday 
         << ", Gender: " << gender << ", Phone: " << phone
         << ", Address: " << address << " Is_Deleted: " << is_delete << " Password: " << password;
    }

string Person::generate_random_password(int length) {
        const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        random_device rd;  // Seed for the random number engine
        mt19937 generator(rd());  // Mersenne Twister random number engine
        uniform_int_distribution<> distribution(0, characters.size() - 1);

        string password;
        for (int i = 0; i < length; ++i) {
            password += characters[distribution(generator)];
        }

        return password;
    }
// void Person::read_a_person_from_file(const string& line) {
//     stringstream ss(line);
//     getline(ss, name, ',');
//     getline(ss, birthday,',');
//     getline(ss, gender, ',');
//     getline(ss, phone, ',');
//     getline(ss, address);
// }




