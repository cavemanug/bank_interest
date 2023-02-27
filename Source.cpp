/*
This program will calculate earned interest
author: john hamlin
Date: 2/4/23
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;



//function for using character fill
string nCharString(size_t n, char c) {
	string aString = "";
	for (int i = 0; i < n; i++)
		aString += c;

	// return the n character string
	return (aString);
}

//function to print Initial investment amount
void initialInvestment() {
	cout << "Initial Investment Amount: ";
}

//functions to print display statements
void monthlyDeposit() {
	cout << "Monthly Deposit: ";
}

void annualInterest() {
	cout << "Annual Interest: ";
}

void numberOfYears() {
	cout << "Number of years: ";
}

//function to calculate interest into interest variable
double interestAmount(double initInvestAmount, double monDeposit, int annInterest) {
	double interest = (initInvestAmount + monDeposit) * (annInterest / 100.0) / 12;

	return interest;
}

//prints header for display
void menuHead() {
	cout << nCharString(34, '*') << endl;
	cout << nCharString(10, '*') << " Data Input " << nCharString(12, '*') << endl;
}

//prints info without values
void displayBasicInfo() {
	initialInvestment();
	cout << endl;

	monthlyDeposit();
	cout << endl;

	annualInterest();
	cout << endl;

	numberOfYears();
	cout << endl;

	cout << "Press any key to continue . . ." << endl;
	cout << endl;
}

//prints info with values
void displayInfo(double initInvestAmount, double monDeposit, int annInterest, int numYears) {
	initialInvestment();
	cout << fixed << setprecision(2) << initInvestAmount << endl;
	monthlyDeposit();
	cout << fixed << setprecision(2) << monDeposit << endl;

	annualInterest();
	cout << fixed << setprecision(2) << annInterest << endl;

	numberOfYears();
	cout << fixed << setprecision(2) << numYears << endl;

	cout << "Press any key to continue . . ." << endl;
	cout << endl;
}

//prints header for statement balances
void statementHeader() {
	cout << "     Balance and Interest Without Additional monthly deposits" << endl;
	cout << nCharString(68, '=') << endl;
	cout << "    Year            " << "Year End Balance" << "     Year End Earned Interest" << endl;
	cout << nCharString(68, '-') << endl;
}

//main function
int main() {
	double initInvestAmount;
	double monDeposit;
	int annInterest;
	int numYears;
	double total; 
	double interest;
	double totalInterest = 0;
	
	menuHead();

	displayBasicInfo();

	//continues to next statement
	getchar();

	cout << "Enter initial investment" << endl;
	cin >> initInvestAmount;
	
	cout << "Enter monthly deposit" << endl;
	cin >> monDeposit;

	cout << "Enter annual interest" << endl;
	cin >> annInterest;
	
	cout << "Enter number of years" << endl;
	cin >> numYears;

	menuHead();
	displayInfo(initInvestAmount, monDeposit, annInterest, numYears);

	//continues to statement balance
	getchar();

	
	statementHeader();
	
	//calculates interest for each year
	for (int i = 0; i < numYears; i++) {

		//calculates interest for each month
		for (int j = 0; j < 12; j++) {
			interest = interestAmount(initInvestAmount, monDeposit, annInterest);
			initInvestAmount = initInvestAmount + interest;
			totalInterest = totalInterest + interest;
		}
		
		//prints statement balance for each year without monthly deposit
		total = initInvestAmount;
		cout << "     " << i + 1 << setw(30) << fixed << setprecision(2) << total;
		cout << setw(29) << totalInterest << endl;
		cout << endl;
	}

	statementHeader();
	
	//calculates interest for each year with monthly deposit
	for (int i = 0; i < numYears; i++) {

		//calculates interest for each month
		for (int j = 0; j < 12; j++) {
			interest = interestAmount(initInvestAmount, monDeposit, annInterest);
			initInvestAmount = initInvestAmount + monDeposit + interest;
			totalInterest = totalInterest + interest;
		}

		//prints statement balance for each year with monthly deposit
		total = initInvestAmount;
		cout << "     " << i + 1 << setw(30) << fixed << setprecision(2) << total;
		cout << setw(29) << totalInterest << endl;
		cout << endl;
	}

	

}