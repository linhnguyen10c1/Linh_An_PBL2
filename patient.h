#ifndef PATIENT_H
#define PATIENT_H
#include "person.h"
class Patient : public Person
{
private:
    long long id_patient;

public:
    static long long set_id;
    void set_data();
    void display() const;
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_patient; }
    string get_password() const {return password; }
};

#endif