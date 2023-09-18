//  Lab6_C_Horace_20186103.cpp
//  June 6, 2019
//  Creator: Horace
//  Description: This programme is used to add a multiplayer functionality to Game of Chance program from Lab 5. 

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

struct player
{
	int balance, NumWin, NumLoss, NumSum;
	bool online = 1;
	string name;
	//Default Constructor
	player()
	{
		name = "";
		balance = 0;
		NumWin = 0;
		NumSum = 0;
	}
};

	//Print Function
	double statics(double NumWin, double NumSum)
	{
		double p = (NumWin / NumSum) * 100;
		return p;
	}

int main()
{
	string name; int balance, NumWin = 0, NumSum = 0, wager, np;
	cout << "How many players do you have?\n";
	cin >> np;
	while (np < 0)
	{
		cout << "Error: The number should be postive integer.\nPlease try new value: ";
		cin >> np;
	}
	cout << "What's the initial balance?" << endl;
	cin >> balance;
	while (balance <= 0)
	{
		cout << "Error: The balance should be postive integer.\nPlease try new value: ";
		cin >> balance;
	}
	system("CLS");
	cout << "********************START********************" << endl;
	srand(time(0));
	vector<player>data(np);
	for (int i = 0; i < np; i++)
	{
		cout << "Player # " << i + 1 << " Name: ";
		cin >> data[i].name;
		data[i].balance = balance;
	}

	//start
	int yes = 1, die = 0, round = 1;
	while (yes == 1)
	{
		if (die == np) { break; }
		cout << "\nRound " << round << endl;
		cout << "There is " << np - die << " people is playing.\n";
		for (int i = 0; i < np; i++)
		{
			if (data[i].online == 1)
			{
				cout << "Player #" << i + 1 << ":" << data[i].name << endl;
				cout << "Your balance is " << data[i].balance << "RMB\n";
				cout << "Enter wager (0 to exit): "; cin >> wager;
				while (wager > data[i].balance || wager < 0)
				{
					cout << "Error: You must wager between $1 and $" << data[i].balance << " (type 0 to exit): ";
					cin >> wager;
				}
				if (wager == 0)
				{
					cout << "Your final account balance is " << data[i].balance << " RMB\n";
					cout << "You are out.\n";
					data[i].online = 0;
					die++;
					break;
				}
				cout << "Enter your point value(1-6): "; int guess; cin >> guess;
				while (guess > 6 || guess < 1)
				{
					cout << "Error: The point value should betweeen 1 and 6.\nPlease enter point value again: ";
					cin >> guess;
				}
				cout << "Now you roll a die 3 times!\n";
				int die1 = rand() % (6) + 1;
				cout << "Roll #1 is  " << die1 << endl;
				int die2 = rand() % (6) + 1;
				cout << "Roll #2 is  " << die2 << endl;
				int die3 = rand() % (6) + 1;
				cout << "Roll #3 is  " << die3 << endl;
				if (die1 == guess || die2 == guess || die3 == guess)
				{
					cout << " ** You win! ** " << endl;
					cout << "Account balance " << data[i].balance << "RMB " << endl;
					data[i].balance += wager;
					data[i].NumWin++;
				}
				else
				{
					data[i].balance -= wager;
					cout << " ** You Lose ** " << endl;
					cout << "Account balance " << data[i].balance << "RMB " << endl;
					data[i].balance -= wager;
				}
				data[i].NumSum++;
				if (data[i].balance <= 0)
				{
					data[i].online = 0;
					die++;
					cout << "Game over, you are out of money!\n";
					cout << "Your final account balance is "<< data[i].balance<< " RMB"<<endl;
					break;
				}
			}
		}round++;
	}
	cout << "********************OVER********************" << endl;
	for (int n = 0; n < np; n++)
	{
		cout << "Player #" << n + 1 << ":" << data[n].name << endl;
		cout << "Your final balance is " << data[n].balance << " RMB\n";
		cout << "You win " << data[n].NumWin << " time out of " << data[n].NumSum << " for a winning percentage of ";
		cout << statics(data[n].NumWin, data[n].NumSum) << "%\n \n";
	}
	return 0;
}