#ifndef SORT_HPP_
#define SORT_HPP_

#include <iostream>
#include <string>
#include "patient.hpp"
#include "doctor.hpp"
#include "appointment.hpp"
#include "linked_list.hpp"

class sort {
    public:
    sort() {}//constructor

    //sort function
    void sort_patient_by_age(linked_list<patient>& patient_list, int first, int last);
    void sort_doctor_by_specification(linked_list<doctor>& doctor_list, int first, int last);

    //sorting appointment
    void sort_appointment_by_appointment_time(linked_list<appointment>& appointment_list, int first, int last);
    void sort_appointment_by_time(linked_list<appointment>& appointment_list, int first, int last);      //call by sort_appointment_by_appointment_time
    void sort_appointment_by_day(linked_list<appointment>& appointment_list, int first, int last);       //call by sort_appointment_by_appointment_time
    void sort_appointment_by_month(linked_list<appointment>& appointment_list, int first, int last);     //call by sort_appointment_by_appointment_time
    void sort_appointment_by_year(linked_list<appointment>& appointment_list, int first, int last);      //call by sort_appointment_by_appointment_time

    //swap function
    void patient_swap(linked_list <patient>& patient_list, int index1, int index2);
    void doctor_swap(linked_list <doctor>& doctor_list, int index1, int index2);
    void appointment_swap(linked_list <appointment>& appointment_list, int index1, int index2);

    //partition for quick sort
    void patient_age_partition(linked_list <patient>& patient_list, int first, int last, int& pivotIndex);
    void doctor_specification_partition(linked_list <doctor>& doctor_list, int first, int last, int& pivotIndex);
    void appointment_time_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex);
    void appointment_day_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex);
    void appointment_month_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex);
    void appointment_year_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex);
};

//sort function
void sort::sort_patient_by_age(linked_list<patient>& patient_list, int first, int last) {
//get copied patient list and sort it by name and by ascending order
    if (first < last) {
      int pivotIndex = first;
      patient_age_partition(patient_list, first, last, pivotIndex);
      sort_patient_by_age(patient_list, first, pivotIndex - 1);     //left-hand side
      sort_patient_by_age(patient_list, pivotIndex + 1, last);      //right-hand side
   }
}

void sort::sort_doctor_by_specification(linked_list<doctor>& doctor_list, int first, int last) {
//get copied doctor list and sort it by specification and by ascending order
    if (first < last) {
      int pivotIndex = first;
      doctor_specification_partition(doctor_list, first, last, pivotIndex);
      sort_doctor_by_specification(doctor_list, first, pivotIndex - 1);     //left-hand side
      sort_doctor_by_specification(doctor_list, pivotIndex + 1, last);      //right-hand side
   }
}

//sorting appointment
void sort::sort_appointment_by_appointment_time(linked_list<appointment>& appointment_list, int first, int last) {
    //get copied appointment list and sort it by ascending order
    //sort by sequence: time -> day -> month -> year (make use of function sort_appointment_by_time etc.)
    sort_appointment_by_time(appointment_list,first,last);
    sort_appointment_by_day(appointment_list,first,last);
    sort_appointment_by_month(appointment_list,first,last);
    sort_appointment_by_year(appointment_list,first,last);
}

void sort::sort_appointment_by_time(linked_list<appointment>& appointment_list, int first, int last){    //call by sort_appointment_by_appointment_time
//sort appointment by starting time and by ascending order
    if (first < last) {
      int pivotIndex = first;
      appointment_time_partition(appointment_list, first, last, pivotIndex);
      sort_appointment_by_time(appointment_list, first, pivotIndex - 1);     //left-hand side
      sort_appointment_by_time(appointment_list, pivotIndex + 1, last);      //right-hand side
   }
}

