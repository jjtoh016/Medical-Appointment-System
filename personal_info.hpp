#ifndef PERSONAL_INFO_HPP_
#define PERSONAL_INFO_HPP_

#include <string>
#include "user_info.hpp"

using namespace std;

class personal_info {
    private:
    user_info userInfo;
    string name;
    int age;
    string phone_number;

    public:
    //constructor
    personal_info() {}
    personal_info(string username, string password, string name, int age, string phone_number) {
        this -> userInfo = user_info(username, password);
        this -> name = name;
        this -> age = age;
        this -> phone_number = phone_number;
    }

    //get method
    string get_username() {return userInfo.get_username();}
    string get_password() {return userInfo.get_password();}
    string get_name() {return name;}
    int get_age() {return age;}
    string get_phone_number() {return phone_number;}

    //set method
    void set_username(string new_username) {userInfo.set_username(new_username);}
    void set_password(string new_password) {userInfo.set_password(new_password);}
    void set_name(string new_name) {this -> name = new_name;}
    void set_age(int new_age) {this -> age = new_age;}
    void set_phone_number(string new_phone_number) {this -> phone_number = new_phone_number;}
};

#endif