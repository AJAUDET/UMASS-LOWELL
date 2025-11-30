/*
    Authors: Group 7
    Purpose: Converting lbs and oz to kg and g using functions and using iomanip for higher precision
    Sources of help: Conversion factors grabbed from the internet
*/
/*
    Conversion Factors:
    lbs -> kg : 1lb = 0.45359237 kg, so lbs * 0.45359237 = kg
    oz -> g : 1oz = 28.3495 g, so oz * 28.3495 = g
*/
#include <iostream> 
#include <limits> 
#include <iomanip>
#include <cmath> 

using namespace std;

void get_lbs_oz(int& lbs, double& oz);
void convert(int lbs, double oz, int& kg, double& g);
void display(int lbs, double oz, int kg, double g);

int main() {
    int lbs, kg;
    double oz, g;

    get_lbs_oz (lbs, oz);
    convert(lbs, oz, kg, g);
    display(lbs, oz, kg, g);

    return 0;
}

// precond: lbs and oz are variables that are initialized
// postcond: lbs and oz are changed to the correct values 
void get_lbs_oz(int& lbs, double& oz) {
    while ((cout << "Please enter the number of pounds: ") && !(cin >> lbs)) {
        cout << "That's not a number greater than or equal to 0! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                // following the example from isocpp
    }
    while ((cout << "Please enter the number of ounces: ") && (!(cin >> oz) || (oz > 16))) {
        cout << "That's not a number greater than or equal to 0, and less than 16! Please try again..." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


// precond: valid input of lbs, oz
// precond: storage variables for kg and g
// postcond: lbs and oz are converted to kg + g
void convert(int lbs, double oz, int& kg, double& g) {
    double temp1;

    // store converted data in a temp variable
    kg = floor(static_cast<double>(lbs) * 0.45359237);     // this truncates decimals bc double to int conversion
    temp1 = (lbs * 0.45359237);                            // stores accurate kg conversion 
    g = (temp1 - kg) * 1000;                               // grams : difference between the accurate kg and int kg, mult by 1000, and store
    g += (oz*28.3495);                                     // add the oz to g conversion to the other value
    while (g >= 1000) {                                    // check if g >= 1000 to see if kg needs to increase 
        g -= 1000;
        kg++;
    }

}

// display lbs , oz and kg , g
void display(int lbs, double oz, int kg, double g) {
    cout << "Pounds: " << lbs;
    cout << " Ounces: " << oz;
    cout << " Kilograms: " << kg;
    cout << setprecision(15) << " Grams: " << g << endl;
}
