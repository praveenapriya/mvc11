#include "qtcontactdetailview.h"
#include "qtcontactform.h"
#include "qterrordialog.h"
#include "errorinfo.h"

#include <string>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>

QtContactDetailView::QtContactDetailView(AddressBookModel& model, 
                    QWidget *parent) : 
                    QGroupBox("Contact Details", parent),
                    dataSource(model),
                    contactForm(new QtContactForm())
{

    contactForm->firstNameField->setReadOnly(true);
    contactForm->lastNameField->setReadOnly(true);
    contactForm->addressField->setReadOnly(true);
    contactForm->phoneNumberField->setReadOnly(true);
    contactForm->emailField->setReadOnly(true);
    contactForm->nationalityField->setReadOnly(true);
    contactForm->genderField->setReadOnly(true);


    setLayout(contactForm);
    setFlat(false);
    
}

void QtContactDetailView::displayContact(Contact::ContactId id)
{
    Contact c;

    ErrorInfo getContactErrorStatus = dataSource.getContact(id, c);

    if(getContactErrorStatus.code != ERR_OK)
    {
        //could not fetch the contact
        //simply clear the fields
        clear();
        return;
    }
    else
    {

        contactForm->firstNameField->setText(c.firstName.c_str());
        contactForm->lastNameField->setText(c.lastName.c_str());
        contactForm->addressField->setText(c.address.c_str());
        contactForm->phoneNumberField->setText(c.phoneNumber.c_str());
        contactForm->emailField->setText(c.email.c_str());
        contactForm->nationalityField->setText(c.nationality.c_str());
        contactForm->genderField->setText(c.gender.c_str());

    }
}

void QtContactDetailView::clear()
{
    contactForm->clear();
}

