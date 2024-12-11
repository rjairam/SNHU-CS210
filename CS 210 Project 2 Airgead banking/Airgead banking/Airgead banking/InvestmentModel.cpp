//We need iostream, string, and iomanip (for formatting)
#include <iostream>
#include <string>
#include <iomanip>

//Include the header for the investment model class
#include "InvestmentModel.h"

using namespace std;

// All setters and getters for variables
    void InvestmentModel::setInitialInvestment(double t_initialInvestment) {
        this->m_initialInvestment = t_initialInvestment;
    }

    double InvestmentModel::getInitialInvestment() {
        return this->m_initialInvestment;
    }

    void InvestmentModel::setMonthlyDeposit(double t_monthlyDeposit) {
        this->m_monthlyDeposit = t_monthlyDeposit;
    }

    double InvestmentModel::getMonthlyDeposit() {
        return this->m_monthlyDeposit;
    }

    void InvestmentModel::setInterestPercentage(double t_interestPercentage) {
        this->m_interestPercentage = t_interestPercentage;
    }

    double InvestmentModel::getInterestPercentage() {
        return this->m_interestPercentage;
    }

    void InvestmentModel::setInvestmentYears(int t_investmentYears) {
        this->m_investmentYears = t_investmentYears;
    }

    int InvestmentModel::getInvestmentYears() {
        return this->m_investmentYears;
    }

    //Method to prompt user for data
    void InvestmentModel::dataInput() {

        //Initialize variables for the opening deposit, monthly, interest rate, number of years
        double openingDeposit = 0.0, monthlyDeposit = 0.0, interestRate = 0;
        int numYears = 0;

        //Print report header
        cout << "********************************" << endl;
        cout << "***********Data Input***********" << endl;
        cout << "Initial Investment Amount: $";

        //Get the opening deposit, check if it's a positive number and then store in a variable
        while (!(cin >> openingDeposit) || openingDeposit < 0.0) {
            cout << "Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        };
        //Set the variable in the object
        this->setInitialInvestment(openingDeposit);

        //Get the monthly deposit, check if it's a positive number and then store in a variable
        cout << "Monthly Deposit: $";
        while (!(cin >> monthlyDeposit) || monthlyDeposit < 0.0) {
            cout << "Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        };
        //Set the variable in the object
        this->setMonthlyDeposit(monthlyDeposit);

        //Get the interest rate, make sure it is a positive number and store in a variable
        cout << "Interest Rate: %";
        while (!(cin >> interestRate) || interestRate < 0.0) {
            cout << "Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        };
        //Set the variable in the object
        this->setInterestPercentage(interestRate);

        //Get the number of years, make sure it is positive integer and store in variable
        cout << "Number of years: ";
        while (!(cin >> numYears) || numYears < 0) {
            cout << "Please enter a positive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        };
        //Set the variable in the object
        this->setInvestmentYears(numYears);

        //Press any key to continue
        system("pause");

    }

    //Method to print the interest report. Boolean parameter for with or without monthly deposits
    void InvestmentModel::interestReport(bool t_withMonthlyDeposits) {

        int numMonths = this->getInvestmentYears() * 12; //Convert number of years to months
        double balance = this->getInitialInvestment(); //Initialize the balance to the initial investment amount
        double yearlyInterest = 0.0; //Initialize yearly interest to 0.0
        double monthlyInterest = 0.0; //Initialize monthly interest to 0.0

        string withOrWithout = (t_withMonthlyDeposits) ? "With" : "Without"; //Modify text based on parameter to say with or without monthly desposit

        //Print header
        cout << "\n Balance And Interest " << withOrWithout << " Monthly Deposits" << endl;
        cout << "==============================================================" << endl;
        cout << "Year \t Year End Balance \t Year End Earned Interest" << endl;
        cout << "--------------------------------------------------------------" << endl;

        //Loop to calculate interest and running balance, starts at month 1
        for (int i = 1; i <= numMonths; i++) {

            //If we are calculating with monthly deposits, add as we go along
            if (t_withMonthlyDeposits) {
                balance += this->getMonthlyDeposit();
            }

            // Call the compound interest method to calculate interest
            monthlyInterest = this->compoundInterestMonth(balance, 0.0, this->getInterestPercentage());
            // Add the monthly compounded interest to the balance
            balance += monthlyInterest;

            //Add the yearly interest separately to the monthly interest
            yearlyInterest += monthlyInterest;

            // Formatting the tables
            cout << fixed;
            cout << setprecision(2);
            
            // If we have a full year, print then reset yearly interest
            if (i % 12 == 0) {
                cout << i / 12 << setw(10)  << "\t$" << balance << setw(20) << "\t$" << yearlyInterest << endl;
                yearlyInterest = 0.0;

            }

        }
    }

    //Method to calculate the compound interest monthly. Private method that is used internally.
    double InvestmentModel::compoundInterestMonth(double t_openingDeposit, double t_monthlyDeposit, double t_interestRate) {
        return ((t_openingDeposit + t_monthlyDeposit) * ((t_interestRate / 100) / 12));
    }
