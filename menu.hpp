#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include "patient.hpp"
#include "doctor.hpp"
#include "admin.hpp"
#include "appointment.hpp"
#include "linked_list.hpp"
#include "stack.hpp"
#include "windows.h"

using namespace std;

class menu {
    public:
    menu() {} //constructor
    void welcome(); //welcome screen
    int role_choosing_page();   //prompt role from users
    int patient_login_or_register();    //ask patient if they want log in or register
    void login_fail();  //display when patient or doctor or admin login fail
    void patient_register_successfully(string patientID);    //display when register successfully and show generated patient ID
    void register_or_added_fail();  //display when patient register fail or admin add doctor/admin fail (user input no)
    int patient_menu(); //display patient menu
    int patient_appointment();  //prompt patients on what they want to do with their appointment
    char patient_my_appointment(Stack<appointment> appointment_stack); //pop the appointment one by one and show
    void appoinment_added_successfully(); //patient added appointment successfully
    void invalid_input(); //display invalid input
    int patient_appointment_choose_specification(); //prompt specification of doctor from patient
    appointment_time patient_appointment_choose_date(appointment_time time_choice[]);   //prompt appointment date from patient
    int patient_appointment_choose_time();  //prompt appointment time from patients
    int patient_appointment_available_doctor(linked_list<doctor>& doctor_list); //prompt doctor from patients
    int patient_delete_appointment(linked_list<appointment>& appointment_list); //prompt the appointment that want to be deleted from patients
    void appointment_deleted_successfully();    //display if appointment deleted successfully
    int patient_my_profile(patient patient);    //display patient profile and prompt user action
    int patient_edit_profile();  //prompt patients which data to be updated
    void patient_profile_editted_successfully(); //display if patient profile edditted successfully
    int doctor_directory(); //prompt what patients want to do with doctor data
    char display_all_doctors(const linked_list<doctor>& doctor_list);  //display all doctors
    void display_searched_doctor(doctor doctor);   //display a certain searched doctor
    void search_doctor_fail();  //display if search doctor fail (doctor ID not exist)
    void thank_you();    //display thank you when patient or doctor or admin exit the application
    int doctor_menu();  //display doctor menu
    char doctor_my_appointment(Stack<appointment> appointment_stack);  //pop the appointment one by one and show
    int doctor_my_profile(doctor doctor);   //display doctor profile and prompt user action
    int doctor_edit_profile();  //prompt doctors which data to be updated
    void doctor_profile_editted_successfully(); //display if doctor profile edditted successfully
    int patient_directory();    //prompt what doctors want to do with patient data
    char display_all_patients(const linked_list<patient>& patient_list);    //display all patients
    void display_searched_patient(patient patient); //display a certain searched patient
    void search_patient_fail(); //display if search doctor fail (patient ID not exist)
    int admin_menu();   //display admin menu
    int admin_appointment();    //prompt admins on what they want to do with all appointments
    char display_all_appointments(const linked_list<appointment>& appointment_list);    //display all appointments in the system
    int admin_delete_appointment(linked_list<appointment>* appointment_list);   //prompt admins which appointment they want delete
    int admin_my_profile(admin admin);    //display admin profile and prompt admin what they want to do
    int admin_edit_profile();   //display admin profile and ask admin which one they want to update
    void admin_profile_editted_successfully();   //display if admin profile edditted successfully
    int admin_directory();  //ask admin what they want to do on patient/doctor/admin data
    int admin_display();    //prompt admin which user list they want to display
    void display_all_admins(const linked_list<admin>& admin_list);    //display all admins
    int admin_search(); //ask admin which user type they want to search
    int admin_delete(); //ask admin which user type they want to delete
    char display_deleted_patient(patient patient);  //display selected patient and confirm with admin
    void patient_deleted_successfully();    //display if patient deleted successfully
    void patient_deleted_fail();    //display if patient deleted fail
    char display_deleted_doctor(doctor doctor);    //display selected doctor and confirm with admin
    void doctor_deleted_successfully(); //display if doctor deleted successfully
    void doctor_deleted_fail(); //display if doctor deleted fail
    int admin_edit(); //ask admin which user type they want to edit
    int admin_add(); //ask admin which user type they want to add
    void doctor_added_successfully(string doctorID); //display if doctor added successfully, display the generated doctor ID
    void admin_added_successfully();    //display if admin added successfully
    void adminpage();
};

