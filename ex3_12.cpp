// ----------------------------------------------------------------
// Author: David Teixeira 
// Project: Unit 2 Exercise 3-12
// Course: SDEV-230
// Creation Date: 10/28/2023
// ----------------------------------------------------------------

// Import the Preprocessor Directives
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <limits>

using namespace std;

// Create the constants
const int intMAX_ARRAY_SIZE = 2;
const int intTOTAL_MINUTES_PER_HOUR = 60;

int main() {
    double dblSpeedA, dblSpeedB;
    int dblHours, dblMinutes;
    double dblTimeInHours;
    double dblDistanceA;
    double dblDistanceB;
    double dblShortestDistance;
    char chrSeparator;

    // Getting user input
    cout << "Enter the average speed of Car A (in mph): ";
    cin >> dblSpeedA;

    cout << "Enter the average speed of Car B (in mph): ";
    cin >> dblSpeedB;

    cout << "Enter the elapsed time for the journey (hours and minutes, separated by a space): ";
    cin >> dblHours;
    cin.get(chrSeparator);
    cin >> dblMinutes;
    cout << endl;
    
    // Converting time to hours (as a decimal)
    dblTimeInHours = dblHours + dblMinutes / 60.0;

    // Calculating distances
    dblDistanceA = dblSpeedA * dblTimeInHours;
    dblDistanceB = dblSpeedB * dblTimeInHours;

    // Calculating the shortest distance
    dblShortestDistance = sqrt(pow(dblDistanceA, 2) + pow(dblDistanceB, 2));

    // Display the shortest distance
    cout << fixed << setprecision(2);
    cout << "The shortest distance between the two cars is: " << dblShortestDistance << " miles." << endl;

    return 0;
}

// // ----------------------------------------------------------------
// // Author: David Teixeira 
// // Project: Unit 2 Exercise 2-18
// // Course: SDEV-230
// // Creation Date: 10/28/2023
// // ----------------------------------------------------------------

// // Import the Preprocessor Directives
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// #include <sstream>
// #include <limits>

// using namespace std;

// // Create the constants
// const int intMAX_ARRAY_SIZE = 2;
// const int intTOTAL_MINUTES_PER_HOUR = 60;

// int main() {
//     char achrCars[2] = {'A', 'B'};
//     double aSpeedInputs[intMAX_ARRAY_SIZE];
//     int intMinute, intHour;
//     double dblCarATotalDist, dblCarBTotalDist, dblShortestDist, dblTotalTimeHours;
//     string strTimeInput;

//     cout << "----------------------------------------------------------------" << endl;
//     cout << "You will be prompted to enter two average speeds for both " << endl;
//     cout << "cars A and B, and the total time elapsed." << endl;
//     cout << "----------------------------------------------------------------" << endl;

//     for (int i = 0; i < intMAX_ARRAY_SIZE; ++i) {
//         // Get the Speed
//         cout << "Enter the speed for Car " << achrCars[i] << ": ";
//         while (!(cin >> aSpeedInputs[i])) {
//             cout << "Invalid input. Please enter a number for speed: ";
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         }
//     }

//     // Get the time elapsed
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     cout << "Enter the time elapsed (hours and minutes) (format - HH MM): ";
//     getline(cin, strTimeInput);
//     stringstream ss(strTimeInput);

//     if (!(ss >> intHour >> intMinute)) {
//         cout << "Invalid input. Please enter time in hours and minutes: ";
//         // Clear the error flag and remove the invalid input from the istream 
//         cin.clear(); 
//         // Get the max number of char in stream to ignore and stop discarding char until encountering '\n' character
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     }

//     // Convert time to total hours
//     dblTotalTimeHours = intHour + static_cast<double>(intMinute) / 60;

//     // Calculate the total distance traveled for both cars
//     dblCarATotalDist = dblTotalTimeHours * aSpeedInputs[0];
//     dblCarBTotalDist = dblTotalTimeHours * aSpeedInputs[1];
//     dblShortestDist =  sqrt(pow(dblCarATotalDist, 2) + pow(dblCarBTotalDist, 2));

//     // Display the shortest distance
//     cout << fixed << setprecision(2);
//     cout << "The shortest distance between the two cars is: " << dblShortestDist << " miles." << endl;

//     return 0;
// }