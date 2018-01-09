#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "qtcontactform.h"



QtContactForm::QtContactForm(QWidget *parent) : 
        QFormLayout(parent), firstNameField(new QLineEdit()),
        lastNameField(new QLineEdit()),
        addressField(new QLineEdit()),
        phoneNumberField(new QLineEdit()),
        emailField(new QLineEdit()),
        nationalityField(new QLineEdit()),
        genderField(new QLineEdit())


{
    addRow("<font style ='color:red'>First Name", firstNameField);
    addRow("<font style ='color:red'>Last Name", lastNameField);
    addRow("<font style ='color:red'>Address", addressField);
    addRow("<font style ='color:red'>Phone Number", phoneNumberField);
    addRow("<font style ='color:red'>Email", emailField);
    addRow("<font style ='color:red'>Nationality", nationalityField);
    addRow("<font style ='color:red'>Gender Name", genderField);

}

void QtContactForm::clear()
{
    firstNameField->setText("");
    lastNameField->setText("");
    addressField->setText("");
    phoneNumberField->setText("");
    emailField->setText("");
    nationalityField->setText("");
    genderField->setText("");

}
