#ifndef TESTING_H
#define TESTING_H

#include "linklist.h"
#include <iostream>
#include <string>
#include "record.h"

using namespace std;

class Testing{
   private:
   long long id_checking;
   long long id_doctor1 = 0;
   long long id_doctor2;
   string room;
   string type;
   string status_testing = "waiting";
   string result_testing = "0";
   double cost = 0;
   //string imagine;
   public:
   void display() const;
   void set_data(long long id_record, const string &type);
   void update_data();
   long long get_id() const {return id_checking+id_doctor1+id_doctor2;}
   long long get_id_doctor()const {return id_doctor1;}
   long long get_id_checking() const{return id_checking;}
   string get_status_testing() const {return status_testing;}
   void read_a_object_from_file(const string &line);
   void write_a_object_to_file(ofstream &file);
};
#endif