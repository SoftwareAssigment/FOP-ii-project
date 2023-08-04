#pragma once
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include<ctime>
#include "Order.h"
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Product.h"
#include "Utils.h"

// a class to store all data in file and read and write to file
class Data
{
private:
	
	
public:
	// a vector of pointers to all users
	static std::vector<User*> users;

	// a vector of pointers to all products
	static std::vector<Product*> products;

	// a vector of pointers to all orders
	static std::vector<Order*> orders;

	// a static function to read all users from file
	static std::vector<User*> readUsers();

	// a static function to read all products from file
	static std::vector<Product*> readProducts();

	// a static function to read all orders from file
	static std::vector<Order*> readOrders();

	// a static function to write all users to file
	static void writeUsers();

	// a static function to write all products to file
	static void writeProducts();

	// a static function to write all orders to file
	static void writeOrders();




};

