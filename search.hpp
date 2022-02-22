#ifndef SEARCH_HPP_
#define SEARCH_HPP_

#include <iostream>
#include <string>
#include "patient.hpp"
#include "doctor.hpp"
#include "linked_list.hpp"

using namespace std;

class search {
    public:
    search() {} //constructor

    //search method
    patient* search_patient_by_patientID(linked_list<patient>& patient_list) const;
    doctor* search_doctor_by_doctorID(linked_list<doctor>& doctor_list) const;
};

patient* search::search_patient_by_patientID(linked_list<patient>& patient_list) const {
//using patient_list to find patient
//return patient found
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t              ***                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            *     *                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t           *       *                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            *     *          SEARCH PATIENT "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t              **8*                            "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                 8                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                  8                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                                             "<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t           -------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t           PATIENT ID: ";

    string patientID;
    cin.get();
    getline(cin,patientID);

    patient* temp = new patient();

    for(int i=1; i<=patient_list.getLength(); i++){
        patient_list.retrieve(i, *temp);
        if(temp->get_patientID()==patientID){
            return temp;
        }
    }

    return NULL;
}

doctor* search::search_doctor_by_doctorID(linked_list<doctor>& doctor_list) const {
//using doctor_list to find doctor
//return doctor found
    system("CLS");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t              ***                              "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            *     *                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t           *       *                             "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t            *     *          SEARCH DOCTOR "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t              **8*                            "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                 8                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                  8                           "<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t                                             "<<endl;

    cout<<"\t\t\t\t\t\t\t\t\t           -------------------------------"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t           DOCTOR ID: ";

    string doctorID;
    cin.get();
    getline(cin,doctorID);

    doctor* temp = new doctor();

    for(int i=1; i<=doctor_list.getLength(); i++){
        doctor_list.retrieve(i, *temp);
        if(temp->get_doctorID()==doctorID){
            return temp;
        }
    }

    return NULL;
}

#endif
