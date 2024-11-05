#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

class Medicine
{
private:
    long long id_medicine;
    string name;
    int quantity_past;
    double cost;
    string NSX;
    int HSD; // month
    string type;
    bool is_delete = false;

public:
    static long long set_id;
    void set_data();
    void display() const;
    void update_data();
    void update_is_delete(int x);
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_medicine; }
    string get_name() const { return name; }
};

#endif