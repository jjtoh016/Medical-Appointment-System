#ifndef PATIENT_PERSONAL_INFO_HPP_
#define PATIENT_PERSONAL_INFO_HPP_

#include <string>
#include "personal_info.hpp"

using namespace std;

class patient_personal_info : public personal_info {
    private:
    string patientID;

    public:
    //constructor
    patient_personal_info() {}

    patient_personal_info(string username, string password, string name, int age, string phone_number, string patientID)
    : personal_info(username, password, name, age, phone_number) {
        this -> patientID = patientID;
    }

    //get method
    string get_patientID() {return patientID;}

    //Set method
    void set_patientID(string new_patientID) {this -> patientID = new_patientID;}
};

#endif