void menu::welcome(){

system("Color 0B");
cout<<"\n\n\n";
cout<<"==============[  IMPORTANT  ]==============\n"<<endl;
cout<<"Please use this system in full screen mode!\n"<<endl;
cout<<"===========================================\n"<<endl;
cout<<"\n\n\n";
system("pause");
system("cls");

cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"\t\t         _____           ___  ___   _____   _____   _   ______   _____   _                                   "<<endl;
cout<<"\t\t        |  ___|         |   \\/   | |  ___| |  _  \ \ | | |___| |  _  | | |                                "<<endl;
cout<<"\t\t        | |__      __   | |\\  /| | | |__   | | | | | | | |     | |_| | | |                                 "<<endl;
cout<<"\t\t        |  __|    |__|  | | \\/ | | |  __|  | | | | | | | |     |  _  | | |                                 "<<endl;
cout<<"\t\t        | |___          | |     | | | |___  | |_| | | | | |___  | | | | | |___                               "<<endl;
cout<<"\t\t        |_____|         |_|     |_| |_____| |_____/ |_| |_____| |_| |_| |_____|                              "<<endl;
cout<<"\t\t                                                                                                            "<<endl;
cout<<"\t\t                                                                                                            "<<endl;
cout<<"\t\t\t\t\t\t\t     _____   _____   _____   _____   _   __    _   _____   ___  ___   _____   __    _   _____     "<<endl;
cout<<"\t\t\t\t\t\t\t    |  _  | |  _  | |  _  | |  _  | | | |  \\  | | |_   _| |   \\/   | |  ___| |  \\  | | |_   _| "<<endl;
cout<<"\t\t\t\t\t\t\t    | |_| | | |_| | | |_| | | | | | | | | | \\ | |   | |   | |\\  /| | | |__   | | \\ | |   | |   "<<endl;
cout<<"\t\t\t\t\t\t\t    |  _  | |  ___| |  ___| | | | | | | | |\\ \\| |   | |   | | \\/ | | |  __|  | |\\ \\| |   | | "<<endl;
cout<<"\t\t\t\t\t\t\t    | | | | | |     | |     | |_| | | | | | \\ \\ |   | |   | |    | | | |___  | | \\ \\ |   | |  "<<endl;
cout<<"\t\t\t\t\t\t\t    |_| |_| |_|     |_|     |_____| |_| |_|  \\__|   |_|   |_|    |_| |_____| |_|  \\__|   |_|    "<<endl;
cout<<"\t\t\t\t                                                                                                        "<<endl;
cout<<"\t\t\t\t                                                                                                        "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t _____    _   _   _____   _____   _____   ___  ___       "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|  ___|  | | | | |  ___| |_   _| |  ___| |   \\/   |     "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| |___   | |_| | | |___    | |   | |__   | |\\  /| |     "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|___  |  |_   _| |___  |   | |   |  __|  | | \\/ | |     "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ___| |    | |    ___| |   | |   | |___  | |    | |      "<<endl;
cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|_____|    |_|   |_____|   |_|   |_____| |_|    |_|      "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
cout<<"                                                                                                                "<<endl;
system("PAUSE");

}

int menu::role_choosing_page() {
    while (true) {
        try {
            system("CLS");
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %--------------------  WHO ARE YOU  -------------------%           |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%           |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                       1) Patient                 |              2)Doctor                         "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                       3) Admin                   |              4) Exit                          "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout<<"\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}   //prompt role from users

int menu::patient_login_or_register() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %----------------------  PATIENT  -------------------%             |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                          |                         |                         |        "<<endl;
            cout<<"\t\t\t\t\t\t                                     |                         |                                   "<<endl;
            cout<<"\t\t\t\t\t\t          |                          |                         |                         |        "<<endl;
            cout<<"\t\t\t\t\t\t                  1) LOGIN           |      2) REGISTER        |        3) BACK                   "<<endl;
            cout<<"\t\t\t\t\t\t          |                          |                         |                         |        "<<endl;
            cout<<"\t\t\t\t\t\t                                     |                         |                                   "<<endl;
            cout<<"\t\t\t\t\t\t          |                          |                         |                         |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout << "\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

}    //ask patient if they want log in or register

void menu::login_fail() {
    system("CLS");
    cout << "Password wrong or account not exist." << endl << endl;
    system("PAUSE");
}  //display when patient or doctor or admin login fail

void menu::patient_register_successfully(string patientID) {
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t      **********                                       "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t    *            *                                    "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t   *         /    *                                   "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  *         /      *    Account successfully created. " << endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  *     \\  /       *    Your ID : "<<patientID<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t   *     \\/       *                                  "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t    *            *                                "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t      **********                                "<<endl;
    system("PAUSE");
}    //display when register successfully and show generated patient ID

void menu::register_or_added_fail() {
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t      **********                                       "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t    *            *                                    "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t   *     \\  /     *                                   "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  *       \\/       *    Account is not created." << endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t  *       /\\       *                                    "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t   *     /  \\     *                                  "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t    *            *                                "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t      **********                                "<<endl;
    system("PAUSE");
}  //display when patient register fail or admin add doctor/admin fail (user input no)

int menu::patient_menu() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %-------------------- PATIENT MENU -------------------%            |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                       1) APPOINTMENT             |            2) MY PROFILE                      "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                 3) DIRECTORY OF EXPERTISE        |               4) Exit                          "<<endl;
            cout<<"\t\t\t\t\t\t          |       (Display / search doctor)       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout<<"\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

} //display patient menu

int menu::patient_appointment() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %------------------- MY APPOINTMENT ------------------%            |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                    1) VIEW APPOINTMENT           |          2) ADD APPOINTMENT                 "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                   3) DELETE APPOINTMENT          |               4) BACK                         "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout << "\t\t\t\t\t\t          ENTER YOUR CHOICE: ";


            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //prompt patients on what they want to do with their appointment

