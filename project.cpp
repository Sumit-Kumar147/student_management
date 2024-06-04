#include <iostream>
using namespace std;
#include <fstream>
int ID;
class student
{
public:
    string name;
    int admissionNumber;
    string className;
    int bookissued;

    void addStudent()
    {
        cout << "Enter name" << endl;
        cin.get();
        getline(cin, name);
        cout << "Enter number of book issued" << endl;
        cin >> bookissued;
        cout << "Enter your className" << endl;
        cin.get();
        getline(cin, className);
        ID++;

        ofstream fout;
        fout.open("student.txt", ios::app);
        fout << "\n"
             << ID;
        fout << "\n"
             << name;
        fout << "\n"
             << className;
        fout << "\n"
             << bookissued;
        fout.close();

        fout.open("ID.txt", ios::app);
        fout << "\n"
             << ID;
        fout.close();

        cout << "Record Added Sucessfully" << endl;
    }
    void print_students()
    {
        ifstream fin;
        fin.open("student.txt");
        student s;

        while (!fin.eof())
        {
            fin >> s.admissionNumber;
            fin.ignore();
            getline(fin, s.name);
            fin.ignore();
            getline(fin, s.className);
            fin >> s.bookissued;

            cout << "\nAdmission number = " << s.admissionNumber;
            cout << "\nName = " << s.name;
            cout << "\nClass name = " << s.className;
            cout << "\nIssued Book Number = " << s.bookissued << endl
                 << endl
                 << endl;
                }
        fin.close();
    }
    void update_student(int admissionNumber)
    {
        delete_student(admissionNumber);
        student s;
        cout << "Enter name" << endl;
        cin.get();
        getline(cin, s.name);
        cout << "Enter number of book issued" << endl;
        cin >> bookissued;
        cout << "Enter your className" << endl;
        cin.get();
        getline(cin, s.className);

        ofstream fout;
        fout.open("student.txt", ios::app);
        fout << "\n"
             << admissionNumber;
        fout << "\n"
             << s.name;
        fout << "\n"
             << s.className;
        fout << "\n"
             << s.bookissued;

        fout.close();
        cout << "Record Update Sucessfully" << endl;
    }
    void delete_student(int admissionNumber)
    {
        ifstream fin;
        fin.open("student.txt");

        ofstream fout;
        fout.open("temp.txt");

        student s;
        while (!fin.eof())
        {
            fin >> s.admissionNumber;
            fin.ignore();
            getline(fin, s.name);
            fin.ignore();
            getline(fin, s.className);
            fin >> s.bookissued;
            if (admissionNumber != s.admissionNumber)
            {
                fout << "\n"
                     << s.admissionNumber;
                fout << "\n"
                     << name;
                fout << "\n"
                     << className;
                fout << "\n"
                     << bookissued;
            }
        }
        fin.close();
        fout.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");

        cout << "Record Deleted Sucessfully" << endl;
    }
    void Search_Student(int admissionNumber)
    {
        ifstream fin;
        fin.open("student.txt");
        student s;

        while (!fin.eof())
        {
            fin >> s.admissionNumber;
            fin.ignore();
            getline(fin, s.name);
            fin.ignore();
            getline(fin, s.className);
            fin >> s.bookissued;

            if (admissionNumber == s.admissionNumber)
            {
                cout << "\nAdmission number = " << s.admissionNumber;
                cout << "\nName = " << s.name;
                cout << "\nClass name = " << s.className;
                cout << "\nIssued Book Number = " << s.bookissued << endl
                     << endl
                     << endl;
                break;
            }
        }
        fin.close();
    }
};
int main()
{
    int choice;
    ifstream fin;
    fin.open("id.txt");

    if (!fin)
    {
        cout << "File Not Found" << endl;
    }
    else
    {
        while (!fin.eof())
        {
            fin >> ID;
        }
    }
    fin.close();
    while (1)
    {
        cout << "Enter the choice you want to do that:" << endl;
        cout << "1:Add a student" << endl;
        cout << "2:Print all the students details" << endl;
        cout << "3:Search a student" << endl;
        cout << "4:Update a student detail" << endl;
        cout << "5:Delete a student detail" << endl;

        cin >> choice;
        student s;
        int admissionNumber;
        switch (choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.print_students();
            break;
        case 3:
            cout << "Enter admission number of student" << endl;
            cin >> admissionNumber;
            s.Search_Student(admissionNumber);
            break;
        case 4:
            cout << "Enter admission number of student" << endl;
            cin >> admissionNumber;
            s.update_student(admissionNumber);
            break;
        case 5:
            cout << "Enter admission number of student" << endl;
            cin >> admissionNumber;
            s.delete_student(admissionNumber);
            break;
        default:
            return 0;
        }
    }
}