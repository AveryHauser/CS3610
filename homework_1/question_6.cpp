/*
* Write a program to find the mean and standard deviation of numbers. The
* mean (average) of n numbers x1, x2, . . ., xn is x ¼ (x1 + x2 + .. . + xn) / n.
* The standard deviation of these numbers is as follows:
*
* When you complie use the following two lines
* g++ -Wall question_6.cpp
* ./a.out
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){

    //creates a vector to store data points
    vector<double> data;
    double mean = 0;

    char choice = 'D';
    cout << "Welcome to the mean and standard deviation calculator" << endl << endl;
    do{
        cout << "input A to add data point to data set" << endl;
        cout << "input C to calculate data set"<< endl << "Choice: " << endl;
        cin >> choice;
        choice = toupper(choice);

        if (choice == 'A'){
            int num = 0;
            cout << "Input data point: " << endl;
            cin >> num;
            data.push_back(num);
        }

    }while(choice != 'C');

    //adds all of the data points together
    for (int i = 0; i < data.size(); i++){
        mean += data[i];
    }
    //divides the sum of data points by the number of data points and gets the mean
    mean = mean/data.size();

    double sd = 0;
    //does the sumation work for calculating standard diviation
    for (int i = 0; i < data.size(); i++){
        double sum = 0;
        sum  = pow((data[i] - mean), 2);
        sd += sum;
    }

    //divides the sumation by n - 1 
    sd = sd/(data.size() - 1.0);
    //squart roots all the data
    sd = sqrt(sd);

    //prints eveyrything on the screen
    cout << endl << "Mean: " << mean << endl;   
    cout << "Standard Deviation: " << sd << endl;   
    
    return 0;
}

