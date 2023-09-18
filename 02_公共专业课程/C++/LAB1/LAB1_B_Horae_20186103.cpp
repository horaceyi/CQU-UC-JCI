//  Lab1_B_Horace_20186103.cpp
//  May 10, 2019
//  Creator: Horace
//  Addition program. 
#include <iostream>
#include <string>
using namespace std;

// function main begins program execution 
int main()
{
	double Width;
	double Height;
	double Area;
	double Perimeter;

	cout << "Enter Width:";
	cin >> Width;

	cout << "Enter Height:";
	cin >> Height;

	Area = Width * Height;
	Perimeter = (Width + Height) * 2;

	cout << "Area is " << Area << endl;
	cout << "Perimeter is " << Perimeter << endl;
	return 0;
}