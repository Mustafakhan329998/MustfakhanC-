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
    void input()
    {
        cout << "\nEnter your name: ";
        cin >> name;

        cout << "Enter your Roll No: ";
        cin >> rollNo;

        cout << "Enter your marks: ";
        cin >> marks;
    }

    char grade()
    {
        if (marks >= 80) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }

    void display()
    {
        cout << "\n--- Student Info ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade() << endl;
    }

    float getMarks()
    {
        return marks;
    }
};

int main()
{
    int n = 3;
    Student s[n];

    // Input data
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1;
        s[i].input();
    }

    // Display all students
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    // Find highest marks
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i].getMarks() > s[maxIndex].getMarks())
        {
            maxIndex = i;
        }
    }

    // Show topper
    cout << "\n🏆 Topper Student:";
    s[maxIndex].display();

    return 0;
}