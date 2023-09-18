//  Lab4_C_Horace_20186103.cpp
//  June 2, 2019
//  Creator: Horace
//  Description: This programme is used to calculate the electric field for an insulating sphere of charge.

#include<iostream>
#include<cmath>
using namespace std;

int main() 
{
	double Q = pow(10, -9), ke = 9 * pow(10, 9), r, a, E;
	cout << "Enter r: "; 
	cin >> r;
	while (r<0||r>100)
	{
		cout << "The r should in the range of 0 to 100 meters(m)\nEnter r again: ";
		cin >> r;
	}
	cout << "Enter a: "; 
	cin >> a;
	if (r<a)
	{
		E = ke * Q * r / pow(a, 3);
	}
	else 
	{
		E = ke * Q / pow(r, 2);
	}
	cout << "Efield: " << E;
	return 0;
}