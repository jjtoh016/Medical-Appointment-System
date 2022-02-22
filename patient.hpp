#ifndef PATIENT_HPP_
#define PATIENT_HPP_

class appointment;
class appointment_time;
class doctor;
class menu;
template <class ListItemType>
class linked_list;

#include <iostream>
#include <string>
#include "patient_personal_info.hpp"

using namespace std;

class patient {
    private:
    patient_personal_info personal_info;

    public:
    //constructor
    patient() {
        this -> personal_info = patient_personal_info("", "", "", 0, "", "");
    } //create empty patient object

    patient(string username, string password, string name, 
    int age, string phone_number) {
        string patientID = patient_ID_generator(name, phone_number);
        this -> personal_info = patient_personal_info(username, password, name, age, phone_number, patientID);
    }   //used in registration, patientID will be generated inside constructor
    

    patient(string username, string password, string name, 
    int age, string phone_number, string patientID) {
        this -> personal_info = patient_personal_info(username, password, name, age, phone_number, patientID);
    }   //used in loading


    string patient_ID_generator(string name, string phone_number); //generate patient ID

    //get method
    string get_username() {return personal_info.get_username();}
    string get_password() {return personal_info.get_password();}
    string get_name() {return personal_info.get_name();}
    int get_age() {return personal_info.get_age();}
    string get_phone_number() {return personal_info.get_phone_number();}
    string get_patientID() {return personal_info.get_patientID();}

    //set method
    void set_username(string new_username) {personal_info.set_username(new_username);}
    void set_password(string new_password) {personal_info.set_password(new_password);}
    void set_name(string new_name) {personal_info.set_name(new_name);}
    void set_age(int new_age) {personal_info.set_age(new_age);}
    void set_phone_number(string new_phone_number) {personal_info.set_phone_number(new_phone_number);}
    void set_patientID(string new_patientID) {personal_info.set_patientID(new_patientID);}
};

string patient::patient_ID_generator(string name, string phone_number){ //generate patient ID
    string ID = "PT";
    
    for (int i = name.size() - 2; i < name.size(); i++) {
        ID.append(1, name[i]);
    }

    for (int i = phone_number.length() - 2; i < phone_number.length(); i++) {
        ID.append(1, phone_number[i]);
    }

    return ID;
}

#endif