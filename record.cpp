#include "record.h"

long long Record::set_id = 5000000;

void Record::set_data() {
    id_checking = set_id++;
    cout << "Enter patient ID: ";
    cin >> id_patient;
    cin.ignore(); // Clear the input buffer before using getline
    // Set the current date and time for start_day
    // time_t now = time(0);
    // tm *ltm = localtime(&now);
    // start_day = to_string(ltm->tm_mday) + "-" +
    //             to_string(1 + ltm->tm_mon) + "-" +
    //             to_string(1900 + ltm->tm_year) + " " +
    //             to_string(ltm->tm_hour) + ":" +
    //             to_string(ltm->tm_min) + ":" +
    //             to_string(ltm->tm_sec);
}

void Record::update_data() {
    if(status_payment != false){
          time_t now = time(0);
          tm *ltm = localtime(&now);
          end_day = to_string(ltm->tm_mday) + "-" +
                to_string(1 + ltm->tm_mon) + "-" +
                to_string(1900 + ltm->tm_year) + " " +
                to_string(ltm->tm_hour) + ":" +
                to_string(ltm->tm_min) + ":" +
                to_string(ltm->tm_sec);
    }

}

void Record::update_is_delete(int x) {
    if (x == 1)
        is_delete = true;
    if (x == 2)
        is_delete = false;
}

void Record::display() const {
    cout << "Record ID: " << id_checking << ", "
         << "Patient ID: " << id_patient << ", "
         << "Start Day: " << start_day << ", "
         << "Symptom: " << symptom << ", "
         << "Diagnosis: " << diagnosis << ", "
         << "Heart Rate: " << heart << ", "
         << "Blood Pressure: " << blood << ", "
         << "Status Patient: " << status_patient << ", "
         << "Final Result: " << final_result << ","
         << "Total Cost: " << total_cost << ", "
         << "Status Payment: " << status_payment << ", "
         << "End Day: " << end_day << ", "
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
    getline(ss, start_day, ',');
    getline(ss, symptom, ',');
    getline(ss, diagnosis, ',');
    getline(ss, item, ',');
    heart = stod(item);
    getline(ss, item, ',');
    blood = stod(item);
    getline(ss, status_patient, ',');
    getline(ss, final_result, ',');
    getline(ss, item, ',');
    total_cost = stod(item);
    getline(ss, item, ',');
    status_payment = stod(item);
    getline(ss, item, ',');
    getline(ss, end_day, ',');
    is_delete = (item == "1");
}

void Record::write_a_object_to_file(ofstream &file) {
    if (file.is_open()) {
        file << id_checking << ","
             << id_patient << ","
             << start_day << ","
             << symptom << ","
             << diagnosis << ","
             << heart << ","
             << blood << ","
             << end_day << ","
             << status_patient << ","
             << total_cost << ","
             << status_payment << ","
             << (is_delete ? "1" : "0") << endl;
    } else {
        cerr << "Error: File is not open." << endl;
    }
}
