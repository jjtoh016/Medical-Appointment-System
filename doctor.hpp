#ifndef DOCTOR_HPP_
#define DOCTOR_HPP_

class menu;

#include <iostream>
#include <string>
#include "doctor_personal_info.hpp"

using namespace std;

class doctor {
    private:
    doctor_personal_info personal_info;

    public:
    //constructor
    doctor() {
        this -> personal_info = doctor_personal_info("", "", "", 0, "", "", "", "");
    } //create empty doctor object

    doctor(string username, string password, string name, 
    int age, string phone_number, string address, string specification) {
        string doctorID = doctor_ID_generator(name, phone_number);
        this -> personal_info = doctor_personal_info(username, password, name, age, phone_number, doctorID, address, specification);
    } //used in adding new doctor, doctorID will be generated inside constructor

    doctor(string username, string password, string name, 
    int age, string phone_number, string doctorID, string address, string specification) {
        this -> personal_info = doctor_personal_info(username, password, name, age, phone_number, doctorID, address, specification);
    } //used in loading

    string doctor_ID_generator(string name, string phone_number); //generate doctor ID

    //get method
    string get_username() {return personal_info.get_username();}
    string get_password() {return personal_info.get_password();}
    string get_name() {return personal_info.get_name();}
    int get_age() {return personal_info.get_age();}
    string get_phone_number() {return personal_info.get_phone_number();}
    string get_doctorID() {return personal_info.get_doctorID();}
    string get_address() {return personal_info.get_address();}
    string get_specification() {return personal_info.get_specification();}

    //set method
    void set_username(string new_username) {personal_info.set_username(new_username);}
    void set_password(string new_password) {personal_info.set_password(new_password);}
    void set_name(string new_name) {personal_info.set_name(new_name);}
    void set_age(int new_age) {personal_info.set_age(new_age);}
    void set_phone_number(string new_phone_number) {personal_info.set_phone_number(new_phone_number);}
    void set_doctorID(string new_doctorID) {personal_info.set_doctorID(new_doctorID);}
    void set_address(string new_address) {personal_info.set_address(new_address);}
    void set_specification(string new_specification) {personal_info.set_specification(new_specification);}
};

//generate doctor ID
string doctor::doctor_ID_generator(string name, string phone_number) {
    string ID = "DR";
    
    for (int i = name.size() - 2; i < name.size(); i++) {
        ID.append(1, name[i]);
    }

    for (int i = phone_number.length() - 2; i < phone_number.length(); i++) {
        ID.append(1, phone_number[i]);
    }

    return ID;
}

#endif