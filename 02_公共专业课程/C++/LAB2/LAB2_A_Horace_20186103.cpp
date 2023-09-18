//  Lab2_A_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to set up four different values for a,b,c,d and calculate the fesults for three different formulas.
#include <iostream>
#include <string>
using namespace std;

// Set up three different functions for a,b,c,d
double formula1(double a, double b, double c, double d)
{
	return (a + b + c) / (2 * a * c);
}
double formula2(double a, double b, double c, double d)
{
	return pow(a,2)/b+c/d*(a+b);
}
double formula3(double a, double b, double c, double d)
{
	return pow(a,(2+b+c))+a-c+4;
}

// Cauculate the results of formula 1,formula 2,and formula 3
int main()
{
	int a, b, c, d;
	cout << "What is the value of a? " << endl;
	cin >> a;
	cout << "What is the value of b? " << endl;
	cin >> b;
	cout << "What is the value of c? " << endl;
	cin >> c;
	cout << "What is the value of d? " << endl;
	cin >> d;
	cout << "Formula 1: " << formula1(a, b, c, d) << endl;
	cout << "Formula 2: " << formula2(a, b, c, d) << endl;
	cout << "Formula 3: " << formula3(a, b, c, d) << endl;
	return 0;
}