char menu::patient_my_appointment(Stack<appointment> appointment_stack) {
    system("CLS");
    cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                               MY APPOINTMENT                                 |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |           DATE            |          TIME           |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t           ______________________________________________________________________________            "<<endl;


    appointment temp;
    int size = appointment_stack.size();
    for (int i = 1; i <= size; i++) {
        appointment_stack.pop(temp);


        string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());


        string time = to_string(temp.get_strarting_time())  + ".00 - " + to_string(temp.get_ending_time()) + ".00";


        cout<<"\t\t\t\t\t\t          | "<<setw(23)<<left<<temp.get_doctorID()<<"| "<<setw(25)<<left<<date<<" | "<<setw(24)<<left<<time<<"| "<<endl;
        cout<<"\t\t\t\t\t\t          |________________________|___________________________|_________________________|           "<<endl;
    }

    while (true) {
        try {
            cout << "\n\t\t\t\t\t\t           Press 'X' to go back to patient menu page" << endl;
            cout << "\t\t\t\t\t\t           Press 'S' to sort appointments by date" << endl;
            cout << "\t\t\t\t\t\t           ENTER YOUR CHOICE: ";

            //string choice;
            //cin.get();
            //getline(cin,choice);
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'X' && choice != 'S') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t           Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
} //pop the appointment one by one and show

void menu::appoinment_added_successfully() {
    system("CLS");
    cout << "Appointment successfully added." << endl << endl;
    system("PAUSE");
} //patient added appointment successfully

void menu::invalid_input() {
    system("CLS");
    cout << "Invalid input." << endl << endl;
    system("PAUSE");
} //display invalid input

int menu::patient_appointment_choose_specification() {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout << "CHOOSE SPECIFICATION" << endl
                    << "==============================" << endl;
            cout << "1. Cardiologists" << endl;
            cout << "2. Dermatologists" << endl;
            cout << "3. Neurologists" << endl;
            cout << "ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            choice = stoi(input);

            if (choice < 1 || choice > 3) {
                return -1;
            }

            return choice;
            break;

        } catch (...) {
            cout << "\nPlease enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    return choice;

} //prompt specification of doctor from patient

appointment_time menu::patient_appointment_choose_date(appointment_time time_choice[]) {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout << "CHOOSE DATE" << endl
                    << "==============================" << endl;
            cout << setfill(' ');
            cout << setw(5) << " ";
            cout << setw(20) << left << "Date" << endl;

            appointment_time temp;
            for (int i = 0; i < 7; i++) {
                cout << setw(5) << i + 1;

                temp = time_choice[i];
                string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());
                cout << setw(20) << left << date << endl;
            }

            cout << "ENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            choice = stoi(input);

            if (choice < 1 || choice > 7) {
                appointment_time empty;
                return empty;
            }

            break;
        } catch (...) {
            cout << "\nPlease enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    return time_choice [choice - 1];

}   //prompt appointment date from patient

int menu::patient_appointment_choose_time() {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout << "CHOOSE TIME" << endl
                    << "==============================" << endl;
            cout << setfill(' ');
            cout << setw(5) << "1.";
            cout << setw(20) << left << "8.00 - 9.00" << endl;

            cout << setw(5) << "2.";
            cout << setw(20) << left << "9.00 - 10.00" << endl;

            cout << setw(5) << "3.";
            cout << setw(20) << left << "10.00 - 11.00" << endl;

            cout << setw(5) << "4.";
            cout << setw(20) << left << "11.00 - 12.00" << endl;

            cout << "ENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            choice = stoi(input);

            if (choice < 1 || choice > 4) {
                return -1;
            }
            break;

        } catch (...) {
            cout << "\nPlease enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    return choice;
}  //prompt appointment time from patients

int menu::patient_appointment_available_doctor(linked_list<doctor>& doctor_list) {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout << "AVAILABLE DOCTOR" << endl
                    << "==============================" << endl;
            cout << setfill(' ');
            cout << setw(5) << " ";
            cout << setw(20) << left << "Doctor ID";
            cout << setw(20) << left << "Name" << endl;

            doctor temp;
            for (int i = 0; i < doctor_list.getLength(); i++) {
                cout << setw(5) << i + 1;
                doctor_list.retrieve(i,temp);
                cout << setw(20) << left << temp.get_doctorID();
                cout << setw(20) << left << temp.get_name() << endl;
            }

            cout << "ENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            choice = stoi(input);

            if (choice < 1 || choice > doctor_list.getLength()) {
                return -1;
            }
            break;

        } catch (...) {
            cout << "\nPlease enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    return choice;
} //prompt doctor from patients

int menu::patient_delete_appointment(linked_list<appointment>& appointment_list) {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                               DELETE APPOINTMENT                             |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |           DATE            |          TIME           |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ ______________________________________________________________________________            "<<endl;

            appointment temp;
            int size = appointment_list.getLength();
            for (int i = 1; i <= size; i++) {
                appointment_list.retrieve(i,temp);
                cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";

                string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());


                string time = to_string(temp.get_strarting_time())  + " - " + to_string(temp.get_ending_time());
                cout<<setw(24)<< left << temp.get_doctorID()<<"| "<<setw(25)<<left<<date<<" | "<<setw(24)<<left<<time<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|           "<<endl;
            }

            cout << "\n\n\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            choice = stoi(input);
            break;

        } catch (...) {
            cout << "\n\t\t\t\t\t\tPlease enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    if (choice < 1 || choice > appointment_list.getLength()) {
                return -1;
    }

    return choice;
} //prompt the appointment that want to be deleted from patients

