//  Lab1_G_Horace_20186103.cpp
//  May 11, 2019
//  Creator: Horace
//  Addition program. 
#include <iostream>
#include <string>
using namespace std;

// function main begins program execution 
int main()
{
	int option;
	int Nbad;
	double tS;
	double tT;
	double WV;
	double ymax = 0.085;
	double Nmanu = 1e6;
	double kSn = 8e4;
	double kTn = 5e5;
	double WS = 500;
	double kS;
	double kT;
	double y1;
	double y2;
	double yTotal;

	int yes = 1;
	while (yes == 1)
	{
		cout << " Welcome to the menu example!Which option would you like to select ? " << endl;
		cout << "1: Small Car" << endl;
		cout << "2: Large Car" << endl;
		cout << "3: Truck" << endl;
		cout << "4: Exit" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			WV = 15244.7;
			cout << "WV is  " << WV << endl;
			break;
		case 2:
			WV = 21434.9;
			cout << "WV is  " << WV << endl;
			break;
		case 3:
			WV = 23838.3;
			cout << "WV is  " << WV << endl;
			break;
		default:
			cout << "Goodbye!" << endl;
			break;
		}

		Nbad = 0;
		cout << " What is the spring tolerance?  ";
		cin >> tS;
		tT = tS;

		for (int n = 1; n < Nmanu && yes == 1; n++)
		{
			kS = kSn + kSn * tS * (2 * rand() % 2 + 1 - 3) * (rand() % 1000 + 1) / 1000;
			kT = kTn + kTn * tT * (2 * rand() % 2 + 1 - 3) * (rand() % 1000 + 1) / 1000;
			y1 = 0.25 * WV / kS;
			y2 = (0.25 * WV + WS) / kT;
			yTotal = y1 + y2;
			if (yTotal > ymax)
			{
				Nbad = Nbad + 1;
			}
			if (Nbad >= 0.05 * Nmanu)
			{
				cout << "The number of bad results" << endl;
				cout << "exceeds manufacturer allowance" << endl;
				break;
			}
		}
		cout << "The number of  bad results is " << Nbad << endl;
		cout << "The number of good results is " << Nmanu - Nbad << endl;

		cout << "Do you want to do this again?" << endl;
		cout << "Please input 1 for yes or 0 for no~" << endl;
		cin >> yes;
	}
		return 0;
}