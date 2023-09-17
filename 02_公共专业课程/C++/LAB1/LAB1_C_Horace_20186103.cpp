//  Lab1_B_Horace_20186103.cpp
//  May 11, 2019
//  Creator: Horace
//  Addition program. 
#include <iostream>
#include <string>
using namespace std;

const double PI = 3.14159265359;

// function main begins program execution 
int main()
{
	double Height;
	double Radius;
	double SurfaceArea;
	double Volume;

	cout << "Enter Height:";
	cin >> Height;

	cout << "Enter Radius:";
	cin >> Radius;

	SurfaceArea = PI * Radius * Radius * sqrt((pow(Height, 2)+ pow(Radius, 2)));
	Volume = PI * pow(Radius, 2) * Height / 3;

	cout << "Surface Area is  " << SurfaceArea << endl;
	cout << "Volume is  " << Volume << endl;
	return 0;
}