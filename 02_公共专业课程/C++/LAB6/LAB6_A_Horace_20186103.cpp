//  Lab6_A_Horace_20186103.cpp
//  June 6, 2019
//  Creator: Horace
//  Description: This programme is used to get an integer from the user that will represents a total time measured in seconds. 

#include<iostream>
#include<cmath>
using namespace std;

struct Time
{
	int h, m, sec;
	//Default Constructor
	Time ()
	{
		h = 0;
		m = 0;
		sec = 0;
	}
	//User initiated constructor 
	Time (int s)
	{
		h = s / 60 / 60;
		m = s / 60 % 60;
		sec = s % 60;
	}
	//Halftime Function
	int convert()
	{
		return 3600*h +  60*m + sec;
	}
	//Print Function
	void print()
	{
		cout << h << ":" << m << ":" << sec << endl;
	}
};

Time halfTime(int s)
{
	return Time(s/2);
}

int main()
{
	int s = 0;
	cout << "Time (sec):  " << endl;
	cin >>s;
	Time A,B,C;

	//Using the default constructor
	A = Time();
	cout << "Using the default constructor:" <<endl;
	A.print();

	//Using the user constructor
	B = Time(s);
	cout <<"Using the user constructor:"<< endl;
	B.print();

	//Using the half-time function
	C = halfTime(s);
	cout << "Using the half - time function :" << endl;
	C.print();

	//The half-time total seconds
	cout << "The half-time total seconds :" << C.convert() << endl;

	return 0;
}