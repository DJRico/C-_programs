//Payroll Program
// by Dale Rico
// CSC 101 Dr. Glenn Bond
/*
 
 The employee's pay information should be reported like this:
 
 Name                Hours worked   Pay rate   Gross Pay   Social Security   Income Tax   Net Pay
 -----------------   ------------   --------   ---------   ---------------   ----------   -------
 Jim Jones                30.0        10.00      300.00          16.50          30.00      253.50
*/



#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
int main()
{
    string fname, lname;
    
    fname = "Jim" ;         //employee's first name
    lname = "Jones" ;       //employee's last name
    
    
    
    double hrlrate, hworked;
    
    hrlrate = 10.00;        //pay rate of the employee
    hworked = 30.0;         //hours worked by the employee
    
    
    float gPay, sSecurity, iTax, nPay;
    
    if (hworked > 40)                   //setting a condition that if hours worked is > 40 gPay is accomplished by using the equation below
    {
        gPay = 40.0 * hrlrate + 1.50 * hrlrate * (hworked - 40);
    }
    
    else if (hworked <= 40.00)          // gPay is found by rate * hours if hours worked was < 40
    {
        gPay = hrlrate * hworked;
        
    }
    
    sSecurity = gPay * 0.055;
    
    if (gPay <= 100.00)         //social security is taken from 5.5% of gPay
    {
        iTax = 0;
        
    }
    
    else if (100.01 <= gPay)  //income tax is resolved depending on the gPay of the employee
    {
        iTax = gPay * 0.10;     //gPay is >= 100.01, income tax is 10%
    }
    
    else if (gPay > 500.00)     //gPay is > 500, income tax is 20%
    {
        iTax = gPay * 0.20;
    }
    
    nPay = gPay - (sSecurity + iTax); //nPay is found by subtracting the total of sSecurity and iTax from gPay
    
    //Below is assorting the cout to show the same output as the printed example on the top page
    
    cout << left << setw (17) << "Name" << "   " << setw(12) << "Hours worked" << "   " << setw(8) << "Pay rate" << "   " << setw(9) << "Gross Pay" << "   " << setw(15) << "Social Security" << "   " << setw(10) << "Income Tax" << "   " << setw(7) << "Net Pay" << endl;
    
    cout.unsetf(ios::left);
    cout << setfill('-');
        cout << setw(20) << "   " << setw(15) << "   " << setw(11) << "   " << setw(12) << "   " << setw(18) << "   " << setw(13) << "   " << setw(10) << "   "<< endl;
    
    cout << setfill (' ');
    cout << left << fname << " " << setw (18)<< lname << "   " << setw(12) << fixed << setprecision (1) << hworked << fixed << setprecision (2) << setw(8) << hrlrate <<"   " << setw(9) << gPay <<"       "<< sSecurity << setw(10) << "    "<< setw(10) << iTax << " " <<  setw(7) << nPay << endl;
    

return 0;
}
