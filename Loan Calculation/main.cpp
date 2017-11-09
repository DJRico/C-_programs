/*You are to write a program to compute the payoff time for a loan.  The inputs to the program are the amount that the person will borrow, the annual percentage rate, and the amount that the person wants to pay as monthly payments.

Le'ts suppose that the annual percentage rate is 6% and the amount to borrow is $100,000.   Then the monthly interest rate will be 0.5%.

After one month the interest will be 0.005 * 100000 or $500.

If the person's desired monthly payment is less than the first month's interest, your program should report that the monthly payment is too low to ever pay off the loan and exit.

If the desired monthly payment is larger, then your program should present a table of loan balance information:

Month  Loan balance start   Interest   Payment  Loan balance end
-----  ------------------   --------   -------  ----------------
1      100000.00          500.00    1000.00      99500.00
2       99500.00          497.50    1000.00      98997.50
3       98997.50          494.99    1000.00      98492.49
...

Your report should continue until the loan balance at the end of the month is 0.00.  This will mean that the final payment will be equal to the principal plus the interest for the final month. */
 
#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    int month, arate;
    double balancestart, interest, payment, balanceend;
    
    cout << "Enter amount to borrow, annual percentage rate, and payment amount: "; // ask for loan, annual percent rate = 6%, and payment amount
    cin >> balancestart >> arate >> payment;
    
    month = 0;
    interest = balancestart * 0.005;
    arate = arate/100.00;
    interest = balancestart * 0.005;
    balanceend = balancestart - (payment-interest);
    if (payment < interest) {
        cout << "Monthly payment is too low to pay off loan." << endl; // Ends program if payment is lower than interest
    }
    else if (payment > interest){
        
    cout << setw(5)<< "Month" << "   ";
    cout << setw(18) << "Loan balance start" << "   ";
    cout << setw(8) << "Interest" << "   ";
    cout << setw(7) << "Payment" << "   ";                                          // Sets up the table
    cout << setw(16) << "Loan balance end" << endl;
    
    cout << setw(5)<< setfill('-') << "" << "   ";
    cout << setw(18) << setfill('-') << "" << "   ";
    cout << setw(8) << setfill('-') << "" << "   ";
    cout << setw(7) << setfill ('-') << "" << "   ";
    cout << setw(16) << setfill('-') << ""<< endl;
    
    while(balanceend>= 0) {
        month++;
        
        cout << fixed << setprecision (2) << showpoint;                         // Outputs the calculation loop
        cout << setw(5) << setfill (' ') << month << "   ";
        cout << setw(18) << setfill (' ') << balancestart <<"   ";
        cout << setw(8) << setfill (' ') << interest <<"   ";
        cout << setw(7) << setfill (' ') << payment <<"   ";
        cout << setw(16) << setfill (' ') << balanceend <<"   "<< endl;
        
        balancestart = balanceend;
        interest = 0.005 * balancestart;
        balanceend = balancestart - (payment-interest);
    }
    }
    return 0;
}
