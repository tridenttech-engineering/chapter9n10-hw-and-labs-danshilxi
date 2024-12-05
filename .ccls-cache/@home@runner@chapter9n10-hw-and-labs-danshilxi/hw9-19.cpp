//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, 
        dealerRate / 12, term * 12);    //assign values to calculate payments
    
    //display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" 
        << creditPayment << endl;
    cout << "Total cost thru credit union: $"<< (0.10 +creditPayment * term * 12) << endl;
    cout << "Dealer payment: $"
        << dealerPayment << endl;
    cout << "Total cost thru dealer: $" << (0.04 +dealerPayment * term * 12) << endl;
    
    return 0;
}//end of main function    

    //*****function definitions*****
double getPayment(int prin, double monthRate, int months) {
    double monthPay = 0.0;
    double denominator = (1 - pow(monthRate + 1, -months));
    if (denominator == 0) {
        return -1;
    } else {
        monthPay = prin * monthRate / denominator;
        return monthPay;
    } 
}
    //end of getPayment function//*****function definition*****
