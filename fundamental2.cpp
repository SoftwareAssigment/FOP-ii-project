#include <iostream>
#include "Utils.h"
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Data.h"
//#include "C:\Program Files\MySQL\Connector C++ 1.1\include\cppconn\driver.h"
/*
1. main menu
2. user menu
3. get full details
4. my cart
5. view all products
6. login as customer
7. login as admin
8. register as customer
9. register as admin
10. add product to cart
11. add product
12. remove product
13. update product
14. view all customers
15. view all orders

*/

void setInitialAppState(User*& user, int& menu, bool& isAdmin, bool& isLoggedIn) {
    user = nullptr;
    menu = 1;
    isLoggedIn = false;
    isAdmin = false;
}

int main()
{

    //read data from files
    Data::readUsers();
    Data::readProducts();
    Data::readOrders();

    User* user = nullptr; // this will hold the current user
    int menu = 1; // this will hold the current menu
    bool isLoggedIn = false;
    bool isAdmin = false;


    while (true) {
        if (menu == -1) {
            Data::writeUsers();
            Data::writeProducts();
            Data::writeOrders();
            Utils::exitProgam();

        }
        if (!isLoggedIn || menu == 1) {


            // reset the state of the program to the initial state
            setInitialAppState(user, menu, isAdmin, isLoggedIn);

            // save data to files
            Data::writeUsers();
            Data::writeProducts();
            Data::writeOrders();

            menu = Utils::mainMenu();
            switch (menu) {

            case 6:
                std::cout << "loging you as customer" << std::endl;
                user = User::login(Data::users);
                if (user != nullptr) {
                    isLoggedIn = true;
                    isAdmin = false;
                    menu = 2;
                }
                break;

            case 7:
                std::cout << "loging you as admin" << std::endl;
                user = User::login(Data::users);
                if (user != nullptr && !user->isAdminUser()) {
                    std::cout << "sorry you are not an admin";
                    system("pause");
                    user = nullptr;
                }
                else if (user != nullptr && user->isAdminUser()) {
                    isLoggedIn = true;
                    isAdmin = true;
                    menu = 2;
                }
                break;

            case 8:
                std::cout << "registering you as customer" << std::endl;
                Customer::registerCustomer(Data::users);
                break;
            case 9:
                std::cout << "registering you as admin" << std::endl;
                Admin::registerAdmin(Data::users);
                break;
            }

            continue;
        }

        switch (menu) {
        case 2:
            menu = user->displayMenu();
            break;

        case 3:
            menu = user->getFullDetails();
            break;

        case 4:
            // cast the user pointer to a customer pointer
            if (dynamic_cast<Customer*>(user) != nullptr) {
                menu = dynamic_cast<Customer*>(user)->myCart();
            }
            else {
                std::cout << "You are not a customer" << std::endl;
                menu = 2;
            }
            break;
        case 5:
            Product::viewAllProduct(Data::products);
            menu = 2;
            break;
        case 10:
            if (dynamic_cast<Customer*>(user) != nullptr) {
                Product* product = Product::getProduct(Data::products);
                if (product != nullptr) {
                    dynamic_cast<Customer*>(user)->addToCart(*product);
                    menu = 4;
                    
                }
                menu = 2;
            }
            else {
                std::cout << "You are not a customer" << std::endl;
                menu = 2;
            }
            break;
        case 11:
            if (isAdmin) {
                menu = dynamic_cast<Admin*>(user)->addProduct(Data::products);
            }
            else {
                std::cout << "You are not an admin" << std::endl;
                menu = 2;
            }
            break;
        case 12:
            if (isAdmin) {
                menu = dynamic_cast<Admin*>(user)->deleteProduct(Data::products);
            }
            else {
                std::cout << "You are not an admin" << std::endl;
                menu = 2;
            }
            break;
        case 13:
            if (isAdmin) {
                menu = dynamic_cast<Admin*>(user)->editProduct(Data::products);
            }
            else {
                std::cout << "You are not an admin" << std::endl;
                menu = 2;
            }
            break;
        case 14:
            if (isAdmin) {
                for (int i = 0; i < Data::users.size(); i++) {
                    if (dynamic_cast<Customer*>(Data::users[i]) != nullptr) {
                        std::cout << dynamic_cast<Customer*>(Data::users[i])->getUserName() << std::endl;
                    }
                }
                system("pause");
                menu = 2;
            }
            else {
                std::cout << "You are not an admin" << std::endl;
                menu = 2;
            }
            break;
        case 15:
            if (isAdmin) {
                for (int i = 0; i < Data::orders.size(); i++) {
                    //std::cout << Data::orders[i]->orderToString() << std::endl;
                    //std::vector<Product> cur_products = Data::orders[i]->getProducts();
                    //for (int j = 0; j < cur_products.size(); j++) {
                     //   std::cout << "\t" << cur_products[j].productToString() << std::endl;
                    //}
                    Data::orders[i]->displayOrder();
              
                }
                system("pause");
                menu = 2;
            }
            else {
                std::cout << "You are not an admin" << std::endl;
                menu = 2;
            }
            break;
        }

    }

}