void menu::appointment_deleted_successfully() {
    system("CLS");
    cout << "Appointment successfully deleted." << endl << endl;
    system("PAUSE");
}    //display if appointment deleted successfully

int menu::patient_my_profile(patient patient) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t_____________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|                    MY PROFILE                     |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  1  | Username              | "<<setw(20)<<left<< patient.get_username()<<"|"<< endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  2  | Password              | "<<setw(20)<<left<< patient.get_password()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  3  | Name                  | "<<setw(20)<<left<< patient.get_name()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  4  | Age                   | "<<setw(20)<<left<< patient.get_age()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  5  | Phone number          | "<<setw(20)<<left<< patient.get_phone_number()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  6  | Patient ID            | "<<setw(20)<<left<< patient.get_patientID()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;


            cout << "\n\t\t\t\t\t\t\t\t\tWhat you want to do?" << endl<<endl;
            cout << "\t\t\t\t\t\t\t\t\t1. Edit profile" << endl;
            cout << "\t\t\t\t\t\t\t\t\t2. Back" << endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 2) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

}    //display patient profile and prompt user action

int menu::patient_edit_profile() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|               EDIT PROFILE                |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Edit Username                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Edit Password                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Edit Name                      |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    4     | Edit Age                       |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    5     | Edit Phone Number              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;


            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 5) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //prompt patients which data to be updated

void menu::patient_profile_editted_successfully() {
    system("CLS");
    cout << "Profile successfully edited." << endl << endl;
    system("PAUSE");
} //display if patient profile edditted successfully

int menu::doctor_directory() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|             DOCTOR DIRECTORY              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Display all doctors            |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Search                         |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;


            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
} //prompt what patients want to do with doctor data

char menu::display_all_doctors(const linked_list<doctor>& doctor_list) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                            DISPLAY ALL DOCTOR                                |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |           NAME            |      SPECIFICATION      |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ ______________________________________________________________________________            "<<endl;


            doctor temp;
            int size = doctor_list.getLength();
            for (int i = 1; i <= size; i++) {
                doctor_list.retrieve(i,temp);
                cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
                cout<<setw(24)<< left << temp.get_doctorID()<<"| "<<setw(25)<<left<<temp.get_name()<<" | "<<setw(24)<<left<<temp.get_specification()<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|           "<<endl;
            }

            cout << "\n\n\t\t\t\t\t\t     Press 'X' to go back to patient menu page" << endl;
            cout << "\t\t\t\t\t\t     Press 'S' to sort doctors by specification" << endl;
            cout << "\t\t\t\t\t\t     ENTER YOUR CHOICE: ";

            string input;
            //cin >> input;
            //char choice = input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'X' && choice != 'S') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t     Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //display all doctors

void menu::display_searched_doctor(doctor doctor) {
    system("CLS");
    cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                           DISPLAY SEARCHED DOCTOR                            |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |           NAME            |      SPECIFICATION      |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ ______________________________________________________________________________            "<<endl;

    cout << setw(5) << left << "\t\t\t\t\t\t     | 1. |";
    cout<<setw(24)<< left << doctor.get_doctorID()<<"| "<<setw(25)<<left<<doctor.get_name()<<" | "<<setw(24)<<left<<doctor.get_specification()<<"| "<<endl;
    cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|           "<<endl;


    system("PAUSE");
}   //display a certain searched doctor

void menu::search_doctor_fail() {
    system("CLS");
    cout << "This doctor ID does not exist." << endl << endl;
    system("PAUSE");
}  //display if search doctor fail (doctor ID not exist)

void menu::thank_you() {
    system("CLS");
    system("Color 0B");
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::@@@@@@@@@@@@@@@@@:::::::::::::@@@@@@@@@@@@@@@@@:::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::::::@@@@@@@@:::::::::::@@@@@:::::::::@@@@@:::::::::::@@@@@@@@::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::@@@@@:::::::::::::::::@@@@@:::::@@@@@:::::::::::::::::@@@@@:::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::@@@@@:::::::::::::::::::::::@@@:@@@:::::::::::::::::::::::@@@@@:::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::@@@@::::::::::::::::::::::::::::@::::::::::::::::::::::::::::@@@@::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::@@@@::::::::::::                                 ::::::::::::@@@@::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::@@@@:::::::::::: Thank you for using our system! ::::::::::::@@@@::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::@@@@:::::::::::                                 :::::::::::@@@@:::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::::@@@@::::::::::   Brought to you by KFC MEMBERS ::::::::::@@@@::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::@@@@@::::::                                 ::::::@@@@@:::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::@@@@@:::::::::::::::::::::::::::::::::::::@@@@@:::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::@@@@@@:::::::::::::::::::::::::::@@@@@@:::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t:::::::::::::::::::::::::::@@@@@:::::::::::::::::::@@@@@::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::@@@@:::::::::::::@@@@:::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::@@@@:::::@@@@:::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::@@:@@:::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::@:::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\t\t\t\t\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: "<<endl;
    cout<<"\n\n\n";
    system("PAUSE");
}    //display thank you when patient or doctor or admin exit the application

