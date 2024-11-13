#include "record.h"
#include "linklist.h"
#include "patient.h"
#include "doctor.h"

long long Record::set_id = 5000000;

void Record::set_data() {
    LinkedList<Patient> list;
    LinkedList<Doctor> doctor_list;
    cout << "Enter patient ID: ";
    cin >> id_patient;
    cin.ignore();
    read_data_from_file(list,"patients.txt");
    while(list.check(id_patient) == 0){
        cout << "Enter patient ID: ";
        cin >> id_patient;
    }
    id_checking = set_id++;
    cout << "ID checking: " << id_checking << endl;



     // Đọc danh sách bác sĩ từ file
    read_data_from_file(doctor_list, "doctors.txt");
    
    // Tìm bác sĩ có ít bệnh nhân đang chờ nhất
    Doctor* assigned_doctor = nullptr;
    int min_waiting = INT_MAX;

    Node<Doctor>* current = doctor_list.get_head();
    while (current != nullptr) {
        Doctor& doctor = current->data;
        if (doctor.get_waiting() < min_waiting && doctor.get_specialization() == "General") {
            min_waiting = doctor.get_waiting();
            assigned_doctor = &doctor;
        }
        current = current->next;
    }

    // Kiểm tra nếu tìm được bác sĩ
    if (assigned_doctor) {
        // Tăng số bệnh nhân đang chờ của bác sĩ
        assigned_doctor->increment_waiting();

        // Lưu lại ID bác sĩ được phân bổ cho bệnh nhân
        id_doctor = assigned_doctor->get_id();
        room = assigned_doctor->get_room();
        cout << "Assigned Doctor ID: " << id_doctor << std::endl;
        cout << "At room: " << room << endl;
        // Cập nhật danh sách bác sĩ vào file
        write_data_to_file(doctor_list, "doctors.txt");
    } else {
        std::cerr << "Error: No doctors available." << std::endl;
    }

}


void Record::update_data_general_doctor(long long id_doctor){
    // Set the current date and time for start_day
    double x = 0;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    start_day = to_string(ltm->tm_mday) + "-" +
                to_string(1 + ltm->tm_mon) + "-" +
                to_string(1900 + ltm->tm_year) + " " +
                to_string(ltm->tm_hour) + ":" +
                to_string(ltm->tm_min) + ":" +
                to_string(ltm->tm_sec);
    status_checking = "processing";
    LinkedList<Doctor> doctor_list;
    read_data_from_file(doctor_list, "doctors.txt");
    x = doctor_list.get_cost(id_doctor);
    write_data_to_file(doctor_list, "doctors.txt");

    update_total_cost(x);

    cout << "Heart Rate: ";
    cin >> heart;
    cin.ignore();
    cout << "Blood Pressure: ";
    cin >> blood;
    cin.ignore();
    cout << "Symptom: ";
    getline(cin, symptom);
    cout << "Diagnosis: ";
    getline(cin, diagnosis);
    cout << "Patient Status: ";
    getline(cin,status_patient);
    cout << "Final result: ";
    getline(cin, final_result);
    cout << "Note: ";
    getline(cin, doctor_note);

    
}

void Record::update_data(){
    cout << "YOU DON'T PERMISSION UPDATE" << endl;
}

// void Record::update_data() {
//     if(status_payment != false){
//           time_t now = time(0);
//           tm *ltm = localtime(&now);
//           end_day = to_string(ltm->tm_mday) + "-" +
//                 to_string(1 + ltm->tm_mon) + "-" +
//                 to_string(1900 + ltm->tm_year) + " " +
//                 to_string(ltm->tm_hour) + ":" +
//                 to_string(ltm->tm_min) + ":" +
//                 to_string(ltm->tm_sec);
//     }

// }

void Record::update_is_delete(int x) {
    if (x == 1)
        is_delete = true;
    if (x == 2)
        is_delete = false;
}

void Record::display() const {
    cout << "Record ID: " << id_checking << ", "
         << "Patient ID: " << id_patient << ", "
         << "Doctor ID: " << id_doctor << ", "
         << "Room: " << room << ", "
         << "Status Checking: " << status_checking << ", "
         << "Start Day: " << start_day << ", "
         << "End Day: " << end_day << ", "
         << "Heart Rate: " << heart << ", "
         << "Blood Pressure: " << blood << ", "
         << "Symptom: " << symptom << ", "
         << "Diagnosis: " << diagnosis << ", "
         << "Status Patient: " << status_patient << ", "
         << "Final Result: " << final_result << ","
         << "Note of Doctor: " << doctor_note << ","
         << "Follow-up-appointment" << follow_up_appointment << ","
         << "Total Cost: " << total_cost << ", "
         << "Status Payment: " << status_payment << ", "
         << "Is Deleted: " << is_delete << endl;
}

void Record::read_a_object_from_file(const string &line) {
    stringstream ss(line);
    string item;

    // Read and convert id_checking
    getline(ss, item, ',');
    id_checking = stoll(item);

    // Read the rest of the record's data
    getline(ss, item, ',');
    id_patient = stoll(item);

    getline(ss, item, ',');
    id_doctor = stoll(item);

    getline(ss, room, ',');
    getline(ss, status_checking, ',');
    getline(ss, start_day, ',');

    getline(ss, end_day, ',');

    getline(ss, item, ',');
    heart = stod(item);
    getline(ss, item, ',');
    blood = stod(item);

    getline(ss, symptom, ',');
    getline(ss, diagnosis, ',');

    getline(ss, status_patient, ',');
    getline(ss, final_result, ',');
    getline(ss, doctor_note, ',');
    getline(ss, follow_up_appointment, ',');

    getline(ss, item, ',');
    total_cost = stod(item);
    getline(ss, item, ',');
    status_payment = stod(item);
    getline(ss, item, ',');
    is_delete = (item == "1");
}

void Record::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_checking << ","
             << id_patient << ","
             << id_doctor << ","
             << room << ","
             << status_checking << ","
             << start_day << ","
             << end_day << ","
             << blood << ","
             << heart << ","
             << symptom << ","
             << diagnosis << ","
             << status_patient << ","
             << final_result << ","
             << doctor_note << ","
             << follow_up_appointment << ","
             << total_cost << ","
             << status_payment << ","
             << (is_delete ? "1" : "0") << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}
