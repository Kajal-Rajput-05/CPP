
#include <iostream>
#include <string>
#include <regex>
using namespace std;

struct Node {
    string name;
    string number;
    Node* next;

    Node(string name, string number) {
        this->name = name;
        this->number = number;
        next = nullptr;
    }
};

class Phonebook {
private:
    Node* head;

public:
    Phonebook() {
        head = nullptr;
    }

    void addContact(string name, string number) {
        Node* newNode = new Node(name, number);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "\t\t\t" << newNode->number << " & " << newNode->name << " added successfully....!" << endl;
    }

    void display() {
        int len = 0;
        Node* temp = head;
        if (temp == nullptr) {
            cout << "\t\t\tContact list is Empty" << endl;
        } else {
            while (temp != nullptr) {
                cout << "\t\t\t Name         : " << temp->name << endl;
                cout << "\t\t\t Phone Number : " << temp->number << endl;
                temp = temp->next;
                len++;
            }
            cout << "\n\t\t\t Total contacts in the list = " << len << endl;
        }
    }

    void searchByNumber(string data) {
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && temp->number != data) {
            count++;
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\t\t\t" << data << " Not found" << endl;
        else
            cout << "\t\t\tContact found at " << count << ". Name: " << temp->name << " Number: " << temp->number << endl;
    }

    void searchByName(string data) {
        Node* temp = head;
        int count = 1;
        while (temp != nullptr && temp->name != data) {
            count++;
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\t\t\t" << data << " Not found...!" << endl;
        else
            cout << "\t\t\tContact found at " << count << ". Name: " << temp->name << " Number: " << temp->number << endl;
    }

    void editContact(string name, string number) {
        Node* temp = head;
        while (temp != nullptr && temp->name != name) {
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\t\t\t" << name << " not found...!" << endl;
        else {
            temp->number = number;
            cout << "\t\t\t" << name << " --> " << number << " updated successfully...!" << endl;
        }
    }

    void deleteContact(string data) {
        Node* temp = head;
        Node* temp2 = nullptr;
        if (temp != nullptr && (temp->number == data || temp->name == data)) {
            head = temp->next;
            cout << "\t\t\tContact " << data << " deleted successfully..!" << endl;
            delete temp;
            return;
        }
        while (temp != nullptr && (temp->number != data && temp->name != data)) {
            temp2 = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            cout << "\t\t\tContact not found...!" << endl;
        else {
            if (temp->next == nullptr)
                temp2->next = nullptr;
            else {
                temp2->next = temp->next;
                cout << "\t\t\tContact " << data << " deleted successfully...!" << endl;
            }
            delete temp;
        }
    }

    void clearAll() {
        if (head == nullptr) {
            cout << "\t\tList is Empty...!" << endl;
        } else {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            cout << "\t\t\tALL contact list has been deleted ...!" << endl;
        }
    }

    static bool checkNumber(string checkNumber) {
        string validateRegex = "(91)?[7-9][0-9]{9}";
        bool matched = regex_match(checkNumber, regex(validateRegex));
        return matched;
    }

    void menu() {
        cout << "1. Add contact" << endl;
        cout << "2. Display all contacts" << endl;
        cout << "3. Search contact (By number)" << endl;
        cout << "4. Search contact (By name)" << endl;
        cout << "5. Edit contact" << endl;
        cout << "6. Delete contact" << endl;
        cout << "7. Clear all records" << endl;
        cout << "8. Terminate\n" << endl;
        cout << "Enter choice: ";
    }
};

int main() {
		cout << "\n********************************************************************\n" << endl;
	    cout << "\t\t\tPhoneBook Directory" << endl;
	    cout << "\n********************************************************************" << endl;
    Phonebook phoneObj;
    int ch;
    while (true) {
        phoneObj.menu();
        cin >> ch;
        switch (ch) {
            case 1: {
                string name, number;
                cout << "Enter Name   : ";
                cin >> name;
                cout << "Enter number : ";
                cin >> number;
                bool matchedComplete = Phonebook::checkNumber(number);
                if (matchedComplete)
                    phoneObj.addContact(name, number);
                else
                    cout << "\t\t\tNumber not valid! Try again...!" << endl;
                break;
            }
            case 2:
                phoneObj.display();
                break;
            case 3: {
                string dataNumber;
                cout << "Enter number to find: ";
                cin >> dataNumber;
                phoneObj.searchByNumber(dataNumber);
                break;
            }
            case 4: {
                string dataName;
                cout << "Enter name to find: ";
                cin >> dataName;
                phoneObj.searchByName(dataName);
                break;
            }
            case 5: {
                string nameEdit, numberUpdate;
                cout << "Enter name to edit contact number: ";
                cin >> nameEdit;
                cout << "Enter number to update: ";
                cin >> numberUpdate;
                bool isMatched = Phonebook::checkNumber(numberUpdate);
                if (isMatched)
                    phoneObj.editContact(nameEdit, numberUpdate);
                else
                    cout << "\t\t\tNumber not valid! Try again...!" << endl;
                break;
            }
            case 6: {
                string deleteData;
                cout << "Enter the contact name or number to delete: ";
                cin >> deleteData;
                phoneObj.deleteContact(deleteData);
                break;
            }
            case 7:
                phoneObj.clearAll();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid Option....!" << endl;
        }
    }
    return 0;
}

