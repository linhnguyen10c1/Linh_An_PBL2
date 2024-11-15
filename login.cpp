#include <iostream>
#include "admin_menu.h"
#include "admin.h"
#include "linklist.h"
#include "doctor.h"
#include "doctor_menu.h"
#include "patient.h"
//#include "patient_menu.h"
#include "medicine.h"
#include "record.h"


using namespace std;

template <typename T>
bool is_exist_in_file(long long ID, string password, const string& filename){
  LinkedList<T> list;
  read_data_from_file(list, filename);
  return list.check(ID, password);
}

void login()
{
  int role;
  do
  {
    long long ID;
    string password;
    cout << "------LOGIN------" << endl;
    cout << "1. You are administrator\n"
         << "2. You are doctor\n"
         << "3. You are patient\n"
         << "4. Exit\n";
    cout << "-----------------" << endl;
    cout << "Choose your option: ";
    cin >> role;
    cout << "Enter your ID: ";
    cin >> ID;
    cout << "Enter your password: ";
    cin >> password;
    cin.ignore();
    switch (role)
    {
    case 1:
    {
      if (is_exist_in_file<Admin>(ID, password,"admins.txt"))
        menu_admin();
      else
        break;
      break;
    }
    case 2:
    {
      if (is_exist_in_file<Doctor>(ID, password, "doctors.txt"))
        menu_doctor(ID);
      else
        break;
      break;
    }
    case 3:
    {
      if (is_exist_in_file<Patient>(ID, password, "patients.txt"))
        //menu_patient(ID);
        int x = 1;
      else
        break;
      break;
    }
    case 4:{

    }
    }

  } while (role != 4);
}

int main(){
  LinkedList<Admin> list;
  Admin ad;
  list.add(ad);
  write_data_to_file(list, "admins.txt");
  login();
}