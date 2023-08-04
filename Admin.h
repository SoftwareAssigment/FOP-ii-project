#pragma once
#include "User.h"
class Admin : public User
{
public:

	// the constructor
	Admin(const std::string& name, const std::string& fatherName, const std::string& userName,
		const std::string& password);

	// register a new admin
	static void registerAdmin(std::vector<User*>& users);

	// display the admin menu
	int displayMenu() override;

	// choose and edit a product used for restocking too
	int editProduct(std::vector<Product*>& products);

	// delete a product
	int deleteProduct(std::vector<Product*>& products);

	// add a new product
	int addProduct(std::vector<Product*>& products);
};
