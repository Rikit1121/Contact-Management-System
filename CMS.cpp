#include <iostream>
#include <string>
using namespace std;

// Maximum number of contacts allowed
#define MAX 1000

// Contact structure to store individual contact information
struct Contact {
    string name;    // Name of the contact
    int gender;     // Gender (1 for male, 2 for female)
    int age;        // Age of the contact
    string phone;   // Phone number
    string address; // Address
};

// Address book structure to manage a collection of contacts
struct AddressBook {
    Contact contacts[MAX]; // Array to store contacts
    int count = 0;         // Current number of contacts
};

// Function to display the main menu
void showMenu() {
    cout << "" << endl;
    cout << "***** Contact Management ******" << endl;
    cout << "" << endl;
    cout << "1. Add Contact" << endl;
    cout << "2. Display All Contacts" << endl;
    cout << "3. Delete Contact" << endl;
    cout << "4. Search Contact" << endl;
    cout << "5. Modify Contact" << endl;
    cout << "6. Clear All Contacts" << endl;
    cout << "0. Exit" << endl;
    cout << "" << endl;
    cout << "Please enter your choice: ";
}

// Function to add a contact
void addContact(AddressBook* book) {
    if (book->count == MAX) {
        cout << "Address book is full! Cannot add more contacts." << endl;
        return;
    }

    Contact newContact;
    cout << "Enter Name: ";
    cin >> newContact.name;

    cout << "Enter Gender (1 for Male, 2 for Female): ";
    while (true) {
        cin >> newContact.gender;
        if (newContact.gender == 1 || newContact.gender == 2) break;
        cout << "Invalid input! Please enter 1 for Male or 2 for Female: ";
    }

    cout << "Enter Age: ";
    cin >> newContact.age;

    cout << "Enter Phone Number: ";
    cin >> newContact.phone;

    cout << "Enter Address: ";
    cin >> newContact.address;

    book->contacts[book->count] = newContact;
    book->count++;

    cout << "Contact added successfully!" << endl;
}

// Function to display all contacts
void displayContacts(const AddressBook* book) {
    if (book->count == 0) {
        cout << "No contacts to display!" << endl;
        return;
    }

    for (int i = 0; i < book->count; ++i) {
        const Contact& contact = book->contacts[i];
        cout << "Name: " << contact.name
             << ", Gender: " << (contact.gender == 1 ? "Male" : "Female")
             << ", Age: " << contact.age
             << ", Phone: " << contact.phone
             << ", Address: " << contact.address << endl;
    }
}

// Function to find a contact by name
int findContact(const AddressBook* book, const string& name) {
    for (int i = 0; i < book->count; ++i) {
        if (book->contacts[i].name == name) return i;
    }
    return -1;
}

// Function to delete a contact
void deleteContact(AddressBook* book) {
    cout << "Enter the name of the contact to delete: ";
    string name;
    cin >> name;

    int index = findContact(book, name);
    if (index == -1) {
        cout << "Contact not found!" << endl;
        return;
    }

    for (int i = index; i < book->count - 1; ++i) {
        book->contacts[i] = book->contacts[i + 1];
    }
    book->count--;

    cout << "Contact deleted successfully!" << endl;
}

// Function to search for a contact
void searchContact(const AddressBook* book) {
    cout << "Enter the name of the contact to search: ";
    string name;
    cin >> name;

    int index = findContact(book, name);
    if (index == -1) {
        cout << "Contact not found!" << endl;
        return;
    }

    const Contact& contact = book->contacts[index];
    cout << "Name: " << contact.name
         << ", Gender: " << (contact.gender == 1 ? "Male" : "Female")
         << ", Age: " << contact.age
         << ", Phone: " << contact.phone
         << ", Address: " << contact.address << endl;
}

// Function to modify a contact
void modifyContact(AddressBook* book) {
    cout << "Enter the name of the contact to modify: ";
    string name;
    cin >> name;

    int index = findContact(book, name);
    if (index == -1) {
        cout << "Contact not found!" << endl;
        return;
    }

    Contact& contact = book->contacts[index];
    cout << "Enter new details for the contact:" << endl;

    cout << "Enter Name: ";
    cin >> contact.name;

    cout << "Enter Gender (1 for Male, 2 for Female): ";
    while (true) {
        cin >> contact.gender;
        if (contact.gender == 1 || contact.gender == 2) break;
        cout << "Invalid input! Please enter 1 for Male or 2 for Female: ";
    }

    cout << "Enter Age: ";
    cin >> contact.age;

    cout << "Enter Phone Number: ";
    cin >> contact.phone;

    cout << "Enter Address: ";
    cin >> contact.address;

    cout << "Contact modified successfully!" << endl;
}

// Function to clear all contacts
void clearContacts(AddressBook* book) {
    cout << "Are you sure you want to clear all contacts? (Y/N): ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        book->count = 0;
        cout << "All contacts cleared!" << endl;
    } else {
        cout << "Clear operation canceled." << endl;
    }
}

int main() {
    AddressBook book;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addContact(&book); break;
            case 2: displayContacts(&book); break;
            case 3: deleteContact(&book); break;
            case 4: searchContact(&book); break;
            case 5: modifyContact(&book); break;
            case 6: clearContacts(&book); break;
            case 0: 
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default: 
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}