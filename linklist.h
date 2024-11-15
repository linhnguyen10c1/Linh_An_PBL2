#ifndef LINKLIST_H
#define LINKLIST_H
#include "doctor.h"
#include "record.h"
#include "testing_lap.h"
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
// tình trạng mức độ bệnh, 
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
    void remove_recover(long long id, int x); 
    Node<T>* get_head() const { return head; }
    void search(long long id) const;
    int check(long long id) const;
    // search cho phone, name
    void search_record_patient(long long id) const;
    //void search(string name) const;
    int check_specialization(long long id) const;
    void update(long long id);
    // check xem tồn tại hay không
    int check(long long id, string password);
    void display_list_waiting_testing(long long id_doctor) const;
    void display_list_waiting(long long id_doctor) const;
    void update_from_general_doctor(long long id_record, double x);
    double  get_cost(long long ID_doctor) const;
    void update_result_record_from_doctor(long long id_record);
    void display_list_testing(long long ID_checking) const;
    void update_data_from_detail_doctor(long long ID_checking);
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
void LinkedList<T>::remove_recover(long long id, int x) {
    Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while (current != nullptr) {
        if (current->data.get_id() == id) {
            current->data.display();
            current->data.update_is_delete(x);
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
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

template<typename T>
int LinkedList<T>::check(long long id) const{
        Node<T>* current = head;
        if(current == nullptr){
            cout << "List empty" << endl;
            return 0;
        }
        while (current) {
            if(current->data.get_id() == id && current->data.get_is_deleted() == false){
                current->data.display();
                return 1;
            }
            current = current->next;
        }
        cout << "Item don't exsit" << endl;
        return 0;
    }

template <typename T>
void LinkedList<T>::search_record_patient(long long id) const{
        Node<T>* current = head;
        if(current == nullptr){
            cout << "List empty" << endl;
            return;
        }
        while (current) {
            if(current->data.get_id_patient() == id){
                current->data.display();
            }
            current = current->next;
        }
        cout << "Item don't exsit" << endl;
    }

// search cho phone, name
template <typename T>
// void LinkedList<T>::search(string name) const{
//          Node<T>* current = head;
//          if(current == nullptr){
//             cout << "List empty" << endl;
//             return;
//          }
//         while (current) {
//             if(current->data.get_name()== name || current->data.get_phone() == name){
//             current->data.display();
//             }
//             current = current->next;
//         }
//     }
int LinkedList<T>::check_specialization(long long ID) const{
         Node<T>* current = head;
         if(current == nullptr){
            cout << "List empty" << endl;
            return 0;
         }
        while (current) {
            if(current->data.get_id() == ID && current->data.get_is_delete() == false
                                      && current->data.get_specialization() == "General"){
                return 1;
            }
            current = current->next;
        }
        return 2;
    }

template <typename T>
double LinkedList<T>::get_cost(long long ID) const{
         Node<T>* current = head;
         if(current == nullptr){
            cout << "List empty" << endl;
            return 0;
         }
        while (current) {
            if(current->data.get_id() == ID && current->data.get_is_delete() == false){
                current->data.decreasing_waiting();
                return current->data.get_price();
            }
            current = current->next;
            
        }
        return 0;
    }

// check xem co ton tai hay ko
template <typename T>
int LinkedList<T>::check(long long id, string password){
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
            current->data.update_data();
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
}

template <typename T>
void LinkedList<T>::update_data_from_detail_doctor(long long id) {
       Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while (current != nullptr) {
        if (current->data.get_id_checking() == id) {
            current->data.display();
            current->data.update_data();
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
}

template <typename T>
void LinkedList<T>::update_from_general_doctor(long long id_record, double x) {
       Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while (current != nullptr) {
        if (current->data.get_id() == id_record) {
            current->data.display();
            current->data.update_data_general_doctor(x);
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
}
template <typename T>
void LinkedList<T>::update_result_record_from_doctor(long long id_record){
           Node<T>* current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while (current != nullptr) {
        if (current->data.get_id() == id_record) {
            current->data.display();
            current->data.update_result_record_doctor();
            return;
        }
        current = current->next;
    }
    cout << "Item don't exist" << endl;
}

template <typename T>
void LinkedList<T>::display_list_waiting(long long id_doctor) const{
    Node<T> *current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while(current != nullptr){
        if(current->data.get_id_doctor() == id_doctor && current->data.get_is_delete() == false
                                       && current->data.get_status_checking() == "waiting" ){
            cout << "ID Checking: " << current->data.get_id()
                 << " ID Patient: " << current->data.get_id_patient() << endl;
        }
        current = current->next;
    }
}

template <typename T>
void LinkedList<T>::display_list_waiting_testing(long long id_doctor) const{
    Node<T> *current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while(current != nullptr){
        if(current->data.get_id_doctor() == id_doctor
                                       && current->data.get_status_testing() == "waiting" ){
            cout << "ID Checking: " << current->data.get_id_checking() << endl;
        }
        current = current->next;
    }

}

template <typename T>
void LinkedList<T>::display_list_testing(long long ID_checking) const{
    Node<T> *current = head;
    if(current == nullptr){
        cout << "List empty" << endl;
        return;
    }
    while(current != nullptr){
        if(current->data.get_id_checking() == ID_checking && current->data.get_status_testing() == "completing" ){
                   current->data.display();
        }
        current = current->next;
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


#endif 