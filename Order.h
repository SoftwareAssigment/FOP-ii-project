#pragma once
#include<iostream>
#include<vector>
#include "Product.h"
#include "Utils.h"
#include <ctime>
class Order
{
private:


	// a unique id for each order
	std::string m_orderId; 

	// the username of the customer who made the order
	std::string m_customerUsername; 

	// a vector of pointers to the products in the order
	std::vector<Product> m_products; 
	// order date using ctime
	std::time_t m_orderDate;


public:
	// a static vector to store all orders
	static void makeOrder(std::vector<Product>&, std::string username, std::vector<Order*>&);

	// order with id and time
	Order(std::string id, std::string username, std::vector<Product> products, std::time_t orderDate);

	// get products
	std::vector<Product> getProducts();
	// the constructor
	Order(std::string username, std::vector<Product> products);

	// add product to an order
	void addProduct(Product&);

	// display the current order
	void displayOrder();

	//order to string
	std::string orderToString();
};

