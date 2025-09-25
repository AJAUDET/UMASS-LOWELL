/*
    Authors: Group 7
    Purpose: Defining a Class object Mass and using OOP design principles to convert masses

    Conversion Factors: 
    1 dram = 1.7718451953125 grams
    1 dram = 1/256 Avoirdupois pound2
    1 dram = 1/96 Troy (apothecaries) pound3
*/

#include <iostream> // for cin / cout
#include <iomanip>  // setprecision()
using namespace std;

class Mass
{
private:
    double avoirdupois;
    double troy_pounds;
    double grams;
    double drams;

public:
    Mass(); // default constructor

    // display functions
    double promptInpupt(int prompt_val);
    void display();

    // mutator functions 
    void setMassAvoirdupoisPounds(double avoPounds);
    void setMassTroyPounds(double troyPounds);
    void setMassMetricGrams(double metricGrams);
    void setDrams(double new_drams);
    void convert(int conversion_type, double data);

    // accessor functions
    double getMassAvoirdupoisPounds(void);
    double getMassTroyPounds(void);
    double getMassGrams(void);
    double getDrams(void);
};

// Precond : A valid Mass object has been created
// Postcond : All variables are initialized to 0.0
Mass::Mass()
{
    setMassAvoirdupoisPounds(0.0);
    setMassMetricGrams(0.0);
    setMassTroyPounds(0.0);
    setDrams(0.0);
}

int main()
{
    Mass obj;
    bool running = true;
    int userInput;

    while (running)
    {
        cout << "Please enter 1 to use Avoirdupois pounds, 2 to use troy pounds, 3 to use grams, or 0 to exit: ";

        // Prompt for options
        cin >> userInput;

        // Check for invalid input and re-prompt until it is valid
        while (userInput < 0 || userInput > 3)
        {
            cout << "Invalid option, please try again: ";
            cin >> userInput;
        }
        // 0: Terminate program
        if (userInput == 0)
        {
            running = false;
        }
        // 1, 2, 3: Convert
        else
        {
            double data = obj.promptInpupt(userInput);
            obj.convert(userInput, data);

            obj.display();
        }
    }

    return 0;
}

// Precond : A valid Mass object has been created and initialized
// Precond : A valid prompt value has been inputted
// Postcond : The data for conversion was returned to the storage variable properly
double Mass::promptInpupt(int prompt_val)
{
    double data;

    switch (prompt_val)
    {
    case 1:
        cout << "Please enter a mass in Avoirdupois pounds: ";
        break;

    case 2:
        cout << "Please enter a mass in Troy pounds: ";
        break;

    case 3:
        cout << "Please enter a mass in Grams: ";
        break;

    default:
        break;
    }

    cin >> data;
    return data;
}

// Precond : A valid Mass object has been created and initialized
// Postcond : The values of the mass variables are displayed with 9 decimal precision
void Mass::display()
{
    cout << fixed << setprecision(9)
         << "Mass in Avoirdupois Pounds is: " << getMassAvoirdupoisPounds() << endl
         << "Mass in Troy Pounds is: " << getMassTroyPounds() << endl
         << "Mass in Grams is: " << getMassGrams() << endl;
}

// Precond : A valid Mass object has been created and initialized
// Postcond : The mass of Avoirdupois Pounds is returned successfully
double Mass::getMassAvoirdupoisPounds(void)
{
    return avoirdupois;
}

// Precond : A valid Mass object has been created and initialized
// Postcond : The mass of Troy Pounds is returned successfully
double Mass::getMassTroyPounds(void)
{
    return troy_pounds;
}

// Precond : A valid Mass object has been created and initialized
// Postcond : The mass of Grams is returned successfully
double Mass::getMassGrams(void)
{
    return grams;
}

// Precond : A valid Mass object has been created and initialized
// Postcond : The mass of Drams is returned successfully
double Mass::getDrams(void)
{
    return drams;
}

// Precond : A valid Mass object has been created and initialized
// Precond : A double is passed to the function
// Postcond : The Avoirdupois Pounds in the Mass object is set to the given value
void Mass::setMassAvoirdupoisPounds(double avoPounds)
{
    avoirdupois = avoPounds;
}

// Precond : A valid Mass object has been created and initialized
// Precond : A double is passed to the function
// Postcond : The Troy Pounds in the Mass object is set to the given value
void Mass::setMassTroyPounds(double troyPounds)
{
    troy_pounds = troyPounds;
}

// Precond : A valid Mass object has been created and initialized
// Precond : A double is passed to the function
// Postcond : The Grams in the Mass object is set to the given value
void Mass::setMassMetricGrams(double metricGrams)
{
    grams = metricGrams;
}

// Precond : A valid Mass object has been created and initialized
// Precond : A double is passed to the function
// Postcond : The Drams in the Mass object is set to the given value
void Mass::setDrams(double new_drams)
{
    drams = new_drams;
}


// Precond : A valid Mass object has been created and initialized
// Precond : A valid number for the conversion type is passed to the function
// Precond : The data passed to the function is valid
// Postcond : The data is properly converted from one Mass value to another
// Postcond : The variables of the Mass object are updated to their converted valus
void Mass::convert(int conversion_type, double data)
{
    double dram = 0.0, avoirdupois = 0.0, gram = 0.0, troy = 0.0;
    switch (conversion_type)
    {
    case 1:
        avoirdupois = data;
        dram = avoirdupois * 256;
        troy = dram / 96;
        gram = dram * 1.7718451953125;
        break;

    case 2:
        troy = data;
        dram = troy * 96;
        avoirdupois = dram / 256;
        gram = dram * 1.7718451953125;
        break;

    case 3:
        gram = data;
        dram = gram / 1.7718451953125;
        avoirdupois = dram / 256;
        troy = dram / 96;
        break;

    default:
        break;
    }

    setMassAvoirdupoisPounds(avoirdupois);
    setMassTroyPounds(troy);
    setMassMetricGrams(gram);
    setDrams(dram);
}
