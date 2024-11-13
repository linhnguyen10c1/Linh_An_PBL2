#ifndef DOCTORMENU_H
#define DOCTORMEUNU_H
#include "linklist.h"
#include "doctor.h"
#include "record.h"
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

				// cout << "0. Result testing" << endl;
				// cout << "1. X-ray" << endl
				//      << "2. Endoscopy" << endl
				// 		 << "3. Ultrasound" << endl
				// 		 << "4. Blood + Urine test" << endl
				// 		 << "5. ECG" << endl
				// 		 << "6. Exit" << endl;

void Menu_general_doctor(long long ID_doctor, LinkedList<Record> &record_list){
	  int choice;
		do{
    cout << "1. Waiting List" << endl
		     << "2. List Records of a Patient" << endl
				 << "3. Checking" << endl
				 << "0. Exit" << endl;
		cout << "Choose your option: ";
		cin >> choice;
		switch(choice){
			case 1: {
					record_list.display_list_waiting(ID_doctor);
					break;
			}
			case 2:{
				   long long ID_patient;
					 cout << "ID patient you want search records: ";
					 cin >> ID_patient;
					 cin.ignore();
					 record_list.search_record_patient(ID_patient);
					 break;
			}

      case 3:{
				   long long ID_checking;
					 cout << "Enter ID_Checking you want checking: ";
					 cin >> ID_checking;
					 cin.ignore();
           int choice;
					 do{
					 cout << "1. Checking general" << endl
					      << "2. Checking Detail" << endl
								<< "3. Prescription" << endl
								<< "4. Appointment" << endl
								<< "0. Exit" << endl;
						cout << "Choose your choice: ";
						cin >> choice;
						cin.ignore();
						switch(choice){
							case 1:{
								record_list.update_from_general_doctor(ID_checking, ID_doctor);
								write_data_to_file(record_list, "records.txt");
								break;
							}
						}
					 } while(choice != 0);
           
				
			}
		}
		} while(choice != 0);
}

void Menu_detail_doctor(long long ID, LinkedList<Record> &record_list){

}

void menu_doctor(long long ID){
  LinkedList<Doctor> doctor_list;
	LinkedList<Record> record_list;
	read_data_from_file(doctor_list, "doctors.txt");
	read_data_from_file(record_list, "records.txt");
	int choice;
	do {
		cout << "1. Manage your information" << endl
		     << "2. Manage medical record" << endl
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
			// nếu là bác sĩ lâm sàng
			if(doctor_list.check_specialization(ID) == 1){
				Menu_general_doctor(ID, record_list);
			}
			else if(doctor_list.check_specialization(ID) == 2){
				Menu_detail_doctor(ID, record_list);
			}
			// nếu là bác sĩ cận lâm sàng
         
		} 
		}
	} while(choice != 0);
}

#endif