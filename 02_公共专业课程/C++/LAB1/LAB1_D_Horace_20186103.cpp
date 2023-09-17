//  Lab1_D_Horace_20186103.cpp
//  May 11, 2019
//  Creator: Horace
//  Addition program. 
#include <iostream>
#include <string>
using namespace std;

// function main begins program execution 
int main()
{
	double EdgeLength;
	double SurfaceArea;
	double Volume;

	cout << "Enter Edge Length:";
	cin >> EdgeLength;

	SurfaceArea = 6 * pow(EdgeLength,2);
	Volume = pow(EdgeLength,3);

	cout << "Surface Area is  " << SurfaceArea << endl;
	cout << "Volume is  " << Volume << endl;
	return 0;
}