int menu::doctor_menu() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %-------------------- DOCTOR  MENU -------------------%            |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                    1) MY APPOINTMENT             |            2) MY PROFILE                      "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                 3)   PATIENT DIRECTORY           |               4) Exit                          "<<endl;
            cout<<"\t\t\t\t\t\t          |        (Display / search patient)     |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout<<"\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //display doctor menu

char menu::doctor_my_appointment(Stack<appointment> appointment_stack) {
    system("CLS");

            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                               MY APPOINTMENT                                 |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       PATIENTID        |           DATE            |           TIME          |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ ______________________________________________________________________________            "<<endl;


    appointment temp;
    int size = appointment_stack.size();
    for (int i = 1; i <= size; i++) {
        appointment_stack.pop(temp);


        string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());


        string time = to_string(temp.get_strarting_time())  + ".00 - " + to_string(temp.get_ending_time()) + ".00";
        cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
        cout<<setw(24)<< left << temp.get_patientID()<<"| "<<setw(25)<<left<<date<<" | "<<setw(24)<<left<<time<<"| "<<endl;
        cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|           "<<endl;
    }

    while (true) {
        try {
            cout << "\n\t\t\t\t\t\t     Press 'X' to go back to patient menu page" << endl;
            cout << "\t\t\t\t\t\t     Press 'S' to sort appointments by date" << endl;
            cout << "\t\t\t\t\t\t     ENTER YOUR CHOICE: ";

            string input;
            //cin >> input;
            //char choice = input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'X' && choice != 'S') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t     Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //pop the appointment one by one and show

int menu::doctor_my_profile(doctor doctor) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t_________________________________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|                               MY PROFILE                              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  1  | Username              | "<<setw(40)<<left<< doctor.get_username()<<"|"<< endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  2  | Password              | "<<setw(40)<<left<< doctor.get_password()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  3  | Name                  | "<<setw(40)<<left<< doctor.get_name()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  4  | Age                   | "<<setw(40)<<left<< doctor.get_age()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  5  | Phone number          | "<<setw(40)<<left<< doctor.get_phone_number()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  6  | Address               | "<<setw(40)<<left<< doctor.get_address()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  7  | Specification         | "<<setw(40)<<left<< doctor.get_specification()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  8  | Doctor ID             | "<<setw(40)<<left<< doctor.get_doctorID()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;

            cout << "\n\t\t\t\t\t\t\t\tWhat you want to do?" << endl<<endl;
            cout << "\t\t\t\t\t\t\t\t1. Edit profile" << endl;
            cout << "\t\t\t\t\t\t\t\t2. Back" << endl<<endl;

            cout << "\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 2) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}   //display doctor profile and prompt user action

int menu::doctor_edit_profile() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|               EDIT PROFILE                |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Edit Username                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Edit Password                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Edit Name                      |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    4     | Edit Age                       |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    5     | Edit Phone Number              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    6     | Edit Address                   |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 6) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //prompt doctors which data to be updated

void menu::doctor_profile_editted_successfully() {
    system("CLS");
    cout << "Profile successfully edited." << endl << endl;
    system("PAUSE");
} //display if doctor profile edditted successfully

int menu::patient_directory() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|             PATIENT DIRECTORY             |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Display all patients           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Search                         |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //prompt what doctors want to do with patient data

char menu::display_all_patients(const linked_list<patient>& patient_list) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                            DISPLAY ALL PATIENTS                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================            "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |          "<<endl;
            cout<<"\t\t\t\t\t\t          |       PATIENTID        |           NAME            |           AGE           |          "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |          "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================            "<<endl;
            cout<<"\t\t\t\t\t\t      ____ _____________________________________________________________________________            "<<endl;



            patient temp;
            int size = patient_list.getLength();
            for (int i = 1; i <= size; i++) {
                patient_list.retrieve(i,temp);

                cout<<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
                cout<<setw(24)<< left << temp.get_patientID()<<"| "<<setw(25)<<left<<temp.get_name()<<" | "<<setw(24)<<left<<temp.get_age() <<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|________________________ | "<<endl;

            }
            cout << "\n\t\t\t\t\t\t     Press 'X' to go back to patient menu page" << endl;
            cout << "\t\t\t\t\t\t     Press 'S' to sort patients by age" << endl<<endl;
            cout << "\t\t\t\t\t\t     ENTER YOUR CHOICE: ";

            string input;
            //cin >> input;
            //char choice = input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'X' && choice != 'S') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t     Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //display all patients

void menu::display_searched_patient(patient patient) {
    system("CLS");
    cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                          DISPLAY SEARCHED PATIENTS                           |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =============================================================================            "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |          "<<endl;
            cout<<"\t\t\t\t\t\t          |       PATIENTID        |           NAME            |           AGE           |          "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |          "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================            "<<endl;
            cout<<"\t\t\t\t\t\t      ____ _____________________________________________________________________________            "<<endl;


    cout << setw(5) << left << "\t\t\t\t\t\t     | 1. |";
     cout<<setw(24)<< left << patient.get_patientID()<<"| "<<setw(25)<<left<<patient.get_name()<<" | "<<setw(23)<<left<<patient.get_age()<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|________________________| "<<endl;


    system("PAUSE");
} //display a certain searched patient

void menu::search_patient_fail() {
    system("CLS");
    cout << "This patient ID does not exist." << endl << endl;
    system("PAUSE");
} //display if search doctor fail (patient ID not exist)

int menu::admin_menu() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %--------------------  ADMIN MENU  -------------------%            |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                    1) MY APPOINTMENT             |            2) MY PROFILE                      "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                    3) ADMIN DIRECTORY            |               4) Exit                          "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout<<"\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}   //display admin menu

