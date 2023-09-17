//  Lab6_B_Horace_20186103.cpp
//  June 6, 2019
//  Creator: Horace
//  Description: This programme is used to output a list of your top five favorite restaurants with your personal restaurant rating.

#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;

class Restaurant
{
	string name;
	int rating;
	
public:
	Restaurant()
	{
		name = "";
		rating = 0;
	}

	void name_set(string u_name)
	{
		name= u_name;
	}

	void rating_set(int u_rating)
	{
		rating= u_rating;
	}

	void print()
	{
		cout << name << ":" << rating << endl;
	}
};

int main()
{
	string Name, user_name;
	int Rating, i;
	cout << "What's your name? " << endl;
	cin >> user_name;
	vector<Restaurant>rv(3);
	for (i = 0; i < 3; i ++)
	{
		cout << "For the restaurant #" <<i<<":"<< endl;
		cout << "Name: " << endl;
		cin >> Name;
		rv[i].name_set(Name);
		cout << "Rating: " << endl;
		cin >> Rating;
		rv[i].rating_set(Rating);
	}
	cout << "These are the three restaurants that " << user_name << "rated : " << endl;
	for (i = 0; i < 3; i++)
	{
	rv[i].print();
	}
	return 0;
}