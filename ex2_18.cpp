// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Unit 2 Exercise 2-18
// Course: SDEV-230
// Creation Date: 10/28/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iomanip>
#include <iostream>
#include <limits>

// Provide scope to identifiers inside the standard library
using namespace std;

// Create the constants
// const double dblHOURLY_RATE = 15.50; // Percentage
const double dblTAX_RATE = 0.14; // Percentage
const double dblACCESSORY_PURCHASE_RATE = 0.10; // Percentage
const double dblSCHOOL_SUPPLY_RATE = 0.01; // Percentage
const double dblSAVING_BOND_RATE = 0.25; // Percentage
const double dblPARENT_CONTRIBUTE_RATE = 0.50; // Currency
const int intMAX_ARRAY_SIZE = 5; // Set the array size to a number 

int main() {
    // Create the Local Variables
    double dblTotalIncomeBeforeTax = 0.0, dblTotalIncomeAfterTax = 0.0, dblTotalAccessorySpent = 0.0, dblTotalSchoolSupplySpent = 0.0, dblPayRate = 0.0;
    double dblTotalSelfBondSpent = 0.0, dblTotalParentBondSpent = 0.0, dblTotalBondSpent = 0.0, dblRemainingTotalIncome = 0.0, dblResultTotal = 0.0;
    int intCount = 0, intHourInput = 0, intTotalIncomeBeforeTax = 0;
    int aintWeeklyHourInput[intMAX_ARRAY_SIZE];
    
    // Display instruction message to user
    cout << "----------------------------------------------------------------" << endl;
    cout << "You will be prompted to enter both your hourly pay wage and the " << endl;
    cout << "total number of hours worked per week for 5 weeks." << endl;
    cout << "----------------------------------------------------------------" << endl;

    // Get the pay rate from user
    cout << "Enter Pay Rate: ";
    cin >> dblPayRate;

    // Step Two: Prompt the user to enter hours worked per week for 5 weeks total
    for (intCount = 0; intCount < intMAX_ARRAY_SIZE; ++intCount) {
        // Get the user input and increment the counter by one during first pass
        cout << "Week " << intCount + 1 << ": ";
        // Create a while loop. While cin is true, (ie that the input is of integer type) proceed. 
        while (!(cin >> intHourInput)) {
            // If the input type is not integer, or the cin returns false, display error message to user
            cout << "Invalid input. Please enter a number: ";
            // Clear the error flag and remove the invalid input from the istream 
            cin.clear(); 
            // Get the max number of char in stream to ignore and stop discarding char until encountering '\n' character
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // When out of the while loop, proceed to insert/append the array list with the user input
        aintWeeklyHourInput[intCount] = intHourInput;
    }
    // For debugging purposes, check what is inside the array list
    // for (int i = 0; i < intMAX_ARRAY_SIZE; ++i)
    //     cout << aintWeeklyHourInput[i] << endl; 

    // Calculate the total income before taxes
    for (intCount = 0; intCount < intMAX_ARRAY_SIZE; ++intCount) {
        dblTotalIncomeBeforeTax += (dblPayRate * aintWeeklyHourInput[intCount]);
    }

    // Calculate the total income after taxes
    dblTotalIncomeAfterTax = dblTotalIncomeBeforeTax - (dblTotalIncomeBeforeTax * dblTAX_RATE); 
    // Change the double to integer 
    intTotalIncomeBeforeTax = static_cast<int>(dblTotalIncomeBeforeTax);    

    // Calculate the money spent on accessories
    dblTotalAccessorySpent = dblTotalIncomeAfterTax * dblACCESSORY_PURCHASE_RATE;
    // Calculate the money spent on school supplies
    dblTotalSchoolSupplySpent = dblTotalIncomeAfterTax * dblSCHOOL_SUPPLY_RATE;
    // Calculate the remainder of money at this point 
    dblRemainingTotalIncome = dblTotalIncomeAfterTax - (dblTotalAccessorySpent + dblTotalSchoolSupplySpent);

    // Calculate the money spent on buying savings bonds 
    dblTotalSelfBondSpent = dblRemainingTotalIncome * dblSAVING_BOND_RATE;
    dblTotalParentBondSpent = dblTotalSelfBondSpent * dblPARENT_CONTRIBUTE_RATE;
    dblTotalBondSpent = dblTotalSelfBondSpent + dblTotalParentBondSpent;

    // Calculate the money left over 
    dblResultTotal = dblRemainingTotalIncome - dblTotalSelfBondSpent;

    // Step Three: Display the income before and after taxes
    cout << "Results" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << setfill('.') << left << setw(40) << "Total Income Before Tax: " << right << "$"  << intTotalIncomeBeforeTax << endl;
    cout << setfill('.') << left << setw(40) << "Total Income After Tax: " << right << fixed << setprecision(2) << "$" << dblTotalIncomeAfterTax << endl;

    // Step Four: Display the money spent on clothes and other accessories
    cout << setfill('.') << left << setw(40) << "Total Spent on Accessories: " << right << fixed << setprecision(3) << "$" << dblTotalAccessorySpent << endl;

    // Step Five: Display the money spent on school supplies
    cout << setfill('.') << left << setw(40) << "Total Spent on School Supplies: " << right << fixed << setprecision(4) << "$" << dblTotalSchoolSupplySpent << endl;

    // Step Six: Display the money spent to buy savings bonds
    cout << setfill('.') << left << setw(40) << "Total Spent on Self Bonds: " << right << fixed << setprecision(3) << "$" << dblTotalSelfBondSpent << endl;
    cout << setfill('.') << left << setw(40) << "Total Spent on Parent Bonds: " << right << fixed << setprecision(3) << "$" << dblTotalParentBondSpent << endl;
    cout << setfill('.') << left << setw(40) << "Total Spent Bonds: " << right << fixed << setprecision(3) << "$" << dblTotalBondSpent << endl;
    cout << setfill('.') << left << setw(40) << "Total Remaining Income: " << right << fixed << setprecision(3) << "$" << dblResultTotal << endl;
    cout << endl;
    // Return to exit method
    return 0;
}
