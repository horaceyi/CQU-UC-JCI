// Lab6_A_Horace_20186103.cpp
// June 28, 2019 
// Creator: Horace
// Description: This programme will start with the program that we created in Lab 03 Part D (Wk 14) 

#include<iostream>
#include<cmath>
#include <fstream> 
using namespace std;

namespace Global
{
	extern double g = 9.80665;
	double y(double y0, double v0, double t)
	{
		double height = y0 + v0 * t - 0.5 * g * pow(t, 2);
		return height;
	}
}

int main() 
{
	ifstream InputA;
	InputA.open("InputA.txt");
	if (!InputA.is_open()) 
	{
		cout << "Error-You can'y open this file correctly!" << endl; 
		return 0; 
	}
	double v0, y0;
	string text;
	InputA >> text >> v0 >> text; InputA >> text >> y0; InputA.close();
	ofstream OutputA;
	OutputA.open("OutputA.txt");
	cout << "The initial velocity is 60 m/s.\nThe initial height is 50 m.\n";
	cout << "Time(s)\t\t\tHeight(m)\n";
	OutputA << "The initial velocity is 60 m/s.\nThe initial height is 50 m.\n";
	OutputA << "Time(s)\t\t\tHeight(m)\n";
	double t = 0, tmax = 0; double ymax = 0;
	while(true) 
	{
		double y = Global:: y(y0, v0, t);
		if (y < 0) 
		{ 
			cout << t << "\t\t\t" << 0 << endl;
			OutputA << t << "\t\t\t" << 0 << endl;
			break; 
		}
		else 
		{ 
			cout << t << "\t\t\t" << y << endl; 
			OutputA << t << "\t\t\t" << y << endl;
		}
		if (y > ymax) 
		{ 
			ymax = y; 
			tmax = t;
		}
		t++;
	}
	cout << "Total Time: " << t << "-seconds\n";
	cout << "Maximum Height: " << ymax << " @ " << tmax << "-seconds";
	OutputA << "Total Time: " << t << "-seconds\n";
	OutputA << "Maximum Height: " << ymax << " @ " << tmax << "-seconds";
	OutputA.close();
	return 0;
}