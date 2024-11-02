#include <iostream>
#include <string>
#include "class_linklist.cpp"

using namespace std;

class Medicine
{
private:
    long long id_medicine;
    string name;
    int quantity;
    double cost;

public:
    static long long set_id;
    // use when edit
    void set_data_general();
    // use when add
    void set_data();
    void display();
    void read_a_object_from_file(const string &line);
    void write_a_object_to_file(ofstream &file);

    long long get_id() const { return id_medicine; }
    string get_name() const { return name; }
};
static int get_id_from_file(LinkedList<Medicine> &medicines)
{
    Node<Medicine> *current = medicines.getHead();
    if (!current)
        return 400000;
    else
    {
        while (current->next)
        {
            current = current->next;
        }
        return (current->data.get_id()) + 1;
    }
}
void Medicine::set_data_general()
{
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Quantity: ";
    cin >> quantity;
    cout << "Enter Cost: ";
    cin >> cost;
}

void Medicine::set_data()
{
    id_medicine = set_id++;
    set_data_general();
}

void Medicine::display()
{
    cout << "Medicine ID: " << id_medicine
         << ", Name: " << name
         << ", Quantity: " << quantity
         << ", Cost: " << cost << endl;
}


// File operations
static void load_from_file(LinkedList<Medicine> &medicines)
{
    ifstream file("medicines.txt");
    string line;
    while (getline(file, line))
    {
        Medicine medicine;
        stringstream ss(line);
        string item;

        getline(ss, item, ',');
        medicine.id_medicine = stoi(item);
        getline(ss, medicine.name, ',');
        getline(ss, item, ',');
        medicine.quantity = stoi(item);
        getline(ss, item, ',');
        medicine.cost = stod(item);

        medicines.add(medicine);
    }
    file.close();
}

static void save_to_file(const LinkedList<Medicine> &medicines)
{
    ofstream file("medicines.txt");
    Node<Medicine> *temp = medicines.getHead();
    while (temp)
    {
        file << temp->data.get_id() << ","
             << temp->data.name << ","
             << temp->data.quantity << ","
             << temp->data.cost << endl;
        temp = temp->next;
    }
    file.close();
}

void menu(LinkedList<Medicine> &medicines)
{
    int choice;
    load_from_file(medicines); // Load medicines from the file
    set_id_medicine = get_id_from_file(medicines);

    do
    {
        cout << "\n1. Add Medicine\n2. Display Medicines\n3. Delete Medicine\n4. Edit Medicine\n5. Search\n0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            set_medicine();
            medicines.add(*this);
            save_to_file(medicines);
            cout << "Medicine added successfully." << endl;
            break;
        }
        case 2:
            medicines.display();
            break;
        case 3:
        {
            int id;
            cout << "Enter Medicine ID to delete: ";
            cin >> id;
            medicines.deleteItem(id);
            save_to_file(medicines);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter Medicine ID to edit: ";
            cin >> id;
            Node<Medicine> *current = medicines.getHead();
            while (current && current->data.get_id() != id)
            {
                current = current->next;
            }
            if (!current)
            {
                cout << "Medicine not found!" << endl;
            }
            else
            {
                current->data.set_medicine_general(); // Update the medicine's information
                save_to_file(medicines);
                cout << "Medicine information updated successfully." << endl;
            }
            break;
        }
        case 5:
        {
            int choice;
            do
            {
                cout << "\n1. Search_by_ID\n2. Search_by_name\n0. Exit\n";
                cout << "Choose an option: ";
                cin >> choice;
                switch (choice)
                {
                    int id;
                case 1:
                {
                    cout << "Enter id_medicine you want search: ";
                    cin >> id;
                    medicines.search(id);
                    break;
                }
                case 2:
                {
                    string name;
                    cout << "Enter name_medicine you want search: ";
                    cin >> name;
                    medicines.search(name);
                    break;
                }

                case 0:
                {
                }
                }
            } while (choice != 0);
        }
        case 0:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}
}
;
int Medicine::set_id_medicine = 400000;

int main()
{
    LinkedList<Medicine> medicines;
    Medicine medicine;
    medicine.menu(medicines);
}
