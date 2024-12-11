#ifndef INVESTMENTMODEL_H
#define INVESTMENTMODEL_H

using namespace std;



class InvestmentModel{
public:

    //All setters and getters for variables
    void setInitialInvestment(double t_initialInvestment);
    double getInitialInvestment();

    void setMonthlyDeposit(double t_monthlyDeposit);
    double getMonthlyDeposit();
    
    void setInterestPercentage(double t_interestPercentage);
    double getInterestPercentage(); 

    void setInvestmentYears(int t_investmentYears);

    int getInvestmentYears();

    
    //Method to get user input
    void dataInput();

    //Method to print the interest report. Takes a boolean value, true for monthly deposits and false for no monthly deposits
    void interestReport(bool t_withMonthlyDeposits);

private:
    //private member variables
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_interestPercentage;
    int m_investmentYears;

    //Method for compound interest per month. This is private because we don't really need to expose this, it's used for internal calculations
    double compoundInterestMonth(double t_openingDeposit, double t_monthlyDeposit, double t_interestRate);


};

#endif