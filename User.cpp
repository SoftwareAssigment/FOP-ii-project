
#include "User.h"

struct order
{
    std::string orderId;
    std::string customerId;
    std::vector<Product> orderedProducts;
    std::vector<int> orderedProductsQnt;
    double totalPrice;
    time_t orderDateTime;
};


// constructor defination
User::User() : m_isAdmin(false) {}
// function over loading to handle diffrent ypes of input
User::User(const std::string& name, const std::string& fatherName, const std::string& userName, 
    const std::string& password,const bool& isAdmin) {
    m_name = name;
    m_fatherName = fatherName;
    m_userName = userName;
    m_password = password;
    m_isAdmin = isAdmin;
}


//getter functions
std::string User::getName() { return m_name;}
std::string User::getFatherName() { return m_fatherName; }
std::string User::getUserName() { return m_userName; }
std::string User::getPassword() { return m_password; }
bool User::isAdminUser() { return m_isAdmin; }

// setter functions
void User::setName(const std::string& name) { m_name = name; }

void User::setFatherName(const std::string& fatherName) { m_fatherName = fatherName; }
void User::setUserName(const std::string& userName) { m_userName = userName; }
void User::setPassword(const std::string& password) { m_password = password; }
void User::setAdmin(const bool& isAdminUser) { m_isAdmin = isAdminUser; }


// get full detail of a user

int User::getFullDetails(){
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Father Name: " << m_fatherName << std::endl;
    std::cout << "Username: " << m_userName << std::endl;
    std::cout << "Password: " << m_password << std::endl;
    std::cout << (m_isAdmin ? "You are an admin" : "") << std::endl;
    std::cout << "Press any key to continue" << std::endl;
    system("pause");
    return 2;
}


int User::displayMenu() {
    while (true) {
        system("cls");
        std::cout << "Welcome " << m_name << "! to our market place" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "1. View Available Products" << std::endl;
        std::cout << "2. View Cart and checkout" << std::endl;
        std::cout << "3. View your details" << std::endl;
        std::cout << "4. add product to cart" << std::endl;
		std::cout << "5. Logout" << std::endl;
        std::cout<<"6. Exit"<<std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        choice = Utils::getInt(1, 6);
        switch (choice){
            case 1:return 5;
            case 2:return 4;
            case 3:return 3;
            case 4:return 10;
            case 5:return 1;
            case 6: return -1;
        }

    }
}

// login function
User* User::login(std::vector<User*>& users){
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
	std::cin >> password;
	for (int i = 0; i < users.size(); i++) {
		if (users[i]->getUserName() == username && users[i]->getPassword() == password) {
            std::cout << "Login successful" << std::endl;
			return users[i];
		}
	}
    std::cout << "Invalid username or password" << std::endl;
    system("pause");
	return nullptr;



}

std::string User::userToString() {
    std::string result;
    std::string type = m_isAdmin ? "admin" : "customer";
    result = type + "," + m_name + "," + m_fatherName + "," + m_userName + "," + m_password;
    return result;
}