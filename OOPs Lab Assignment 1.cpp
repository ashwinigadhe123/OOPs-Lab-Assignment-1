#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks;

public:
    // Constructor
    Student()
    {
        cout << "Constructor is called." << endl;
    }

    // User-defined function to take input
    void getData()
    {
        cout << "\nEnter student name: ";
        cin >> name;

        cout << "Enter roll number: ";
        cin >> rollNo;

        cout << "Enter marks: ";
        cin >> marks;
    }

    // User-defined function to display data
    void displayData()
    {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name        : " << name << endl;
        cout << "Roll Number : " << rollNo << endl;
        cout << "Marks       : " << marks << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "\nDestructor is called." << endl;
    }
};

int main()
{
    // Creating object
    Student s;

    // Calling user-defined functions
    s.getData();
    s.displayData();

    return 0;
}

