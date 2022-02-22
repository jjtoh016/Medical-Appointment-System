#include <iostream>
#include <stdlib.h>
#include <string>
#include <type_traits>
#include "patient.hpp"
#include "doctor.hpp"
#include "admin.hpp"
#include "appointment.hpp"
#include "appointment_time.hpp"
#include "search.hpp"
#include "sort.hpp"
#include "menu.hpp"
#include "linked_list.hpp"
#include "stack.hpp"

using namespace std;

void patient_register(linked_list<patient>* patient_list);
patient* patient_login(const linked_list<patient>& patient_list);
doctor* doctor_login(const linked_list<doctor>& doctor_list);
admin* admin_login(const linked_list<admin>& admin_list);

//adding function
void add_doctor(linked_list<doctor>* doctor_list);
void add_admin(linked_list<admin>* admin_list);

//deleting function
void delete_patient(linked_list<patient>* patient_list);
void delete_doctor(linked_list<doctor>* doctor_list);

//for editting users' info
template <class user>
void edit_username(user* edit_user, linked_list<patient>* patient_list,
linked_list<doctor>* doctor_list, linked_list<admin>* admin_list); //called by main function - by admin, patient and doctor

template <class user>
void edit_password(user* edit_user);  //called by main function - by admin, patient and doctor

template <class user>
void edit_name(user* edit_user); //called by main function - by patient and doctor

template <class user>
void edit_age(user* edit_user); //called by main function - by patient and doctor

template <class user>
void edit_phone_number(user* edit_user); //called by main function - by patient and doctor

template <class user>
void edit_address(user* edit_user); //called by main function - by doctor

//for doing appointment
appointment do_appointment(const linked_list <patient> patient_list,
const linked_list <doctor> doctor_list, const linked_list <appointment> appointment_list);