int menu::admin_appointment() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |           %----------------- ADMIN APPOINTMENT -----------------%            |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |      \n"<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                    1) VIEW APPOINTMENT           |          2) ADD APPOINTMENT                 "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------        "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                   3) DELETE APPOINTMENT          |               4) BACK                         "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t                                                  |                                               "<<endl;
            cout<<"\t\t\t\t\t\t          |                                       |                                      |        "<<endl;
            cout<<"\t\t\t\t\t\t          --------------------------------------------------------------------------------      \n"<<endl<<endl;

            cout << "\t\t\t\t\t\t          ENTER YOUR CHOICE: ";

            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //prompt admins on what they want to do with all appointments

char menu::display_all_appointments(const linked_list<appointment>& appointment_list) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                           VIEW ALL APPOINTMENT                                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
    cout << setfill(' ');
    cout << setw(5) << " ";
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |        PATIENTID          |          DATE           |          TIME           |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ _______________________________________________________________________________________________________            "<<endl;


            appointment temp;
            int size = appointment_list.getLength();
            for (int i = 1; i <= size; i++) {
                appointment_list.retrieve(i,temp);

                string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());


                string time = to_string(temp.get_strarting_time())  + ".00 - " + to_string(temp.get_ending_time()) + ".00";

                cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
                cout<<setw(24)<< left << temp.get_doctorID()<<"| "<<setw(25)<<left<<temp.get_patientID()<<" | "<<setw(24)<<left<<date<<"| "<<setw(24)<<left<<time<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|_________________________|           "<<endl;
            }

            cout << "\n\t\t\t\t\t\t     Press 'X' to go back to patient menu page" << endl;
            cout << "\t\t\t\t\t\t     Press 'S' to sort appointments by date" << endl;
            cout << "\t\t\t\t\t\t     ENTER YOUR CHOICE: ";

            string input;
            //cin >> input;
            //char choice = input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'X' && choice != 'S') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t     Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //display all appointments in the system

int menu::admin_delete_appointment(linked_list<appointment>* appointment_list) {
    int choice;
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                           DELETE  APPOINTMENT                                          |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |       DOCTORID         |        PATIENTID          |          DATE           |          TIME           |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                        |                           |                         |                         |           "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ _______________________________________________________________________________________________________            "<<endl;




            appointment temp;
            int size = appointment_list->getLength();
            for (int i = 1; i <= size; i++) {
                appointment_list->retrieve(i,temp);


                string date = to_string(temp.get_day())  + '/' + to_string(temp.get_month()) + '/' + to_string(temp.get_year());


                string time = to_string(temp.get_strarting_time())  + " - " + to_string(temp.get_ending_time());

                cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
                cout<<setw(24)<< left << temp.get_doctorID()<<"| "<<setw(25)<<left<<temp.get_patientID()<<" | "<<setw(24)<<left<<date<<"| "<<setw(24)<<left<<time<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________|___________________________|_________________________|_________________________|           "<<endl;

            }

            cout << "\n\t\t\t\t\t\t     ENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            choice = stoi(input);
            break;
        } catch (...) {
            cout << "\n\t\t\t\t\t\t     Please enter only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    if (choice < 1 || choice > appointment_list->getLength()) {
        return -1;
    }

    return choice;



    if (choice < 1 || choice > appointment_list->getLength()) {
        return -1;
    }

    return choice;
}   //prompt admins which appointment they want delete

int menu::admin_my_profile(admin admin) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t_________________________________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|                               MY PROFILE                              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  1  | Username              | "<<setw(40)<<left<< admin.get_username()<<"|"<< endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  2  | Password              | "<<setw(40)<<left<< admin.get_password()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;


            cout << "\n\t\t\t\t\t\t\t\tWhat you want to do?" << endl<<endl;
            cout << "\t\t\t\t\t\t\t\t1. Edit profile" << endl;
            cout << "\t\t\t\t\t\t\t\t2. Back" << endl<<endl;

            cout << "\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 2) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //display admin profile and prompt admin what they want to do

int menu::admin_edit_profile() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t=========================================="<<endl;
                                              cout << "\t\t\t\t\t\t\t\t\t\t               EDIT PROFILE               "<< endl;
                                              cout << "\t\t\t\t\t\t\t\t\t\t==========================================" << endl<<endl;

            cout << "\n\t\t\t\t\t\t\t\t\t\tWhat you want to update?" << endl<<endl;
            cout << "\t\t\t\t\t\t\t\t\t\t1. Edit Username" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t2. Edit Password" << endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 2) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}   //display admin profile and ask admin which one they want to update

