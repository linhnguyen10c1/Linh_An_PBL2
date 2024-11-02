#include <iostream>
#include <string>
#include "class_patient.cpp"
//#include "class_doctor.cpp"
#include "class_linklist.cpp"

using namespace std;

template <typename T>
void module_menu(LinkedList<T>& list,const string& filename){
	read_data_from_file(list, filename);
	T::set_id = list.get_id_from_file();
	int choice;
	do {
		cout <<"1. Add an object"<< endl<<"2. Display list objects"<< endl << "3. Search an object" << endl 
		     << "4. Update an object"<<endl<<"5. Delete an object"<<endl<<"6. Exit"<<endl;

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
				list.update(id);
				write_data_to_file(list,filename);
				break;
			}
			case 5:{
				long long id;
				cout << "Enter ID you want delete: ";
				cin >> id;
				list.remove(id);
				write_data_to_file(list,filename);
				// but when delete a doctor, but doctor have data
				// in another file? how solve problem
				break;
			}
			case 6: {
				
			}
		}
	} while(choice != 6);
}
void menu(){
	LinkedList<Patient> patient_list;
  //LinkedList<Doctor> doctor_list;
	//Link_list<Medicine> medicine_list;
	int choice;
	while(choice!=4){
		cout<<"1. Manage doctors"<< endl<<"2. Manage patients"<< endl << "3. Manage medicines "<<endl<<"4. exit"<<endl  ;
		cout << "Choose an option: ";
		cin>>choice;
		cin.ignore();
		switch (choice){
			case 1:
				//module_menu(doctor_list,"doctors.txt");
				break;
			case 2:
				module_menu(patient_list,"patients.txt");
				break;
			case 3:
				//module_menu(medicine_list,"medicines.txt");
				break;
			case 4: 
				break;
		}
	}
}


int main() {
	menu();
  return 0;
}
