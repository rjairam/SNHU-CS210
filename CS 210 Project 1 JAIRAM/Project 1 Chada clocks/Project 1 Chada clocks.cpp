/*
Name: Ria Jairam
Project: Chada Clocks
Date: November 15, 2024

This program will output two clocks based on user input. One is a 12 hour clock and the other 24 hours.
*/


//Keeping it simple - just need iostream and vector
#include <iostream>
#include <vector>

using namespace std;


//Print clock outlines
void printClockOutline() {
    //27 '*'
    for (int i = 0; i < 27; i++) {
        cout << "*";
    }
}

//The main menu. 
char mainMenu() {
    char menuChoice; //Menu choice is char, so we can capture non numeric characters.

    //print the menu.
    cout << endl;
    printClockOutline();
    cout << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    printClockOutline();
    cout << endl;
    cout << "Enter a choice 1-4: ";

    //get the menu choice.
    cin >> menuChoice;

    //return the menu choice
    return menuChoice;

}

//Initialize the clock - prompt the user to enter hours, minutes, seconds.
//It is stored in a vector in 24-hour format.

void initClock(vector<int>& timeVec) {
    cout << "Initialize the clock in 24 hour format." << endl << endl;

    //Hours stored in the vector
    cout << "Enter hours: ";
    cin >> timeVec[0]; 

    //Checking for valid input and prompting the user if input is invalid
    while (timeVec[0] < 0 || timeVec[0] > 23) {
        cout << "Enter a valid hour between 0 and 23: ";
        cin >> timeVec[0]; 
    }

    //Minutes stored in a vector
    cout << "Enter minutes: ";
    cin >> timeVec[1];

    //Checking for valid input and prompting the user if input is invalid
    while (timeVec[1] < 0 || timeVec[1] > 59) {
        cout << "Enter a valid minute between 0 and 59: ";
        cin >> timeVec[1];
    }

    //Seconds stored in a vector
    cout << "Enter seconds: ";
    cin >> timeVec[2];

    //Checking for valid input and prompting the user if input is invalid
    while (timeVec[2] < 0 || timeVec[2] > 59) {
        cout << "Enter a valid second between 0 and 59: ";
        cin >> timeVec[2];
    }
}

//Function to process the user's actions
bool processUserAction(char userChoice, vector<int>& timeVec) {

    //Switch statement for the user's choice
    switch (userChoice) {
    case '1': //Add 1 hour. Roll over to 0 if over 23 hours
        if (timeVec[0] < 23) {
            timeVec[0]++;
            cout << "1 hour added" << endl;
        }
        else timeVec[0] = 0;
        break;
    case '2': //Add 1 minute. Rollover to 0 if over 59 minutes
        if (timeVec[1] < 59) {
            timeVec[1]++;
            cout << "1 minute added" << endl;
        }
        else timeVec[1] = 0;
        break;
    case '3': //Add 1 second. Rollover to 0 if over 59 seconds
        if (timeVec[2] < 59) {
            timeVec[2]++;
            cout << "1 second added" << endl;
        }
        else timeVec[2] = 0;
        break;
    case '4':
        return false; // Don't display clocks but return to main for exit.
    default:
        cout << "Enter a valid choice 1-4 only." << endl;
        cin.clear();
        return false; //Return false if invalid value.
        break;
    }
    return true;
}
//This prints the clock spacing. 
void printClockSpacing(){
    cout << "     ";
}

//This prints the 24 hour clock, takes the vector passed in
void printClock24(vector<int>& timeVec) {
    for (int i = 0; i < 3; i++) { //Loop to print out each value stored in the vector
        cout.width(2); //Formatted to 2 digits
        cout.fill('0'); //Fill of 0 leading
        cout << timeVec[i]; 
        if (i < 2) cout << ":";
    }

}

//This prints the 12 hour clock, takes the vector passed it
void printClock12(vector<int>& timeVec) {
    int hour = 0; // Temp variable to store the 12 hour converted hour

    if (timeVec[0] > 12) hour = timeVec[0] - 12; // 12-23 hours are stored as 12 hour value
    else if (timeVec[0] == 0 || timeVec[0] == 12) hour = 12; //If hours are 0 OR 12, 12 is stored in the hour value
    else if (timeVec[0] < 12) hour = timeVec[0]; // If hours are less than 12, they're stored as-is in the hour value
   

    cout.width(2);
    cout.fill('0');
    cout << hour << ":"; //print the hour with width 2 and leading 0

    cout.width(2);
    cout.fill('0');
    cout << timeVec[1] << ":"; //print the minute with width 2 and leading 0

    cout.width(2);
    cout.fill('0');
    cout << timeVec[2]; //print the seconds with width 2 and leading 0

    if (timeVec[0] >=12) {
        cout << " PM"; // If original hours from 12-23, print PM
    }
    else if (timeVec[0] < 12 && timeVec[0] >= 0) {
        cout << " AM"; // If original hours 0-11, print AM
    }
    
}

//Display the clocks - this will format and display the clocks. Takes vector as input.
void displayClocks(vector<int>& timeVec) {
    printClockOutline(); //Print the '*' at the top for 12 hour
    printClockSpacing(); //Insert the spacing between the 12 and 24h clocks
    printClockOutline(); //Print the '*' at the top for 24 hour
    cout << endl;
    cout << "*      12-Hour Clock      *"; //Print for 12 hour
    printClockSpacing(); //Insert the spacing between the 12 and 24h clocks
    cout << "*      24-Hour Clock      *" << endl; //Print for 12 hour
    cout << "*       "; // Border '*'
    printClock12(timeVec); //Print the 12 hour clock
    cout << "       *"; // Border '*'
    printClockSpacing(); //Insert the spacing between the 12 and 24h clocks
    cout << "*         "; // Border '*'
    printClock24(timeVec); //Print the 24 hour clock
    cout << "        *"; // Border '*'
    cout << endl;
    printClockOutline(); //Print the '*' at the top for 12 hour
    printClockSpacing(); //Insert the spacing between the 12 and 24h clocks
    printClockOutline(); //Print the '*' at the top for 12 hour

    cout << endl;
}



int main()
{
    int userChoice = '0'; // Initialize the menu user choice to '0'. It's a char. 
    
    vector<int> timeVec = { 0, 0, 0 }; //We're using a vector. H, M, S as elements.

    initClock(timeVec); // Call function to ask user to input initial time
    
    while (userChoice != '4') { //While loop which will exit if the choice '4' is entered

        userChoice = mainMenu(); // Call the function for main menu

        //Display clocks only if there is a valid command. 
        if (processUserAction(userChoice, timeVec)) displayClocks(timeVec);
           
    }

    return 0;
}