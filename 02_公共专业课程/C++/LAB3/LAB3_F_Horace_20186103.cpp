//  Lab3_F_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to calculate factorial and exponential.

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
using namespace std;

int factorial(int);
void Exp(double);

int main()
{
	int n, a;
	cout << "Enter positive integer: ";
	cin >> n;
	a = factorial(n);
	cout << n << "! = " << a << endl;

	int x;
	cout << "Enter value for x: ";
	cin >> x;
	Exp(x);
	return 0;
}

int factorial(int n)
{
	int series = 1;
	if (n == 0)
		return 1;
	else
	{
		for (int i = 1; i <= n; i++)
		{
			series *= i;
		}
		return series;
	}
}

void Exp(double x)
{
	double sum = 0, error, sum_begin, sum_after;
	int m;
	for (m = 0; m < 20; m++)
	{
		sum_begin = sum;
		sum += pow(x, m) / factorial(m);
		sum_after = sum;
		error = abs(sum_after - sum_begin);
		if (error < 0.0001)
		{
			cout << "Solution converged before reaching 20 calculations" << endl;
			break;
		}
	}
	cout << "Number of calculation: " << m << endl;
	cout << "e^" << x << " = " << fixed << setw(11) << setprecision(9) << sum << endl;
}