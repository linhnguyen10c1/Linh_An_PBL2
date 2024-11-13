#include "testing_lap.h"
#include "linklist.h"

void Testing::display() const{
  cout << "Record ID: " << id_checking
       << "Doctor1 ID: " << id_doctor1
       << "Doctor2 ID: " << id_doctor2
       << "Status testing" << status_testing
       << "Type testing: " << type
       << "Result testing: " << result_testing
       << "Cost: " << cost << endl;
}

// void Testing::set_data(long long id_record, const string &type){
//   id_checking = id_record;
//   this->type = type;
//   LinkedList<Doctor> doctor_list;
//   read_data_from_file(doctor_list, "doctors.txt");
    
//     // Tìm bác sĩ có ít bệnh nhân đang chờ nhất
//   Node<Doctor>* current = doctor_list.get_head();
//     while (current != nullptr) {
//         Doctor& doctor = current->data;
//         if (doctor.get_specialization() == "type" && doctor.get_is_delete() == false) {
//             doctor.increment_waiting();
//             if(id_doctor1 == 0) id_doctor1 = doctor.get_id();
//             else id_doctor2 = doctor.get_id();
//             room = doctor.get_room();
//             cost = doctor.get_price();
//         }
//         current = current->next;
//     }
  
//         cout << "Assigned Doctor ID: " << id_doctor1 << ", " << id_doctor2 << endl;
//         cout << "At room: " << room << endl;
//         write_data_to_file(doctor_list, "doctors.txt");

// }

void Testing::set_data(long long id_record, const string &type) {
    id_checking = id_record;
    this->type = type;

    LinkedList<Doctor> doctor_list;
    read_data_from_file(doctor_list, "doctors.txt");

    Doctor* assigned_doctor = nullptr;
    Node<Doctor>* current = doctor_list.get_head();
    
    while (current != nullptr) {
        Doctor& doctor = current->data;
        // Ensure we're checking the specialization correctly
        if (doctor.get_specialization() == type && !doctor.get_is_delete()) {
            if (id_doctor1 == 0) {
                id_doctor1 = doctor.get_id();
            } else {
                id_doctor2 = doctor.get_id();
            }
            room = doctor.get_room();
            cost = doctor.get_price();
        }
        current = current->next;
    }

    cout << "Assigned Doctor ID: " << id_doctor1 << ", " << id_doctor2 << endl;
    cout << "At room: " << room << endl;
    write_data_to_file(doctor_list, "doctors.txt");
}



void Testing::update_data(){

}

void Testing::read_a_object_from_file(const string &line) {
    stringstream ss(line);
    string item;

    getline(ss, item,',');
    id_checking = stoll(item);

    getline(ss, item,',');
    id_doctor1 = stoll(item);

    getline(ss, item, ',');
    id_doctor2 = stoll(item);
    getline(ss, room, ',');
    getline(ss, type, ',');
    getline(ss, status_testing, ',');
    getline(ss, result_testing, ',');
    getline(ss, item, ',');
    cost = stod(item);
}

void Testing::write_a_object_to_file(ofstream &file) {
  if(file.is_open()){
    file << id_checking << ","
         << id_doctor1 << ","
         << id_doctor2 << ","
         << room << ","
         << type << ","
         << status_testing << ","
         << result_testing << ","
         << cost << endl;
  } else{
    cerr << "Error: File is not open." << endl;
  }
}