#include <iostream>
using namespace std;

struct date{
    int month;
    int day;
    int year;
};
typedef struct date Date;

class New_Date {
public: 
    void display(void);

    int month;
    int day;
    int year;
};

void display_date(Date aDate);

int main(void)
{
    // Date today = {9, 16, 2025};

    New_Date today = {9,16,2205};

    // Date last_day_school;
    New_Date last_day_school;
    last_day_school.month = 12;
    last_day_school.day = 12;
    last_day_school.year = 2025;

    // display_date(today);
    // display_date(last_day_school);
}

void display_date(Date aDate)
{
    cout << aDate.month << "/" << aDate.day << "/" << aDate.year << endl;
}
