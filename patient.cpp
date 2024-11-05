
#include "patient.h"

long long Patient::set_id = 2000000;

void Patient::set_data()
{
    id_patient = set_id++;
    Person::set_person();
    cout << "Patient has ID: " << id_patient << " ,password: " << password << endl;
}

void Patient::display() const
{
    cout << "Patient ID: " << id_patient << ", ";
    Person::display();
    cout << endl;
}

// File operations
void Patient::read_a_object_from_file(const string &line)
{
    stringstream ss(line);
    string item;
        // Read and convert id_doctor
    getline(ss, item, ',');
    id_patient = stoll(item);

    // Read the rest of the person's data
    getline(ss, name, ',');
    getline(ss, birthday, ',');
    getline(ss, gender, ',');
    getline(ss, phone, ',');
    getline(ss, address, ',');
    getline(ss, password, ',');
    getline(ss, item, ',');
    is_delete = (item == "1");
}

void Patient::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_patient << "," 
             << name << "," 
             << birthday << "," 
             << gender << "," 
             << phone << "," 
             << address << "," 
             << password << ","
             << (is_delete ? "1" : "0")
             << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}

