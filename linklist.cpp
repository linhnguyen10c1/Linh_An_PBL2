#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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
    // check xem tồn tại hay không
    int search(long long id, string password);
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
            return;
        }
        while (current) {
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

// check xem co ton tai hay ko
template <typename T>
int LinkedList<T>::search(long long id, string password){
    Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return 0;
    }
    while (current) {
            if(current->data.get_id() == id && current->data.get_password()== password
                                            && current->data.get_is_delete() == false){
                return 1;
            }
            current = current->next;
        }
        cout << "Item don't exsit" << endl;
        return 0;

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
