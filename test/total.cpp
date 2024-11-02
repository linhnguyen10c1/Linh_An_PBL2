#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// Node structure for linked list
template <typename T>
struct Node {
    T data;
    Node* next;
};

// Base class for linked list operations
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    long long get_id_from_file();
    void add(const T& item);
    void display_list() const;
    void remove(long long id); 
    Node<T>* get_head() const { return head; }
    void search(long long id) const;
    // search cho phone, name
    void search(string name) const;
    void update(long long id);
};

template <typename T>
void LinkedList<T>::add(const T& item) {
        Node<T>* newNode = new Node<T>{item, nullptr};
        if (!head) {
            head = newNode;
            return;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                if(temp->data.get_id() == item.get_id()){
                    cout << "Item existed" << endl;
                    return;
                }
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

template <typename T>
void LinkedList<T>::display_list() const {
        Node<T>* temp = head;
        if(temp == nullptr){
            cout << "List empty" << endl;
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
        if(current == nullptr){
            cout << "List empty" << endl;
            return;
        }
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
            head = current->next;  // Deleting head
        } else {
            previous->next = current->next;
        }

        delete current;  // Free the memory
        cout << "Item with ID " << id << " deleted successfully." << endl;
    }
// search cho id
template <typename T>
void LinkedList<T>::search(long long id) const{
        Node<T>* current = head;
        if(current == nullptr){
            cout << "List empty" << endl;
        }
        while (current) {
            current = current->next;
            if(current->data.get_id() == id){
                current->data.display();
                return;
            }
            current = current->next;
        }
        cout << "Item don't exsit" << endl;
    }

// search cho phone, name
template <typename T>
void LinkedList<T>::search(string name) const{
         Node<T>* current = head;
         if(current == nullptr){
            cout << "List empty" << endl;
            return;
         }
        while (current) {
            if(current->data.get_name()== name || current->data.get_phone() == name){
            current->data.display();
            }
            current = current->next;
        }
    }
template <typename T>
long long LinkedList<T>::get_id_from_file(){
    Node<T> *current = head;
    if(current == nullptr){
        return T::set_id;
    }
    else{
        while(current->next){
            current = current->next;
        }
        return (current->data.get_id())+1;
    }
}

template <typename T>
void LinkedList<T>::update(long long id) {
       Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while (current != nullptr) {
        if (current->data.get_id() == id) {
            current->data.display();
            current->data.set_data_general();
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
}

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


class Doctor : public Person {
private:
    long long id_doctor;
    int experience_year;

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
void write_data_to_file(LinkedList<T>& list,const string& filename) {
    ofstream file(filename);
    Node<T>* temp = list.get_head();
	  while (temp != nullptr) {
			  temp->data.write_a_object_to_file(file);
	      temp = temp->next;
	    }

    file.close();
    cout << "Data was wrote in: " << filename << endl;
}

template <typename T>
void module_menu(LinkedList<T>& list,const string& filename){
	read_data_from_file(list, filename);
	T::set_id = list.get_id_from_file();
	int choice;
	do {
		cout <<"1. Add an object"<< endl<<"2. Display list objects"<< endl << "3. Search an object" << endl 
		     << "4. Update an object"<<endl<<"5. Delete an object"<<endl<<"6. Exit"<<endl;

		cout << "Choose an option: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice){
			case 1:{
				T item;
				item.set_data();
				list.add(item);
				write_data_to_file(list,filename);
				cout << "Object added successfully" << endl;
				break;
			}
			case 2:{
				list.display_list();
				break;
			}
			case 3:{
				long long id;
				cout << "Enter ID you want search: ";
				cin >> id;
				list.search(id);
				break;
			}
			case 4:{
				long long id;
				cout << "Enter ID you want update: ";
				cin  >> id;
				list.update(id);
				write_data_to_file(list,filename);
				break;
			}
			case 5:{
				long long id;
				cout << "Enter ID you want delete: ";
				cin >> id;
				list.remove(id);
				write_data_to_file(list,filename);
				// but when delete a doctor, but doctor have data
				// in another file? how solve problem
				break;
			}
			case 6: {
				
			}
		}
	} while(choice != 6);
}
void menu(){
	LinkedList<Patient> patient_list;
  //LinkedList<Doctor> doctor_list;
	//Link_list<Medicine> medicine_list;
	int choice;
	while(choice!=4){
		cout<<"1. Manage doctors"<< endl<<"2. Manage patients"<< endl << "3. Manage medicines "<<endl<<"4. exit"<<endl  ;
		cout << "Choose an option: ";
		cin>>choice;
		cin.ignore();
		switch (choice){
			case 1:
				//module_menu(doctor_list,"doctors.txt");
				break;
			case 2:
				module_menu(patient_list,"patients.txt");
				break;
			case 3:
				//module_menu(medicine_list,"medicines.txt");
				break;
			case 4: 
				break;
		}
	}
}


int main() {
	menu();
  return 0;
}



