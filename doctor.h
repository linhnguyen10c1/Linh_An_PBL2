#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"

class Doctor : public Person {
private:

    long long id_doctor;
    int experience_year;

public:
    static long long set_id;
    void set_data();
    void display() const;
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_doctor; }
    string get_password() const{return password;}

};

#endif