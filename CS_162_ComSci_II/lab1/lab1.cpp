// This is the Lab1 / Budget Control in Shopping Cart (lab1.cpp)
// Written by: Joseph Kramer
// Class: CS162
// Date: 06/26/14
// Sources: Text Book & D2L Videos
// Sources: http://mathbits.com/MathBits/CompSci/looping/dowhile.htm


#include <iostream>

using namespace std;

// CONSTANTS
const int iCHAR_MAX = 101;

// Prototype
void getString (char str[], int capacity);
void getYesOrNo (char& r_YesOrNO);
void checkBudget (double& r_total, double budget, double price, char& r_cCorrectProductAndPrice, char& r_cAskToLeave, char& r_cKeepGoing);
void pause();
double getDouble();


int main () {

	// Variables
	char	a_cProduct[iCHAR_MAX];
	char	cKeepGoing = 'y';
	char	cCorrectBudget = 'n';
	char	cCorrectProductAndPrice = 'n';
	char	cCorrectPrice = 'n';
	char	cAskToLeave = 'n';
	double	dPrice;
	double	dRunningTotal = 0;
	double	dDailyBudget = 0;
	
	cout << "Welcom to Joe's Budget Control System 1.0!" << endl;
	
	while (cKeepGoing == 'y') {

		while (cCorrectBudget == 'n') {
		cout << "\nWhat is your budget today? $";
		dDailyBudget = getDouble();
		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << "You entered *** $" << dDailyBudget << " *** Is that correct? (Y)es or (N)o: ";
		getYesOrNo(cCorrectBudget);
		} // end cCorrectBudget loop

		while (cCorrectProductAndPrice == 'n') {
		cout << "\nPlease enter the Product name ex. Milk:  ";
		getString(a_cProduct, iCHAR_MAX);
		cout << "Please enter the price i.e. 12.24: $" ;
		dPrice = getDouble();
		cout << "You entered *** " << a_cProduct << " for $" << dPrice << " *** Is that correct? (Y)es or (N)o: ";
		getYesOrNo(cCorrectProductAndPrice);
		} // end cCorrectProduct while loop

		dRunningTotal += dPrice;	// Tracks the running total
		checkBudget(dRunningTotal, dDailyBudget, dPrice, cCorrectProductAndPrice, cAskToLeave, cKeepGoing);
	
		if (cAskToLeave == 'n') {
		cout << "Would you like to add another product? ";
		getYesOrNo(cKeepGoing);
		} // end cAskToLeave IF Statement

		if (cKeepGoing == 'y') {
			cCorrectProductAndPrice = 'n';
		} // end cKeepGoing IF Statement

	} // end cKeepGoing main while loop

	cout << "\n Thank you for using Joe's Budget System 1.0!" << endl;
	cout << " ********************************************* " << endl;
	cout << " Grand Total: $" << dRunningTotal << endl;
	cout << " ********************************************* " << endl;
	cout << " HAVE A NICE DAY!\n" << endl;

	pause();	
	return 0;
}
	
/*
This functions returns a string from parameter.
in: a_cProduct & capacity
out: str --> a_cProduct
*/		
void getString (char str[], int capacity) {
	cin.get(str, capacity, '\n');

	while(!cin) {
		cin.clear();
		cin.ignore(iCHAR_MAX, '\n');
		cout << "Invalid Entry, Please Try Again: ";
		cin.get(str, capacity, '\n');
	}
	cin.ignore(iCHAR_MAX, '\n');
}
	
/*
This function returns a double floating point number.
return: value
*/
double getDouble () {
	double	value;
	cin >> value;

	while (!cin) {
		cin.clear();
		cin.ignore(iCHAR_MAX, '\n');
		cout << "Please enter a valid number! i.e. 12.00 or 24.25: ";
		cin >> value;
	}
	cin.ignore(iCHAR_MAX, '\n');
	return value;
}

/*
This functions returns a character of 'y' or 'n' via refernce.
in: r_YesOrNo --> which is referenced in by the calling fucntion
out: r_YesOrNo via refernce
*/	
void getYesOrNo (char& r_YesOrNO) {
	char	yesno;
	cin >> yesno;
	while ((yesno !='Y')&&(yesno !='N')&&(yesno !='y')&&(yesno !='n')) {
		cin.clear();
		cin.ignore(iCHAR_MAX, '\n');
		cout << "Please enter either (Y)es or (N)o ";
		cin >> yesno;
	}
	r_YesOrNO = yesno;
	cin.ignore(iCHAR_MAX, '\n');
}

/*
This functions determines total speding compared to the budget.
in: total & budget
out: warnings between 90% of budget, 100% of budget and greater than 100% of budget
*/	
void checkBudget (double& r_total, double budget, double price, char& r_cCorrectProductAndPrice, char& r_cAskToLeave, char& r_cKeepGoing) {
	if (r_total > budget) {
		cout << "\n **** ALERT *** *** ALERT *** " << endl;
		cout << "You are now $" << (budget - r_total)*-1 << " over your daily budget of $" << budget << endl;
		cout << "Would you like to keep this item? (Y)es or (N)o: ";
		getYesOrNo(r_cCorrectProductAndPrice);
		if (r_cCorrectProductAndPrice == 'n') {
			r_total = r_total - price;
			cout << "************" << endl;
			cout << "Item Removed" << endl;
			cout << "************" << endl;
		}
		cout << "Would you like to exit the program? (Y)es or (N)o: ";
		getYesOrNo(r_cAskToLeave);
		if (r_cAskToLeave == 'y') {
			r_cKeepGoing = 'n';
		}
	} 
	else if (r_total == budget) {
		cout << "\n **** WARNING *** *** WARNING *** " << endl;
		cout << "You have reach your daily budget of $" << budget << endl;
		} 
	else if  (r_total >= (budget *.9)) {
		cout << "\n **** WARNING *** *** WARNING *** " << endl;
		cout << "You are $" << budget - r_total << " away from your daily budget of $" << budget << endl;
	}
}

void pause() {
	char	ch;
	cout << "Press any key to Quit...";
	cin >> ch;
}






