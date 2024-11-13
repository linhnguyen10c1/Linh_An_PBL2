#ifndef DOCTOR_H
#define DOCTOR_H
#include "person.h"

class Doctor : public Person {
private:

    long long id_doctor;
    string specialization;
    string room;
    int experience_year;
    int patients_waiting = 0;
    double price;

public:
    static long long set_id;
    void set_data();
    void display() const;

    void increment_waiting() { ++patients_waiting; }  // Tăng số lượng bệnh nhân chờ thêm 1
    void decreasing_waiting(){if(patients_waiting > 0)--patients_waiting;}
    void reset_waiting() { patients_waiting = 0; }    // Đặt lại số bệnh nhân đang chờ
    int get_waiting() const { return patients_waiting; }

    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_doctor; }
    string get_password() const{return password;}
    string get_specialization()const{return specialization;}
    string get_room()const{return room;}
    double get_price()const{return price;}

};

#endif