int main() {
    menu displayer;
    search search_helper;
    sort sort_helper;
    int choice;

    displayer.welcome();
    linked_list<patient> patient_list;
    patient_list.load("patient.txt");

    linked_list<doctor> doctor_list;
    doctor_list.load("doctor.txt");

    linked_list<admin> admin_list;
    admin_list.load("admin.txt");

    linked_list<appointment> appointment_list;
    appointment_list.load("appointment.txt");

    patient* cur_patient_ptr = nullptr;
    doctor* cur_doctor_ptr = nullptr;
    admin* cur_admin_ptr = nullptr;

    string menu;

    while (true) {
        int role = displayer.role_choosing_page();

        //role choosing
        if (role == 1) {
            choice = displayer.patient_login_or_register();

            if (choice == 1) {  //patient login
                cur_patient_ptr = patient_login(patient_list);
                if (cur_patient_ptr == nullptr) {
                    displayer.login_fail();
                    continue;
                } else {
                    menu = "patient";
                    break;
                } //endif

            } else if(choice == 2) { //patient register
                patient_register(&patient_list);
                continue;
            } else if(choice == 3) {
                continue;
            }
        } else if (role == 2) {
            cur_doctor_ptr = doctor_login(doctor_list);
            if (cur_doctor_ptr == nullptr) {
                displayer.login_fail();
                continue;
            } else {
                menu = "doctor";
                break;
            }
        } else if (role == 3) {
            cur_admin_ptr = admin_login(admin_list);
            if (cur_admin_ptr == nullptr) {
                displayer.login_fail();
                continue;
            } else {
                menu = "admin";
                break;
            }
        } else if (role == 4) {
            displayer.thank_you();
            break;
        }
    }


    if (menu == "patient") {
        while (true) {
            choice = displayer.patient_menu();
            if (choice == 1) {
                int response = displayer.patient_appointment();
                if (response == 1) {
                    linked_list <appointment> copied_appointment_list(appointment_list);
                    display_patient_appointments:
                    int size = appointment_list.getLength();
                    appointment temp;
                    Stack<appointment> appointments;
                    for (int i = 1; i <= size; i++) {
                        copied_appointment_list.retrieve(i,temp);
                        if (cur_patient_ptr->get_patientID() == temp.get_patientID()) {
                            appointments.push(temp);
                        }
                    }

                    char sort_or_not = displayer.patient_my_appointment(appointments);
                    if (sort_or_not == 'X') {
                        continue;
                    } else if (sort_or_not == 'S') {
                        sort_helper.sort_appointment_by_appointment_time(copied_appointment_list, 1, copied_appointment_list.getLength());
                        goto display_patient_appointments;
                    }
                } else if (response == 2) {
                    system("CLS");
                    cout << "Please contact our staff to add appointment." << endl;
                    cout << "Phone number: 0123456789" << endl << endl;
                    system("PAUSE");
                    continue;
                } else if (response == 3) {
                    linked_list<appointment> this_patient_app;
                    appointment temp;
                    for (int i = 1; i <= appointment_list.getLength(); i++) {
                        appointment_list.retrieve(i,temp);
                        if (temp.get_patientID() == cur_patient_ptr->get_patientID()) {
                            this_patient_app.insert(1,temp);
                        }
                    }

                    int delete_index = displayer.patient_delete_appointment(this_patient_app);

                    if (delete_index == -1) {
                        displayer.invalid_input();
                        continue;
                    } else {
                        appointment delete_app;
                        this_patient_app.retrieve(delete_index,delete_app);

                        for (int i = 1; i <= appointment_list.getLength(); i++) {
                            appointment_list.retrieve(i,temp);
                            if (temp.get_patientID() == delete_app.get_patientID()) {
                                appointment_list.remove(i);
                                break;
                            }
                        }
                        displayer.appointment_deleted_successfully();
                        continue;
                    }
                } else if (response == 4) {
                    continue;
                }
            } else if (choice == 2) {
                choice = displayer.patient_my_profile(*cur_patient_ptr);

                if (choice == 1) {
                    choice = displayer.patient_edit_profile();
                    switch (choice)
                    {
                        case 1:
                        edit_username(cur_patient_ptr, &patient_list, &doctor_list, &admin_list);
                        break;

                        case 2:
                        edit_password(cur_patient_ptr);
                        break;

                        case 3:
                        edit_name(cur_patient_ptr);
                        break;

                        case 4:
                        edit_age(cur_patient_ptr);
                        break;

                        case 5:
                        edit_phone_number(cur_patient_ptr);
                        break;
                    }

                    patient temp;
                    for (int i = 1; i <= patient_list.getLength(); i++) {
                        patient_list.retrieve(i,temp);
                        if (temp.get_patientID() == cur_patient_ptr->get_patientID()) {
                            patient_list.remove(i);
                            patient_list.insert(i,*cur_patient_ptr);
                        }
                    }

                    displayer.patient_profile_editted_successfully();
                    continue;
                } else if (choice == 2) {
                    continue;
                }

            } else if (choice == 3) {
                choice = displayer.doctor_directory();

                if (choice == 1) {
                    linked_list<doctor> copied_doctor_list(doctor_list);
                    display_all_doctors:
                    char sort_or_not = displayer.display_all_doctors(copied_doctor_list);

                    if (sort_or_not == 'X') {
                        continue;
                    } else if (sort_or_not == 'S') {
                        sort_helper.sort_doctor_by_specification(copied_doctor_list,1,copied_doctor_list.getLength());
                        goto display_all_doctors;
                    }
                } else if (choice == 2) {
                    doctor* searched_doctor = search_helper.search_doctor_by_doctorID(doctor_list);
                    if (searched_doctor == NULL) {
                        displayer.search_doctor_fail();
                        continue;
                    }

                    displayer.display_searched_doctor(*searched_doctor);
                    continue;
                }
            } else if (choice == 4) {
                displayer.thank_you();
                break;
            }
        }

    } else if (menu == "doctor") {
        while (true) {
            choice = displayer.doctor_menu();
            if (choice == 1) {
                linked_list <appointment> copied_appointment_list(appointment_list);
                display_doctor_appointments:
                int size = appointment_list.getLength();
                appointment temp;
                Stack<appointment> appointments;
                for (int i = 1; i <= size; i++) {
                    copied_appointment_list.retrieve(i,temp);
                    if (cur_doctor_ptr->get_doctorID() == temp.get_doctorID()) {
                        appointments.push(temp);
                    }
                }

                char sort_or_not = displayer.doctor_my_appointment(appointments);
                if (sort_or_not == 'X') {
                    continue;
                } else if (sort_or_not == 'S') {
                    sort_helper.sort_appointment_by_appointment_time(copied_appointment_list, 1, copied_appointment_list.getLength());
                    goto display_doctor_appointments;
                }

            } else if (choice == 2) {
                choice = displayer.doctor_my_profile(*cur_doctor_ptr);

                if (choice == 1) {
                    choice = displayer.doctor_edit_profile();
                    switch (choice)
                    {
                        case 1:
                        edit_username(cur_doctor_ptr, &patient_list, &doctor_list, &admin_list);
                        break;

                        case 2:
                        edit_password(cur_doctor_ptr);
                        break;

                        case 3:
                        edit_name(cur_doctor_ptr);
                        break;

                        case 4:
                        edit_age(cur_doctor_ptr);
                        break;

                        case 5:
                        edit_phone_number(cur_doctor_ptr);
                        break;

                        case 6:
                        edit_address(cur_doctor_ptr);
                        break;
                    }

                    doctor temp;
                    for (int i = 1; i <= doctor_list.getLength(); i++) {
                        doctor_list.retrieve(i,temp);
                        if (temp.get_doctorID() == cur_doctor_ptr->get_doctorID()) {
                            doctor_list.remove(i);
                            doctor_list.insert(i,*cur_doctor_ptr);
                        }
                    }

                    displayer.doctor_profile_editted_successfully();
                    continue;
                } else if (choice == 2) {
                    continue;
                }
            } else if (choice == 3) {
                choice = displayer.patient_directory();

                if (choice == 1) {
                    linked_list <patient> copied_patient_list(patient_list);
                    display_all_patients:
                    char sort_or_not = displayer.display_all_patients(copied_patient_list);

                    if (sort_or_not == 'X') {
                        continue;
                    } else if (sort_or_not == 'S') {
                        sort_helper.sort_patient_by_age(copied_patient_list,1,copied_patient_list.getLength());
                        goto display_all_patients;
                    }
                } else if (choice == 2) {
                    patient* searched_patient = search_helper.search_patient_by_patientID(patient_list);
                    if (searched_patient == NULL) {
                        displayer.search_patient_fail();
                        continue;
                    }

                    displayer.display_searched_patient(*searched_patient);
                    continue;
                }
            } else if (choice == 4) {
                displayer.thank_you();
                break;
            }
        }

    } else if (menu == "admin") {
        while (true) {
            choice = displayer.admin_menu();

            if (choice == 1) {
                choice = displayer.admin_appointment();
                if (choice == 1) {
                    linked_list <appointment> copied_appointment_list(appointment_list);
                    display_all_appointments:
                    char sort_or_not = displayer.display_all_appointments(copied_appointment_list);
                    if (sort_or_not == 'X') {
                        continue;
                    } else if (sort_or_not == 'S') {
                        sort_helper.sort_appointment_by_appointment_time(copied_appointment_list,1,copied_appointment_list.getLength());
                        goto display_all_appointments;
                    }

                } else if (choice == 2) {
                    appointment add_appointment = do_appointment(patient_list, doctor_list, appointment_list);

                    if (add_appointment.get_day() == 0) {
                        continue;
                    } else {
                        appointment_list.insert(1,add_appointment);
                        displayer.appoinment_added_successfully();
                        continue;
                    }

                } else if (choice == 3) {
                    int delete_index = displayer.admin_delete_appointment(&appointment_list);

                    if (delete_index == -1) {
                        displayer.invalid_input();
                        continue;
                    } else {
                        appointment_list.remove(delete_index);
                        displayer.appointment_deleted_successfully();
                        continue;
                    }
                } else if (choice == 3) {
                    continue;
                }
            } else if (choice == 2) {
                choice = displayer.admin_my_profile(*cur_admin_ptr);

                if (choice == 1) {
                    choice = displayer.admin_edit_profile();

                    admin temp;
                    switch (choice)
                    {
                        case 1:
                        edit_username(cur_admin_ptr, &patient_list, &doctor_list, &admin_list);
                        for (int i = 1; i <= admin_list.getLength(); i++) {
                            admin_list.retrieve(i,temp);
                            if (temp.get_password() == cur_admin_ptr->get_password()) {
                                admin_list.remove(i);
                                admin_list.insert(i,*cur_admin_ptr);
                            }
                        }
                        break;

                        case 2:
                        edit_password(cur_admin_ptr);
                        for (int i = 1; i <= admin_list.getLength(); i++) {
                            admin_list.retrieve(i,temp);
                            if (temp.get_username() == cur_admin_ptr->get_username()) {
                                admin_list.remove(i);
                                admin_list.insert(i,*cur_admin_ptr);
                            }
                        }
                        break;
                    }




                    displayer.admin_profile_editted_successfully();
                    continue;
                } else if (choice == 2) {
                    continue;
                }
            } else if (choice == 3) {
                choice = displayer.admin_directory();

                if (choice == 1) {
                    choice = displayer.admin_display();

                    if (choice == 1) {
                        displayer.display_all_admins(admin_list);

                    } else if (choice == 2) {
                        linked_list <patient> copied_patient_list(patient_list);
                        admin_display_all_patients:
                        char sort_or_not = displayer.display_all_patients(copied_patient_list);

                        if (sort_or_not == 'X') {
                            continue;
                        } else if (sort_or_not == 'S') {
                            sort_helper.sort_patient_by_age(copied_patient_list,1,copied_patient_list.getLength());
                            goto admin_display_all_patients;
                        }

                    } else if (choice == 3) {
                        linked_list <doctor> copied_doctor_list(doctor_list);
                        admin_display_all_doctors:
                        char sort_or_not = displayer.display_all_doctors(copied_doctor_list);

                        if (sort_or_not == 'X') {
                            continue;
                        } else if (sort_or_not == 'S') {
                            sort_helper.sort_doctor_by_specification(copied_doctor_list,1,copied_doctor_list.getLength());
                            goto admin_display_all_doctors;
                        }
                    } else if (choice == 4) {
                        continue;
                    }

                    continue;
                } else if (choice == 2) {
                    choice = displayer.admin_search();

                    if (choice == 1) {
                        patient* searched_patient = search_helper.search_patient_by_patientID(patient_list);
                        if (searched_patient == NULL) {
                            displayer.search_patient_fail();
                            continue;
                        }

                        displayer.display_searched_patient(*searched_patient);
                    } else if (choice == 2) {
                        doctor* searched_doctor = search_helper.search_doctor_by_doctorID(doctor_list);
                        if (searched_doctor == NULL) {
                            displayer.search_doctor_fail();
                            continue;
                        }

                        displayer.display_searched_doctor(*searched_doctor);
                    } else if (choice == 3) {
                        continue;
                    }

                    continue;
                } else if (choice == 3) {
                    choice = displayer.admin_delete();
                    if (choice == 1) {
                        delete_patient(&patient_list);
                    } else if (choice == 2) {
                        delete_doctor(&doctor_list);
                    } else if (choice == 3) {
                        continue;
                    }

                    continue;
                } else if (choice == 4) {
                    choice = displayer.admin_edit();
                    if (choice == 1) {
                        system("CLS");
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                                              cout<<"\t\t\t\t\t\t\t\t\t\t             EDIT PATIENT           "<<endl;
                                                              cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

                        cout<<"\t\t\t\t\t\t\t\t\t\tPATIENT ID: ";
                        string ID;
                        cin.get();
                        getline(cin,ID);
                        cout<<endl;

                        patient* edited_patient = new patient();
                        bool found = false;
                        for (int i = 1; i <= patient_list.getLength(); i++) {
                            patient_list.retrieve(i,*edited_patient);
                            if (edited_patient->get_patientID() == ID) {
                                found = true;
                                break;
                            }
                        }

                        if (found == false) {
                            displayer.search_patient_fail();
                            continue;
                        }

                        choice = displayer.patient_my_profile(*edited_patient);

                        if (choice == 1) {
                            choice = displayer.patient_edit_profile();
                            switch (choice)
                            {
                                case 1:
                                edit_username(edited_patient, &patient_list, &doctor_list, &admin_list);
                                break;

                                case 2:
                                edit_password(edited_patient);
                                break;

                                case 3:
                                edit_name(edited_patient);
                                break;

                                case 4:
                                edit_age(edited_patient);
                                break;

                                case 5:
                                edit_phone_number(edited_patient);
                                break;
                            }

                            patient temp;
                            for (int i = 1; i <= patient_list.getLength(); i++) {
                                patient_list.retrieve(i,temp);
                                if (temp.get_patientID() == edited_patient->get_patientID()) {
                                    patient_list.remove(i);
                                    patient_list.insert(i,*edited_patient);
                                }
                            }

                            displayer.patient_profile_editted_successfully();
                            continue;
                        }
                    } else if (choice == 2) {
                        system("CLS");
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                                              cout<<"\t\t\t\t\t\t\t\t\t\t             EDIT DOCTOR              "<<endl;
                                                              cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

                        cout<<"\t\t\t\t\t\t\t\t\t\tDOCTOR ID: ";

                        string ID;
                        cin.get();
                        getline(cin,ID);
                        cout<<endl;

                        doctor* edited_doctor = new doctor();
                        bool found = false;
                        for (int i = 1; i <= doctor_list.getLength(); i++) {
                            doctor_list.retrieve(i,*edited_doctor);
                            if (edited_doctor->get_doctorID() == ID) {
                                found = true;
                                break;
                            }
                        }

                        if (found == false) {
                            displayer.search_doctor_fail();
                            continue;
                        }

                        choice = displayer.doctor_my_profile(*edited_doctor);

                        if (choice == 1) {
                            choice = displayer.patient_edit_profile();
                            switch (choice)
                            {
                                case 1:
                                edit_username(edited_doctor, &patient_list, &doctor_list, &admin_list);
                                break;

                                case 2:
                                edit_password(edited_doctor);
                                break;

                                case 3:
                                edit_name(edited_doctor);
                                break;

                                case 4:
                                edit_age(edited_doctor);
                                break;

                                case 5:
                                edit_phone_number(edited_doctor);
                                break;
                            }

                            doctor temp;
                            for (int i = 1; i <= doctor_list.getLength(); i++) {
                                doctor_list.retrieve(i,temp);
                                if (temp.get_doctorID() == edited_doctor->get_doctorID()) {
                                    doctor_list.remove(i);
                                    doctor_list.insert(i,*edited_doctor);
                                }
                            }

                            displayer.doctor_profile_editted_successfully();
                            continue;
                        }
                    }

                } else if (choice == 5) {
                    choice = displayer.admin_add();
                    if (choice == 1) {
                        add_doctor(&doctor_list);
                    } else if (choice == 2) {
                        add_admin(&admin_list);
                    } else if (choice == 3) {
                        continue;
                    }
                    continue;
                } else if (choice == 6) {
                    continue;
                }

            } else if (choice == 4) {
                displayer.thank_you();
                break;
            }
        }

    }

    patient_list.save("patient.txt");
    doctor_list.save("doctor.txt");
    admin_list.save("admin.txt");
    appointment_list.save("appointment.txt");
    return 0;
}

