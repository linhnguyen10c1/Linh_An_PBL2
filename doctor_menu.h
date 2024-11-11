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

void module_menu_doctor(long long ID, LinkedList<Record> &record_list){
	//read_data_from_file(record_list, "records.txt");
	if(ID == 1000000 || ID == 1000001 || ID == 1000002){
		int choice;
		do {
		//	int ID checking
			cout << "Enter ID Checking: "
				cout << "1. General Checking" << endl
				     << "2. Test_Lab" << endl
						 << "3. Prescription" << endl
						 << "4. Follow-up Appointment" << endl
						 << "0. Exit" << endl;
		cin >> choice;
		cin.ignore();
    switch(choice){
			case 1:{
			  //module_menu_admin(record_list, "records.txt");
				break;
			}
			case 2: {
				int choice;
				do{
				cout << "0. Result testing" << endl;
				cout << "1. X-ray" << endl
				     << "2. Endoscopy" << endl
						 << "3. Ultrasound" << endl
						 << "4. Blood + Urine test" << endl
						 << "5. ECG" << endl
						 << "6. Exit" << endl;
				cin >> choice;
				cin.ignore();
				switch(choice){
					case 1:{
						// menu_test(1);
					}
					case
				}
				}while(choice != 0);
			}
        
		}
		} while(choice != 0);
	}
	else {
		cout << "1. Display record of patient" << endl
		     << "2. Testing" << endl
	}
}


void menu_doctor(long long ID){
  LinkedList<Doctor> doctor_list;
	LinkedList<Record> record_list;
	int choice;
	while(choice != 0){
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
			if(doctor_list.check_specialization(ID) == "General"){
				Menu_general_doctor();
			}
			else{
				Menu_detail_doctor();
			}
			// nếu là bác sĩ cận lâm sàng
         
		} 
		}
	}
}

#endif