/* Citation and Sources...
Final Project Milestone 2
Module : Perishable
Filename: Perishable.cpp
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
#include "Perishable.h"
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std  ; 
namespace sdds {

    // Default Constructor
    Perishable::Perishable(){
        // Default constructor of Item is called.
        handlingInstructions = nullptr ; 
        // Setting date to empty state.
        m_expiry.setEmpty() ; 



    } ; 

    // Destructor
    Perishable::~Perishable(){

        delete [] handlingInstructions ; 

    } ; 

    // Copy Constructor
    Perishable::Perishable(const Perishable& src):Item(src){
        // Copying the base part.
        // Derived part
        if(src.handlingInstructions != nullptr){
            handlingInstructions = new char[strlen(src.handlingInstructions) + 1] ;
            strcpy(handlingInstructions , src.handlingInstructions) ;  

        }else {
            handlingInstructions = nullptr ; 

        } ; 

        // Date.
        m_expiry.setEmpty() ; 
        m_expiry = src.m_expiry ; 
    }; 

    // Copy Assignment operator
    Perishable& Perishable::operator=(const Perishable& src) {
        // Copying the base part
        Item::operator=(src) ; 
        // Copying the derived part
        delete [] handlingInstructions ; 
        if(src.handlingInstructions != nullptr){
            handlingInstructions = new char[strlen(src.handlingInstructions) + 1] ;
            strcpy(handlingInstructions , src.handlingInstructions) ;  

        }else {
            handlingInstructions = nullptr ; 

        } ; 
        // Date
        m_expiry = src.m_expiry ; 
        return *this ; 
    }; 

    // Query
    const Date& Perishable::expiry() const{
        return m_expiry ; 

    }; 

    // Overrides
    int Perishable::readSku(std::istream& istr){
        cout << "SKU: " ; 
        int sku = (int)ut.getIntegerWithRange(39999,10000,istr) ; 
        (*this).setSku(sku) ; 
        return sku ; 

    } ; 

    ofstream& Perishable::save(std::ofstream& ofstr)const {
        if(bool(*this)){
        // saving the base part
        Item::save(ofstr) ;
        ofstr << '\t' ;  
        if(handlingInstructions != nullptr && strlen(handlingInstructions)>0){
            ofstr << handlingInstructions ; 
        } ; 
        ofstr << '\t' ; 
        // Writing an unformatted copy of date
        m_expiry.save(ofstr) ; 

        }else {
            // do nothing

        }; 
        return ofstr ; 
    } ; 

    // Load Override.
    ifstream& Perishable::load(std::ifstream& ifstr){
        if(Item::load(ifstr)){
        char tempInst[1000] = "\0" ;
        int i = 0 ; 
        while (ifstr.peek() != '\t'){
            tempInst[i] = ifstr.get(); 
            i+= 1 ; 
        } ; 

        delete [] handlingInstructions ; 
        if (strlen(tempInst) > 0) {
            handlingInstructions = new char[strlen(tempInst) + 1] ;
            strcpy(handlingInstructions , tempInst) ;   
        }else {
            handlingInstructions = nullptr ; 

        } ;

        ifstr.get(); 
        int tempDate ; 
        ifstr >> tempDate ;     
        m_expiry.setDate(tempDate) ; 
        ifstr.get() ; 
        
        if(ifstr.fail()){
            (*this).setStatus("Input file stream read (perishable) failed!") ;    

        } ; 

        } ; 


        return ifstr ; 

    } ;

    // Display Override.
    ostream& Perishable::display(std::ostream& ostr)const{
        if(bool(*this)) {
            // Good state.
            if(linear()){
            Item::display(ostr) ;
            if(handlingInstructions!= nullptr && strlen(handlingInstructions) > 0){
                ostr << "*" ; 
            }else {
                ostr << " " ; 

            } ;  
            // Displaying the date.
            //m_expiry.formatted(true) ; 
            m_expiry.write(ostr) ; 

            }else {
                // Descriptive.
                ostr << "Perishable " ; 
                Item::display(ostr) ; 
                ostr << "Expiry date: " ; 
                //m_expiry.formatted(true) ; 
                m_expiry.write(ostr) ;
                ostr << endl ; 
                if(handlingInstructions != nullptr && strlen(handlingInstructions) > 0){
                    ostr << "Handling Instructions: " ; 
                    ostr << handlingInstructions  ;  
                    ostr << endl ; 

                } ; 
            } ; 


        }else {
            // Print state.
            (*this).printState(ostr) ; 
        } ; 

        return ostr ; 
    } ; 

    // Read Override.
    istream& Perishable::read(std::istream& istr){
        Item::read(istr); 
        delete [] handlingInstructions ; 
        handlingInstructions = nullptr ; 
        cout << "Expiry date (YYMMDD): " ; 
        m_expiry.read(istr) ; 
        istr.get() ; 
        cout << "Handling Instructions, ENTER to skip: " ;
        if(istr.peek() == '\n'){
            // Nothing is read
            istr.get(); // Just reading the new line character
            cout << endl ; 
        } else {
            char tempInst[1000] = "\0" ; 
            int i = 0 ;  
            while(istr.peek() != '\n'){
                tempInst[i] = istr.get() ; 
                i += 1;  
            } ; 
            istr.get() ; // Reading the new line
            handlingInstructions = new char[strlen(tempInst) + 1] ;
            strcpy(handlingInstructions , tempInst) ;  
        } ; 
        if(istr.fail()){
            m_state.set("Perishable console date entry failed!"); 

        } ; 

        return istr ; 
    } ; 

    Perishable::operator bool() const {
        bool returnValue ; 
        if(m_sku != 0 && m_state) {  
            returnValue = true ; 
        }else {
            returnValue = false ; 

        } ; 

    return returnValue ; 
    } ; 

    ofstream& Perishable::tableSave(std::ofstream& ofstr)const{
        Item::tableSave(ofstr) ; 
        if(handlingInstructions!= nullptr && strlen(handlingInstructions) > 0){
            ofstr << "*" ; 
        }else {
            ofstr << " " ; 
        } ;  

    m_expiry.write(ofstr) ; 
    
    return ofstr ; 
    } ; 


}