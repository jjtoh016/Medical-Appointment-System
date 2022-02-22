#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>    // Only for displaying copy constructor
#include <fstream>     // for file I/O
#include <cstddef>     // for NULL
//#include <new>         // for bad_alloc
#include <sstream>
#include "patient.hpp"
#include "doctor.hpp"
#include "admin.hpp"
#include "appointment.hpp"
//#include "ListException.h"
//#include "ListIndexOutOfRangeException.h"
//typedef string ListItemType;
//#include "ListP.h"     // header file

using namespace std;

template <class ListItemType>
class linked_list
{
   public:
   // Constructors and destructor:

      /** Default constructor. */
      linked_list();

      /** Copy constructor.
       * @param aList The list to copy. */
      linked_list(const linked_list& aList);

      /** Destructor. */
      ~linked_list();


   // List operations:
      bool isEmpty() const;
      int getLength() const;
      bool insert(int index, const ListItemType& newItem);
      bool remove(int index);
      bool retrieve(int index, ListItemType& dataItem) const;
      void save( string fileName );
      bool load( string fileName );

   private:
      /** A node on the list. */
      struct ListNode
      {
         /** A data item on the list. */
         ListItemType item;
         /** Pointer to next node. */
         ListNode    *next;
      }; // end ListNode

      /** Number of items in list. */
      int       size;
      /** Pointer to linked list of items. */
      ListNode *head;

      /** Locates a specified node in a linked list.
       * @pre index is the number of the desired node.
       * @post None.
       * @param index The index of the node to locate.
       * @return A pointer to the index-th node. If index < 1
       *         or index > the number of nodes in the list,
       *         returns NULL. */
      ListNode *find(int index) const;
};

template <class ListItemType>
linked_list<ListItemType>::linked_list() : size( 0 ), head( NULL )
{
}//end default constructor

template <class ListItemType>
linked_list<ListItemType>::~linked_list()
{
   while (!isEmpty())
      remove(1);
}  // end destructor

template <class ListItemType>
linked_list<ListItemType>::linked_list(const linked_list& aList)
   : size(aList.size)
{
   cout << "Copy Constructor" << endl;
   if ( aList.head == NULL )
   {
      head = NULL;  // original list is empty
   }
   else
   {
      // copy first node
      head = new ListNode;
      head->item = aList.head->item;

      // copy rest of list
      ListNode *newPtr = head;  // new list pointer
      // newPtr points to last node in new list
      // origPtr points to nodes in original list
      for (ListNode *origPtr = aList.head->next;
	       origPtr != NULL;
           origPtr = origPtr->next)
      {
         newPtr->next = new ListNode;
         newPtr = newPtr->next;
	     newPtr->item = origPtr->item;
      }  // end for

      newPtr->next = NULL;
   }  // end if
}  // end copy constructor

template <class ListItemType>
bool linked_list<ListItemType>::isEmpty() const
{
   return size == 0;
}  // end isEmpty

template <class ListItemType>
int linked_list<ListItemType>::getLength() const
{
   return size;
}  // end getLength

//input index, return node
//helper function
template <class ListItemType>
typename linked_list<ListItemType>::ListNode *linked_list<ListItemType>::find(int index) const
{
   if ( (index < 1) || (index > getLength()) )
      return NULL;

   else  // count from the beginning of the list.
   {
      ListNode *cur = head;
      for (int skip = 1; skip < index; ++skip)
         cur = cur->next;
      return cur;
   }  // end if
}  // end find

template <class ListItemType>
bool linked_list<ListItemType>::retrieve(int index,
                    ListItemType& dataItem) const
{
   if ( (index < 1) || (index > getLength()) )
      return false;
   else
   {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item;
   }  // end if
   return true;
}  // end retrieve

template <class ListItemType>
bool linked_list<ListItemType>::insert(int index, const ListItemType& newItem)
{
   int newLength = getLength() + 1;

   if ( (index < 1) || (index > newLength) )
        return false;
   else
   {
      // try to create new node and place newItem in it
         ListNode *newPtr = new ListNode;
         newPtr->item = newItem;
         size = newLength;

         // attach new node to list
         if (index == 1)
         {  // insert new node at beginning of list
            newPtr->next = head;
            head = newPtr;
         }
         else
         {  ListNode *prev = find(index-1);
            // insert new node after node
            // to which prev points
            newPtr->next = prev->next;
            prev->next = newPtr;
         }  // end if
      
   }  // end if
   return true;
}  // end insert

