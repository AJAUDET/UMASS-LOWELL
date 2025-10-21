#include <iostream>
#include <string>

using namespace std;

// ***** Add your Date class definition and driver program at the end of this file
// (at about line 107). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation unit (file),
// we are not nesting the Month class in the Date class or vice versa.

class Month {
 public:
	friend class Date;
	
	friend ostream& operator<< (ostream&, Month);
	
 private:
	enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
		
	Month() : _month(Jan) {} // default constructor
	Month(int im) : _month( static_cast<EMonth>(im) ) {} // value constructor
	
	void setMonth(string m) { _month = StringToEMonth(m); } // mutator functions
	void setMonth(int im) { _month = static_cast<EMonth>(im); }
	
	/* Private helper member functions */
	EMonth StringToEMonth(string);
	int MonthToInt() { return static_cast<int>(_month); }
	string MonthToString();
	string MonthToString2();

	EMonth _month;
};

/* Definitions of helper member functions for class Month */

Month::EMonth Month::StringToEMonth(string m) {
	if (m == "Jan") return Jan;
	else if (m == "Feb") return Feb;
	else if (m == "Mar") return Mar;
	else if (m == "Apr") return Apr;
	else if (m == "May") return May;
	else if (m == "Jun") return Jun;
	else if (m == "Jul") return Jul;
	else if (m == "Aug") return Aug;
	else if (m == "Sep") return Sep;
	else if (m == "Oct") return Oct;
	else if (m == "Nov") return Nov;
	else if (m == "Dec") return Dec;
	else {
		cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
		exit(1);
	}
}

string Month::MonthToString() {
	switch (_month) {
		case Jan: return "Jan";
		case Feb: return "Feb";
		case Mar: return "Mar";
		case Apr: return "Apr";
		case May: return "May";
		case Jun: return "Jun";
		case Jul: return "Jul";
		case Aug: return "Aug";
		case Sep: return "Sep";
		case Oct: return "Oct";
		case Nov: return "Nov";
		case Dec: return "Dec";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

string Month::MonthToString2() {
	switch (_month) {
		case Jan: return "January";
		case Feb: return "February";
		case Mar: return "March";
		case Apr: return "April";
		case May: return "May";
		case Jun: return "June";
		case Jul: return "July";
		case Aug: return "August";
		case Sep: return "September";
		case Oct: return "October";
		case Nov: return "November";
		case Dec: return "December";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

/* Definition of friend function operator<< */

ostream& operator<< (ostream& out, Month m) {
	out << m.MonthToString2();
	return out;
}


// ***** Add your Date class definition and driver program below. *****
class Date {
 public:
	// Constructors
	Date();
	Date(int d, int m, int y);
	Date(int d, string m, int y);

	// Output functions
	void outputDateAsInt(ostream& out, Date date);
	void outputDateAsString(ostream& out, Date date);

	// Month string accessors
	string const getMonthasString();
	string const getMonthasString2();

	// Accessors
	int const getDay();
	int const getMonthasInt();
	int const getYear();
	
	// Mutators
	void setDay(int d) ;
	void setMonth(int m);
	void setMonth(string m);
	void setYear(int y);

	// Operator overloaders
	friend ostream& operator<<(ostream& out, Date rightOp);
	friend Date &operator++(Date& operand);
	
 private:
	int day;
	class Month month;
	int year;
};
Date &operator++(Date& operand);

// Constructors
Date::Date(): Date(1, 1, 2018) {}
Date::Date(int d, int m, int y): day(d), year(y) { month.setMonth(m); }

Date::Date(int d, string m, int y)
{
	day = d;
	month.setMonth(m);
	year = y;
}

// Accessors
int const Date::getDay() 
{ 
	return day; 
}

int const Date::getMonthasInt()
{
	return month.MonthToInt();
}

int const Date::getYear()
{
	return year;
}

string const Date::getMonthasString()
{
	return month.MonthToString();
}

string const Date::getMonthasString2()
{
	return month.MonthToString2();
}

// Mutators
void Date::setYear(int y) { year = y; }
void Date::setDay(int d) { day = d; }
void Date::setMonth(int m) { month.setMonth(m); }
void Date::setMonth(string m) { month.setMonth(m); }


void Date::outputDateAsInt(ostream& out, Date date) {
	out << date.getMonthasInt() << "/";
	out << date.getDay() << "/";
	out << date.getYear() << endl;
}

void Date::outputDateAsString(ostream& out, Date date) {
	out << date.getMonthasString() << " ";
	out << date.getDay() << ", ";
	out << date.getYear() << endl;
}

ostream& operator<<(ostream& out, Date rightOp)
{
	out << rightOp.getMonthasString2() << " ";
	out << rightOp.getDay() << ", ";
	out << rightOp.getYear() << endl;
	return out;
}

Date &operator++(Date& operand)
{
	operand.year++;
	return operand;
}

int main() {
	Date d1, d2(1, 2, 2018), d3(1, "Mar", 2018);

	d1.setDay(1);
	d1.setMonth(1);
	d1.setYear(2018);
	
	cout << "d1 == "; d1.outputDateAsString(cout, d1);
	cout << "d2 == "; d2.outputDateAsString(cout, d2);

	d3.setMonth(4);
	cout << "d3 == "; d3.outputDateAsString(cout, d3);
	
	Date d4(31, 12, 2018);
	d4.outputDateAsInt(cout, d4);
	d4.outputDateAsString(cout, d4);

	return 0;
}