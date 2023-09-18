//  Lab2_B_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to set up a time value and approximate the freezer temperature.
#include <iostream>
#include <string>
using namespace std;

// Set up three different functions for a,b
double formula(double a, double b)
{
	return a+b/60;
}

// Cauculate the results of formula 1,formula 2,and formula 3
int main()
{
	int a, b;
	cout << "Enter hours:  " << endl;
	cin >> a;
	cout << "Enter minutes:  " << endl;
	cin >> b;
	double t = formula(a, b) ;
	double FT = 4 * pow(t, 2) / (t + 2) - 20;
	cout << "Approximate temperature: " << FT << " F" << endl;
	return 0;
}