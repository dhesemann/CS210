/*
 * CustomerAccount.cpp
 *
 *  Created on: Oct 4, 2020
 *      Author: 1823901_snhu
 */

#include "CustomerAccount.h" //Include header file
#include <iostream> //Include input/output system
#include <ios> //Required for output formatting
#include <iomanip> //Required for output formatting
#include <Windows.h> //Required for capturing key entries
#include <string> //Supports use of "string" data type
using namespace std; //Required namespace that defines cout and cin

void CustomerAccount::displayInitialReport() { //Calculate and display the investment report without monthly deposits
	double currentAmount = m_initialAmount; //establish a placeholder for the balance
	cout << "  Balance and Interest Without Additional Monthly Deposits  " << endl;
	cout << "============================================================" << endl;
	cout << "  Year      Year End Balance      Year End Earned Interest  " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < m_numYears; i++) { //loop through each year
		double totalInterest = 0; //establish a variable to track interest
		for (int j = 0; j < 12; j++) { //loop through months
			double monthlyInterest = currentAmount * (m_annualInterest / 1200); //calculate monthly interest
					currentAmount = currentAmount + monthlyInterest; //calculate balance with interest
					totalInterest = totalInterest + monthlyInterest; //update total interest
		}
		//print the year, balance, and interest for each year
		cout << "   " << i + 1 << "          $" << setprecision(2) << fixed << currentAmount << "                 $" << setprecision(2) << fixed << totalInterest << endl;
	}
	cout << "------------------------------------------------------------" << endl;
}

void CustomerAccount::displayFullReport() { //Calculate and display the investment report without monthly deposits
	double currentAmount = m_initialAmount; //establish a placeholder for the balance
	cout << "  Balance and Interest Without Additional Monthly Deposits  " << endl;
	cout << "============================================================" << endl;
	cout << "  Year      Year End Balance      Year End Earned Interest  " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < m_numYears; i++) { //loop through each year
		double totalInterest = 0; //establish a variable to track interest
		for (int j = 0; j < 12; j++) { //loop through months
			currentAmount = currentAmount + m_monthlyAmount; //add monthly deposit
			double monthlyInterest = currentAmount * (m_annualInterest / 1200); //calculate monthly interest
			currentAmount = currentAmount + monthlyInterest; //calculate balance with interest
			totalInterest = totalInterest + monthlyInterest; //update total interest
		}
		//print the year, balance, and interest for each year
		cout << "   " << i + 1 << "          $" << setprecision(2) << fixed << currentAmount << "                 $" << setprecision(2) << fixed << totalInterest << endl;
	}
	cout << "------------------------------------------------------------" << endl;
}

void dataInputDisplay() { //display the data to input
	cout << "********************************" << endl;
	cout << "***********Data Input***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	cout << "Press C to continue..." << endl;
}

int main() {
	CustomerAccount InvestmentInfo; //create a new customer account
	//declare variables
	double initialAmount;
	double monthlyAmount;
	double annualInterest;
	int numYears;
	char userInput;
	bool tryAgain = true;

	//FIXME: Adjust error handling for incorrect types of input
	while (tryAgain == true) { //while loop to allow the option of multiple tries
		try {
			dataInputDisplay();
			cin >> initialAmount >> monthlyAmount >> annualInterest >> numYears >> userInput; //collect input and assign to variables
			/* My failed attempt at accounting for invalid input types
			 * if (cin.fail()) {
				cin.clear();
				throw runtime_error("Invalid input.");
			}*/
			//Error handling for negative inputs
			if (initialAmount < 0) {
				throw runtime_error("Invalid initial investment.");
			}
			if (monthlyAmount < 0) {
				throw runtime_error("Invalid monthly deposit.");
			}
			if (annualInterest < 0) {
				 throw runtime_error("Invalid annual interest.");
			}
			if (numYears < 1) {
				throw runtime_error("Invalid number of years.");
			}
			/*if (userInput != 'c' || userInput != 'C') {
				throw runtime_error("Invalid input.");
			}*/

			//Assign input values to Customer Account InvestmentInfo
			InvestmentInfo.setInitialAmount(initialAmount);
			InvestmentInfo.setMonthlyAmount(monthlyAmount);
			InvestmentInfo.setAnnualInterest(annualInterest);
			InvestmentInfo.setNumYears(numYears);

			//calculate and output results
			InvestmentInfo.displayInitialReport();
			cout << endl;
			InvestmentInfo.displayFullReport();

		}
		catch (runtime_error& excpt) { //catch errors
			cout << excpt.what() << endl;
		}

		//FIXME: Adjust error handling to account for other input
		cout << "Would you like to try again? (Y/N)" << endl; //Determine whether to continue the loop
		cin >> userInput;
		if (userInput == 'n' || userInput == 'N') {
			tryAgain = false; //exit loop
		}

	}
	cout << "Goodbye.";
}

