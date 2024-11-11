#ifndef PATIENTMENU_H
#define PATIENTMEUNU_H
#include "linklist.h"
#include "patient.h"
#include "record.h"
void menu_patient(long long ID){
  LinkedList<Patient> patient_list;
	LinkedList<Record> record_list;
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
        long long ID_Record;
				cout <<"Enter ID record you want search: ";
				cin >> ID_Record;
				cin.ignore();
				read_data_from_file(record_list, "records.txt");
				record_list.search(ID_Record);
				break;
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
#endif