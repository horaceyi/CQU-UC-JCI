// Lab6_B_Horace_20186103.cpp
// June 28, 2019 
// Creator: Horace
// Description: This program will start with the program that you created in Lab 03 Part E (Wk 14) 

#include<iostream>
#include<cmath>
#include <iomanip>
#include <fstream> 
using namespace std;

namespace Global
{
	double expansion(double w, double T)
	{
		double x = w + 0.0001 * (T - 70.);
		return x;
	}
}

int main() 
{
	ifstream InputB;
	InputB.open("InputB.txt");
	if (!InputB.is_open()) {
		cout << "Could not open file" << endl;
		return 0;
	}
	double width, tolerance;
	string text;
	InputB >> text >> text >> width; InputB >> text >> text >> tolerance; InputB.close();
	ofstream OutputB;
	OutputB.open("OutputB.txt");
	cout << "Width: " << width << endl;
	cout << "Tolerance: " << tolerance << endl;
	cout << "Temperature\t\tWidth\t\tWithin Tolerance\n";
	OutputB << "Width: " << width << endl;
	OutputB << "Tolerance: " << tolerance << endl;
	OutputB << "Temperature\t\tWidth\t\tWithin Tolerance\n";
	int T;
	for ( T=40; T < 125; T++)
	{
		double joker = Global::expansion(width, T);
		cout << "    " << T << "\t\t    ";
		OutputB << "    " << T << "\t\t    ";
		cout << fixed << setw(11) << setprecision(7) << joker;
		OutputB << fixed << setw(11) << setprecision(7) << joker;
		if (joker > width - tolerance && joker < width + tolerance) {
			cout << "\t\t\t*";
			OutputB << "\t\t\t*";
		}
		cout << endl; 
		OutputB << endl;
	}
	OutputB.close();
	return 0;
}