void sort::sort_appointment_by_day(linked_list<appointment>& appointment_list, int first, int last) {    //call by sort_appointment_by_appointment_time
//sort appointment by day and by ascending order
    if (first < last) {
      int pivotIndex = first;
      appointment_day_partition(appointment_list, first, last, pivotIndex);
      sort_appointment_by_day(appointment_list, first, pivotIndex - 1);     //left-hand side
      sort_appointment_by_day(appointment_list, pivotIndex + 1, last);      //right-hand side
   }
}

void sort::sort_appointment_by_month(linked_list<appointment>& appointment_list, int first, int last){   //call by sort_appointment_by_appointment_time
//sort appointment by month and by ascending order
    if (first < last) {
      int pivotIndex = first;
      appointment_month_partition(appointment_list, first, last, pivotIndex);
      sort_appointment_by_month(appointment_list, first, pivotIndex - 1);     //left-hand side
      sort_appointment_by_month(appointment_list, pivotIndex + 1, last);      //right-hand side
   }
}

void sort::sort_appointment_by_year(linked_list<appointment>& appointment_list, int first, int last) {   //call by sort_appointment_by_appointment_time
    //sort appointment by year and by ascending order
    if (first < last) {
      int pivotIndex = first;
      appointment_year_partition(appointment_list, first, last, pivotIndex);
      sort_appointment_by_year(appointment_list, first, pivotIndex - 1);     //left-hand side
      sort_appointment_by_year(appointment_list, pivotIndex + 1, last);      //right-hand side
   }
}

void sort::patient_swap(linked_list <patient>& patient_list, int index1, int index2) {
    patient temp1;
    patient temp2;

    patient_list.retrieve(index1, temp1);
    patient_list.retrieve(index2, temp2);

    patient_list.remove(index1);
    patient_list.insert(index1, temp2);

    patient_list.remove(index2);
    patient_list.insert(index2, temp1);
}

void sort::doctor_swap(linked_list <doctor>& doctor_list, int index1, int index2) {
    doctor temp1;
    doctor temp2;

    doctor_list.retrieve(index1, temp1);
    doctor_list.retrieve(index2, temp2);

    doctor_list.remove(index1);
    doctor_list.insert(index1, temp2);

    doctor_list.remove(index2);
    doctor_list.insert(index2, temp1);
}

void sort::appointment_swap(linked_list <appointment>& appointment_list, int index1, int index2) {
    appointment temp1;
    appointment temp2;

    appointment_list.retrieve(index1, temp1);
    appointment_list.retrieve(index2, temp2);

    appointment_list.remove(index1);
    appointment_list.insert(index1, temp2);

    appointment_list.remove(index2);
    appointment_list.insert(index2, temp1);
}

