# Inventory Management System Documentation

Welcome to the documentation for the Inventory Management System! This document provides a comprehensive guide on how to use and understand the various classes and functions of the system.

### Table of Contents

1. [Utils Class](#utils-class)
2. [Product Class](#product-class)
3. [User Class](#user-class)
4. [Admin Class](#admin-class)
5. [Customer Class](#customer-class)
6. [Order Class](#order-class)
7. [Data Class](#data-class)

---
## Utils Class 

The `Utils` class is a utility class that provides various helper functions to assist in the functionality of the inventory management system. These functions handle user input validation, menu display, and string manipulation. Below, you will find detailed documentation for each function in the class.

## Class: Utils

### Public Static Functions:

#### `static void exitProgram()`    

This function is used to exit the inventory management system. It clears the screen, displays a farewell message, waits for a short period, and then exits the program.

**Parameters:**
None

**Return:**
None

#### `static int getInt()`

This function is responsible for obtaining integer input from the user. It validates the input and continues prompting the user until a valid integer is entered.

**Parameters:**
None

**Return:**
- `int`: The integer value entered by the user.

#### `static int getInt(int min, int max)`

This function is similar to `getInt()`, but it additionally checks if the entered integer falls within a specified range. It continues to prompt the user until a valid integer within the given range is entered.

**Parameters:**
- `int min`: The minimum allowed value for the input.
- `int max`: The maximum allowed value for the input.

**Return:**
- `int`: The integer value entered by the user within the specified range.

#### `static float getFloat()`

This function is responsible for obtaining float input from the user. It validates the input and continues prompting the user until a valid float is entered.

**Parameters:**
None

**Return:**
- `float`: The float value entered by the user.

#### `static int mainMenu()`

This function displays the main menu of the inventory management system. It presents a list of options to the user and handles their selection.

**Parameters:**
None

**Return:**
- `int`: The user's choice represented as an integer, which corresponds to the selected option in the menu.

#### `static std::vector<std::string> split(std::string str, char delimiter)`

This function is used to split a string into a vector of substrings based on a specified delimiter.

**Parameters:**
- `std::string str`: The input string to be split.
- `char delimiter`: The character that acts as a delimiter to split the string.

**Return:**
- `std::vector<std::string>`: A vector containing the substrings resulting from the split operation.

## Usage:

The `Utils` class provides essential utility functions that can be used throughout the inventory management system. To utilize these functions, simply include the "Utils.h" header file in the relevant parts of your application.

Example usage of `getInt()`:
```cpp
#include "Utils.h"
#include <iostream>

int main() {
    int num = Utils::getInt(); // Asks the user to enter an integer and validates the input.
    std::cout << "You entered: " << num << std::endl;
    return 0;
}
```

Example usage of `split()`:
```cpp
#include "Utils.h"
#include <iostream>

int main() {
    std::string inputStr = "apple,banana,orange";
    char delimiter = ',';
    std::vector<std::string> fruits = Utils::split(inputStr, delimiter);
    
    for (const std::string& fruit : fruits) {
        std::cout << fruit << std::endl;
    }
    return 0;
}
```
## Product Class 

The `Product` class represents a product in the inventory management system. Each product has a unique ID, name, category, price, and quantity. This class provides functions to access and modify these properties. Additionally, it includes static functions to display all products and retrieve a specific product from a collection.

## Class: Product

### Private Static Member:

#### `static int m_idGenerator`

This static variable is used to generate a unique ID for each product. It ensures that each product has a distinct identifier.

### Private Members:

#### `std::string m_name`

This member stores the name of the product.

#### `std::string m_id`

This member represents the unique ID of the product.

#### `std::string m_category`

This member stores the category of the product.

#### `double m_price`

This member holds the price of the product.

#### `int m_quantity`

This member represents the quantity of the product available in the inventory.

### Public Functions:

#### `Product(const std::string name, const std::string& category, const double& price, const int& quantity)`

This is the constructor of the `Product` class. It is used to initialize a new product object with the provided name, category, price, and quantity. It automatically generates a unique ID for the product using the `m_idGenerator`.

**Parameters:**
- `const std::string name`: The name of the product.
- `const std::string& category`: The category of the product.
- `const double& price`: The price of the product.
- `const int& quantity`: The quantity of the product.

**Note:** The constructor automatically generates a unique ID for the product.

#### `std::string getName()`

This function returns the name of the product.

**Parameters:**
None

**Return:**
- `std::string`: The name of the product.

#### `std::string getId()`

This function returns the unique ID of the product.

**Parameters:**
None

**Return:**
- `std::string`: The unique ID of the product.

#### `std::string getCategory()`

This function returns the category of the product.

**Parameters:**
None

**Return:**
- `std::string`: The category of the product.

#### `double getPrice()`

This function returns the price of the product.

**Parameters:**
None

**Return:**
- `double`: The price of the product.

#### `int getQuantity()`

This function returns the quantity of the product available in the inventory.

**Parameters:**
None

**Return:**
- `int`: The quantity of the product.

#### `void setName(const std::string& name)`

This function is used to set or update the name of the product.

**Parameters:**
- `const std::string& name`: The new name of the product.

**Return:**
None

#### `void setId(const std::string& id)`

This function is used to set or update the unique ID of the product.

**Parameters:**
- `const std::string& id`: The new unique ID of the product.

**Return:**
None

#### `void setCategory(const std::string& category)`

This function is used to set or update the category of the product.

**Parameters:**
- `const std::string& category`: The new category of the product.

**Return:**
None

#### `void setPrice(const double& price)`

This function is used to set or update the price of the product.

**Parameters:**
- `const double& price`: The new price of the product.

**Return:**
None

#### `void setQuantity(const int& quantity)`

This function is used to set or update the quantity of the product available in the inventory.

**Parameters:**
- `const int& quantity`: The new quantity of the product.

**Return:**
None

#### `void print()`

This function prints the details of the product, including its ID, name, category, price, and available quantity.

**Parameters:**
None

**Return:**
None

#### `static void viewAllProduct(std::vector<Product*> products)`

This static function displays all the products present in the inventory.

**Parameters:**
- `std::vector<Product*> products`: A vector containing pointers to all the products.

**Return:**
None

#### `static Product* getProduct(std::vector<Product*> products)`

This static function is used to obtain a specific product from the inventory. It displays all the available products and prompts the user to select one.

**Parameters:**
- `std::vector<Product*> products`: A vector containing pointers to all the products.

**Return:**
- `Product*`: A pointer to the selected product.

#### `std::string productToString()`

This function converts the product information into a string format.

**Parameters:**
None

**Return:**
- `std::string`: A string containing the product information in the following format: "name,id,category,price,quantity"

## Usage:

The `Product` class represents the core entity in the inventory management system. To utilize this class, include the "Product.h" header file in your application.

Example usage:
```cpp
#include "Product.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Product*> products;
    products.push_back(new Product("Product A", "Category X", 10.99, 50));
    products.push_back(new Product("Product B", "Category Y", 5.50, 100));
    
    Product::viewAllProduct(products);
    
    Product* selectedProduct = Product::getProduct(products);
    
    std::cout << "You selected: " << selectedProduct->getName() << std::endl;
    
    // Remember to release memory for dynamically allocated products
    
    return 0;
}
```
## User Class 

The `User` class represents a user in the inventory management system. Users can be either customers or administrators. Each user has a name, father's name, username, password, and a flag indicating whether they are an admin or not. The class provides functions to access and modify user information, display menus based on user roles, and handle user login.

## Class: User

### Private Members:

#### `std::string m_name`

This member stores the name of the user.

#### `std::string m_fatherName`

This member stores the father's name of the user.

#### `std::string m_userName`

This member stores the username of the user.

#### `std::string m_password`

This member stores the password of the user.

#### `bool m_isAdmin`

This member is a boolean flag that indicates whether the user is an administrator (`true`) or a customer (`false`).

#### `std::vector<Product> m_cart`

This member is a vector that stores the products in the user's shopping cart. 

### Public Functions:

#### `User()`

This is the default constructor of the `User` class. It initializes the `m_isAdmin` flag to `false`.

**Parameters:**
None

#### `User(const std::string& name, const std::string& fatherName, const std::string& userName, const std::string& password, const bool& isAdmin)`

This constructor allows you to create a `User` object with the provided information.

**Parameters:**
- `const std::string& name`: The name of the user.
- `const std::string& fatherName`: The father's name of the user.
- `const std::string& userName`: The username of the user.
- `const std::string& password`: The password of the user.
- `const bool& isAdmin`: A boolean flag indicating whether the user is an administrator (`true`) or a customer (`false`).

#### `std::string getName()`

This function returns the name of the user.

**Parameters:**
None

**Return:**
- `std::string`: The name of the user.

#### `std::string getFatherName()`

This function returns the father's name of the user.

**Parameters:**
None

**Return:**
- `std::string`: The father's name of the user.

#### `std::string getUserName()`

This function returns the username of the user.

**Parameters:**
None

**Return:**
- `std::string`: The username of the user.

#### `std::string getPassword()`

This function returns the password of the user.

**Parameters:**
None

**Return:**
- `std::string`: The password of the user.

#### `bool isAdminUser()`

This function checks whether the user is an administrator.

**Parameters:**
None

**Return:**
- `bool`: Returns `true` if the user is an administrator, otherwise `false`.

#### `void setName(const std::string& name)`

This function is used to set or update the name of the user.

**Parameters:**
- `const std::string& name`: The new name of the user.

**Return:**
None

#### `void setFatherName(const std::string& fatherName)`

This function is used to set or update the father's name of the user.

**Parameters:**
- `const std::string& fatherName`: The new father's name of the user.

**Return:**
None

#### `void setUserName(const std::string& userName)`

This function is used to set or update the username of the user.

**Parameters:**
- `const std::string& userName`: The new username of the user.

**Return:**
None

#### `void setPassword(const std::string& password)`

This function is used to set or update the password of the user.

**Parameters:**
- `const std::string& password`: The new password of the user.

**Return:**
None

#### `void setAdmin(const bool& isAdmin)`

This function is used to set or update the user's role as an administrator or customer.

**Parameters:**
- `const bool& isAdmin`: Set to `true` if the user is an administrator, `false` if the user is a customer.

**Return:**
None

#### `int getFullDetails()`

This function displays the full details of the user, including their name, father's name, username, password, and role (admin or customer). It waits for user input to continue.

**Parameters:**
None

**Return:**
- `int`: A value of `2` to indicate the user has chosen to continue.

#### `int displayMenu()`

This function displays a menu based on the user's role (admin or customer) and prompts them to choose an option. It returns the user's choice.

**Parameters:**
None

**Return:**
- `int`: The user's choice represented as an integer, which corresponds to the selected option in the menu.

#### `std::string userToString()`

This function converts the user information into a string format.

**Parameters:**
None

**Return:**
- `std::string`: A string containing the user information in the following format: "type,name,fatherName,userName,password" (where type is "admin" or "customer").

#### `static User* login(std::vector<User*>& users)`

This static function is used to handle user login. It prompts the user to enter their username and password. If the login is successful, it returns a pointer to the corresponding `User` object. Otherwise, it returns `nullptr`.

**Parameters:**
- `std::vector<User*>& users`: A vector containing pointers to all the users in the system.

**Return:**
- `User*`: A pointer to the `User` object if the login is successful, otherwise `nullptr`.

## Usage:

The `User` class represents the base class for both customers and administrators in the inventory management system. To utilize this class, include the "User.h" header file in your application.

Example usage:
```cpp
#include "User.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector to store users
    std::vector<User*> users;
    users.push_back(new User("John Doe", "Mike", "john_doe", "password123", false));
    users.push_back(new User("Admin1", "Admin Father", "admin1", "adminpass", true));
    
    // Perform login
    User* loggedInUser = User::login(users);
    if (loggedInUser) {
        std::cout << "Welcome, " << loggedInUser->getName() << "!" << std::endl;
        int choice = loggedInUser->displayMenu();
        // Perform actions based on the user's choice...
    }
    
    // Don't forget to release memory for dynamically allocated users
    
    return 0;
}
```
## Admin Class

The `Admin` class is derived from the `User` class and represents an administrator in the inventory management system. Administrators have additional functionalities beyond regular users, such as adding, editing, and deleting products.

## Class: Admin

### Public Functions:

#### `Admin(const std::string& name, const std::string& fatherName, const std::string& userName, const std::string& password)`

This constructor creates an `Admin` object with the provided name, father's name, username, and password. It sets the `m_isAdmin` flag to `true` to indicate that this user is an administrator.

**Parameters:**
- `const std::string& name`: The name of the admin.
- `const std::string& fatherName`: The father's name of the admin.
- `const std::string& userName`: The username of the admin.
- `const std::string& password`: The password of the admin.

#### `static void registerAdmin(std::vector<User*>& users)`

This static function allows the registration of a new admin. It prompts the user to enter a passcode for registration. If the correct passcode is provided, the function proceeds with the admin registration process. It creates a new `Admin` object and adds it to the `users` vector.

**Parameters:**
- `std::vector<User*>& users`: A vector containing pointers to all the users in the system.

#### `int displayMenu() override`

This function overrides the `displayMenu()` function from the base class `User`. It displays the admin menu with additional options available to administrators. It returns the user's choice.

**Parameters:**
None

**Return:**
- `int`: The user's choice represented as an integer, which corresponds to the selected option in the admin menu.

#### `int editProduct(std::vector<Product*>& products)`

This function allows the admin to edit a specific product. It displays all the available products, prompts the admin to select a product by its ID, and then provides options to edit the product's name, price, quantity, or category. The function updates the product's details based on the admin's choice.

**Parameters:**
- `std::vector<Product*>& products`: A vector containing pointers to all the products in the system.

**Return:**
- `int`: A value of `2` to indicate the admin has chosen to continue.

#### `int deleteProduct(std::vector<Product*>& products)`

This function allows the admin to delete a specific product. It displays all the available products and prompts the admin to select a product by its ID. The function then removes the selected product from the `products` vector.

**Parameters:**
- `std::vector<Product*>& products`: A vector containing pointers to all the products in the system.

**Return:**
- `int`: A value of `2` to indicate the admin has chosen to continue.

#### `int addProduct(std::vector<Product*>& products)`

This function allows the admin to add a new product to the inventory. The admin provides the product's name, price, quantity, and category, and the function creates a new `Product` object and adds it to the `products` vector.

**Parameters:**
- `std::vector<Product*>& products`: A vector containing pointers to all the products in the system.

**Return:**
- `int`: A value of `2` to indicate the admin has chosen to continue.

## Usage:

The `Admin` class represents a specialized user role in the inventory management system, granting administrative privileges. To utilize this class, include the "Admin.h" header file in your application.

Example usage:
```cpp
#include "Admin.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector to store users
    std::vector<User*> users;
    users.push_back(new Admin("Admin1", "Admin Father", "admin1", "adminpass"));
    
    // Perform login
    User* loggedInUser = User::login(users);
    if (loggedInUser && loggedInUser->isAdminUser()) {
        std::cout << "Welcome, " << loggedInUser->getName() << "!" << std::endl;
        int choice = loggedInUser->displayMenu();
        // Perform actions based on the admin's choice...
    }
    
    // Don't forget to release memory for dynamically allocated users
    
    return 0;
}
```
## Customer Class 

The `Customer` class is derived from the `User` class and represents a customer in the inventory management system. Customers have access to functionalities such as managing their cart, adding products to the cart, and placing orders.

## Class: Customer

### Public Functions:

#### `Customer(const std::string& name, const std::string& fatherName, const std::string& userName, const std::string& password)`

This constructor creates a `Customer` object with the provided name, father's name, username, and password. It sets the `m_isAdmin` flag to `false` to indicate that this user is not an administrator.

**Parameters:**
- `const std::string& name`: The name of the customer.
- `const std::string& fatherName`: The father's name of the customer.
- `const std::string& userName`: The username of the customer.
- `const std::string& password`: The password of the customer.

#### `static void registerCustomer(std::vector<User*>& users)`

This static function allows the registration of a new customer. It prompts the user to enter their details and creates a new `Customer` object. The object is then added to the `users` vector.

**Parameters:**
- `std::vector<User*>& users`: A vector containing pointers to all the users in the system.

#### `int myCart()`

This function displays the contents of the customer's cart. If the cart is empty, it displays a message accordingly. If there are items in the cart, it shows the items along with their prices and the total price of the cart. The function provides options to place an order or delete items from the cart.

**Parameters:**
None

**Return:**
- `int`: A value of `2` to indicate the customer has chosen to continue.

#### `void addToCart(Product& product)`

This function allows the customer to add a product to their cart. The product to be added is provided as a reference parameter.

**Parameters:**
- `Product& product`: The product to be added to the cart.

**Return:**
None

#### `std::vector<Product> getCart()`

This function returns a copy of the customer's cart.

**Parameters:**
None

**Return:**
- `std::vector<Product>`: A vector containing copies of the products in the customer's cart.

## Usage:

The `Customer` class represents a user role in the inventory management system with customer privileges. To utilize this class, include the "Customer.h" header file in your application.

Example usage:
```cpp
#include "Customer.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector to store users
    std::vector<User*> users;
    users.push_back(new Customer("Customer1", "Customer Father", "customer1", "customerpass"));
    
    // Perform login
    User* loggedInUser = User::login(users);
    if (loggedInUser && !loggedInUser->isAdminUser()) {
        std::cout << "Welcome, " << loggedInUser->getName() << "!" << std::endl;
        int choice = loggedInUser->displayMenu();
        if (choice == 4) {
            Customer* customer = dynamic_cast<Customer*>(loggedInUser);
            if (customer) {
                // Customer-specific actions
                choice = customer->myCart();
                // Perform further actions based on the customer's choice...
            }
        }
    }
    
    // Don't forget to release memory for dynamically allocated users
    
    return 0;
}
```
## Order Class

The `Order` class represents an order made by a customer in the inventory management system. Each order contains a unique identifier, the username of the customer who placed the order, and a vector of pointers to the products included in the order.

## Class: Order

### Private Members:

#### `static int m_idGenerator`

A static integer used to generate a unique identifier for each order.

#### `std::string m_orderId`

A unique identifier for the order.

#### `std::string m_customerUsername`

The username of the customer who placed the order.

#### `std::vector<Product*> m_products`

A vector of pointers to `Product` objects representing the products included in the order.

### Public Functions:

#### `Order(std::string username, std::vector<Product*> products)`

This constructor creates an `Order` object with the provided customer's username and a vector of pointers to the products included in the order. It assigns a unique order ID to the order using the `m_idGenerator`.

**Parameters:**
- `std::string username`: The username of the customer who placed the order.
- `std::vector<Product*> products`: A vector of pointers to `Product` objects representing the products in the order.

#### `static void makeOrder(std::vector<Product>& products, std::string username)`

This static function allows the creation of a new order. It takes a vector of products and the username of the customer who placed the order. The products in the vector are converted to a vector of pointers, and a new `Order` object is created and added to the static vector `orders`.

**Parameters:**
- `std::vector<Product>& products`: A vector of `Product` objects representing the products to be included in the order.
- `std::string username`: The username of the customer who placed the order.

#### `void addProduct(Product& product)`

This function allows the addition of a product to the order.

**Parameters:**
- `Product& product`: A reference to the `Product` object to be added to the order.

#### `void displayOrder()`

This function displays the details of the order, including the order ID, the customer's username, and the products included in the order along with their prices.

**Parameters:**
None

#### `std::vector<Product*> getProducts()`

This function returns a vector containing pointers to the products in the order.

**Parameters:**
None

**Return:**
- `std::vector<Product*>`: A vector containing pointers to the `Product` objects in the order.

#### `std::string orderToString()`

This function returns the username of the customer who placed the order.

**Parameters:**
None

**Return:**
- `std::string`: The username of the customer who placed the order.

### Static Members:

#### `static std::vector<Order*> orders`

A static vector that stores pointers to all the orders made by customers. Each element in the vector represents an order.

## Usage:

The `Order` class is responsible for handling orders placed by customers in the inventory management system. To utilize this class, include the "Order.h" header file in your application.

Example usage:
```cpp
#include "Order.h"
#include "Product.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector of products
    std::vector<Product> products;
    products.push_back(Product("Product1", "Category1", 10.99, 100));
    products.push_back(Product("Product2", "Category2", 20.99, 50));

    // Create a new order
    Order::makeOrder(products, "customer1");

    // Display the orders
    for (Order* order : Order::orders) {
        order->displayOrder();
    }

    return 0;
}
```

## Data Class

The `Data` class is responsible for storing and managing data related to users, products, and orders in the inventory management system. It provides functions to read data from files and write data to files.

## Class: Data

### Private Members:

#### `static std::vector<User*> m_users`

A static vector of pointers to `User` objects, used to store all users in the system.

#### `static std::vector<Product*> m_products`

A static vector of pointers to `Product` objects, used to store all products in the system.

#### `static std::vector<Order*> m_orders`

A static vector of pointers to `Order` objects, used to store all orders made by customers.

### Public Functions:

#### `static std::vector<User*> readUsers()`

This static function reads all user data from the "users.txt" file and populates the `m_users` vector.

**Parameters:**
None

**Return:**
- `std::vector<User*>`: A vector of pointers to `User` objects representing all users in the system.

#### `static std::vector<Product*> readProducts()`

This static function reads all product data from the "products.txt" file and populates the `m_products` vector.

**Parameters:**
None

**Return:**
- `std::vector<Product*>`: A vector of pointers to `Product` objects representing all products in the system.

#### `static std::vector<Order*> readOrders()`

This static function reads all order data from the "orders.txt" file and populates the `m_orders` vector.

**Parameters:**
None

**Return:**
- `std::vector<Order*>`: A vector of pointers to `Order` objects representing all orders in the system.

#### `static void writeUsers(std::vector<User*>& users)`

This static function writes all user data to the "users.txt" file.

**Parameters:**
- `std::vector<User*>& users`: A reference to a vector of pointers to `User` objects representing all users in the system.

**Return:**
None

#### `static void writeProducts(std::vector<Product*>& products)`

This static function writes all product data to the "products.txt" file.

**Parameters:**
- `std::vector<Product*>& products`: A reference to a vector of pointers to `Product` objects representing all products in the system.

**Return:**
None

#### `static void writeOrders(std::vector<Order*>& orders)`

This static function writes all order data to the "orders.txt" file.

**Parameters:**
- `std::vector<Order*>& orders`: A reference to a vector of pointers to `Order` objects representing all orders in the system.

**Return:**
None

## Usage:

The `Data` class is responsible for handling data storage and retrieval in the inventory management system. To utilize this class, include the "Data.h" header file in your application.

Example usage:
```cpp
#include "Data.h"
#include "User.h"
#include "Product.h"
#include "Order.h"

int main() {
    // Read data from files
    std::vector<User*> users = Data::readUsers();
    std::vector<Product*> products = Data::readProducts();
    std::vector<Order*> orders = Data::readOrders();

    // ... Perform operations on users, products, and orders ...

    // Save data to files
    Data::writeUsers(users);
    Data::writeProducts(products);
    Data::writeOrders(orders);

    // Free memory by deleting objects
    for (User* user : users) {
        delete user;
    }
    for (Product* product : products) {
        delete product;
    }
    for (Order* order : orders) {
        delete order;
    }

    return 0;
}
```

