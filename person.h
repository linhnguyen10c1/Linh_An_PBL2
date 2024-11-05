#ifndef PERSON_H
#define PERSON_H

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
    string password = generate_random_password(5);
    bool is_delete = false;
public:
    void set_person();
    void update_data();
    void update_is_delete(int x);
    void display() const;
    
    string get_name() const{return name;}
    string get_phone() const{return phone;}
    bool get_is_delete() const{return is_delete;}
    static string generate_random_password(int length);
   // void read_a_person_from_file(const string& line);
};

#endif