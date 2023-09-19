#include "Data.h"
// add mysql connector to project

// connect to database and return connection object
// connect to mysql database
// define static vectors

std::vector<User*> Data::users = {};
std::vector<Product*> Data::products = {};
std::vector<Order*> Data::orders = {};

std::vector<User*> Data::readUsers() {

	// open the file
	std::ifstream file("users.txt");

	// if the file is not open, print an error message and return
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}

	// while there is a line in the file read the users 
	std::string line;

	while (std::getline(file, line)) {
		try {
			// split the line into tokens
			std::vector<std::string> tokens = Utils::split(line, ',');

			// if the user is an admin
			if (tokens[0] == "admin") {

				// create a new admin
				Admin* admin = new Admin(tokens[1], tokens[2], tokens[3], tokens[4]);

				// add the admin to the vector
				users.push_back(admin);
			}

			// if the user is a customer
			else if (tokens[0] == "customer") {

				// create a new customer
				Customer* customer = new Customer(tokens[1], tokens[2], tokens[3], tokens[4]);

				// add the customer to the vector
				users.push_back(customer);
			}
			// if it is a product
			else if (tokens[0] == "product") {

				// get the customer last added to the vector
				Customer* customer = (Customer*)users[users.size() - 1];

				// create a new product
				Product product = Product(tokens[1], tokens[2], tokens[3], std::stod(tokens[4]), std::stoi(tokens[5]));

				// add product to customer cart
				customer->addToCartWithoutMessage(product);
			}
		}
		catch (std::string err) {
			continue;
		}
	}

	// close the file
	file.close();
	// return the vector
	return users;
}

// read products from file
std::vector<Product*> Data::readProducts(){

	// open the file
	std::fstream file("products.txt");

	// if the file is not open, print an error message and return
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}

	// while there is a line in the file read the products
	std::string line;
	
		while (std::getline(file, line)) {
			try {
			// split the line into tokens
			std::vector<std::string> tokens = Utils::split(line, ',');

			// create a new product
			Product* product = new Product(tokens[0], tokens[1], tokens[2], std::stod(tokens[3]), std::stoi(tokens[4]));

			// add the product to the vector 
			products.push_back(product);
			}
			catch (std::string err) {
				continue;
			}
		}
	
	

	file.close();
	return products;

}

// read orders from file
std::vector<Order*> Data::readOrders() {
	std::fstream file("orders.txt");
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return {};
	}
	std::string line;
	while (std::getline(file, line)) {
		try {
			std::vector<std::string> tokens = Utils::split(line, ',');
			if (tokens[0] == "order") {
				std::time_t date = std::stol(tokens[3]);
				orders.push_back(new Order(tokens[1], tokens[2], {}, date));
			}
			else if (tokens[0] == "product") {
				Product product = Product(tokens[1], tokens[2], tokens[3], std::stod(tokens[4]), std::stoi(tokens[5]));
				orders[orders.size() - 1]->addProduct(product);
			}

		}
		catch(std::string err){
			continue;
		}
	}
	file.close();
	return orders;

}

// write users to file
void Data::writeUsers() {
	std::ofstream file;
	file.open("users.txt", std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open()) {
		std::cout << "Error opening file to write users" << std::endl;
		system("pause");
		return;
	}
	for (User* user : users) {
		file << user->userToString() << std::endl;
		if (dynamic_cast<Customer*>(user)) {
			Customer* customer = (Customer*)user;
			for (Product product : customer->getCart()) {
				file <<"product," + product.productToString() << std::endl;
			}
		}
	}
	file.close();
}


// write products to file
void Data::writeProducts() {
	std::ofstream file;
	file.open("products.txt", std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	// clear the file
	file.clear();
	for (Product* product : products) {
		file << product->productToString() << std::endl;
	}
	file.close();
}

// write orders to file
void Data::writeOrders() {
	std::ofstream file;
	file.open("orders.txt", std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return;
	}
	// clear the file
	file.clear();
	for (Order* order : orders) {
		file << "order,"+order->orderToString() << std::endl;
		std::vector<Product> product = order->getProducts();
		for (int i = 0; i < product.size();i++ ) {
		file << "product," + product[i].productToString() << std::endl;
		
		}
	}
	file.close();
}
