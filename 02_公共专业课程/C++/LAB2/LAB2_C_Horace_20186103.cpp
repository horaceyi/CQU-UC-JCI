//  Lab2_C_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to determine the type of substance from an observed boiling point.
#include <iostream>
#include <string>
using namespace std;

// Set up a function to judge the type of substance 
void judge(int x)
{
	if (x >= 95 && x <= 105)
	{
		cout << "Your substance is Water" << endl;
	}
	else if (x >= 357*(1-0.05) && x <= 357 * (1 + 0.05))
	{
		cout << "Your substance is Mercury" << endl;
	}
	else if (x >= 1187*(1-0.05) && x <= 1187 * (1 + 0.05))
	{
		cout << "Your substance is Copper" << endl;
	}
	else if (x >= 2193 * (1 - 0.05) && x <= 2193 * (1 + 0.05))
	{
		cout << "Your substance is Silver" << endl;
	}
	else if (x >= 2660 * (1 - 0.05) && x <= 2660 * (1 + 0.05))
	{
		cout << "Your substance is Gold" << endl;
	}
	else if (x >= 95 && x <= 105)
	{
		cout << "Your substance is Water" << endl;
	}
	else
	{
		cout << "Unknow" << endl;
	}
}

// Judge the type of substance 
int main()
{
	int x;
    cout << " Enter boiling point:  " << endl;
	cin >>x;
	judge(x);
}