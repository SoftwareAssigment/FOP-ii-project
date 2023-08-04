#pragma once
#include<iostream>
#include<vector>
#include <ctime>
#include <vector>
#include "Utils.h"
#include "Product.h"
class User
{
protected:
    std::string m_name;
    std::string m_fatherName;
    std::string m_userName;
    std::string m_password;
    bool m_isAdmin;
    std::vector<Product> m_cart;
public:
    //constructor function
    User();
    User(const std::string& name, const std::string& fatherName, const std::string& userName, 
        const std::string& password, const bool& isAdmin);

    //getter function 
    std::string getName();
    std::string getFatherName();
    std::string getUserName();
    std::string getPassword();
    bool isAdminUser();

    //set the name of a user 
    void setName(const std::string& );
    void setFatherName(const std::string& );
    void setUserName(const std::string& );
    void setPassword(const std::string& );
    void setAdmin(const bool& );

    //get the full detail of a user
    int getFullDetails();

    //display menu and return the choise 
    virtual int displayMenu();
    
    // user to string
    std::string userToString();
    //static login function
    static User* login(std::vector<User*>&);






};

