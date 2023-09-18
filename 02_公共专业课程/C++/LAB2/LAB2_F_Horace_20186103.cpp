//  Lab2_F_Horace_20186103.cpp
//  May 20, 2019
//  Creator: Horace
//  Description: This programme is used to simulates a two dice game using random numbers for input.
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

// Simulates a two dice game using random numbers for input
int main() 
{
	int die1;
	int die2;
	int total;
	do 
	{
		int seed;
		cout << "Please input a seed value for the random number generator between 100 and 10000~" << endl;
		cout << "Enter seed :" << endl;
		cin >> seed;
		srand(seed);        //Seeds random number generator; provides IC
		die1 = rand() % (6) + 1;   //Generates random number between 1 and 6
		die2 = rand() % (6) + 1;
		total = die1 + die2;
		cout << "You rolled Die 1 £º" <<die1<< " and Die 2 :"<< die2 <<" for a total of : " <<total<<" was rolled" << endl;
		if (total == 7 || total == 9 || total == 11)
		{
			cout << "You are a Winner! " << endl;
			cout << "Game Over! " << endl;
		}
		else if(total == 2 || total == 3 || total == 5)
		{
			cout << "You are NOT a Winner! " << endl;
			cout << "Game Over! " << endl;
		}
		else
		{
			cout << "Please Roll Again " << endl;
		}
	} 
	while (total == 1 || total == 4 || total == 6|| total == 8|| total == 10|| total == 12);
	return 0;
}