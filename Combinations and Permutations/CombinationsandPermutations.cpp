/*  You are to write a C++ program to prompt for and read two integers: n and k.  The number n is the number of items in a collection - like 52 for a deck of cards.  The number k is the number of items to select from the collection - like 5 for a poker hand.

Your goal is print the number of permutations of n things taken k at a time and the number of combinations of n things taken k at a time.  The number of permutations is generally greater since combinations ignore order.

Let's support you are dealing cards.  Then there are 52 choices for the first card.  After dealing the first card there are 51 choices for the second card.  After dealing 2 cards there are 50 choices for the third card, ...

So we see that there are P = 52*51*50*49*48 possible permutations.

Now if we don't care about the order of the dealing there are few possible choices (combinations).  You would divide P by the number of different ways you can order 5 things.  The number of different orderings of 5 things is 5*4*3*2*1.

So we get the number of combinations: C = 52*51*50*49*48/(5*4*3*2*1)

You need to write functions to compute the number of permutations and the number of combinations.

You will have a moderately small limit on n and k if you use int for the types for your variables.  You can compute larger values using the C++ type long which is an 8 byte integer    */

#include <iostream>
using namespace std;

long per(long, long);               //The prototype functions to be used are declared
long combo(long);


int main() {

    long n, k, permutation, combination ;           //Declaring the variables that would be used in the program
    
    cout << "Please enter the number of items in a collection: ";  //Ask the user to input the following number of items in a
                                                                   //collection
    cin >> n;
    cout << n << endl;
    
    cout << "Please enter the number of items to select from the collection: "; //Ask user to input number of items to select from
                                                                                // the collection
    cin >> k;
    cout << k << endl;
    
    permutation = per(k, n);            //Call the per function
    combination = per(k, n)/combo (k);  //Call the per function and combo function then divide per by combo
    
    cout << "The number of permutations of " << n << " things taken "<< k << " at a time equals: " << permutation << " ." << endl;
    cout << "The number of combinations of " << n << " things taken "<< k << " at a time equals: " << combination << " ." << endl;
    //Outputs the calculations of permutation and combination respectively
    
    return 0;
}

long per (long k, long n){
    long P = 1;                             //Initializing the value of P
    for (int i = 0; i < k; i++)             //For loop to calculate P = (n-0)*(n-1)*...*(n-k-1)
    { P *= (n - i);}
    
    return P;                               //Returns the value of P to per(k,n)
}
long combo (long k){
    long Q = 1;                             //Initialize the value of Q
    for (long i = k; i > 0; i--)            //For loop to calculate Q = (Q*k-1)*(Q*k-2)*...*(Q*1)
    { Q *= i;}
    
    return Q;                               //Returns the value of Q to combo(k)
}