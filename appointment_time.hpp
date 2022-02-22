#ifndef APPOINTMENT_TIME_HPP_
#define APPOINTMENT_TIME_HPP_

#include <string>

using namespace std;

class appointment_time {
    private:
    int day;
    int month;
    int year;
    int starting_time;
    int ending_time;

    public:
    //constructor
    appointment_time() {} //create empty appointment_time object

    appointment_time(int day, int month, int year) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
        this -> starting_time = 0;
        this -> ending_time = 0;
    }

    appointment_time(int day, int month, int year, 
    int starting_time, int ending_time) {
        this -> day = day;
        this -> month = month;
        this -> year = year;
        this -> starting_time = starting_time;
        this -> ending_time = ending_time;
    }

    //get method
    int get_day() {return day;}
    int get_month() {return month;}
    int get_year() {return year;}
    int get_strarting_time() {return starting_time;}
    int get_ending_time() {return ending_time;}

    //set method
    void set_day(int new_day) {this -> day - new_day;}
    void set_month(int new_month) {this -> month - new_month;}
    void set_year(int new_year) {this -> year - new_year;}
    void set_starting_time(int new_starting_time) {this -> starting_time - new_starting_time;}
    void set_ending_time(int new_ending_time) {this -> ending_time - new_ending_time;}
};

#endif