void patient_register(linked_list<patient>* patient_list) {
    //display title "Patient Register"
    //ask personal info one by one (refer to UI)
    //call patient(username, password, name, age, phone_number, patientID),
    //no need to insert patient ID because we will create it in constructor
    //add new patient to patient list
    //call void patient_register_success(patient ID) in menu class
    system("CLS");
    string usnm,pass,name,ID,phnm,ans;
    int age;
    menu newUser;
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******      #                      "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******      #                      "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****    #######           PATIENT REGISTER "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t          *********     #                     "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********    #                      "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           \n\n\n\n"<<endl;

    cin.get();
    while (true) {
        try {
            cout<<"\t\t\t\t\t\t\t\t\t\t         Please enter your username: ";
            cin.clear();
            getline(cin,usnm);
            cout<<endl;

            patient temp;
            for (int i = 1; i <= patient_list->getLength(); i++) {
                patient_list->retrieve(i,temp);
                if (usnm == temp.get_username()) {
                    throw -1;
                }
            }

            break;
        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\t         This username already exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<"\t\t\t\t\t\t\t\t\t\t         Please enter your password: ";
    cin.clear();
    getline(cin,pass);
    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         Please enter your name: ";
    cin.clear();
    getline(cin,name);
    //transform(name.begin(),name.end(),name.begin(),::toupper);
    for (auto & c: name) c = toupper(c);
    cout<<endl;

    while (true) {
        try{
            cout<<"\t\t\t\t\t\t\t\t\t\t         Please enter your age: ";

            string input;
            cin>>input;
            age = stoi(input);

            if(age<0 || age>999)
            {
                throw 0;
            }
            break;
        }
        catch(...)
        {
            cout<<"\t\t\t\t\t\t\t\t\t\t         Please Enter valid positive integer number!"<<endl;
            continue;
        }
    }

    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         Please enter your phone number(without '-'): ";
    cin.get();
    getline(cin,phnm);
    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         Is all the information correct?"<< endl<<endl<<endl<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Username: "<< usnm << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Password: "<< pass << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Name: "<< name << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Age: " << age << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Handphone Number: " << phnm << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         Confirm? (y/n)" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t         : ";
    cin>>ans;
    if(ans=="y"||ans=="Y")
    {
        patient temp(usnm,pass,name,age,phnm);
        patient_list->insert(1,temp);
        ID = temp.get_patientID();
        newUser.patient_register_successfully(ID);
    }
    else
    {
        newUser.register_or_added_fail();
    }

}

patient* patient_login(const linked_list<patient>& patient_list){
    //display title "Patient Login"
    //ask for username and password
    //compare user input with all entries in patient_list
    //If match, retrieve the element to *cur_patient_ptr (later record in main program and proceed to patient_menu())
    //If not match, set  (later display fail page and go to role choosing page again in main program)
    system("CLS");
    string usnm,pass;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                PATIENT LOGIN "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t          *********                            "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         USERNAME: ";
    cin>>usnm;
    cout<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         PASSWORD: ";
    cin>>pass;
    cout<<endl;
    patient *cur_patient_ptr = new patient;
    patient temp;

    for (int i = 1; i <= patient_list.getLength(); i++)
    {
        patient_list.retrieve(i,temp);
        if (usnm == temp.get_username() && pass == temp.get_password())
        {
            patient_list.retrieve(i, *cur_patient_ptr);
            return cur_patient_ptr;
        }
    }

    return nullptr;
}

doctor* doctor_login(const linked_list<doctor>& doctor_list) {
    //display title "Doctor Login"
    //ask for username and password
    //compare user input with all entries in doctor_list
    //If match, return the current doctor (later record in main program and proceed to doctor_menu())
    //If not match, return NULL (later display fail page and go to role choosing page again in main program)
    system("CLS");
    string usnm,pass;
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                DOCTOR LOGIN  "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t          *********                            "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl<<endl<<endl;


    cout<<"\t\t\t\t\t\t\t\t\t\t         USERNAME: ";
    cin.get();
    getline(cin,usnm);
    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         PASSWORD: ";
    cin.clear();
    getline(cin,pass);
    cout<<endl;

    doctor *cur_doctor_ptr = new doctor;
    doctor temp;

    for (int i = 1; i <= doctor_list.getLength(); i++)
    {
        doctor_list.retrieve(i,temp);
        if (usnm == temp.get_username() && pass == temp.get_password())
        {
            doctor_list.retrieve(i, *cur_doctor_ptr);
            return cur_doctor_ptr;
        }
    }

    return nullptr;
}

admin* admin_login(const linked_list<admin>& admin_list) {
    //display title "Admin Login"
    //ask for username and password
    //compare user input will all entries in admin_list
    //If match, return the current admin (later record in main program and proceed to admin_menu())
    //If not match, return NULL (later display fail page and go to role choosing page again in main program)
    system("CLS");
    string usnm,pass;
    menu displayer;
    displayer.adminpage();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t           *******                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t            *****                ADMIN LOGIN   "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t          *********                            "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\t         ***********                           "<<endl<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         USERNAME: ";
    cin.get();
    getline(cin,usnm);
    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\t         PASSWORD: ";
    cin.clear();
    getline(cin,pass);
    cout<<endl;

    admin *cur_admin_ptr = new admin;
    admin temp;

    for (int i = 1; i <= admin_list.getLength(); i++)
    {
        admin_list.retrieve(i,temp);
        if (usnm == temp.get_username() && pass == temp.get_password())
        {
            admin_list.retrieve(i, *cur_admin_ptr);
            return cur_admin_ptr;
        }
    }

    return nullptr;
}

//adding function
void add_doctor(linked_list<doctor>* doctor_list) {
    //display the title "Add Doctor"
    //ask for doctor personal info (refer to user interface)
    //after finish input, display info one more time and ask for confirmation
    //yes ->    create a doctor object with user inputs
    //          add the new doctor object into doctor_list
    //          call doctor_added_successfully(doctorID) in menu class (need create to menu object first)
    //          return
    //no ->     call register_or_added_fail() in menu class
    //          return
    system("CLS");
    string usnm,pass,name,ID,phnm,addr,spec,ans;
    int age;
    menu newUser;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t             ADD  DOCTOR              "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cin.get();
    while (true) {
        try {
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's username: ";
            cin.clear();
            getline(cin,usnm);
            cout<<endl;

            doctor temp;
            for (int i = 1; i <= doctor_list->getLength(); i++) {
                doctor_list->retrieve(i,temp);
                if (usnm == temp.get_username()) {
                    throw -1;
                }
            }

            break;
        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThis username already exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's password: ";
    cin.clear();
    getline(cin,pass);
    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's name: ";
    cin.clear();
    getline(cin,name);
    for (auto & c: name) c = toupper(c);
    cout<<endl;

    while (true) {
        try{
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's age: ";

            string input;
            cin>>input;
            age = stoi(input);

            if(age<0 || age>999)
            {
                throw 0;
            }
            break;
        }
        catch(...)
        {
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease Enter valid positive integer number!"<<endl;
            continue;
        }
    }

    cout<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's phone number(without '-'): ";
    cin.get();
    getline(cin,phnm);
    cout<<endl;

    while (true) {
        try {
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter doctor's address (do not inclcude comma (,)): ";
            cin.clear();
            getline(cin,addr);
            cout << endl << endl;

            if (addr.find(',') != string::npos) {
                throw -1;
            }

            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThe address should not contain comma(,). Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    while (true) {
        try {
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease select doctor's specification: " << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t1. Cardiologists" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t2. Dermatologists" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t3. Neurologists" << endl << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t";

            string input;
            cin.clear();
            getline(cin,input);

            if (input == "1") {
                spec = "CARDIOLOGISTS";
            } else if (input == "2") {
                spec = "DERMATOLOGISTS";
            } else if (input == "3") {
                spec = "NEUROLOGISTS";
            } else {
                throw -1;
            }

            cout<<endl;
            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<"\n\t\t\t\t\t\t\t\t\t\tIs all the information correct?"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\tUsername: "<< usnm << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tPassword: "<< pass << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tName: "<< name << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tAge: " << age << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tHandphone Number: " << phnm << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tAddress: " << addr << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tSpecification: "<< spec << endl<<endl;
    cout << "\t\t\t\t\t\t\t\t\t\tConfirm? (y/n)" << endl;
    cin.clear();
    getline(cin,ans);
    if(ans=="y"||ans=="Y")
    {
        doctor temp(usnm,pass,name,age,phnm,addr,spec);
        doctor_list->insert(1,temp);
        ID = temp.get_doctorID();
        newUser.doctor_added_successfully(ID);
    }
    else
    {
        newUser.register_or_added_fail();
    }

}

void add_admin(linked_list<admin>* admin_list) {
    //display the title "Add Admin"
    //ask for admin username and password (refer to user interface)
    //after finish input, display info one more time and ask for confirmation
    //yes ->    create an admin object with user inputs
    //          add the new admin object into admin_list
    //          call admin_added_successfully() in menu class (need create to menu object first)
    //          return
    //no ->     call register_or_added_fail() in menu class
    //          return
    system("CLS");
    string usnm,pass,ans;
    menu newUser;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t             ADD  ADMIN               "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cin.get();
    while (true) {
        try {
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter admin's username: ";
            cin.clear();
            getline(cin,usnm);
            cout<<endl;

            admin temp;
            for (int i = 1; i <= admin_list->getLength(); i++) {
                admin_list->retrieve(i,temp);
                if (usnm == temp.get_username()) {
                    throw -1;
                }
            }

            break;
        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThis username already exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter admin's password: ";
    cin.clear();
    getline(cin,pass);
    cout<<endl;

    cout<<"\n\t\t\t\t\t\t\t\t\t\tIs all the information correct?"<< endl;
    cout << "\t\t\t\t\t\t\t\t\t\tUsername: "<< usnm << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tPassword: "<< pass << endl <<endl;
    cout << "\t\t\t\t\t\t\t\t\t\tConfirm? (y/n)" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t";

    getline(cin,ans);

    if(ans=="y"||ans=="Y")
    {
        admin temp(usnm,pass);
        admin_list->insert(1,temp);
        newUser.admin_added_successfully();
    }
    else
    {
        newUser.register_or_added_fail();
    }

}

//deleting function
void delete_patient(linked_list<patient>* patient_list) {
    //display the title "Delete Patient"
    //prompt patient id from user
    //search patient from patient_list
    //display all patient info and ask for confirmation
    //yes ->    delete patient from patient_list
    //          call patient_deleted_successfully() in menu class (need create menu object first)
    //no ->     call patient_deleted_fail() in menu class
    //          return
    system("CLS");
    menu mn1;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t            DELETE  PATIENT           "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tPATIENT ID WANT TO BE DELETED: ";
    string ID;
    cin.get();
    getline(cin,ID);

    patient *temp = new patient;
    int index = 0;
    for (int i = 1; i <= patient_list->getLength(); i++) {
        patient_list->retrieve(i, *temp);
        if (ID == temp->get_patientID()) {
            index = i;
            break;
        }
    }

    if (index == 0) {
        mn1.search_patient_fail();
        return;
    }

    while (true) {
        try {

            cout<<"\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\tPatient ID: " << temp->get_patientID() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\tName: " << temp->get_name() << endl << endl;

            cout<<"\t\t\t\t\t\t\t\t\t\tDo you sure you want to delete this patient's account?(y/n): ";
            string ans;
            getline(cin,ans);

            if(ans == "y" || ans == "Y")
            {
                patient_list->remove(index);
                mn1.patient_deleted_successfully();
                return;
            }
            else if (ans == "n" || ans == "N")
            {
                mn1.patient_deleted_fail();
                return;
            } else {
                throw ans;
            }

        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please enter only 'y' or 'n'" << endl << endl;
            system("PAUSE");
            continue;
        }
    }

}

void delete_doctor(linked_list<doctor>* doctor_list) {
    //display the title "Delete Doctor"
    //prompt doctor id from user
    //search doctor from doctor_list
    //display all doctor info and ask for confirmation
    //yes ->    delete doctor from doctor_list
    //          call doctor_deleted_successfully() in menu class (need create menu object first)
    //no ->     call doctor_deleted_fail() in menu class
    //          return
    system("CLS");
    menu mn1;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t             DELETE  DOCTOR           "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tDOCTOR ID WANT TO BE DELETED: ";
    string ID;
    cin.get();
    getline(cin,ID);

    doctor *temp = new doctor;
    int index = 0;
    for (int i = 1; i <= doctor_list->getLength(); i++) {
        doctor_list->retrieve(i, *temp);
        if (ID == temp->get_doctorID()) {
            index = i;
            break;
        }
    }

    if (index == 0) {
        mn1.search_doctor_fail();
        return;
    }

    while (true) {
        try {
            cout<<"\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\tDoctor ID: " << temp->get_doctorID() << endl;
            cout << "\t\t\t\t\t\t\t\t\t\tName: " << temp->get_name() << endl << endl;

            cout<<"\t\t\t\t\t\t\t\t\t\tDo you sure you want to delete this doctor's account?(y/n): ";
            string ans;
            getline(cin,ans);

            if(ans == "y" || ans == "Y")
            {
                doctor_list->remove(index);
                mn1.doctor_deleted_successfully();
                return;
            }
            else if (ans == "n" || ans == "N")
            {
                mn1.doctor_deleted_fail();
                return;
            } else {
                throw ans;
            }

        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please enter only 'y' or 'n'" << endl << endl;
            system("PAUSE");
            continue;
        }
    }
}

template <class user>
//for editting users' info
void edit_username(user* edit_user, linked_list<patient>* patient_list,
linked_list<doctor>* doctor_list, linked_list<admin>* admin_list) {   //called by main function - by admin, patient and doctor
    //display the title "Edit Username"
    //display old username
    //prompt new username
    //call edit_user.set_username(new_username)
    cin.get();
    string input;

    while (true) {
        try {
            system("CLS");
            string old = edit_user->get_username();
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t             EDIT USERNAME"<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tCurrent username: "<< old <<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new username: ";
            cin.clear();
            getline(cin,input);

            if (is_same<user, patient>::value) {
                patient temp;
                for (int i = 1; i <= patient_list->getLength(); i++) {
                    patient_list->retrieve(i,temp);
                    if (input == temp.get_username()) {
                        throw -1;
                    }
                }
            }

            if (is_same<user, doctor>::value) {
                doctor temp;
                for (int i = 1; i <= doctor_list->getLength(); i++) {
                    doctor_list->retrieve(i,temp);
                    if (input == temp.get_username()) {
                        throw -1;
                    }
                }
            }

            if (is_same<user, admin>::value) {
                admin temp;
                for (int i = 1; i <= admin_list->getLength(); i++) {
                    admin_list->retrieve(i,temp);
                    if (input == temp.get_username()) {
                        throw -1;
                    }
                }
            }

            break;
        } catch(...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThis username already exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<endl;
    edit_user->set_username(input);
}

template <class user>
void edit_password(user* edit_user) {  //called by main function - by admin, patient and doctor
    //display the title "Edit Password"
    //display old password
    //prompt new password
    //call edit_user.set_password(new_password)
    system("CLS");
    string input;
    string old = edit_user->get_password();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t             EDIT PASSWORD            "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;


    cout<<"\t\t\t\t\t\t\t\t\t\tCurrent password: "<< old <<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new password: ";
    cin.get();
    getline(cin,input);
    cout<<endl;
    edit_user->set_password(input);
}

template <class user>
void edit_name(user* edit_user) {  //called by main function - by patient and doctor
    //display the title "Edit Name"
    //display old name
    //prompt new name
    //call edit_user.set_name(new_name)
    system("CLS");
    string input;
    string old = edit_user->get_name();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t              EDIT NAME               "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tCurrent name: "<< old <<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new name: ";
    cin.get();
    getline(cin,input);
    cout<<endl;
    for (auto & c: input) c = toupper(c);
    edit_user->set_name(input);
}

template <class user>
void edit_age(user* edit_user) {   //called by main function - by patient and doctor
    //display the title "Edit Age"
    //display old age
    //prompt new age
    //call edit_user.set_age(new_age)

    string input;
    int old = edit_user->get_age();
    int new_age;
    while (true) {
        try {
            system("CLS");
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                                  cout<<"\t\t\t\t\t\t\t\t\t\t              EDIT AGE                "<<endl;
                                                  cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tCurrent age: "<< old <<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new age: ";
            cin.get();
            getline(cin,input);
            new_age = stoi(input);
            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tPlease input only number." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    cout<<endl;
    edit_user->set_age(new_age);
}

template <class user>
void edit_phone_number(user* edit_user) {  //called by main function - by patient and doctor
    //display the title "Edit Phone Number"
    //display old phone_number
    //prompt new phone_number
    //call edit_user.set_phone_number(new_phone_number)
    system("CLS");
    string input;
    string old = edit_user->get_phone_number();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t           EDIT PHONE NUMBER          "<<endl;
                                          cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t\tCurrent phone number: "<< old <<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new phone number: ";
    cin.get();
    getline(cin,input);
    cout<<endl;
    edit_user->set_phone_number(input);
}

template <class user>
void edit_address(user* edit_user) {   //called by main function - by doctor
    //display the title "Edit Address"
    //display old address
    //prompt new address
    //call edit_user.set_address(new_address)

    cin.get();
    string input;
    while (true) {
        try {
            system("CLS");
            string old = edit_user->get_address();
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t======================================"<<endl;
                                                  cout<<"\t\t\t\t\t\t\t\t\t\t            EDIT ADDRESS              "<<endl;
                                                  cout<<"\t\t\t\t\t\t\t\t\t\t======================================" << endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tCurrent address: "<< old <<endl;
            cout<<"\t\t\t\t\t\t\t\t\t\tPlease enter new address (do not include comma (,)): ";
            cin.clear();
            getline(cin,input);
            cout << endl << endl;

            if (input.find(',') != string::npos) {
                throw -1;
            }

            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThe address should not contain comma(,). Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    edit_user->set_address(input);
}

//for doing appointment
appointment do_appointment(const linked_list <patient> patient_list,
const linked_list <doctor> doctor_list, const linked_list <appointment> appointment_list) {
    string PID, DID;
    int d, m, y, choice, StartT, EndT;

    cin.get();
    while (true) {
        try {
            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t=========================================="<<endl;
                                              cout << "\t\t\t\t\t\t\t\t\t\t              ADD APPOINTMENT             "<< endl;
                                              cout << "\t\t\t\t\t\t\t\t\t\t==========================================" << endl<<endl;
                                              cout << "\t\t\t\t\t\t\t\t\t\tPlease enter patient ID: ";
            cin.clear();
            getline(cin, PID);
            cout << endl;

            bool found = false;
            for (int i = 1; i <= patient_list.getLength(); i++) {
                patient temp;
                patient_list.retrieve(i, temp);

                if (PID == temp.get_patientID()) {
                    found = true;
                    break;
                }
            }

            if (found == false) {
                throw -1;
            }

            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThis patient ID does not exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    while (true) {
        try {
            cout << "\t\t\t\t\t\t\t\t\t\tPlease enter doctor ID: ";
            cin.clear();
            getline(cin, DID);
            cout << endl;

            bool found = false;
            for (int i = 1; i <= doctor_list.getLength(); i++) {
                doctor temp;
                doctor_list.retrieve(i, temp);

                if (DID == temp.get_doctorID()) {
                    found = true;
                    break;
                }
            }

            if (found == false) {
                throw -1;
            }

            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tThis doctor ID does not exist." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    while (true) {
        try {
            string input;

            cout << "\t\t\t\t\t\t\t\t\t\tPlease enter year of appointment: ";
            cin.clear();
            getline(cin, input);
            y = stoi(input);
            cout << endl;

            while (y < year || y > year + 5) {
                cout << "\t\t\t\t\t\t\t\t\t\tInvalid year input !!!\n";
                cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your year of appointment again: ";
                cin.clear();
                getline(cin, input);
                y = stoi(input);
                cout << endl;
            }

            cout << "\t\t\t\t\t\t\t\t\t\tPlease enter month of appointment: ";
            cin.clear();
            getline(cin, input);
            m = stoi(input);
            cout << endl;

            while(m < 1 || m > 12){
                cout << "\t\t\t\t\t\t\t\t\t\tInvalid month input !!!\n";
                cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your month of appointment again: ";
                cin.clear();
                getline(cin, input);
                m = stoi(input);
                cout << endl;
            }

            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
                cout << "\t\t\t\t\t\t\t\t\t\tPlease enter day of appointment: ";
                cin.clear();
                getline(cin, input);
                d = stoi(input);
                cout << endl;

                while (d < 1 || d > 31){
                    cout << "\t\t\t\t\t\t\t\t\t\tInvalid day input !!!\n";
                    cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your day of appointment again: ";
                    cin.clear();
                    getline(cin, input);
                    d = stoi(input);
                    cout << endl;
                }

            } else if (m == 4 || m == 6 || m == 9 || m == 11){
                cout << "\t\t\t\t\t\t\t\t\t\tPlease enter day of appointment: ";
                cin.clear();
                getline(cin, input);
                d = stoi(input);
                cout << endl;

                while(d < 1 || d > 30){
                    cout << "\t\t\t\t\t\t\t\t\t\tInvalid day input !!!\n";
                    cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your day of appointment again: ";
                    cin.clear();
                    getline(cin, input);
                    d = stoi(input);
                    cout << endl;

                }

            } else if (m == 2){
                cout << "\t\t\t\t\t\t\t\t\t\tPlease enter day of appointment: ";
                cin.clear();
                getline(cin, input);
                d = stoi(input);
                cout << endl;

                if(y % 4 == 0){
                    while(d < 1 || d > 29) {
                        cout << "\t\t\t\t\t\t\t\t\t\tInvalid day input !!!\n";
                        cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your day of appointment again: ";
                        cin.clear();
                        getline(cin, input);
                        d = stoi(input);
                        cout << endl;
                    }
                } else {
                    while(d < 1 || d > 28) {
                        cout << "\t\t\t\t\t\t\t\t\t\tInvalid day input !!!\n";
                        cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your day of appointment again: ";
                        cin.clear();
                        getline(cin, input);
                        d = stoi(input);
                        cout << endl;
                    }
                }
            }

            if ((y == year && m < month) || (y == year && m == month && d <= day)) {
                throw -1;
            }

            break;
        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. You can not choose today or the day before today. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    while(true) {
        try {
            string input;

            cout << "\t\t\t\t\t\t\t\t\t\tOperating time: \n";
            cout << "\t\t\t\t\t\t\t\t\t\t1. 8.00am - 9.00am \n";
            cout << "\t\t\t\t\t\t\t\t\t\t2. 9.00am - 10.00am \n";
            cout << "\t\t\t\t\t\t\t\t\t\t3. 10.00am - 11.00am \n";
            cout << "\t\t\t\t\t\t\t\t\t\t4. 11.00am - 12.00pm \n";
            cout << "\t\t\t\t\t\t\t\t\t\tPlease enter your choice: ";
            cin.clear();
            getline(cin, input);
            choice = stoi(input);
            cout << endl;

            while(choice > 4 || choice < 1){
                throw -1;
            }

            switch(choice){
                case 1:
                    StartT = 8;
                    EndT = 9;
                    break;
                case 2:
                    StartT = 9;
                    EndT = 10;
                    break;
                case 3:
                    StartT = 10;
                    EndT = 11;
                    break;
                case 4:
                    StartT = 11;
                    EndT = 12;
                    break;
            }
            break;

        } catch (...) {
            cout << "\t\t\t\t\t\t\t\t\t\tInvalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }

    }

    //checking whether it is possible
    for (int i = 1; i <= appointment_list.getLength(); i++) {
        appointment temp;
        appointment_list.retrieve(i,temp);

        if (temp.get_patientID() == PID && temp.get_year() == y
        && temp.get_month() == m && temp.get_day() == d && temp.get_strarting_time() == StartT) {
            system("CLS");
            cout << "This patient already have another appointment at the same time!" << endl << endl;
            system("PAUSE");
            appointment empty;
            return empty;
        }

        if (temp.get_doctorID() == DID && temp.get_year() == y
        && temp.get_month() == m && temp.get_day() == d && temp.get_strarting_time() == StartT) {
            system("CLS");
            cout << "This doctor already have another appointment at the same time!" << endl << endl;
            system("PAUSE");
            appointment empty;
            return empty;
        }
    }

    while (true)
    {
        try {
            system("CLS");
            cout<<"\n\n\n\n";
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                               ADD APPOINTMENT                                |           "<<endl;
            cout<<"\t\t\t\t\t\t          |                                                                              |           "<<endl;
            cout<<"\t\t\t\t\t\t           =============================================================================             "<<endl<<endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Patient ID:        | " <<setw(56)<<left<< PID <<"|"<< endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Doctor ID:         | " <<setw(56)<<left<< DID <<"|"<< endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Appointment year:  | " <<setw(56)<<left<< y <<"|"<< endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Appointment month: | " <<setw(56)<<left<< m <<"|"<< endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Appointment day:   | " <<setw(56)<<left<< d <<"|"<< endl;
            cout<<"\t\t\t\t\t\t           ------------------------------------------------------------------------------            "<<endl;
            cout<<"\t\t\t\t\t\t          | Appointment time:  | " <<setw(2)<<left<< StartT << ".00 - " <<setw(2)<<left<< EndT << ".00" <<setw(44)<<right<<"|"<< endl;
            cout<<"\t\t\t\t\t\t          |______________________________________________________________________________|"<<endl<<endl;
            cout<<"\t\t\t\t\t\t           Confirm? (y/n): ";

            string input;
            cin.clear();
            getline(cin, input);
            for (auto & c: input) c = toupper(c);
            cout << endl;

            if (input == "Y") {
                break;
            } else if (input == "N") {
                system("CLS");
                cout << "Appointment is not created!" << endl << endl;
                system("PAUSE");
                appointment empty;
                return empty;
            } else {
                throw -1;
            }

        } catch (...) {
            cout << "\t\t\t\t\t\t          Invalid input. Please try again." << endl << endl;
            system("PAUSE");
            continue;
        }
    }

    appointment app(PID,DID,d,m,y,StartT,EndT);
    return app;
}
