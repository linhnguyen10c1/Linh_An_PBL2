#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;
class Admin{
  private:
     long long id_admin;
     string password;
     bool is_delete;

  public:
  bool get_is_delete() const{return is_delete;}
  long long get_id() const { return id_admin; }
  string get_password() const{return password;}
  Admin(long long id_admin = 123,string password = "admin123", bool is_delete = false )
  :id_admin(id_admin), password(password), is_delete(is_delete){
  }

  void read_a_object_from_file(const string &line);
  void write_a_object_to_file(ofstream &file);
};


void Admin::read_a_object_from_file(const string &line) {
    stringstream ss(line);
    string item;

    // Read and convert id_doctor
    getline(ss, item, ',');
    id_admin = stoll(item);

    // Read the rest of the person's data
    getline(ss, password, ',');
    
    getline(ss, item, ',');
    is_delete = (item == "1");
}

void Admin::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_admin << "," 
             << password << "," 
             << (is_delete ? "1" : "0")<< endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}