template <class ListItemType>
bool linked_list<ListItemType>::remove(int index)
{
   ListNode *cur;

   if ( (index < 1) || (index > getLength()) )
      return false;
   else
   {
      --size;
      if (index == 1)
      {  // delete the first node from the list
         cur = head;  // save pointer to node
         head = head->next;
      }

      else
      {  ListNode *prev = find(index - 1);
         // delete the node after the node to which prev points
         cur = prev->next;  // save pointer to node
	     prev->next = cur->next;
      }  // end if

      // return node to system
      cur->next = NULL;
      delete cur;
      cur = NULL;
   }  // end if

   return true;
}  // end remove

template <>
void linked_list<patient>::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item.get_username() << ","
            << cur->item.get_password() << ","
            << cur->item.get_name() << ","
            << cur->item.get_age() << ","
            << cur->item.get_phone_number() << ","
            << cur->item.get_patientID()
            << endl;
   }
   outFile.close();
}

template <>
void linked_list<doctor>::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item.get_username() << ","
            << cur->item.get_password() << ","
            << cur->item.get_name() << ","
            << cur->item.get_age() << ","
            << cur->item.get_phone_number() << ","
            << cur->item.get_doctorID() << ","
            << cur->item.get_address() << ","
            << cur->item.get_specification()
            << endl;
   }
   outFile.close();
}

template <>
void linked_list<admin>::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item.get_username() << ","
            << cur->item.get_password()
            << endl;
   }
   outFile.close();
}

template <>
void linked_list<appointment>::save( string fileName )
{
   ofstream outFile( fileName.c_str() );

   // traverse the list to the end, writing each item
   for (ListNode *cur = head; cur != NULL; cur = cur->next)
   {
      outFile << cur->item.get_patientID() << ","
            << cur->item.get_doctorID() << ","
            << cur->item.get_day() << ","
            << cur->item.get_month() << ","
            << cur->item.get_year() << ","
            << cur->item.get_strarting_time() << ","
            << cur->item.get_ending_time()
            << endl;
   }
   outFile.close();
}

template <>
bool linked_list<patient>::load( string fileName )
{
   ifstream inFile( fileName.c_str() );
   string nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove( 1 );
   }
   size = 0;

   if ( getline(inFile,nextItem) ) // Is file empty?
   {  // File not empty:
         head = new ListNode;
         // Add the first integer to the list.
         stringstream line;
         line << nextItem;
         string input;
         string attributes[6];
         
         for (int i = 0; i < 6; i++) {
            getline(line, input, ',');
            attributes[i] = input;
         }

         string username = attributes[0];
         string password = attributes[1];
         string name = attributes[2];
         int age = stoi(attributes[3]);
         string phone_number = attributes[4];
         string patientID = attributes[5];

         patient input_patient(username, password, name, age, phone_number, patientID);
         head->item = input_patient;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( getline(inFile,nextItem) )
         {
            tail->next = new ListNode;
            tail = tail->next;
            
            stringstream line;
            line << nextItem;
            string input;
            string attributes[6];
         
            for (int i = 0; i < 6; i++) {
               getline(line, input, ',');
               attributes[i] = input;
            }

            string username = attributes[0];
            string password = attributes[1];
            string name = attributes[2];
            int age = stoi(attributes[3]);
            string phone_number = attributes[4];
            string patientID = attributes[5];

            patient input_patient(username, password, name, age, phone_number, patientID);
            tail->item = input_patient;

            tail->next = NULL;
            size = size + 1;
         }  // end while
      
   }  // end if

   inFile.close();
   return true;
}

