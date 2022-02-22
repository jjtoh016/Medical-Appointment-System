#ifndef APPOINTMENT_HPP_
#define APPOINTMENT_HPP_

#include <string>
#include <iostream>
#include "appointment_time.hpp"

using namespace std;

class appointment {
    private:
    string patientID;
    string doctorID;
    appointment_time time;

    public:
    //constructor
    appointment() {
        this -> patientID = "";
        this -> doctorID = "";
        this -> time = appointment_time(0, 0, 0, 0, 0);
    }

    appointment(string patientID, string doctorID, int day, int month, int year,
    int starting_time, int ending_time) {
        this -> patientID = patientID;
        this -> doctorID = doctorID;
        this -> time = appointment_time(day, month, year, starting_time, ending_time);
    }

    //get method
    string get_patientID() {return patientID;}
    string get_doctorID() {return doctorID;}
    int get_day() {return time.get_day();}
    int get_month() {return time.get_month();}
    int get_year() {return time.get_year();}
    int get_strarting_time() {return time.get_strarting_time();}
    int get_ending_time() {return time.get_ending_time();}

    //set method
    void set_patientID(string new_patientID) {this -> patientID = new_patientID;}
    void set_doctorID(string new_doctorID) {this -> doctorID = new_doctorID;}
    void set_day(int new_day) {time.set_day(new_day);}
    void set_month(int new_month) {time.set_month(new_month);}
    void set_year(int new_year) {time.set_year(new_year);}
    void set_starting_time(int new_starting_time) {time.set_starting_time(new_starting_time);}
    void set_ending_time(int new_ending_time) {time.set_ending_time(new_ending_time);}
};

#endif