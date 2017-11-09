//
//  main.cpp
//  Sort.cpp
//
//  Created by Dale Rico on 2/4/15.
//  Copyright (c) 2015 Dale Rico. All rights reserved.
//

#include <iostream>

using namespace std;


void numberSort(int collection [], int size);
//Declare function for sorting


int main() {
//main function
    int ArraySize;
    
    cout << "Please enter the size of array you would like to use." << endl; //Ask user to input desired array size
    cin >> ArraySize;
    
    int collection[ArraySize];
    
    cout << "Please insert " << ArraySize << " integers."<< endl; // Asks user to input desired integers
    
    for (int a = 0; a < ArraySize; a++) //For loop is for the input of the array integers
        cin >> collection[a];
   
    numberSort(collection, ArraySize);
    
    cout << "After the array is sorted, the collection is listed as: " << endl;
    
    for (int b = 0; b < ArraySize; b++) //Sorted array output
        cout << collection [b]<< " ";
        cout << endl;
    
    if(ArraySize % 2 == 0)
    {
        cout << "The median of the array is: " << collection[(ArraySize/2 - 1)]<< endl; //Searches for the median of an even number array size
                                                               
    }
    
    else if (ArraySize % 2 != 0)
    {
        cout << "The median of the array is: " << collection[(ArraySize/2)]<< endl; //Searches for the median of an odd number array size
    }
    return 0;
}

void numberSort(int collection[], int size) //Bubble Sort function
{
    int temp;
    
    
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size + 1; j++)
            if (collection[i] > collection[j])
            {
                temp = collection[i];
                collection[i] = collection [j];
                collection[j] = temp;
            }
        
    }
}

