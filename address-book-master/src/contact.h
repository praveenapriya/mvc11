#ifndef CORE_CONTACT_H
#define CORE_CONTACT_H

/************************************************************
    Class: Contact

    Author: Phil Grohe

    Data structure to hold a single address book contact's
    info.
************************************************************/

#include <string>
#include <vector>

class Contact 
{
    public:

        typedef std::vector<Contact> ContactRecordSet;
        typedef unsigned int ContactId;
        static const ContactId INVALID_ID = 0;

        ContactId id;
        std::string firstName;
        std::string lastName;
        std::string phoneNumber;
        std::string address;
        std::string email;
        std::string nationality;
        std::string gender;


        Contact():id(0), firstName(), lastName(), phoneNumber(), email(), nationality(), gender(){ }
        bool isValidToAdd() const;
        bool isEmpty() const;

};

#endif
