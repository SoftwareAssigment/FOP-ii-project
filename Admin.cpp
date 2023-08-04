#include "Admin.h"
Admin::Admin(const std::string& name, const std::string& fatherName, const std::string& userName,
    const std::string& password) : User(name, fatherName, userName, password, true) {}



void Admin::registerAdmin(std::vector<User*>& users) {
    std::string name, fatherName, userName, password, adminPasscode;
    std::cout << "enter the admin passcode to register" << std::endl;
    std::cin >> adminPasscode;
    if (adminPasscode != "12345678") {
        std::cout<<"wrong admin passcode"<<std::endl;
        Sleep(1000);
		return;
    }

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your father name: ";
    std::cin >> fatherName;
    std::cout << "Enter your username: ";
    std::cin >> userName;
    std::cout << "Enter your password: ";
    std::cin >> password;
    for (long unsigned int i = 0; i < users.size(); i++) {
        if (users[i]->getUserName() == userName) {
            std::cout << "User already exists, sign in to use accoutn" << std::endl;
            Sleep(1000);
            return;
        }
    }
    users.push_back(new Admin(name, fatherName, userName, password));
    std::cout << "Admin registered successfully login to accses your account" << std::endl;
    Sleep(1000);
}

int Admin::displayMenu() {
    system("cls");
    std::cout<<"Hello "<<getName()<<" Wellcome tho the admin pannel" << std::endl;
    std::cout<<"-------------------------------------------------------"<<std::endl;
    std::cout << "1. Add new product" << std::endl;
    std::cout << "2. Remove product" << std::endl;
    std::cout << "3. Edit product or restock" << std::endl;
    std::cout<<"4. View all products"<<std::endl;
    std::cout<<"5. View all Customers"<<std::endl;
    std::cout<<"6. View all orders"<<std::endl;
    std::cout << "7. Logout" << std::endl;
    std::cout<<"8. Exit"<<std::endl;
    int choice;
    choice = Utils::getInt(1, 8);
    switch (choice) {
        case 1: return 11;
        case 2: return 12;
        case 3: return 13;
        case 4: return 5;
        case 5: return 14;
        case 6: return 15;
        case 7: return 1;
        case 8: return -1;
    }



}

int Admin::editProduct(std::vector<Product*>& products) {
    Product::viewAllProduct(products);
    std::cout << "Enter the id of the product you want to edit" << std::endl;
    int id = Utils::getInt(1, products.size());
    std::cout<<"1. Edit name"<<std::endl;
    std::cout<<"2. Edit price"<<std::endl;
    std::cout<<"3. Edit quantity"<<std::endl;
    std::cout<<"4. Edit category"<<std::endl;
    int choice = Utils::getInt(1, 4);
    switch (choice) {
		case 1: {
			std::cout<<"Enter the new name"<<std::endl;
			std::string name;
			std::cin>>name;
			products[id - 1]->setName(name);
			break;
		}
		case 2: {
			std::cout<<"Enter the new price"<<std::endl;
			double price;
			std::cin>>price;
			products[id - 1]->setPrice(price);
			break;
		}
		case 3: {
			std::cout<<"Enter the new quantity"<<std::endl;
			int quantity;
			quantity = Utils::getInt(1, 1000000);
			products[id - 1]->setQuantity(quantity);
			break;
		}
		case 4: {
			std::cout<<"Enter the new category"<<std::endl;
			std::string category;
			std::cin>>category;
			products[id - 1]->setCategory(category);
			break;
		}
	}
    std::cout << "Product edited successfully" << std::endl;
	system("pause");
	return 2;

}

int Admin::deleteProduct(std::vector<Product*>& products) {
    Product::viewAllProduct(products);
    std::cout << "Enter the id of the product you want to delete" << std::endl;
    int id = Utils::getInt(1, products.size());
    products.erase(products.begin() + id - 1);
    std::cout << "Product deleted successfully" << std::endl;
    system("pause");
    return 2;
}

int Admin::addProduct(std::vector<Product*>& products) {
	std::string name, category;
	double price;
	int quantity;
	std::cout << "Enter the name of the product" << std::endl;
	std::cin >> name;
	std::cout << "Enter the price of the product" << std::endl;
	std::cin >> price;
	std::cout << "Enter the quantity of the product" << std::endl;
	quantity = Utils::getInt(1, 1000000);
	std::cout << "Enter the category of the product" << std::endl;
	std::cin >> category;
	products.push_back(new Product(name, category, price, quantity));
	std::cout << "Product added successfully" << std::endl;
	system("pause");
	return 2;
}