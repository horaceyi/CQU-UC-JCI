//  Lab3_C_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to display a solidly filled rectangle of the width and height given by the user using the chosen character.

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<string> 
using namespace std;

int main()
{
	string inside, outside;
	int width, height;
	cout << "Width: ";
	cin >> width;
	cout << "Height: ";
	cin >> height;
	cout << "Outside Character: ";
	cin >> outside;
	cout << "Inside Character: ";
	cin >> inside;

	for (int i = 1; i <= width; i++)
	{
		cout << outside;
	}
	cout << endl;
	
	for (int j = 2; j <= height - 1;j++)
	{
		cout << outside;
		for (int i = 2; i <= width - 1; i++)
		{
			cout << inside;
		}
		cout << outside << endl;
	}

	for (int i = 1; i <= width; i++)
	{
		cout << outside;
	}
	cout << endl;
}