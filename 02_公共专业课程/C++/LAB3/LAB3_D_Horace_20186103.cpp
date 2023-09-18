//  Lab3_D_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to creates a table to show the change in height of an object
//  launched straight up for each second from launch time (time zero) until the object reaches the ground.

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string> 
using namespace std;

int main()
{
	int t = 0, tmax;
	double y = 0, V0, ymax=0;
	const double g = 9.80665;

	cout << "Enter the initial velocity V0: ";
	cin >> V0; 
	cout << "Initial Velocity of Object: " << V0 << " m/s" << endl;

	cout << "Time" << "\t\t\t" << "Height" << endl;
	do
	{
		cout << t << "\t\t\t" << y << endl;
		t++;
		y = V0 * t - 1 / 2.0 * g * pow(t, 2);
		if (ymax < y)
		{
			ymax = y;
			tmax = t;
		}
	} 
	while (y >= 0);
	cout << t << "\t\t\t" << 0 << endl;
	cout << "Total Time: " << t << endl;
	cout << "Maximum height: " << tmax << " @ " << tmax << "-second" << endl;
}