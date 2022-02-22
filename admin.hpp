#ifndef ADMIN_HPP_
#define ADMIN_HPP_

class doctor;
class patient;
class menu;
template <class ListItemType>
class linked_list;

#include <iostream>
#include <string>
#include "user_info.hpp"

using namespace std;

class admin {
    private:
    user_info userInfo;

    public:
    //constructor
    admin() {
        userInfo = user_info("", "");
    } //create empty admin object
    
    admin(string username, string password) {
        userInfo = user_info(username, password);
    } //used in adding new admin and loading

    //get method
    string get_username() {return userInfo.get_username();}
    string get_password() {return userInfo.get_password();}

    //set method
    void set_username(string new_username) {userInfo.set_username(new_username);}
    void set_password(string new_password) {userInfo.set_password(new_password);}
};

#endif