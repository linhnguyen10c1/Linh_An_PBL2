#ifndef ADMINMENU_H
#define ADMINMEUNU_H
#include "linklist.h"
#include "doctor.h"
#include "patient.h"
#include "medicine.h"
#include "record.h"
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
   LinkedList<Record> record_list;
	int choice;
	  do{
		cout<< "1. Manage doctors"<< endl
		    << "2. Manage patients"<< endl
			  << "3. Manage medicines "<<endl
        << "4. Manage medical record" << endl
				// mở rộng sau
				<< "5. Statistic (mở rộng sau)" << endl 
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
         module_menu_admin(record_list, "records.txt");
				break;
			case 0: 
			  break;
		}
	}while(choice != 0);
  }

  #endif 
