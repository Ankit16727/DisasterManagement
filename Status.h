/* Citation and Sources...
Final Project Milestone 2 
Module : Status
Filename: Status.h
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2022/02/28  Preliminary release
2022/02/28  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
/*
   Name - Ankit Thapar
   Email - athapar4@myseneca.ca
   Student Id - 125698217
   Date - 7 April 2022

*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds {
  class Status {
      // Data members
      char* description ;
      int errorCode ; 

      public:
        // Constructor
        Status(const char* Description = nullptr) ; 
        // Destructor
        ~Status() ; 
        // Copy Constructor.
        Status(const Status& srcStatus) ; 
        // Copy assignment operator.
        Status& operator=(const Status& srcStatus);

        // Assignment operator overloads.
        // Int
        Status& operator=(int newCode);
        // String
        Status& operator=(const char* newDescription); 

        // Type Coversion.
        operator int() const ; 
        operator const char*() const ; 
        operator bool() const ;

        // Set
        void set(const char* Description , int code = 0) ; 

        // clear
        Status& clear() ;  
        

  };  

  // Insertion Operator Overload..
     std::ostream& operator<<(std::ostream& os, const Status& status);

   
   
}
#endif // !SDDS_HealthCard_H


