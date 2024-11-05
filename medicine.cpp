#include "medicine.h"

long long Medicine::set_id = 4000000;

void Medicine::set_data()
{
    id_medicine = set_id++;
    update_data();
}

void Medicine::display() const
{
    cout << "Medicine ID: " << id_medicine
         << ", Name: " << name
         << ", Type: " << type
         << ", NSX: " << NSX
         << ", HSD (month): " << HSD
         << ", Quantity: " << quantity_past
         << ", Cost: " << cost << endl;
}

void Medicine::read_a_object_from_file(const string &line) {
    stringstream ss(line);
    string item;

    // Read and convert id_doctor
    getline(ss, item, ',');
    id_medicine = stoll(item);

    // Read the rest of the person's data
    getline(ss, name, ',');
    getline(ss, type, ',');
    getline(ss, NSX, ',');
    getline(ss, item, ',');
    HSD = stoi(item);
    getline(ss, item, ',');
    quantity_past = stoi(item);
    getline(ss, item, ',');
    cost = stoi(item);
    getline(ss, item, ',');
    is_delete = (item == "1");

}

void Medicine::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_medicine << "," 
             << name << "," 
             << type << "," 
             << NSX << "," 
             << HSD << "," 
             << quantity_past << "," 
             << cost << ","
             << (is_delete ? "1" : "0")
             << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}

void Medicine::update_is_delete(int x){
    if(x == 1)
    is_delete = true;
    if(x == 2)
    is_delete = false;
}

void Medicine::update_data(){
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter type: ";
    getline(cin, type);

    cout << "Enter NSX d-m-y: ";
    getline(cin, NSX);

    cout << "Enter HSD (month): ";
    cin >> HSD;
    cin.ignore();

    cout << "Enter Quantity: ";
    cin >> quantity_past;
    cin.ignore();

    cout << "Enter Cost: ";
    cin >> cost;
    cin.ignore();
}