#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// using declarations
using std::ostream;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::stable_sort;
using std::find;
using std::minmax;
using std::count;
using std::for_each;

const int IGNORE_SIZE = 256;


class UMLPerson { // base class
	public:
		// constructors and destructor
	    UMLPerson() : _firstName("NoName"), _lastName("NoName"), _address("NoAddress"), _IDNumber(0) {}
		
        UMLPerson(string firstName, string lastName, string address, unsigned IDNumber) :
			_firstName(firstName), _lastName(lastName), _address(address), _IDNumber(IDNumber) {}
			
		UMLPerson(const UMLPerson&); // copy constructor
			
		~UMLPerson();
		
		// Implements lexicographic comparison of UMLPerson objects based on last name
		bool operator< (const UMLPerson& rhs) const { return this->_lastName < rhs._lastName; }
		
		// Implements equality based on IDNumber
		bool operator== (const UMLPerson& rhs) const { return this->_IDNumber == rhs._IDNumber; }
		bool operator== (const unsigned rhs) const { return this->_IDNumber == rhs; }
		
		// accessor functions
	    string getFirstName() const { return _firstName; }
        string getLastName() const { return _lastName; }
		string getAddress() const { return _address; }
		unsigned getIDNumber() const { return _IDNumber; }
		
		void output(ostream& out) const { out << *this; }
				
	friend ostream& operator<< (ostream&, const UMLPerson&);
	friend ofstream& operator<< (ofstream&, const UMLPerson&);
	friend ifstream& operator>> (ifstream&, UMLPerson&);
	
	private:
	    string _firstName;
        string _lastName;
        string _address;
		unsigned _IDNumber;
};


UMLPerson::UMLPerson(const UMLPerson& p) {
    // make an independent copy of any dynamic member variables of UMLPerson here
    _firstName = p._firstName;
    _lastName  = p._lastName;
    _address = p._address;
    _IDNumber = p._IDNumber;
//	cout << "UMLPerson copy constructor called for \"" << _firstName << " " << _lastName << "\"\n";
}


UMLPerson::~UMLPerson() {
	// delete any dynamic data members for UMLPerson here
//	cout << "UMLPerson destructor called for \"" << _firstName << " " << _lastName << "\"\n";
}


ostream& operator<< (ostream& out, const UMLPerson& p) {
    out << p._firstName << " " << p._lastName << ", " << p._address << ", " << p._IDNumber << endl;
        
    return out;
}


ofstream& operator<< (ofstream& out, const UMLPerson& p) {
    out << p._firstName << " " << p._lastName << ", " << p._address << ", " << p._IDNumber << endl;
        
    return out;
}


ifstream& operator>> (ifstream& fin, UMLPerson& p) {
	string addr, separator;
	
	fin >> p._firstName >> p._lastName >> separator;
	
	char c = fin.get(); // skip space after separator
	
	// get address (delimited by comma)
	c = fin.get(); // first character of address
	while (fin.good() && (c != ',')) {
		addr += c;
		c = fin.get();
	}
	p._address = addr;
	
	fin >> p._IDNumber;
	
	return fin;
}


vector<UMLPerson> inputUMLPeople(ifstream& ifs) {
	vector<UMLPerson> uv;
	UMLPerson up;

	do {
		ifs >> up; // get one UMLPerson from the file, and ignore to end of line
		ifs.clear();
		ifs.ignore(IGNORE_SIZE, '\n');
		
		if (!ifs.good()) // end of file?
			break;
		
		uv.push_back(up);
	} while (true);
	
	return uv;
}


void outputUMLPeople(ofstream& ofs, const vector<UMLPerson>& uv) {
	for (auto up: uv)
		ofs << up;
}


// createUMLPeopleDB() is shown here for learning purposes only;
// its output is already provided in lab11_input.txt
void createUMLPeopleDB (void) {
	vector<UMLPerson> uv;
		
	uv.push_back( UMLPerson("Sally", "Brown", "110 Canal Street", 12345678) );
	uv.push_back( UMLPerson("Jimmy", "Smith", "99 Canal Street", 87654321) );
	uv.push_back( UMLPerson("Mary", "Doe", "10 Maple Drive", 47100123) );
	uv.push_back( UMLPerson("John", "Doe", "10 Maple Drive", 69271023) );
	uv.push_back( UMLPerson("Howard", "Johnson", "20 Maple Drive", 89177224) );
	uv.push_back( UMLPerson("Jane", "Astor", "40 Birch Street", 34112316) );
	uv.push_back( UMLPerson("Jane", "Smith", "50 Birch Street", 60289502) );
	uv.push_back( UMLPerson("Hermione", "Granger", "55 Pine Avenue", 87654321) );
	uv.push_back( UMLPerson("Luke", "Skywalker", "Tatooine", 51519030) );
	uv.push_back( UMLPerson("Leia", "Organa", "Alderaan", 71590710) );
	
	// ofstream value constructor performs function of ofstream::open()
	ofstream fout("lab11_input.txt", std::ofstream::out);
	
	outputUMLPeople(fout, uv);
	
	fout.close();
}


