#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include<conio.h>
#include<fstream>

using namespace std;

//node to store each contact
struct Contact {
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    Contact* next; //pointer to the next node

    //constructor
    Contact(const string& fn, const string& ln, const string& phone, const string& mail)
        : firstName(fn), lastName(ln), phoneNumber(phone), email(mail), next(nullptr) {}
};

//SinglyLinkedList
class PhoneBook {
private:
    Contact* head;

public:
    PhoneBook() : head(nullptr) {}

    // Function to add a new contact
    void addContact(const string& fn, const string& ln, const string& phone, const string& email){
        Contact* newContact = new Contact(fn, ln, phone, email);

        if (!head) {
            head = newContact;
        } else {
            Contact* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newContact;
        }

        char choice;
        cout << "Do you want to add another phone number for this contact? (Y/N): ";
        cin >> choice;
        cin.ignore();  // Clear newline character from previous input
        while (toupper(choice) == 'Y') {
            string additionalPhone;
            cout << "Enter an additional phone number: ";
            cin >> additionalPhone;
            Contact* newPhone = new Contact(fn, ln, additionalPhone, "");
            Contact* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newPhone;
            cout << "Do you want to add another phone number for this contact? (Y/N): ";
            cin >> choice;
            cin.ignore();  // Clear newline character from previous input
        }
        cout << "Contact added successfully!" << endl;
    }

    // // Function to compare two contacts for sorting by first name

    // bool compareContacts(const Contact* a, const Contact* b) {
    //     return a->firstName < b->firstName;
    // }

    // // Function to display all contacts


    // void displayContacts(){
    //     if (!head) {
    //     cout << "Phone book is empty." << endl;
    //     return;
    //     }

    // // Create a dynamic array to store the contacts for sorting
    // int contactCount = getContactCount();
    // Contact** contactArray = new Contact*[contactCount];

    // Contact* current = head;
    // int index = 0;
    // while (current) {
    //     contactArray[index] = current;
    //     current = current->next;
    //     index++;
    // }

    // // Sort the contacts by first name
    // std::sort(contactArray, contactArray + contactCount, compareContacts);

    // // Display sorted contacts
    // cout << "Contacts in alphabetical order:" << endl;
    // for (int i = 0; i < contactCount; i++) {
    //     cout << "First Name: " << contactArray[i]->firstName << endl;
    //     cout << "Last Name: " << contactArray[i]->lastName << endl;
    //     cout << "Phone Number: " << contactArray[i]->phoneNumber << endl;
    //     cout << "Email: " << contactArray[i]->email << endl;
    //     cout << endl;
    // }

    // // Clean up the dynamic array
    // delete[] contactArray;
    // }

    



