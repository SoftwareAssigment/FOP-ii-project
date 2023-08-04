#pragma once
#include "User.h"
#include "Order.h"
class Customer : public User
{

public:

	// the constructor
	Customer(const std::string& name, const std::string& fatherName, const std::string& userName, 
    const std::string& password);

	// The function responsible for managing the customer's cart
	int myCart();
	// get cart
	std::vector<Product> getCart();
	// add a product to the cart
	void addToCart(Product&);

	// add to cart without message
	void addToCartWithoutMessage(Product&);

	// register a new customer
	static void registerCustomer(std::vector<User*>&);

};

