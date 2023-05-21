#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Human
{
protected:
    string full_name;
    int birth_year;
    string gender;

public:
    Human()
    {
        full_name = "Ivan Ivanov Ivanovich";
        birth_year = 2000;
        gender = "Male";
    }

    void set_info();
    void print();
};

class Student : public Human
{
    int admission_year;
    int stud_recbook_num;
    int disciplines_num;
    string* disciplines;
    int* disc_mark;
    double aver_mark;
    bool check;

public:
    Student()
    {
        admission_year = 2022;
        stud_recbook_num = 241;
        disciplines_num = 5;
        aver_mark = 100;
        check = false;
        disciplines = new string[disciplines_num];
        disc_mark = new int[disciplines_num];

        for (int i = 0; i < disciplines_num; i++)
        {
            disciplines[i] = "Discipline";
            disc_mark[i] = 54;
        }
    }

    ~Student()
    {
        delete[] disciplines;
        delete[] disc_mark;
    }

    void add_disc();
    double average_mark();
    void set_info();
    void print();
};

void Human::set_info()
{
    cout << "\nEnter a full name of a person: ";
    cin.ignore();
    getline(cin, full_name);

    cout << "Enter year of birth: ";
    cin >> birth_year;

    cout << "Enter a gender of a person: ";
    cin >> gender;
}

void Human::print()
{
    cout << "\nFull name: " << full_name << "\nYear of birth: " << birth_year << "\nGender: " << gender;
}

void Student::add_disc()
{
    string* temp_disc = new string[disciplines_num + 1];
    int* temp_mark = new int[disciplines_num + 1];

    for (int i = 0; i < disciplines_num; i++)
    {
        temp_disc[i] = disciplines[i];
        temp_mark[i] = disc_mark[i];
    }

    delete[] disciplines;
    delete[] disc_mark;

    string add_disc;
    int mark;

    cout << "Enter additional discipline: ";
    cin.ignore();
    getline(cin, add_disc);

    do
    {
        cout << "Enter a mark (0 - 100): ";
        cin >> mark;
    } while (mark > 100 || mark < 0);

    temp_disc[disciplines_num] = add_disc;
    temp_mark[disciplines_num] = mark;

    disciplines_num++;

    disciplines = temp_disc;
    disc_mark = temp_mark;
}

double Student::average_mark()
{
    double summ = 0;

    for (int i = 0; i < disciplines_num; i++)
    {
        summ += disc_mark[i];
        aver_mark = summ / disciplines_num;
        check = true;
    }

    return aver_mark;
}

void Student::set_info()
{
    Human::set_info();

    cout << "\nEnter year of admission: ";
    cin >> admission_year;

    cout << "Enter student`s record book number: ";
    cin >> stud_recbook_num;

    cout << "Enter number of disciplines (max - 5): ";
    cin >> disciplines_num;

    for (int i = 0; i < disciplines_num; i++)
    {
        cout << "\nDiscipline #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, disciplines[i]);

        do
        {
            cout << "Mark (0 - 100): ";
            cin >> disc_mark[i];
        } while (disc_mark[i] > 100 || disc_mark[i] < 0);
    }
}

void Student::print()
{
    Human::print();

    cout << "\nYear of admission: " << admission_year << "\nStudent`s record book number: " << stud_recbook_num << "\nNumber of disciplines: " << disciplines_num <<
        "\nDisciplines: \n";

    for (int i = 0; i < disciplines_num; i++)
        cout << "\n" << i + 1 << ". " << disciplines[i] << " - " << disc_mark[i];

    cout << "\nAverage mark: ";
    if (check == true)
        cout << aver_mark;
    else
        cout << "average mark was not calculated yet!";
}

void menu(Student b)
{
    int choice, returning;
    double av_mark;

    do
    {
        cout << "1 - Enter info\n2 - Print\n3 - Add discipline\n4 - Calculate average mark\n5 - Exit;\n\nYour choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            b.set_info();
            system("cls");
            break;

        case 2:
            b.print();

            cout << "\n\nEnter 0 to return to menu: ";
            cin >> returning;

            if (returning == 0)
                system("cls");

            break;

        case 3:
            b.add_disc();
            system("cls");
            break;

        case 4:
            av_mark = b.average_mark();

            cout << "\nAverage mark = " << av_mark;

            cout << "\n\nEnter 0 to return to menu: ";
            cin >> returning;

            if (returning == 0)
                system("cls");
            break;

        case 5:
            break;
        }
    } while (choice != 5);
}

int main()
{
    Student b;

    menu(b);

    return 0;
}