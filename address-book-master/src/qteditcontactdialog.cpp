#include "contact.h"
#include "qtcontactform.h"
#include "qteditcontactdialog.h"
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


QtEditContactDialog::QtEditContactDialog(Contact &c, 
                                        QWidget *parent,
                                        Qt::WindowFlags f) :
                                        QDialog(parent, f),
                                        contactForm(new QtContactForm()),
                                        contactToEdit(c)
{
    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(contactForm);

    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");
    buttonContainer->addWidget(okButton);
    buttonContainer->addWidget(cancelButton);
    mainContainer->addLayout(buttonContainer);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    fillForm();
    setLayout(mainContainer);
    setWindowTitle("Edit Contact");
}

void QtEditContactDialog::fillForm()
{
    contactForm->firstNameField->setText(contactToEdit.firstName.c_str());
    contactForm->lastNameField->setText(contactToEdit.lastName.c_str());
    contactForm->addressField->setText(contactToEdit.address.c_str());
    contactForm->phoneNumberField->setText(contactToEdit.phoneNumber.c_str());
    contactForm->emailField->setText(contactToEdit.email.c_str());
    contactForm->nationalityField->setText(contactToEdit.nationality.c_str());
    contactForm->genderField->setText(contactToEdit.gender.c_str());


}

void QtEditContactDialog::accept()
{
    contactToEdit.firstName = contactForm->firstNameField->text().toStdString();
    contactToEdit.lastName = contactForm->lastNameField->text().toStdString();
    contactToEdit.address = contactForm->addressField->text().toStdString();
    contactToEdit.phoneNumber = contactForm->phoneNumberField->text().toStdString();
    contactToEdit.email = contactForm->emailField->text().toStdString();
    contactToEdit.nationality = contactForm->nationalityField->text().toStdString();
    contactToEdit.gender = contactForm->genderField->text().toStdString();


    QDialog::accept();

}
