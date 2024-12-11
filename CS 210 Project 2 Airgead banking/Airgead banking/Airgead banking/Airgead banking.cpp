/* Project 2 - Airgead banking
   Ria Jairam
   ria.jairam@snhu.edu
   Created on 11/29/2024 
*/

//Include iostream and the InvestmentModel class and specify the standard namespace
#include <iostream>
#include "InvestmentModel.h"

using namespace std;



int main()
{
    //This variable is declared to allow us to continue the program or quit
    char keepGoing='x';

    //Create an object of type InvestmentModel. 
    InvestmentModel sampleInvestment;

    //Main while loop which allows us to do multiple investment scenarios
    while (keepGoing != 'q' && keepGoing !='Q') {
        sampleInvestment.dataInput(); // Get user data

        sampleInvestment.interestReport(true); //Get the interest report with monthly deposits
        sampleInvestment.interestReport(false); //Get interest report without monthly deposits

        //prompt user for another scenario or q to quit
        cout << "Type any key and enter to do another calculation or q to quit." << endl;  
        cin >> keepGoing;
        

    }
    return 0;
}