void menu::admin_profile_editted_successfully() {
    system("CLS");
    cout << "Profile successfully edited." << endl << endl;
    system("PAUSE");
}   //display if admin profile edditted successfully

int menu::admin_directory() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|              ADMIN DIRECTORY              |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Display                        |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Search                         |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Delete                         |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    4     | Edit                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    5     | Add                            |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    6     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;


            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 6) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //ask admin what they want to do on patient/doctor/admin data

int menu::admin_display() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|               ADMIN DISPLAY               |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Display all admins             |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Display all patients           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Display all doctors            |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    4     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 4) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //prompt admin which user list they want to display

void menu::display_all_admins(const linked_list<admin>& admin_list) {
    system("CLS");
    cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                    DISPLAY ALL ADMIN USERNAMES                                         |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                                                        |           "<<endl;
            cout<<"\t\t\t\t\t\t           =======================================================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t      ____ _______________________________________________________________________________________________________            "<<endl;


    admin temp;
    int size = admin_list.getLength();
    for (int i = 1; i <= size; i++) {
        admin_list.retrieve(i,temp);
        cout <<"\t\t\t\t\t\t     | "<< setw(3) << left << i<<"|";
                cout<<setw(103)<< left << temp.get_username()<<"| "<<endl;
                cout<<"\t\t\t\t\t\t     |____|________________________________________________________________________________________________________|           "<<endl;
    }
    cout << endl;
    system("PAUSE");
}    //display all admins

int menu::admin_search() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|               ADMIN DISPLAY               |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Search patient                 |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Search doctor                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout<<"\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
} //ask admin which user type they want to search

int menu::admin_delete() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|               ADMIN DELETE                |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Delete patient                 |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Delete doctor                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout<<"\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
} //ask admin which user type they want to delete

char menu::display_deleted_patient(patient patient) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t_____________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|                  DELETE PATIENT                   |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  1  | Username              | "<<setw(20)<<left<< patient.get_username()<<"|"<< endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  2  | Password              | "<<setw(20)<<left<< patient.get_password()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  3  | Name                  | "<<setw(20)<<left<< patient.get_name()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  4  | Age                   | "<<setw(20)<<left<< patient.get_age()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  5  | Phone number          | "<<setw(20)<<left<< patient.get_phone_number()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|  6  | Patient ID            | "<<setw(20)<<left<< patient.get_patientID()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t|===================================================|"<<endl<<endl;


            cout << "\n\t\t\t\t\t\t\t\t\tConfirm (Y/N)? ";

            string input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'Y' && choice != 'N') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}  //display selected patient and confirm with admin

void menu::patient_deleted_successfully() {
    system("CLS");
    cout << "Patient is deleted." << endl << endl;
    system("PAUSE");
}    //display if patient deleted successfully

void menu::patient_deleted_fail() {
    system("CLS");
    cout << "Patient is not deleted." << endl << endl;
    system("PAUSE");
}    //display if patient deleted fail

char menu::display_deleted_doctor(doctor doctor) {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t_________________________________________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|                             DELETE DOCTOR                             |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  1  | Username              | "<<setw(40)<<left<< doctor.get_username()<<"|"<< endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  2  | Password              | "<<setw(40)<<left<< doctor.get_password()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  3  | Name                  | "<<setw(40)<<left<< doctor.get_name()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  4  | Age                   | "<<setw(40)<<left<< doctor.get_age()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  5  | Phone number          | "<<setw(40)<<left<< doctor.get_phone_number()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  6  | Address               | "<<setw(40)<<left<< doctor.get_address()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  7  | Specification         | "<<setw(40)<<left<< doctor.get_specification()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|  8  | Doctor ID             | "<<setw(40)<<left<< doctor.get_doctorID()<<"|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t|=======================================================================|"<<endl;

            cout << "\n\t\t\t\t\t\t\t\tConfirm (Y/N)? ";

            string input;
            char choice = toupper(getch());
            cout << endl;

            if (choice != 'Y' && choice != 'N') {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}    //display selected doctor and confirm with admin

void menu::doctor_deleted_successfully() {
    system("CLS");
    cout << "Doctor is deleted." << endl << endl;
    system("PAUSE");
} //display if doctor deleted successfully

void menu::doctor_deleted_fail() {
    system("CLS");
    cout << "Doctor is not deleted." << endl << endl;
    system("PAUSE");
} //display if doctor deleted fail

int menu::admin_edit() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|                ADMIN EDIT                 |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Edit patient                   |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Edit doctor                    |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}

int menu::admin_add() {
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t\t\t\t_____________________________________________"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|                ADMIN ADD                  |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    1     | Add doctor                     |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    2     | Add admin                      |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|    3     | Back                           |"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t|===========================================|"<<endl<<endl;

            cout << "\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ";
            string input;
            cin >> input;
            int choice = stoi(input);

            if (choice < 1 || choice > 3) {
                throw choice;
            }

            return choice;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }
} //ask admin which user type they want to add

