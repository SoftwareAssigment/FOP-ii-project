#include "Product.h"
#include "utils.h"

// new product without id
Product::Product(const std::string& name, const std::string& categort, const double& price , const int& quantity)
{
	m_name = name;
	m_id = Utils::UUID();
	m_category = categort;
	m_price = price;
	m_quantity = quantity;

}
// product with id
Product::Product(const std::string& id, const std::string& name, const std::string& categort, const double& price, const int& quantity)
{
	m_name = name;
	m_id = id;
	m_category = categort;
	m_price = price;
	m_quantity = quantity;

}


// getters
std::string Product::getName()
{
	return m_name;
}

std::string Product::getId()
{
	return m_id;
}

std::string Product::getCategory()
{
	return m_category;
}

double Product::getPrice()
{
	return m_price;
}

int Product::getQuantity()
{
	return m_quantity;
}

// setters
void Product::setName(const std::string& name)
{
	m_name = name;
}

void Product::setId(const std::string& id)
{
	m_id = id;
}

void Product::setCategory(const std::string& category)
{
	m_category = category;
}

void Product::setPrice(const double& price)
{
	m_price = price;
}

void Product::setQuantity(const int& quantity)
{
	m_quantity = quantity;
}


void Product::print()
{
	std::cout << " ID: " << m_id <<" Name: "<<m_name<<" Category: "<<m_category<<" Price: "<<m_price<<"Birr"<<" Available Quantity: "<<m_quantity<<std::endl;
}

void Product::viewAllProduct(std::vector<Product*> products)
{
	for (int i = 0; i < products.size(); i++)
	{
		std::cout << i + 1 << ". ";
		products[i]->print();
		std::cout << std::endl;
	}
	system("pause");
}

Product* Product::getProduct(std::vector<Product*> products){

	for (long unsigned int i = 1; i <= products.size(); i++)
	{
		std::cout << i << ". ";
		products[i-1]->print();
		std::cout << std::endl;
	}
	std::cout << "Enter the product number you want to buy: ";
	long unsigned int productNumber;
	productNumber = Utils::getInt(1, products.size());
	return products[productNumber - 1];


}

std::string Product::productToString()
{
	std::string productString =  m_id+ "," + m_name + "," + m_category + "," + std::to_string(m_price) + "," + std::to_string(m_quantity);
	return productString;
}
