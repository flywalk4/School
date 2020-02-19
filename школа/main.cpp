#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include "school.h"

using namespace std;

int main()
{
    string name, surname, proffesion, subject,grade;
    int day, month, year, money, amounOfStudents = 0, amounOfWorkers = 0, amounOfTeachers = 0;

    enum{EXIT,ADDSTUDENT, ADDWORKER, ADDTEACHER, DELETESTUDENT,DELETEWORKER, DELETETEACHER, CHANGETEACHER, CHANGESTUDENT, CHANGEWORKER, PRINTALL};
    enum{NAME=1, SURNAME, SEX, DAY, MONTH,YEAR, MONEY, SUBJECT};
    //0 - exit\n1 - name\n2 - surname\n3 - sex\n4 - day\n5 - month\n6 - year\n7 - money\n8 - subject\n
    char sex;
    const int GRADE=7;
    int select = 0, selectPerson = 0;
    int selectChange = 0;
    bool workChange = false;
    bool work = true;
//printf("Name      Surname    Sex    Date of birth      Grade\n");
    vector<Student> Students;

    Students.push_back(Student("Denis","Avgustov",'m', 29, 3, 2003, "10A"));
    Students.push_back(Student("Katerina","Ershova",'f', 8, 8, 2003,"10A"));
    amounOfStudents ++;
    amounOfStudents ++;

    vector<Teacher> Teachers;
    Teachers.push_back(Teacher("Denis","Avgustov",'m', 29, 3, 2000, 12000,"Teacher", "Math"));
    Teachers.push_back(Teacher("Katerina","Ershova",'f', 8, 11, 1992, 13500,"Teacher", "Russian"));
    amounOfTeachers ++;
    amounOfTeachers ++;


    vector<Worker> Workers;
    Workers.push_back(Worker("Oleg","Bondarenko",'m', 9, 6, 1989, 20000,"Security"));
    amounOfWorkers ++;



    while(work )
    {
        printf("0 - exit\n1 - add student\n2 - add worker\n3 - add teacher\n4 - delete student\n5 - delete worker\n6 - delete teacher\n7 - change info teacher\n8 - change info student\n9 - change info worker\n10 - print all\n");
        scanf("%d",&select);
        switch (select)
        {
        case EXIT:
            work = false;
            break;
        case ADDSTUDENT: //edit
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter surname: ";
            cin>>surname;
            cout<<"Enter sex(char): ";
            cin>>sex;
            cout<<"Enter day of birth: ";
            cin>>day;
            cout<<"Enter month of birth: ";
            cin>>month;
            cout<<"Enter year of birth: ";
            cin>>year;
            cout<<"Enter grade: ";
            cin>>grade;
            Students.push_back(Student(name, surname, sex, day, month, year, grade));
            amounOfStudents++;
            break;
        case ADDWORKER: //Edit worker
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter surname: ";
            cin>>surname;
            cout<<"Enter sex(char): ";
            cin>>sex;
            cout<<"Enter day of birth: ";
            cin>>day;
            cout<<"Enter month of birth: ";
            cin>>month;
            cout<<"Enter year of birth: ";
            cin>>year;
            cout<<"Enter money: ";
            cin>>money;
            cout<<"Enter profession: ";
            cin>>proffesion;
            Workers.push_back(Worker(name, surname, sex, day, month, year, money,proffesion));
            amounOfWorkers++;
            break;
        case ADDTEACHER:
            cout<<"Enter name: ";
            cin>>name;
            cout<<"Enter surname: ";
            cin>>surname;
            cout<<"Enter sex(char): ";
            cin>>sex;
            cout<<"Enter day of birth: ";
            cin>>day;
            cout<<"Enter month of birth: ";
            cin>>month;
            cout<<"Enter year of birth: ";
            cin>>year;
            cout<<"Enter money";
            cin>>money;
            cout<<"Enter profession: ";
            cin>>proffesion;
            cout<<"Enter subject: ";
            cin>>subject;
            Teachers.push_back(Teacher(name, surname, sex, day, month, year, money, proffesion, subject));
            amounOfTeachers++;
            break;

        case DELETESTUDENT:


            printf("Enter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;


            for(int i = 0; i < amounOfStudents; i++ )
            {
                if( Students[i].surname == surname && Students[i].name == name)
                {
                    Students.erase(Students.begin() + i);
                    amounOfStudents--;
                    break;
                }

            }
            printf("Deleted successfully\n");
            break;
        case DELETEWORKER:


            printf("\nEnter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;


            for(int i = 0; i < amounOfWorkers; i++ )
            {
                if( Workers[i].surname == surname && Workers[i].name == name)
                {
                    Workers.erase(Workers.begin() + i);
                    amounOfWorkers--;
                    break;
                }

            }
            printf("Deleted successfully\n");
            break;
        case DELETETEACHER:


            printf("\nEnter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;


            for(int i = 0; i < amounOfTeachers; i++ )
            {
                if( Teachers[i].surname == surname && Teachers[i].name == name)
                {
                    Teachers.erase(Teachers.begin() + i);
                    amounOfTeachers--;
                    break;
                }

            }
            printf("Deleted successfully\n");
            break;
        case CHANGETEACHER:
            printf("\nEnter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;
            for(int i = 0; i < amounOfTeachers; i++ )
            {
                if( Teachers[i].surname == surname && Teachers[i].name == name)
                {

                    selectPerson = i;
                    workChange = true;
                    break;

                }

            }


            while (workChange == true)
            {
                printf("0 - exit\n1 - name\n2 - surname\n3 - sex\n4 - day\n5 - month\n6 - year\n7 - money\n8 - subject\n");
                cin>>selectChange;
                switch (selectChange)
                {
                case EXIT:
                    workChange = false;
                    break;
                case NAME:
                    printf("Enter new name:");
                    cin>>Teachers[selectPerson].name;

                    break;
                case SURNAME:
                    printf("Enter new surname:");
                    cin>>Teachers[selectPerson].surname;

                    break;
                case SEX:
                    printf("Enter new sex(char):");
                    cin>>Teachers[selectPerson].sex;

                    break;
                case DAY:
                    printf("Enter new day:");
                    cin>>Teachers[selectPerson].day;

                    break;
                case MONTH:
                    printf("Enter new month:");
                    cin>>Teachers[selectPerson].month;

                    break;
                case YEAR:
                    printf("Enter new year:");
                    cin>>Teachers[selectPerson].year;

                    break;
                case MONEY:
                    printf("Enter new money;");
                    cin>>Teachers[selectPerson].money;

                    break;
                case SUBJECT:
                    printf("Enter new subject:");
                    cin>>Teachers[selectPerson].subject;

                    break;
                };

            };
            break;

        case CHANGEWORKER:
            printf("\nEnter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;
            for(int i = 0; i < amounOfWorkers; i++ )
            {
                if( Workers[i].surname == surname && Workers[i].name == name)
                {
                    selectPerson = i;
                    workChange = true;
                    break;

                }

            }


            while (workChange == true)
            {
                printf("0 - exit\n1 - name\n2 - surname\n3 - sex\n4 - day\n5 - month\n6 - year\n7 - money\n");
                cin>>selectChange;
                switch (selectChange)
                {
                case EXIT:
                    workChange = false;
                    break;
                case NAME:
                    printf("Enter new name:");
                    cin>>Workers[selectPerson].name;

                    break;
                case SURNAME:
                    printf("Enter new surname:");
                    cin>>Workers[selectPerson].surname;

                    break;
                case SEX:
                    printf("Enter new sex(char):");
                    cin>>Workers[selectPerson].sex;

                    break;
                case DAY:
                    printf("Enter new day:");
                    cin>>Workers[selectPerson].day;

                    break;
                case MONTH:
                    printf("Enter new month:");
                    cin>>Workers[selectPerson].month;

                    break;
                case YEAR:
                    printf("Enter new year:");
                    cin>>Workers[selectPerson].year;

                    break;
                case MONEY:
                    printf("Enter new money;");
                    cin>>Workers[selectPerson].money;

                    break;


                };
                break;

            };
            break;

        case CHANGESTUDENT:
            printf("\nEnter name:");
            cin>>name;
            printf("Enter surname:");
            cin>>surname;
            for(int i = 0; i < amounOfStudents; i++ )
            {
                if( Students[i].surname == surname && Students[i].name == name)
                {
                    workChange = true;
                    selectPerson = i;
                    break;

                }

            }

            while (workChange == true)
            {
                printf("0 - exit\n1 - name\n2 - surname\n3 - sex\n4 - day\n5 - month\n6 - year\n7 - grade\n");
                cin>>selectChange;
                switch (selectChange)
                {
                case EXIT:
                    workChange = false;
                    break;
                case NAME:
                    printf("Enter new name:");
                    cin>>Students[selectPerson].name;

                    break;
                case SURNAME:
                    printf("Enter new surname:");
                    cin>>Students[selectPerson].surname;

                    break;
                case SEX:
                    printf("Enter new sex(char):");
                    cin>>Students[selectPerson].sex;

                    break;
                case DAY:
                    printf("Enter new day:");
                    cin>>Students[selectPerson].day;

                    break;
                case MONTH:
                    printf("Enter new month:");
                    cin>>Students[selectPerson].month;

                    break;
                case YEAR:
                    printf("Enter new year:");
                    cin>>Students[selectPerson].year;

                    break;
                case GRADE:
                    printf("Enter new grade:");
                    cin>>Students[selectPerson].grade;
                    break;
                };

            };
            break;
        case PRINTALL:
            printf("Students\n");

            for (int c = 0; c < amounOfStudents; c++ )
            {
                printf("%s %s %c %d.%d.%d %s\n",Students[c].name.c_str(), Students[c].surname.c_str(),Students[c].sex,Students[c].day,Students[c].month,Students[c].year,Students[c].grade.c_str()  );
            };
            printf("\nTeachers\n");
            for (int c = 0; c < amounOfTeachers; c++ )
            {
                printf("%s %s %c %d.%d.%d %s %d\n",Teachers[c].name.c_str(), Teachers[c].surname.c_str(),Teachers[c].sex,Teachers[c].day,Teachers[c].month,Teachers[c].year,Teachers[c].subject.c_str(),Teachers[c].money  );
            };
            printf("\nWorkers\n");
            for (int c = 0; c < amounOfWorkers ; c++ )
            {
                printf("%s %s %c %d.%d.%d %d %s\n", Workers[c].name.c_str(), Workers[c].surname.c_str(), Workers[c].sex, Workers[c].day, Workers[c].month, Workers[c].year, Workers[c].money, Workers[c].profession.c_str()  );
            };
            break;
        };
    };



    return 0;
}
