#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class Person {
protected:
    string name;
    string birthday;
    string gender;
    string phone;
    string address;

public:
    void set_person();
    void display() const;
    void read_a_person_from_file(const string& line);
};

void Person::set_person() {
    cout << "Enter full name: ";
    getline(cin, name);
    
    cout << "Enter birthday (d-m-y): ";
    getline(cin, birthday);

    cout << "Enter gender (Male/Female): ";
    getline(cin, gender);
        
    cout << "Enter address: "; 
    getline(cin, address);
        
    cout << "Enter phone (10 digits): ";
    cin >> phone;

    while (phone.length() != 10 || !all_of(phone.begin(), phone.end(), ::isdigit)) {
        cout << "Invalid phone number! Enter a valid 10-digit phone: ";
        cin >> phone;
    }
    cin.ignore();
}

void Person::display() const {
    cout << "Name: " << name << ", Birthday: " << birthday 
         << ", Gender: " << gender << ", Phone: " << phone
         << ", Address: " << address;
}

void Person::read_a_person_from_file(const string& line) {
    stringstream ss(line);
    getline(ss, name, ',');
    getline(ss, birthday, ',');
    getline(ss, gender, ',');
    getline(ss, phone, ',');
    getline(ss, address);
}

class Doctor : public Person {
private:
    long long id_doctor;
    int experience_year;

public:
    static long long set_id;
    void set_data_general();
    void set_data();
    void display();
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_doctor; }
    string get_name() const { return name; }
    string get_phone() const { return phone; }
};

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
    getline(ss, item, ',');
    id_doctor = stoll(item);
    getline(ss, item, ',');
    experience_year = stoi(item);
    Person::read_a_person_from_file(line);
}

void Doctor::write_a_object_to_file(ofstream &file) {
    file << id_doctor << "," 
         << name << "," 
         << birthday << "," 
         << gender << "," 
         << phone << "," 
         << address << "," 
         << experience_year 
         << endl;
}

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    long long get_id_from_file();
    void add(const T& item);
    void display_list() const;
    void remove(long long id);
    void search(long long id) const;
    void search(const string& term) const;
    void update(long long id);
    Node<T>* get_head() const { return head; }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* current = head;
    while (current) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void LinkedList<T>::add(const T& item) {
    Node<T>* newNode = new Node<T>{item, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node<T>* temp = head;
    while (temp->next) {
        if (temp->data.get_id() == item.get_id()) {
            cout << "Item already exists with ID " << item.get_id() << endl;
            delete newNode;
            return;
        }
        temp = temp->next;
    }
    temp->next = newNode;
}

template <typename T>
void LinkedList<T>::display_list() const {
    Node<T>* temp = head;
    if (!temp) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp) {
        temp->data.display();
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::remove(long long id) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current && current->data.get_id() != id) {
        previous = current;
        current = current->next;
    }

    if (!current) {
        cout << "Item not found!" << endl;
        return;
    }

    if (!previous) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Item with ID " << id << " deleted successfully." << endl;
}

template <typename T>
void LinkedList<T>::search(long long id) const {
    Node<T>* current = head;
    while (current) {
        if (current->data.get_id() == id) {
            current->data.display();
            return;
        }
        current = current->next;
    }
    cout << "Item not found!" << endl;
}

template <typename T>
void LinkedList<T>::search(const string& term) const {
    Node<T>* current = head;
    bool found = false;
    while (current) {
        if (current->data.get_name() == term || current->data.get_phone() == term) {
            current->data.display();
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "No match found!" << endl;
    }
}

template <typename T>
void LinkedList<T>::update(long long id) {
    Node<T>* current = head;
    while (current) {
        if (current->data.get_id() == id) {
            current->data.display();
            current->data.set_data_general();
            cout << "Data updated successfully." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Item not found!" << endl;
}

template <typename T>
long long LinkedList<T>::get_id_from_file() {
    Node<T>* current = head;
    if (!current) {
        return T::set_id;
    }
    while (current->next) {
        current = current->next;
    }
    return current->data.get_id() + 1;
}

template <typename T>
void read_data_from_file(LinkedList<T>& list, const string& filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        T item;
        item.read_a_object_from_file(line);
        list.add(item);
    }
    file.close();
}

template <typename T>
void write_data_to_file(LinkedList<T>& list, const string& filename) {
    ofstream file(filename);
    Node<T>* temp = list.get_head();
    while (temp) {
        temp->data.write_a_object_to_file(file);
        temp = temp->next;
    }
    file.close();
    cout << "Data saved to " << filename << endl;
}

template <typename T>
void module_menu(LinkedList<T>& list, const string& filename) {
    read_data_from_file(list, filename);
    T::set_id = list.get_id_from_file();
    int choice;
    do {
        cout << "\n1. Add an object\n2. Display list\n3. Search by ID\n4. Update\n5. Delete\n6. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                T item;
                item.set_data();
                list.add(item);
                write_data_to_file(list, filename);
                break;
            }
            case 2: list.display_list(); break;
            case 3: {
                long long id;
                cout << "Enter ID to search: ";
                cin >> id;
                list.search(id);
                break;
            }
            case 4: {
                long long id;
                cout << "Enter ID to update: ";
                cin >> id;
                list.update(id);
                write_data_to_file(list, filename);
                break;
            }
            case 5: {
                long long id;
                cout << "Enter ID to delete: ";
                cin >> id;
                list.remove(id);
                write_data_to_file(list, filename);
                break;
            }
            case 6: break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);
}

int main() {
    LinkedList<Doctor> doctor_list;
    module_menu(doctor_list, "Doctor.txt");
    return 0;
}
