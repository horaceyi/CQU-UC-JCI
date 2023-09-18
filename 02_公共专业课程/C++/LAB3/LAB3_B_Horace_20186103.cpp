//  Lab3_B_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to allows the user to enter floating-point numbers greater than zero, adds these numbers and prints the sum.

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	double number = 1, total = 0;
	while (number > 0) 
	{
		cout << "Enter positive number to add or enter zero or negative number to end:  ";
		cin >> number;
		total += number;
	}
	cout << "Sum of entered numbers: " << total;
}