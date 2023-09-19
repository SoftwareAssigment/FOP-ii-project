#include "Order.h"	
#include "Data.h"

Order::Order(std::string username, std::vector<Product> products) {
	m_orderId = Utils::UUID();
	m_customerUsername = username;
	m_products = products;
	m_orderDate = std::time(0);
 }
// order with id
Order::Order(std::string id, std::string username, std::vector<Product> products,std::time_t time) {
	m_orderId = id;
	m_customerUsername = username;
	m_products = products;
	m_orderDate = time;
}
void Order::makeOrder(std::vector<Product>& products, std::string username, std::vector<Order*>& tot_orders) {
	//  products vector to product * vector


	Order* order = new Order(username, products);
	Data::orders.push_back(order);
	products = {};


}
void Order::addProduct(Product& product) {
	m_products.push_back(product);
	std::cout << product.productToString();
}

void Order::displayOrder() {
	std::cout<< "Order ID: " << m_orderId << " ordered by: " << m_customerUsername <<
		" contains: " << std::endl;
	double total = 0;
	for (int i = 0; i < m_products.size(); i++) {
		std::cout << m_products[i].getName() << " ---- " << m_products[i].getPrice() << std::endl;
		total += m_products[i].getPrice();
		}
	std::cout << "Total: " << total << std::endl;
}

std::vector<Product> Order::getProducts() {
	return m_products;
}

std::string Order::orderToString() {
	std::string result = m_orderId + "," + m_customerUsername + "," + std::to_string(m_orderDate);
	return result;
}