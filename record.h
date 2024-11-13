#ifndef RECORD_H
#define RECORD_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;

class Record {
private:
    long long id_checking;
    long long id_patient;
    long long id_doctor;
    string room;
    string status_checking = "waiting";
    string start_day = "0";
    string end_day ="0";
    double heart = 0;
    double blood = 0;
    string symptom = "0";
    string diagnosis = "0";
    string status_patient = "0";
    string final_result = "0";
    string doctor_note = "0";
    string follow_up_appointment = "0";
    double total_cost = 0;
    double status_payment = -1;
    bool is_delete = false;

public:
    static long long set_id;
    void set_data();
    void update_data();
    void update_data_general_doctor(long long id_doctor);
    void update_total_cost(double x){
        total_cost += x;
    }
    void update_is_delete(int x);
    void display() const;
    long long get_id() const { return id_checking; }
    long long get_id_patient() const { return id_patient; }
    long long get_id_doctor() const {return id_doctor;}
    bool get_is_delete() const{return is_delete;}
    string get_status_checking() const{return status_checking;}
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);
};

#endif // RECORD_H
