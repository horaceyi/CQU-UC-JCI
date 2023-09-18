//  Lab4_B_Horace_20186103.cpp
//  June 2, 2019
//  Creator: Horace
//  Description: This programme is used to as a typical root finding algorithm which is called the Newton-Raphson (Newton) method.

#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

double f, df, i = 0;
const double tolerance = .0001;
vector<double> guess(1);

double polynominal(double x) 
{
	f = pow(x, 4) + 2 * pow(x, 3) - 31 * pow(x, 2) - 32 * x + 60;
	return  f;
}

double derivative(double x) 
{
	df = 4 * pow(x, 3) + 6 * pow(x, 2) - 62 * x - 32;
	return df;
}

double Newton(double x1) 
{
	double dif = 1;
	do{
		if (derivative(x1) == 0)
		{ 
			cout << "Error";
			break; 
		}
	double x2 = x1 - polynominal(x1)/ derivative(x1);
	guess.push_back(x2);
	dif = abs(x2 - x1);
	x1 = x2;
	i++;
	} 
	while (dif > tolerance);
	return 0;
}

int main() 
{
	char yes = 'y';
	while (yes == 'y') 
	{
		cout << "Enter Guess: "; 
		double guess_number; 
		cin >> guess_number;
		while (guess_number > 10 || guess_number < -10) 
{
			cout << "The guess should in the range of -10 to 10.\nEnter Guess again: ";
			cin >> guess_number;
		}
		guess[0] = guess_number;
		Newton(guess[0]);
		cout << "Root: " << guess[i] << endl ;
		cout << "Enter Another Guess y/n? ";
		cin >> yes;
	}
	return 0;
}