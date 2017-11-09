//
//  main.cpp
//  BMI Project
//
//  Created by Dale Rico on 9/17/14.
//  Copyright (c) 2014 Dale Rico. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
    string name;
    name = " " ;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "Nice to meet you " << name << "!" << endl;
    
    double feet, inches;
    cout << "Enter your height as feet and inches with a space separating them." << endl;
    cin >> feet >> inches;
    cout << "Your height is " << feet << " feet " << inches << " inches." << endl;
    
    double pounds;
    cout << "Enter your weight in pounds." << endl;
    cin >> pounds;
    cout << "Your weight is " << pounds << " pounds." << endl;
    
    double height, weight, total;
    height = (12 * feet) + inches;
    weight = pounds;
    total = (703 * weight) / pow(height, 2);
    cout << "Hey "<< name << ", your BMI is " << total << "." << endl;
    
    if (total < 18.5) {cout << "You need to put some meat in dem bones!!!"<<endl;
        
    }
    
    else if (total >= 18.5 && total <= 24.9) { cout << "Wow, way to take care of yourself!"<<endl;
        
    }
    
   else if (total >= 25 && total <= 29.9) {cout << "Work harder, " << name << "!"<<endl;
        
    }
    
    else if (total >= 30) {cout << "You may need to rethink your lifestyle, " << name << "."<<endl;
        
    }
    
    return 0;
}

