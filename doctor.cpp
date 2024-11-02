
//#include <ionip>
#include "person.cpp"

class Doctor : public Person {
private:

    long long id_doctor;
    int experience_year;
    static int role;
    bool is_delete = false;
    

public:
    static long long set_id;
    // use when edit
    void set_data_general();
    // use when add 
    void set_data();
    void display();
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_doctor; }
    string get_name() const{return name;}
    string get_phone() const{return phone;}

};
int Doctor:: role = 4;
long long Doctor::set_id = 1000000;

void Doctor::set_data_general() {
        Person::set_person();
        cout << "Enter Experience Years: ";
        cin >> experience_year;
        cin.ignore();
    }

void Doctor::set_data() {
        id_doctor = set_id++;
        set_data_general();
        cout << "Doctor has ID: " << id_doctor << endl;
    }

void Doctor::display() {
        cout << "Doctor ID: " << id_doctor << ", ";
        Person::display();
        cout << ", Experience Years: " << experience_year << endl;

    }
void Doctor::read_a_object_from_file(const string &line) {
    stringstream ss(line);
    string item;

    // Read and convert id_doctor
    getline(ss, item, ',');
    id_doctor = stoll(item);

    // Read the rest of the person's data
    getline(ss, name, ',');
    getline(ss, birthday, ',');
    getline(ss, gender, ',');
    getline(ss, phone, ',');
    getline(ss, address, ',');

    // Read and convert experience_year
    getline(ss, item, ',');
    experience_year = stoi(item);
}

void Doctor::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_doctor << "," 
             << name << "," 
             << birthday << "," 
             << gender << "," 
             << phone << "," 
             << address << "," 
             << experience_year 
             << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}
