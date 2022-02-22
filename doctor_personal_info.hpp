#ifndef DOCTOR_PERSONAL_INFO_HPP_
#define DOCTOR_PERSONAL_INFO_HPP_

#include <string>
#include "personal_info.hpp"

using namespace std;

class doctor_personal_info : public personal_info {
    private:
    string doctorID;
    string address;
    string specification;

    public:
    //constructor
    doctor_personal_info() {}

    doctor_personal_info(string username, string password, string name, int age, string phone_number, string doctorID,
     string address, string specification) : personal_info(username, password, name, age, phone_number) {
        this -> doctorID = doctorID;
        this -> address = address;
        this -> specification = specification;
    }

    //get method
    string get_doctorID() {return doctorID;}
    string get_address() {return address;}
    string get_specification() {return specification;}

    //Set method
    void set_doctorID(string new_doctorID) {this -> doctorID = new_doctorID;}
    void set_address(string new_address) {this -> address = new_address;}
    void set_specification(string new_specification) {this -> specification = new_specification;}
};

#endif