template <>
bool linked_list<doctor>::load( string fileName )
{
   ifstream inFile( fileName.c_str() );
   string nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove( 1 );
   }
   size = 0;

   if ( getline(inFile,nextItem) ) // Is file empty?
   {  // File not empty:
         head = new ListNode;
         // Add the first integer to the list.
         stringstream line;
         line << nextItem;
         string input;
         string attributes[8];

         for (int i = 0; i < 8; i++) {
            getline(line, input, ',');
            attributes[i] = input;
         }

         string username = attributes[0];
         string password = attributes[1];
         string name = attributes[2];
         int age = stoi(attributes[3]);
         string phone_number = attributes[4];
         string doctorID = attributes[5];
         string address = attributes[6];
         string specification = attributes[7];

         doctor input_doctor(username, password, name, age, phone_number, doctorID,
         address, specification);
         head->item = input_doctor;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( getline(inFile,nextItem) )
         {
            tail->next = new ListNode;
            tail = tail->next;
            
            stringstream line;
            line << nextItem;
            string input;
            string attributes[8];
            
            for (int i = 0; i < 8; i++) {
               getline(line, input, ',');
               attributes[i] = input;
            }

            string username = attributes[0];
            string password = attributes[1];
            string name = attributes[2];
            int age = stoi(attributes[3]);
            string phone_number = attributes[4];
            string doctorID = attributes[5];
            string address = attributes[6];
            string specification = attributes[7];

            doctor input_doctor(username, password, name, age, phone_number, doctorID,
            address, specification);
            tail->item = input_doctor;

            tail->next = NULL;
            size = size + 1;
         }  // end while
      
   }  // end if

   inFile.close();
   return true;
}

template <>
bool linked_list<admin>::load( string fileName )
{
   ifstream inFile( fileName.c_str() );
   string nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove( 1 );
   }
   size = 0;

   if ( getline(inFile,nextItem) ) // Is file empty?
   {  // File not empty:
         head = new ListNode;
         // Add the first integer to the list.
         stringstream line;
         line << nextItem;
         string input;
         string attributes[2];
         
         for (int i = 0; i < 2; i++) {
            getline(line, input, ',');
            attributes[i] = input;
         }

         string username = attributes[0];
         string password = attributes[1];

         admin input_admin(username, password);
         head->item = input_admin;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( getline(inFile,nextItem) )
         {
            tail->next = new ListNode;
            tail = tail->next;
            
            stringstream line;
            line << nextItem;
            string input;
            string attributes[2];
            
            for (int i = 0; i < 2; i++) {
               getline(line, input, ',');
               attributes[i] = input;
            }

            string username = attributes[0];
            string password = attributes[1];

            admin input_admin(username, password);
            tail->item = input_admin;

            tail->next = NULL;
            size = size + 1;
         }  // end while
      
   }  // end if

   inFile.close();
   return true;
}

template <>
bool linked_list<appointment>::load( string fileName )
{
   ifstream inFile( fileName.c_str() );
   string nextItem;
   ListNode *tail;

   while (!isEmpty())
   {
      remove( 1 );
   }
   size = 0;

   if ( getline(inFile,nextItem) ) // Is file empty?
   {  // File not empty:
         head = new ListNode;
         // Add the first integer to the list.
         stringstream line;
         line << nextItem;
         string input;
         string attributes[7];
         
         for (int i = 0; i < 7; i++) {
            getline(line, input, ',');
            attributes[i] = input;
         }

         string patientID = attributes[0];
         string doctorID = attributes[1];
         int day = stoi(attributes[2]);
         int month = stoi(attributes[3]);
         int year = stoi(attributes[4]);
         int starting_time = stoi(attributes[5]);
         int ending_time = stoi(attributes[6]);

         appointment input_appointment(patientID, doctorID, day, month, year, starting_time, ending_time);
         head->item = input_appointment;
         head->next = NULL;
         tail = head;
         size = size + 1;

         // Add remaining integers to linked list.
         while ( getline(inFile,nextItem) )
         {
            tail->next = new ListNode;
            tail = tail->next;
            
            stringstream line;
            line << nextItem;
            string input;
            string attributes[7];
            
            for (int i = 0; i < 7; i++) {
               getline(line, input, ',');
               attributes[i] = input;
            }

            string patientID = attributes[0];
            string doctorID = attributes[1];
            int day = stoi(attributes[2]);
            int month = stoi(attributes[3]);
            int year = stoi(attributes[4]);
            int starting_time = stoi(attributes[5]);
            int ending_time = stoi(attributes[6]);

            appointment input_appointment(patientID, doctorID, day, month, year, starting_time, ending_time);
            tail->item = input_appointment;

            tail->next = NULL;
            size = size + 1;
         }  // end while
      
   }  // end if

   inFile.close();
   return true;
}
#endif