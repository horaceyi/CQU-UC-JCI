//  Lab4_A_Horace_20186103.cpp
//  June 2, 2019
//  Creator: Horace
//  Description: This programme is used to  a function that takes a type double array with three parameters.
//  The first two numbers are the numbers to compare. The last parameter is the ¡°Delta¡±. 
//  The function returns a true if the two parameters lay between the plus/minus of said third ¡°Delta¡± parameter.

#include<iostream>
using namespace std;

bool compareDelta(double array[3]) 
{
	if (array[0]<array[1] + array[2] && array[0] > array[1] - array[2] && array[1]<array[0] + array[2] && array[1] > array[0] - array[2])
	{
		cout << "This set of numbers would return a ture.";
	}
	else 
	{
		cout << "This set of numbers would return a false."; 
	}
	return 0;
}

int main() {
	double array[3];
	cout << "Number1: ";
	cin >> array[0];
	cout << "Number2: ";
	cin >> array[1];
	cout << "Delta: ";
	cin >> array[2];
	compareDelta(array);
	return 0;
}