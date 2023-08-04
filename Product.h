#pragma once
#include <iostream>
#include <string>
#include <vector>
class Product
{
private:


	//name of the product
	std::string m_name;

	// a unique id for each product
	std::string m_id;

	// the category of the product
	std::string m_category;

	// the price of the product
	double m_price;

	// the quantity of the product
	int m_quantity;
public:

	// the constructor
	Product(const std::string&, const std::string&, const double&, const int&);
	// product with id
	Product(const std::string&, const std::string&, const std::string&, const double&, const int&);

	// funcrions to get private members
	std::string getName();
	std::string getId();
	std::string getCategory();
	double getPrice();
	int getQuantity();

	// functions to set private members
	void setName(const std::string&);
	void setId(const std::string&);
	void setCategory(const std::string&);
	void setPrice(const double&);
	void setQuantity(const int&);
	void print();
	std::string productToString();

	// static vector show products
    static void viewAllProduct(std::vector<Product*>);

	// static function to get a specific product 
	static Product* getProduct(std::vector<Product*>);

};


