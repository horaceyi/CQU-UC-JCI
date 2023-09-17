//  Lab2_E_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to takes in a pair (x, y) and determines the quadrant of said pair. 
#include <iostream>
#include <string>
using namespace std;

// Set up a function to judge the type of substance 
void judge(double x,double y)
{
	if (x > 0 && y > 0)
	{
		cout << "Pair is located in quadrant 1 " << endl;
	}
	else if (x < 0 && y > 0)
	{
		cout << "Pair is located in quadrant 2 " << endl;
	}
	else if (x < 0 && y < 0)
	{
		cout << "Pair is located in quadrant 3 " << endl;
	}
	else if (x > 0 && y < 0)
	{
		cout << "Pair is located in quadrant 4 " << endl;
	}
	else if (x = 0 && y != 0)
	{
		cout << "Pair is located on Y-axis " << endl;
	}
	else if (y = 0 && x != 0)
	{
		cout << "Pair is located on X-axis " << endl;
	}
	else
	{
		cout << "Pair is located on origin " << endl;
	}
}

// Judge the type of substance 
int main()
{
	double x,y;
	cout << "Enter pair (x, y):  " << endl;
	cin >> x >> y;
	judge(x, y);
}