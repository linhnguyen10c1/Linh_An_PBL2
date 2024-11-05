#include "person.h"

void Person::update_data(){
    int choice;
    do{
    cout << "1. Update Information\n"
         << "2. Update password\n" 
         << "3. Exit\n";
    cout << "Choose your option: ";
    cin >> choice;
    cin.ignore();

    switch (choice){
        case 1:{
              Person::set_person();
              cout << "Update successfully" << endl;
              display();
              cout << "\n";
              break;
        }
        case 2:{
              string mk;
              cout << "Enter password you want change: ";
              cin >> mk;
              password = mk;
              cout << "Update successfully" << endl;
              display();
              cout << "\n";
              break;
        }
        case 3: {
              break;
        }

        default: {
              cout << "Invalid choice. Please try again." << endl;
              break;
            }
    }
    } while(choice != 3);
}

void Person::update_is_delete(int x){
    if(x == 1)
    is_delete = true;
    if(x == 2)
    is_delete = false;
}
void Person::set_person() {
    
    //cin.ignore();
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
    //cin.ignore(); // Clear the input buffer
}


void Person::display() const {
    cout << "Name: " << name << ", Birthday: " << birthday 
         << ", Gender: " << gender << ", Phone: " << phone
         << ", Address: " << address << " ,Is_Deleted: " << is_delete << " ,Password: " << password;
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

