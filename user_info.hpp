#ifndef USER_INFO_HPP_
#define USER_INFO_HPP_

#include <string>

using namespace std;

class user_info {
    private:
    string username;
    string password;

    public:
    //constructor
    user_info() {}
    user_info(string username, string password) {
        this -> username = username;
        this -> password = password;
    }

    //get method
    string get_username() {return username;}
    string get_password() {return password;}

    //set method
    void set_username(string new_username) {this -> username = new_username;}
    void set_password(string new_password) {this -> password = new_password;}
};

#endif