    // Function to delete a contact
    void deleteContact(){
    if (!head) {
        cout << "Phone book is empty. No contacts to delete." << endl;
        return;
    }

    string searchKey;
    int choice;

    cout << "How do you want to search for the contact to delete?" << endl;
    cout << "1. By name" << endl;
    cout << "2. By phone number" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // Clear newline character from previous input

    if (choice == 1) {
        // Delete by name
        cout << "Enter the first name of the contact you want to delete: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* prev = nullptr;
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->firstName == searchKey) {
                found = true;
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Contact deleted successfully!" << endl;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else if (choice == 2) {
        // Delete by phone number
        cout << "Enter the phone number of the contact you want to delete: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* prev = nullptr;
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->phoneNumber == searchKey) {
                found = true;
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Contact deleted successfully!" << endl;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}


    // Function to update a contact
    void updateContact(){
    if (!head) {
        cout << "Phone book is empty. No contacts to update." << endl;
        return;
    }

    string searchKey;
    int choice;

    cout << "How do you want to search for the contact to update?" << endl;
    cout << "1. By name" << endl;
    cout << "2. By phone number" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // Clear newline character from previous input

    if (choice == 1) {
        // Update by name
        cout << "Enter the first name of the contact you want to update: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->firstName == searchKey) {
                found = true;
                cout << "Contact found. What would you like to update?" << endl;
                cout << "1. Update the name" << endl;
                cout << "2. Update the phone number" << endl;
                cout << "3. Update the email" << endl;
                cout << "4. Add a new phone number" << endl;
                cout << "5. Add a new email" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();  // Clear newline character from previous input

                string newFirstName, newLastName;
                string newPhoneNumber;
                string newEmail;
                switch (choice) {
                    case 1:
                        // Update the name
                        
                        cout << "New First Name : "; 
                        cin >> newFirstName;
                        cin .ignore();
                        cout << "New Last Name : ";
                        cin >> newLastName;
                        cin.ignore();

                        //Update the contact's information
                        current -> firstName = newFirstName;
                        current -> lastName = newLastName;
                        cout << "Contact updated successfully!" << endl;
                        
                        break;
                    case 2:
                        // Update the phone number
                        
                        cout << "New Phone Number: ";
                        cin >> newPhoneNumber;
                        cin.ignore();
                        
                        // Implement the code to update the phone number
                        current->phoneNumber = newPhoneNumber;
                        cout << "Contact updated successfully!" << endl;
                        break;
                    case 3:
                        // Update the email
                        
                        cout << "New Email: ";
                        cin >> newEmail;
                        cin.ignore();

                        // Implement the code to update the email
                        current->email = newEmail;

                        cout << "Contact updated successfully!" << endl;
                        
                        break;
                    case 4:
                        // Add a new phone number
                        
                        break;
                    case 5:
                        // Add a new email
                        
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else if (choice == 2) {
        // Update by phone number
        cout << "Enter the phone number of the contact you want to update: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->phoneNumber == searchKey) {
                found = true;
                cout << "Contact found. What would you like to update?" << endl;
                cout << "1. Update the name" << endl;
                cout << "2. Update the phone number" << endl;
                cout << "3. Update the email" << endl;
                cout << "4. Add a new phone number" << endl;
                cout << "5. Add a new email" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();  // Clear newline character from previous input

                string newFirstName, newLastName;
                string newPhoneNumber;
                string newEmail;
                switch (choice) {
                    case 1:
                        // Update the name
                        
                        cout << "New First Name : "; 
                        cin >> newFirstName;
                        cin .ignore();
                        cout << "New Last Name : ";
                        cin >> newLastName;
                        cin.ignore();

                        //Update the contact's information
                        current -> firstName = newFirstName;
                        current -> lastName = newLastName;
                        cout << "Contact updated successfully!" << endl;
                        break;
                    case 2:
                        // Update the phone number
                        
                        cout << "New Phone Number: ";
                        cin >> newPhoneNumber;
                        cin.ignore();
                        
                        // Implement the code to update the phone number
                        current->phoneNumber = newPhoneNumber;
                        cout << "Contact updated successfully!" << endl;
                        break;
                    case 3:
                        // Update the email
                        
                        cout << "New Email: ";
                        cin >> newEmail;
                        cin.ignore();

                        // Implement the code to update the email
                        current->email = newEmail;

                        cout << "Contact updated successfully!" << endl;
                
                        break;
                    case 4:
                        // Add a new phone number
                        
                        break;
                    case 5:
                        // Add a new email
                        
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}


    // Function to get the number of contacts
    int getContactCount(){
        int count = 0;
        Contact* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        cout << "Number of contacts: " << count << endl;
        return count;
    }

    // Function to search for a contact
    void searchContact(){
    if (!head) {
        cout << "Phone book is empty. No contacts to search." << endl;
        return;
    }

    string searchKey;
    int choice;

    cout << "How do you want to search for the contact?" << endl;
    cout << "1. By name" << endl;
    cout << "2. By email" << endl;
    cout << "3. By phone number" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();  // Clear newline character from previous input

    if (choice == 1) {
        // Search by name
        cout << "Enter the first name of the contact you want to search for: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->firstName == searchKey) {
                found = true;
                cout << "Contact details:" << endl;
                cout << "First Name: " << current->firstName << endl;
                cout << "Last Name: " << current->lastName << endl;
                cout << "Phone Number: " << current->phoneNumber << endl;
                cout << "Email: " << current->email << endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else if (choice == 2) {
        // Search by email
        cout << "Enter the email of the contact you want to search for: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->email == searchKey) {
                found = true;
                cout << "Contact details:" << endl;
                cout << "First Name: " << current->firstName << endl;
                cout << "Last Name: " << current->lastName << endl;
                cout << "Phone Number: " << current->phoneNumber << endl;
                cout << "Email: " << current->email << endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else if (choice == 3) {
        // Search by phone number
        cout << "Enter the phone number of the contact you want to search for: ";
        cin >> searchKey;
        cin.ignore();  // Clear newline character from previous input
        Contact* current = head;
        bool found = false;

        while (current) {
            if (current->phoneNumber == searchKey) {
                found = true;
                cout << "Contact details:" << endl;
                cout << "First Name: " << current->firstName << endl;
                cout << "Last Name: " << current->lastName << endl;
                cout << "Phone Number: " << current->phoneNumber << endl;
                cout << "Email: " << current->email << endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Contact not found." << endl;
        }
    } else {
        cout << "Invalid choice. Please try again." << endl;
    }
}


    // Function to delete all contacts
    void deleteAllContacts(){
        while (head) {
        Contact* current = head;
        head = head->next;
        delete current;
        }
        cout << "All contacts have been deleted." << endl;
    }


    // Destructor to free memory
    ~PhoneBook() {
        while (head) {
            Contact* current = head;
            head = head->next;
            delete current;
        }
    }

};

// void start()
// {
// 	system("Color 9D");
// 	cout<<"\n\n\n\n\n\n\n\n\n";
// 	cout<<"\t\t\t\t\t\t----------------------------\n";
// 	cout<<"\t\t\t\t\t\t----------------------------\n";
// 	cout<<"\t\t\t\t\t\tSMART PHONE BOOK by KHYATI\n";
// 	cout<<"\t\t\t\t\t\t----------------------------\n\n";
// 	cout<<"\t\t\t\t\tLoading ";
// 	char x = 219;
// 	for(int i=0; i<50; i++)
// 	{
// 		cout<<x;
// 		if(i<10)
// 		Sleep(300);
// 		if(i>=10 && i<35)
// 		Sleep(150);
// 		if(i>=35)
// 		Sleep(50);
// 	}
// 	system("cls");
	
// }


// Implement the member functions of PhoneBook
int main() {
    // start();

    system("Color 9C");
    cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t\t----------------------------\n";
	cout<<"\t\t\t\t\t\tSMART PHONE BOOK by KHYATI\n";
	cout<<"\t\t\t\t\t\t----------------------------\n\n";
	cout<<"\t\t\t\t\tLoading ";
	char x = 219;
	for(int i=0; i<30; i++)
	{
		cout<<x;
		if(i<10)
		Sleep(250);
		if(i>=10 && i<20)
		Sleep(100);
		if(i>=20)
		Sleep(50);
	}
	system("cls");
    PhoneBook phoneBook;
    int choice;

    do {
        
        system("Color 9C");
        cout<<"\n\n\n\n\n";
	    cout<<"\t\t\t\t\t--------------------------------------------\n";
	    cout<<"\t\t\t\t\t--------------------------------------------\n";
	    cout<<"\t\t\t\t\t|               PHONE BOOK                 |\n";
	    cout<<"\t\t\t\t\t--------------------------------------------\n";
	    cout<<"\t\t\t\t\t|                                          |\n";
	    cout<<"\t\t\t\t\t|       [1]  Add a new Contact             |\n";
	    cout<<"\t\t\t\t\t|       [2]  Diplay All Contacts           |\n";
	    cout<<"\t\t\t\t\t|       [3]  Delete a contact              |\n";
	    cout<<"\t\t\t\t\t|       [4]  Update a contact              |\n";
	    cout<<"\t\t\t\t\t|       [5]  Number of Contacts            |\n";
	    cout<<"\t\t\t\t\t|       [6]  Search                        |\n";
	    cout<<"\t\t\t\t\t|       [7]  Delete All  Contacts          |\n";
	    cout<<"\t\t\t\t\t|                                          |\n";
	    cout<<"\t\t\t\t\t--------------------------------------------\n";
	    cout<<"\t\t\t\t\t|            [8]    Exit                   |\n";
	    cout<<"\t\t\t\t\t--------------------------------------------\n";

        cout << "Enter your choice: ";
        cin >> choice;

        string firstName, lastName, phoneNumber, eMail;
        switch (choice) {
            case 1:
                // Add a new contact
                cout << "Enter the following details: " << endl;
                
                cout << "\n Enter the first name : " << endl;
                cin >> firstName;
                cout << "Enter the last name : " << endl;
                cin >> lastName;
                cout << "Enter the phone number :" << endl;
                cin >> phoneNumber;
                cout << "Enter the mail :" << endl;
                cin >> eMail;
                phoneBook.addContact(firstName, lastName, phoneNumber, eMail);
                break;
            case 2:
                // Display all contacts
                // phoneBook.displayContacts();
                break;
            case 3:
                // Delete a contact
                phoneBook.deleteContact();
                break;
            case 4:
                // Update a contact
                phoneBook.updateContact();
                break;
            case 5:
                // Number of contacts
                phoneBook.getContactCount();
                break;
            case 6:
                // Search
                phoneBook.searchContact();
                break;
            case 7:
                // Delete all contacts
                phoneBook.deleteAllContacts();
                break;
            case 8:
                // Exit the program
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}



//remove duplicates
//one contact multiple numbers and emails
//place a check if number is 10 digit or not
//place a check if the email is valid or not
// when updating contacts, you should check if the contact exists before trying to update it.
// functionality to save and load contact data from a file, so that contacts are not lost when the program exits.