void sort::patient_age_partition(linked_list <patient>& patient_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    patient temp1;
    patient temp2;

   while (first_unknown <= last) {
       patient_list.retrieve(first_unknown, temp1);
       patient_list.retrieve(pivotIndex, temp2);

      if (temp1.get_age() < temp2.get_age()) {
         //Put array in S1
         last_s1++;
         patient_list.retrieve(last_s1, temp2);

         if (temp1.get_age() != temp2.get_age()) {   //If the 2 numbers are different, perform swap
            patient_swap(patient_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    patient_list.retrieve(pivotIndex, temp1);
    patient_list.retrieve(last_s1, temp2);

   if (temp1.get_age() != temp2.get_age()) {   //If the 2 numbers are different, perform swap
      patient_swap(patient_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

void sort::doctor_specification_partition(linked_list <doctor>& doctor_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    doctor temp1;
    doctor temp2;

   while (first_unknown <= last) {
       doctor_list.retrieve(first_unknown, temp1);
       doctor_list.retrieve(pivotIndex, temp2);

      if (temp1.get_specification() < temp2.get_specification()) {
         //Put array in S1
         last_s1++;
         doctor_list.retrieve(last_s1, temp2);

         if (temp1.get_specification() != temp2.get_specification()) {   //If the 2 numbers are different, perform swap
            doctor_swap(doctor_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    doctor_list.retrieve(pivotIndex, temp1);
    doctor_list.retrieve(last_s1, temp2);

   if (temp1.get_specification() != temp2.get_specification()) {   //If the 2 numbers are different, perform swap
      doctor_swap(doctor_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

void sort::appointment_time_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    appointment temp1;
    appointment temp2;

   while (first_unknown <= last) {
       appointment_list.retrieve(first_unknown, temp1);
       appointment_list.retrieve(pivotIndex, temp2);

      if (temp1.get_strarting_time() < temp2.get_strarting_time()) {
         //Put array in S1
         last_s1++;
         appointment_list.retrieve(last_s1, temp2);

         if (temp1.get_strarting_time() != temp2.get_strarting_time()) {   //If the 2 numbers are different, perform swap
            appointment_swap(appointment_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    appointment_list.retrieve(pivotIndex, temp1);
    appointment_list.retrieve(last_s1, temp2);

   if (temp1.get_strarting_time() != temp2.get_strarting_time()) {   //If the 2 numbers are different, perform swap
      appointment_swap(appointment_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

void sort::appointment_day_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    appointment temp1;
    appointment temp2;

   while (first_unknown <= last) {
       appointment_list.retrieve(first_unknown, temp1);
       appointment_list.retrieve(pivotIndex, temp2);

      if (temp1.get_day() < temp2.get_day()) {
         //Put array in S1
         last_s1++;
         appointment_list.retrieve(last_s1, temp2);

         if (temp1.get_day() != temp2.get_day()) {   //If the 2 numbers are different, perform swap
            appointment_swap(appointment_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    appointment_list.retrieve(pivotIndex, temp1);
    appointment_list.retrieve(last_s1, temp2);

   if (temp1.get_day() != temp2.get_day()) {   //If the 2 numbers are different, perform swap
      appointment_swap(appointment_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

void sort::appointment_month_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    appointment temp1;
    appointment temp2;

   while (first_unknown <= last) {
       appointment_list.retrieve(first_unknown, temp1);
       appointment_list.retrieve(pivotIndex, temp2);

      if (temp1.get_month() < temp2.get_month()) {
         //Put array in S1
         last_s1++;
         appointment_list.retrieve(last_s1, temp2);

         if (temp1.get_month() != temp2.get_month()) {   //If the 2 numbers are different, perform swap
            appointment_swap(appointment_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    appointment_list.retrieve(pivotIndex, temp1);
    appointment_list.retrieve(last_s1, temp2);

   if (temp1.get_month() != temp2.get_month()) {   //If the 2 numbers are different, perform swap
      appointment_swap(appointment_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

void sort::appointment_year_partition(linked_list <appointment>& appointment_list, int first, int last, int& pivotIndex){
   //To do: partition array into [ S1 | Pivot | S2 ]
   //set pivot to first element
   //sort unknowns to S1 and S2
   //given items in S1 are < pivot
   //      items in S2 are >= pivot
   int last_s1 = first;
   int first_unknown = first + 1;

    appointment temp1;
    appointment temp2;

   while (first_unknown <= last) {
       appointment_list.retrieve(first_unknown, temp1);
       appointment_list.retrieve(pivotIndex, temp2);

      if (temp1.get_year() < temp2.get_year()) {
         //Put array in S1
         last_s1++;
         appointment_list.retrieve(last_s1, temp2);

         if (temp1.get_year() != temp2.get_year()) {   //If the 2 numbers are different, perform swap
            appointment_swap(appointment_list, first_unknown, last_s1);
         }

         first_unknown++;

      } else {
         //Put array in S2
         first_unknown++;
      }
   }

    appointment_list.retrieve(pivotIndex, temp1);
    appointment_list.retrieve(last_s1, temp2);

   if (temp1.get_year() != temp2.get_year()) {   //If the 2 numbers are different, perform swap
      appointment_swap(appointment_list, pivotIndex, last_s1);
   }

   pivotIndex = last_s1;   //the location of pivot now after perform swapping
}

#endif