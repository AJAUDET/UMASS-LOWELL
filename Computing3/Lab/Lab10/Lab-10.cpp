// Day 10: Mass class with exception handling
#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int IGNORE_SIZE = 256;
const double MAX_DOUBLE = std::numeric_limits<double>::max();


/**
 *  Generic function to input a number, and check whether the number is within
 *  the specified bounds.
 *  If within bounds, return the input number.
 *  If not a number or not within bounds, should throw an input_error exception with the
 *  specified error message.
 */

// Implement input_exception
class input_exception: public exception {
	private:
		string err_msg;

	public:
		input_exception():err_msg("Error: invalid input") {}
		const char *what() const noexcept override { return err_msg.c_str(); }
};

template<typename T>
T checkInput(T lower, T upper, string message)
{
	T in;
	
	if ( !(cin >> in) || (in < lower) || (in > upper) ) {
		// Throw the input exception error
		throw input_exception();
		//cin.clear();
		//cin.ignore(IGNORE_SIZE, '\n');
	}
	
	return in;
}


class Mass {
	public:
		void setMassAvoirdupoisPounds( double ap ) { drams = ap*dramsPerAvoirdupoisPound; }
		void setMassTroyPounds( double tp ) { drams = tp*dramsPerTroyPound; }
		void setMassMetricGrams( double mg ) { drams = mg/metricGramsPerDram; }
		double getMassAvoirdupoisPounds() { return drams/dramsPerAvoirdupoisPound; }
		double getMassTroyPounds() { return drams/dramsPerTroyPound; }
		double getMassMetricGrams() { return drams*metricGramsPerDram; }
	private:
		double drams;
		const int dramsPerAvoirdupoisPound = 256;
		const int dramsPerTroyPound = 96;
		const double metricGramsPerDram = 1.7718451953125;
};


int main()
{
	int choice;
	double inputMass;
	Mass m;
	
	do {
		do{
		    cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, "
			     << "3 to use grams, or 0 to exit: ";
				 
			// Use try to handle input exceptions; likewise for switch cases 1, 2, and 3
			try {
				choice = checkInput(0, 3, "That's not a number between 0 and 3!");
			}						
			// Catch any input exceptions
			catch (input_exception &ex)
			{
				cout << ex.what() << endl;
				continue;
			}
			break;
			
		} while (true);
		
		switch ( choice ) {
			case 1:
				do {
				    cout << "Please enter a mass in Avoirdupois pounds: ";
				    
					try {
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
					} 
					catch (input_exception &ex) {
						cout << ex.what() << endl;
						continue;
					}
				    break;
					
		        } while (true);
				m.setMassAvoirdupoisPounds( inputMass );
				break;
				
			case 2:
				do {
				    cout << "Please enter a mass in Troy pounds: ";
				    
					try {
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
					}
					catch (input_exception &ex) {
						cout << ex.what() << endl;
						continue;
					}
				    break;
			        
		        } while (true);
				m.setMassTroyPounds( inputMass );
				break;
				
			case 3:
				do {
				    cout << "Please enter a mass in grams: ";
				    
					try {
				    inputMass = checkInput(0.0, MAX_DOUBLE, "That's not a positive number!");
					}
					catch (input_exception &ex) {
						cout << ex.what() << endl;
						continue;
					}
				    break;
 
		        } while (true);
				m.setMassMetricGrams( inputMass );
				break;
				
			default:
				cout << "Thanks for using the mass conversion program!\n";
				exit( 1 );
				
		} // end switch

		cout << "Mass in Avoirdupois pounds is " << m.getMassAvoirdupoisPounds() << endl;
		cout << "Mass in Troy pounds is " << m.getMassTroyPounds() << endl;
		cout << "Mass in grams is " << m.getMassMetricGrams() << endl << endl;
		
	} while (true);
	
	return 0;
}
