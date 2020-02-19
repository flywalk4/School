#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human
{
public:
    string name;
    string surname;
    char sex;
    int day;
    int month;
    int year;
    Human(string name, string surname, char sex, int day, int month, int year )
    {
        this -> name = name;
        this -> surname = surname;
        this -> sex = sex;
        this -> day = day;
        this -> month = month;
        this -> year = year;
    };
};

class Student: public Human
{
public:
    string grade;
    Student (string name, string surname, char sex, int day, int month, int year,  string grade) : Human(name, surname, sex, day, month, year)
    {
        this -> grade = grade;

    };
};

class Worker: public Human
{
public:
    int money;
    string profession;
    Worker (string name, string surname, char sex, int day, int month, int year, int money, string profession) : Human(name, surname, sex, day, month, year)
    {
        this -> money = money;
        this -> profession = profession;
    };
};

class Teacher: public Worker
{
public:
    string subject;
    Teacher (string name, string surname, char sex, int day, int month, int year, int money, string profession,  string subject) : Worker(name, surname, sex, day, month, year, money, profession)
    {
        this -> subject = subject;
    };
};