vector<UMLPerson> loadUMLPeopleDB (void) {
	// ifstream value constructor performs function of ifstream::open()
	ifstream fin("lab11_input.txt", std::ifstream::in);
	if (!fin.good()) {
		cout << "File \"lab11_input.txt\" not found\n";
		exit(-1);
	}
	
	vector<UMLPerson> uv = inputUMLPeople(fin);
	
	fin.close();
	return uv;
}


void displayUMLPeopleDB(const vector<UMLPerson>& upDB) {
	cout << "Contents of upDB:\n";
	for (auto up: upDB)
		cout << up;
	cout << endl;
}


// *** Your team's modifications begin here...

bool compare_IDs(const UMLPerson& lhs, const UMLPerson& rhs)
{
	return lhs.getIDNumber() < rhs.getIDNumber();
}

void printFullName (const UMLPerson& p) {
	cout << p.getFirstName() << " " << p.getLastName() << endl;
}

// Modify this driver program according to the directions given in the comments.
int main (void) {
//	createUMLPeopleDB(); // not needed for Lab 11 - output is already in file lab11_input.txt

	vector<UMLPerson> upDB = loadUMLPeopleDB();
	
	cout << "Original - ";
	displayUMLPeopleDB(upDB);
	
	// Trying out STL algorithm stable_sort...
	stable_sort(upDB.begin(), upDB.end());
	cout << "After std::stable_sort with default comparison (by last name) - ";
	displayUMLPeopleDB(upDB);

	// stable_sort(upDB.begin(), upDB.end(), compare_IDs(*upDB.begin(), *(upDB.begin()+1)));
	stable_sort(upDB.begin(), upDB.end(), compare_IDs);
	cout << "After std::stable_sort using Compare function compare_IDs - ";
	displayUMLPeopleDB(upDB);

	// Trying out STL algorithm find...
	cout << "Using std::find:\n";
	if (find(upDB.begin(), upDB.end(), 87654321) != upDB.end())
		cout << "IDNumber 87654321 found in upDB for UMLPerson: " << *find(upDB.begin(), upDB.end(), 87654321) << endl;
	else
		cout << "IDNumber 87654321 not found in upDB.\n";

	if (find(upDB.begin(), upDB.end(), 89283002) != upDB.end())
		cout << "IDNumber 89283002 found in upDB for UMLPerson: " << *find(upDB.begin(), upDB.end(), 89283002) << endl;
	else
		cout << "IDNumber 89283002 not found in upDB.\n" << endl;
	
	// Trying out STL algorithm minmax_element...
	cout << "std::minmax_element in upDB using default comparison (by last name):\n";
	cout << "min is " << *minmax_element(upDB.begin(), upDB.end()).first;
	cout << "max is " << *minmax_element(upDB.begin(), upDB.end()).second << endl << endl;
	
	cout << "std::minmax_element in upDB using Compare function compare_IDs:\n";
	cout << "min is " << *minmax_element(upDB.begin(), upDB.end(), compare_IDs).first;
	cout << "max is " << *minmax_element(upDB.begin(), upDB.end(), compare_IDs).second << endl << endl;
	
	
	// Trying out STL algorithm count...
	unsigned keyID = 87654321;
	int mycount = -1;
	// Count IDs equal to 87654321 using an inline function
	mycount = count_if(upDB.begin(), upDB.end(), [keyID](const UMLPerson& p) { return p.getIDNumber() == keyID; });
	cout << "Using std::count, IDNumber " << keyID << " appears " << mycount << " times in upDB.\n\n";

	// Trying out STL algorithm for_each...
	cout << "Using std::for_each to print full name of each person in upDB:\n";
	// Print full names
	for_each(upDB.begin(), upDB.end(), printFullName);

    return 0;
}
