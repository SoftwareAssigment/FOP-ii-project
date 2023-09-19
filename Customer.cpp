#include "Customer.h"
#include "Data.h"

Customer::Customer(const std::string& name, const std::string& fatherName, const std::string& userName,
    const std::string& password): User(name, fatherName, userName, password, false) {}
void Customer::registerCustomer(std::vector<User*>& users) {
    std::string name, fatherName, userName, password;
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
	    users.push_back(new Customer(name, fatherName, userName, password));
	    std::cout << "User registered successfully login to accses your account" << std::endl;
	    Sleep(1000);
}
int Customer::myCart() {
    while (true) {


        system("cls");
        std::cout << "My Cart" << std::endl;
        std::cout << "---------" << std::endl;


        if (m_cart.size() == 0)
        {
            std::cout << "Your cart is empty" << std::endl;
            system("pause");
            return 2;
            
        }

        else
        {
            double total = 0;
            for (long unsigned int i = 0; i < m_cart.size(); i++)
            {
                std::cout << i + 1 << ". " << m_cart[i].getName() << "--------" << m_cart[i].getPrice() << std::endl;
                total += m_cart[i].getPrice();
            }
            std::cout << "Your total price is: " << total << std::endl;
            std::cout << "enter 1 to place order" << std::endl;
            std::cout << "enter 2 to delete item from cart" << std::endl;
        }
 
        std::cout << "enter 0 to go back" << std::endl;

        int choice;
        choice = Utils::getInt(0, 2);

        if (choice == 0) return 2;
        else if (choice == 1) {
            // add order to data
            Order::makeOrder(m_cart,m_userName,Data::orders);
            std::cout << "Order placed successfully" << std::endl;
            Sleep(1000);
            return 2;
        }



        else if (choice == 2) {
            std::cout << "enter the item row number you want to delete: ";
            int item;
            item = Utils::getInt(1, m_cart.size());


            m_cart.erase(m_cart.begin() + item - 1);
            std::cout << "Item deleted successfully" << std::endl;
            Sleep(1000);
            return 4;

        }

    }
}


void Customer::addToCart(Product& product) {
    m_cart.push_back(product);
    std::cout << "Item added successfully" << std::endl;
    system("pause");
}

void Customer::addToCartWithoutMessage(Product& product) {
	m_cart.push_back(product);
}

std::vector<Product> Customer::getCart() {
    return m_cart;
}