void menu::doctor_added_successfully(string doctorID) {
    system("CLS");
    cout << "Account successfully created. Doctor ID is: " << doctorID << endl << endl;
    system("PAUSE");
} //display if doctor added successfully, display the generated doctor ID

void menu::admin_added_successfully() {
    system("CLS");
    cout << "Account successfully created." << endl << endl;
    system("PAUSE");
}    //display if admin added successfully

void menu::adminpage(){

system("pause");
system("cls");
system("Color 0A");

cout<<"\t\t\t\t\t========================================================================================================================    \n";
cout<<"\t\t\t\t\t  1       1    1     1     1 1   1       0    1             0    1   1              1       1     0     1       1    1       \n"; Sleep(50);
cout<<"\t\t\t\t\t  0       1    0     0     0 1   1       1    0     1       1    1   0      0       1       1     1     1       0    0      \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1    0    1     1     1 0   0       0    0     1 1     0    1   1      1       1       0     1   1 0       1    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    1    1     @     0 1   1   1   1          0 1     0    0   0      1   1   0       0     0   0 1       1    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  0    0    1           1 0   1   0   1    1     1 0     0    1   0      0   0   0       0     1   0 0       1    0      \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    1    0           1 1   1   0        0     1 0     1    0   0      1   1   1       1     0   1 1       0    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  0    0    1             0   1   1        0     0 1     1        1      1   1   1 0     0     1   1 0       0    1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    0    0     1       1   0   0        0     1 0     0    1          1   1     1  1  1     1   0 0       1    0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1    0    1  1  1       1       0   1    1       1     0    0          0   0     0  0  0     0     1       0     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    1    1  1  0     1         1   1    1  1    1     0    0          1   1     1  1  1     1     0       1     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    0    0     1       1   0   0        0     1 0     0    1          1   1     1  1  1     1   0 0       1     0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1    0    1  1  1       1       0   1    1       1     0    0          0   0     0  0  0     0     1       0     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1    1    1  1  0     1         1   1    1  1    1     0    0          1   1     1  1  1     1     0       1     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  0    @    0  0  1  ========================================================================  1     1       1     0    \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0  =          $$       $$$$$       $      $    $$$$$$    $       $        =  0     1       0     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1         0  1  1  =        $    $     $$   $$     $$    $$      $$      $$     $$        =  1   1          1    0    \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1         0  0  1  =       $$    $$    $$    $$    $$$  $$$      $$      $$$    $$        =      0 0        0    0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1               1  1  =       $$    $$    $$    $$    $$ $$ $$      $$      $$ $   $$        =      0 1        1    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0  =       $$$$$$$$    $$    $$    $$    $$      $$      $$  $  $$        =      0 1       0           \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1         0  1  1  =       $$    $$    $$    $$    $$    $$      $$      $$   $ $$        =      1          1         \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  0         0  0  1  =       $$    $$    $$   $$     $$    $$      $$      $$    $$$        =  1     1       1          \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0  =       $$    $$     $$$$$      $$    $$    $$$$$$    $      $$        =  0     1       0           \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0  ========================================================================  0     1       0     1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1         0  1  1     1 1       1   1   0   1    0     0    1   0      1   0 1   0           1   1          1    0    \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1         0  0  1     0 0       1   0   1   1    1     1    0   0          0 0   1               0 0        0    0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1               1  1     @ 0           1   0   1    1          1   1          1     1               0 1        1    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0     0 0       1   0   1   0    1     1    1   1      1   1 0   0               0 1        0    1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  0         1  1  0     0 0       1   0   1   0    1     1    1   1      1   1 0   0               0 1        0    1     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1         0  1  1     1 1       1   1   0   1    0     0    1   0      1   0 1   0               1          1    0    \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1         0  0  1     0 0       1   0   1   1    1     1    0   0          0 0   1     1         0 0        0    0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1  1         0  1  1     1 1       1   1   0   1    0     0    1   0      1   0 1   0               1          1    0    \n"; Sleep(50);
cout<<"\t\t\t\t\t  0  1         0  0  1     0 0       1   0   1   1    1     1    0   0          0 0   1     1         0 0        0    0     \n"; Sleep(50);
cout<<"\t\t\t\t\t  1               1  1     @ 0           1   0   1    1          1   1          1     1     0         0 1        1    1      \n"; Sleep(50);
cout<<"\t\t\t\t\t  @               1          1               0   0               0   1                0     1         1 1        1    1    \n";
cout<<"\t\t\t\t\t========================================================================================================================    \n";

string admin = "\n\n\t\t\t\t\t\t\t\t\t\t\t _____________________ \n  "
               "    \t\t\t\t\t\t\t\t\t\t\t|                     |\n  "
               "    \t\t\t\t\t\t\t\t\t\t\t|        ENTER        |\n  "
               "    \t\t\t\t\t\t\t\t\t\t\t|_____________________|\n  ";



for(int i=0; admin[i];i ++)
{
     cout << admin[i]; // output the current character
     Sleep(10);     // wait 10 milisecs
}

system("pause");
system ("cls");


}
#endif
