#include <iostream>
#include <string>
#include "class_person.cpp"

using namespace std;

class Patient : public Person
{
private:
    long long id_patient;

public:
    static long long set_id;
    // use when edit
    void set_data_general();
    // use when add
    void set_data();
    void display();
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_patient; }
    string get_name() const { return name; }
    string get_phone() const { return phone; }
};
long long Patient::set_id = 2000000;

void Patient::set_data_general(){
    Person::set_person();
}

void Patient::set_data()
{
    id_patient = set_id++;
    set_data_general();
    cout << "Patient has ID: " << id_patient << endl;
}

void Patient::display()
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

}

void Patient::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_patient << "," 
             << name << "," 
             << birthday << "," 
             << gender << "," 
             << phone << "," 
             << address << "," 
             << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}

