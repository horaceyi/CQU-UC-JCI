// Lab10_A_Horace_20186103.cpp
// July 4, 2019 
// Creator: Horace
// Description: This file's function is time conversion (extended). 

#include<iostream>
#include<cmath>
#include <fstream>
#include<string>
using namespace std;

struct Time_Conversion
{
public:
	double total;
	int Year, Month, Day, hour, minute, second;
	Time_Conversion() 
	{
		Year = 0;
		Month = 0;
		Day = 0;
		hour = 0;
		minute = 0;
		second = 0;
	}
	
	Time_Conversion(double total) 
	{
		double change;
		Year = total / (365.25 * 24 * 60 * 60);
		change = total - Year * 365.25 * 24 * 60 * 60;
		Month = change / (30.4375 * 24 * 60 * 60);
		change -= Month * 30.4375 * 24 * 60 * 60;
		Day = change / (24 * 60 * 60);
		change -= Day * 24 * 60 * 60;
		hour = change / (60 * 60);
		change -= hour * 60 * 60;
		minute = change / 60;
		second = change - minute * 60;
	}

	bool operator>(Time_Conversion input)
	{
		return(total > input.total);
	}
	bool operator==(Time_Conversion input) 
	{
		return(total == input.total);
	}
	bool operator<(Time_Conversion input) 
	{
		return(total < input.total);
	}
	double operator-(Time_Conversion input) 
	{
		return (total - input.total);
	}

	friend ostream& operator<<(ostream& output, const Time_Conversion& P)
	{
		output << "[ " << P.Year << " / " << P.Month << " / " << P.Day << " - " << P.hour << " / " << P.minute << " / " << P.second << " ]";
		return output;
	}
	friend ifstream& operator>>(ifstream& input, Time_Conversion& P)
	{
		string temp;
		input >> temp >> P.Year >> temp >> P.Month >> temp >> P.Day >> temp >> P.hour >> temp >> P.minute >> temp >> P.second >> temp;
		P.total = P.Year * 365.25 * 24 * 60 * 60 +
			P.Month * 30.4375 * 24 * 60 * 60 +
			P.Day * 24 * 60 * 60 +
			P.hour * 60 * 60 + P.minute * 60 + P.second;
		return input;
	}
};

int main() 
{
	Time_Conversion T1, T2;
	double differential;
	ifstream inFile;
	inFile.open("InputA.txt");
	if (!inFile.is_open()) {
		cout << "Could not open file" << endl;
		return 0;
	}
	inFile >> T1;
	inFile >> T2;
	inFile.close();
	cout << "You have entered T1: ";
	cout << T1;
	cout << " and T2: ";
	cout << T2 << endl;
	cout << "Comparion.\n";
	if (T1 > T2) 
	{
		cout << "Date T1 is greater than Date T2.\n";
	}
	else if (T1 < T2) 
	{
		cout << "Date T2 is greater than Date T1.\n";
	}
	else if (T1 == T2)
	{
		cout << "Date T1 is equal to Date T2.\n";
	}
	cout << "\nData subtracion.\n";
	cout << T1;
	cout << " - ";
	cout << T2 << endl;
	cout << "Answer: ";
	differential = T1 - T2;
	Time_Conversion minus(differential);
	cout << minus;
	return 0;
}