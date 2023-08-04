#include "Utils.h"


int Utils::getInt() {
	int input;
	std::cin >> input;
	while (std::cin.fail())
	{
	std::cout << "Please enter a valid integer." << std::endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin >> input;

	}
return input;
}
float Utils::getFloat() {
	float input;
	std::cin >> input;
	while (std::cin.fail())
	{
		std::cout << "Please enter a valid integer." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;

	}
	return input;
}


int Utils::getInt(int min, int max) {
	int input;
	std::cin >> input;
	while (std::cin.fail() || input < min || input > max)
	{
		std::cout << "Please enter a valid integer between "<<min<<" and "<<max<<std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;

	}
	return input;
}



void Utils::exitProgam(){
	system("cls");
	std::cout<<"Thank you for using our inventory managment system"<<std::endl;
	std::cout<<"------------------Goodbye----------------------------"<<std::endl;
	Sleep(2000);
	exit(0);
}



int Utils::mainMenu() {
	system("cls");
	std::cout << "WELLCOME TO OUR INVENTORY MANAGMENT SYSTEM"<<std::endl;
	std::cout << "------------------------------------------"<<std::endl;
	std::cout<<"1. Login as a customer"<<std::endl;
	std::cout<<"2. Login as an admin"<<std::endl;
	std::cout<<"3. Register as a customer"<<std::endl;
	std::cout << "4. Register as an admin" << std::endl;
	std::cout<<"5. Exit"<<std::endl;
	std::cout<<"Please enter your choice: ";
	int choice;
	choice = getInt(1, 5);
	switch (choice) {
	case 1: return 6;
	case 2: return 7;
	case 3: return 8;
	case 4: return 9;
	case 5:return -1;
	}


}

std::vector<std::string> Utils::split(std::string str, char delimiter) {
	std::vector<std::string> result;
	std::string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == delimiter) {
			result.push_back(temp);
			temp = "";
		}
		else {
			temp += str[i];
		}
	}
	result.push_back(temp);
	return result;


}


std::string Utils::UUID() {
	char hex[] = "0123456789ABCDEF";
	std::string uuid = "";
	for (int i = 0; i < 32; i++) {
		uuid += hex[rand() % 16];
	}

	uuid.insert(8, "-");
	uuid.insert(13, "-");
	uuid.insert(18, "-");
	uuid.insert(23, "-");
	return uuid;
}