#include <iostream>
#include "admin.h"
#include "linklist.h"
#include "doctor.h"
#include "patient.h"
#include "medicine.h"
using namespace std;

template <typename T>
void module_menu_admin(LinkedList<T>& list,const string& filename){
	read_data_from_file(list, filename);
	T::set_id = list.get_id_from_file();
	int choice;
	do {
		cout << "1. Add an object" << endl
         << "2. Display list objects"<< endl
         << "3. Search an object" << endl 
		     << "4. Update an object"<< endl
         << "5. Delete--Recover an object" << endl
         << "6. Exit" << endl;

		cout << "Choose an option: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice){
			case 1:{
				T item;
				item.set_data();
				list.add(item);
				write_data_to_file(list,filename);
				cout << "Object added successfully" << endl;
				break;
			}
			case 2:{
				list.display_list();
				break;
			}
			case 3:{
				long long id;
				cout << "Enter ID you want search: ";
				cin >> id;
				list.search(id);
				break;
			}
			case 4:{
				long long id;
				cout << "Enter ID you want update: ";
				cin  >> id;
				cin.ignore();
				list.update(id);
				write_data_to_file(list,filename);
				break;
			}
			case 5:{
				int x;
				cout << "1. Delete\n"
				     << "2. Recover\n";
				cout << "Your option: ";
        cin >> x;
				long long id;
				cout << "Enter ID you want: ";
				cin >> id;
				cin.ignore();
				list.remove_recover(id,x);
				write_data_to_file(list,filename);
				break;
			}
			case 6: {
				
			}
		}
	} while(choice != 6);
}

void menu_admin(){
   LinkedList<Patient> patient_list;
   LinkedList<Doctor> doctor_list;
	 LinkedList<Medicine> medicine_list;
	int choice;
	while(choice!= 4){
		cout<< "1. Manage doctors"<< endl
		    << "2. Manage patients"<< endl
			  << "3. Manage medicines "<<endl
				// mở rộng sau
				<< "4. Statistic (mở rộng sau)" << endl 
				<< "0. exit"<< endl;
		cout << "Choose an option: ";
		cin>>choice;
		cin.ignore();
		switch (choice){
			case 1:
				 module_menu_admin(doctor_list,"doctors.txt");
				break;
			case 2:
				 module_menu_admin(patient_list,"patients.txt");
				break;
			case 3:
				 module_menu_admin(medicine_list,"medicines.txt");
				break;
			case 4: 
				break;
			case 0: 
			  break;
		}
	}
  }

template<typename T>
void module_menu_manage_personal_information(long long ID, LinkedList<T>& list, const string& filename){
      read_data_from_file(list, filename);
			int choice;
			do{
         cout << "1. Display your information" << endl
				      << "2. Update your information" << endl
							<< "0. Exit" << endl;
				 cout << "Choose your option: ";
				 cin >> choice;
				 cin.ignore();
				 switch(choice){
					case 1:{
				    list.search(ID);
				    break;
					}
					case 2:{
            list.update(ID);
				    write_data_to_file(list,filename);
						break;
					}
					case 0: {

					}
				 }

			}while(choice != 0);
}

void menu_doctor(long long ID){
  LinkedList<Doctor> doctor_list;
	int choice;
	while(choice != 0){
		cout << "1. Manage your information" << endl
		     << "2. Manage medical record" << endl
				 << "3. Check" << endl
				 << "4. Prescription" << endl
				 << "5. Appointment" << endl
				 << "0. Exit" << endl;
		cout << "Choose your option: ";
		cin >> choice;
		cin.ignore();
		switch(choice){
		 case 1:{
      module_menu_manage_personal_information(ID, doctor_list, "doctors.txt");
			break;
		}
		case 2: {

		}
		case 3: {

		}
		case 4: {

		}
		case 5: {

		}
		case 0: {

		}
		}
	}
}

void menu_patient(long long ID){
  LinkedList<Patient> patient_list;
	int choice;
	while( choice != 0){
		cout << "1. Manage your information" << endl
		     << "2. Medical Record" << endl
				 << "3. Appointment" << endl
				 << "4. Payment" << endl
				 << "0. Exit" << endl;

		cout << "Choose your option: ";
		cin >> choice;
		cin.ignore();
		switch(choice){
			case 1:{
				module_menu_manage_personal_information(ID, patient_list, "patients.txt");
			}
			case 2:{

			}
			case 3: {

			}
			case 4: {

			}
			case 0: {

			}
		}

	}
}

template <typename T>
bool is_exist_in_file(long long ID, string password, const string& filename){
  LinkedList<T> list;
  read_data_from_file(list, filename);
  return list.search(ID, password);
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
    cout << "Choose your option: ";
    cin >> role;
    cout << "Enter your ID: ";
    cin >> ID;
    cout << "Enter your password: ";
    cin >> password;
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
        menu_patient(ID);
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