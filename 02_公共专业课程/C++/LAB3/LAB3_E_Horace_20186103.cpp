//  Lab3_E_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to create a table of metal expansion versus temperature

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
	double x, w, t;
	int T;

	cout << "Width: ";
	cin >> w;
	cout << "Tolerence: ";
	cin >> t;
	cout << "Temperature" << "\t\t\t" << "Width" << "\t\t\t" << "Within Tolerance" << endl;

	for (T = 60;T <= 85;T++)
	{
		x = w + 0.0001 * (T - 70);
		cout << T << "\t\t\t" << fixed << setw(11) << setprecision(7) << x;
		if (x > w - t && x < w + t)
			cout << "\t\t\t*";
		cout << endl;
	}
	return 0;
}