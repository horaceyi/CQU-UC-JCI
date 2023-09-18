//  Lab5_ABCD_Horace_20186103.cpp
//  June 2, 2019
//  Creator: Horace
//  Description: This programme is used to run a simulation of a game of chance based on a simple dice game.

#include<iostream>
#include<cmath>
#include <ctime> 
#include<vector>
using namespace std;

int seed, wager, account = 100, t = 0, t_win = 0;
void statistic(string name);

int main()
{
	//enter seed
		cout << "Please give the seed: ";
	    cin >> seed;
	srand(seed);
	cout << "Welcome to this game! Please enter your name: ";
	string name;
	cin >> name;
	cout << "Account balance " << account << endl;
	//start
	do
	{
		do
		{
			cout << "Enter wager (0 to exit): ";
			cin >> wager;
			if(wager<0 || wager>account)
           {
			    cout << "Error! Please make the wager between 0 to your present account!";
		    }
		} 
		while (wager<0 || wager>account);
		if (wager == 0) { break; }
		cout << "Enter your point value (1 - 6):   ";
		double guess;
		cin >> guess;
		cout << "Now please roll a die 3 times!\n";
		int die1 = rand() % (6) + 1;
		cout << "Roll #1 is  " << die1 << endl;
		int die2 = rand() % (6) + 1;
		cout << "Roll #2 is  " << die2 << endl;
		int die3 = rand() % (6) + 1;
		cout << "Roll #3 is  " << die3 << endl;
		if (die1 == guess || die2 == guess || die3 == guess)
		{
			account += wager;
			cout << " ** You win! ** " << endl;
			cout << "Account balance " << account << "RMB " << endl;
			t_win++;
		}
		else
		{
			account -= wager;
			cout << " ** You Lose ** " << endl;
			cout << "Account balance " << account << "RMB " << endl;
		}
		t++;
	}
	while (wager != 0 && account > 0);
		double p = static_cast<double>(t_win) / static_cast<double>(t) * 100;
		statistic(name);
		//end
}

void statistic(string name)
{
	double p = static_cast<double>(t_win) / static_cast<double>(t) * 100;
	cout << "Player name : " << name << endl;
	cout << "Your final account balance is " << account << "RMB" << endl;
	cout << "You won " << t_win << " time out of " << t << " for a winning percentage of " << p << "%";
}