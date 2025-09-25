#include <iostream>
using namespace std;

struct date {
    int month;
    int day;
    int year;
};
typedef struct date Date;

class New_Date {
public: 
    // constructors
    New_Date(int init_month, int init_day, int init_year);      // value constructor
    New_Date(int init_month, int init_day);                     // value constructor
    New_Date();                                                 // default constructor

    // member functions
    void display(void);

    // accessor, getter functions
    int get_month(void);
    int get_day(void);
    int get_year(void);

    // mutator, setter functions
    void set_month(int new_month);
    void set_day(int new_day);
    void set_year(int new_year);

private:
    int month;
    int day;
    int year;
};

void display_date(Date aDate);

int main(void)
{
    // Date today = {9, 16, 2025};
    New_Date today(9,18);
    today = New_Date(9,20);

    today.display();

    // New_Date today = {9,16,2205};
    // today.display();

    New_Date new_year_day; // default 
    new_year_day.display();


    // Date last_day_school;
    New_Date last_day_school(12,11,2025);
    // last_day_school.set_month(12);
    // last_day_school.set_day(31);
    // last_day_school.set_year(2025);
    last_day_school.display();

    // display_date(today);
    // display_date(last_day_school);
}
/*
void display_date(Date aDate)
{
    cout << aDate.month << "/" << aDate.day << "/" << aDate.year << endl;
}
*/

New_Date::New_Date(int init_month, int init_day, int init_year)
{
    month = init_month;
    day = init_day;
    year = init_year;
}

New_Date::New_Date()
{
    month = 1;
    day = 1;
    year = 1;
}

New_Date::New_Date(int init_month, int init_day)
{
    month = init_month;
    day = init_day;
    year = 2025;
}

void New_Date::display(void) // :: = scope resolution operator, ie this function belongs to this class
{
    cout << month << "-" << day << "-" << year << endl;
}

int New_Date::get_month(void)
{
    return month;
}

int New_Date::get_day(void)
{
    return day;
}

int New_Date::get_year(void)
{
    return year;
}

void New_Date::set_month(int new_month)
{
    month = new_month;
}
void New_Date::set_day(int new_day)
{
    day = new_day;
}
void New_Date::set_year(int new_year)
{
    year = new_year;
}
