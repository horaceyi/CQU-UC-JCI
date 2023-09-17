//  Lab2_D_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to characterize possible earthquake damage based on the size of a quack measured on the Richter Scale.
#include <iostream>
#include <string>
using namespace std;

// Set up a function to judge the type of substance 
void judge(int R)
{
	if (R <= 5)
	{
		cout << "Little damage" << endl;
	}
	else if (R<=5.5&&R>5)
	{
		cout << "Some damage " << endl;
	}
	else if (R<=6.5&&R>5.5)
	{
		cout << "Damage " << endl;
	}
	else if (R<=7.5&&R>6.5)
	{
		cout << "Serious damage " << endl;
	}
	
	else if(R>7.5)
	{
		cout << "Catastrophic damage " << endl;
	}
}

// Judge the type of substance 
int main()
{
	int R;
	cout << "Enter Richter Scale number:  " << endl;
	cin >> R;
	judge(R);
}