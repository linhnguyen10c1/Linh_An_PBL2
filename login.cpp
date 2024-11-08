#include <iostream>
#include <string>
#include "admin.cpp"
#include "linklist.cpp"
#include "doctor.cpp"
#include <SFML/Graphics.hpp>
#include "button.h" 
using namespace std;


template <typename T>
bool is_exist_in_file(long long ID, string password, const string& filename){
  LinkedList<T> list;
  read_data_from_file(list, filename);
  return list.search(ID, password);
}



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
         << "5. Delete an object" << endl
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



void menu(int role){
  if(role == 1){
  //LinkedList<Patient> patient_list;
   LinkedList<Doctor> doctor_list;
	//Link_list<Medicine> medicine_list;
	int choice;
	while(choice!=4){
		cout<<"1. Manage doctors"<< endl<<"2. Manage patients"<< endl << "3. Manage medicines "<<endl<<"4. exit"<<endl  ;
		cout << "Choose an option: ";
		cin>>choice;
		cin.ignore();
		switch (choice){
			case 1:
				 module_menu_admin(doctor_list,"doctors.txt");
				break;
			case 2:
				//module_menu(patient_list,"patients.txt");
				break;
			case 3:
				//module_menu(medicine_list,"medicines.txt");
				break;
			case 4: 
				break;
		}
	}
	// sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Quan ly Benh vien -  Menu", sf::Style::Fullscreen);

  }

  else if(role == 2){

  }

  else if(role == 3){

  }
}

void texing(string &ID, string &password) {
    sf::Font font;
    sf::RenderWindow window(sf::VideoMode(600, 400), "Login Input");
    if (!font.loadFromFile("E:/lolololol/Linh_An_PBL2/arial.ttf")) {
        std::cerr << "Khong the tai font Arial!" << std::endl;
        return;
    }

    Button loginButton("Login", 220, 250);

    // Tạo hình chữ nhật làm nền cho ô đăng nhập
    sf::RectangleShape loginBox(sf::Vector2f(400, 300));
    loginBox.setFillColor(sf::Color(220, 220, 220));
    loginBox.setPosition(100, 50);

    // Thiết lập tiêu đề "Login"
    sf::Text title("Login", font, 30);
    title.setFillColor(sf::Color::Black);
    title.setPosition(250, 60);

    // Hiển thị nhãn "ID" và "Password"
    sf::Text IDLabel("ID:", font, 20);
    IDLabel.setFillColor(sf::Color::Black);
    IDLabel.setPosition(120, 150);

    sf::Text passwordLabel("Password:", font, 20);
    passwordLabel.setFillColor(sf::Color::Black);
    passwordLabel.setPosition(120, 200);

    // Tạo ô nhập liệu cho ID và Password
    sf::Text IDInput("", font, 20);
    IDInput.setFillColor(sf::Color::Black);
    IDInput.setPosition(220, 150);

    sf::Text passwordInput("", font, 20);
    passwordInput.setFillColor(sf::Color::Black);
    passwordInput.setPosition(220, 200);

    ID = "";         // Chuỗi lưu ID
    password = "";   // Chuỗi lưu mật khẩu
    bool enteringPassword = false; // Biến cờ để xác định đang nhập ID hay password

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Xoá ký tự với Backspace
                    if (enteringPassword && !password.empty())
                        password.pop_back();
                    else if (!enteringPassword && !ID.empty())
                        ID.pop_back();
                } else if (event.text.unicode == '\r') { // Enter để chuyển đổi giữa ID và password
                    enteringPassword = !enteringPassword;
                } else if (event.text.unicode < 128) { // Chỉ nhận ký tự ASCII
                    if (enteringPassword) {
                        password += static_cast<char>(event.text.unicode);
                        passwordInput.setString(std::string(password.length(), '*')); // Hiện dấu '*' cho password
                    } else {
                        ID += static_cast<char>(event.text.unicode);
                        IDInput.setString(ID);
                    }
                }
            } else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (loginButton.isClicked(mousePos)) {
                    window.close(); // Thoát chỉ màn hình nhập liệu
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(loginBox);
        window.draw(title);
        window.draw(IDLabel);
        window.draw(passwordLabel);
        window.draw(IDInput);
        window.draw(passwordInput);
        loginButton.draw(window);
        window.display();
    }
}

void login() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Login Screen");

    sf::Font font;
    if (!font.loadFromFile("E:/lolololol/Linh_An_PBL2/arial.ttf")) {
        std::cerr << "Khong the tai font Arial!" << std::endl;
        return;
    }

    sf::Text title("Login", font, 50);
    title.setFillColor(sf::Color::Black);
    title.setPosition(300, 50);

    Button administrator("1. You are administrator", 300, 150);
    Button doctor("2. You are doctor", 300, 220);
    Button patient("3. You are patient", 300, 290);
    Button exitButton("4. Exit", 300, 360);

    string id;
    string password;
    long long ID;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                if (administrator.isClicked(mousePos)) {
                    texing(id, password);
                    ID = stoll(id);
                    if (is_exist_in_file<Admin>(ID, password, "admins.txt"))
                        menu(1);
                } else if (doctor.isClicked(mousePos)) {
                    texing(id, password);
                    ID = stoll(id);
                    if (is_exist_in_file<Doctor>(ID, password, "doctors.txt"))
                        menu(2);
                } else if (patient.isClicked(mousePos)) {
                    texing(id, password);
                    ID = stoll(id);
                    // Kiểm tra file bệnh nhân
                } else if (exitButton.isClicked(mousePos)) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(title);
        administrator.draw(window);
        doctor.draw(window);
        patient.draw(window);
        exitButton.draw(window);
        window.display();
    }
}


int main(){
  LinkedList<Admin> list;
  Admin ad;
  list.add(ad);
  write_data_to_file(list, "admins.txt");
  login();
}