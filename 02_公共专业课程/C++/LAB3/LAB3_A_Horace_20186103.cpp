//  Lab3_A_Horace_20186103.cpp
//  May 28, 2019
//  Creator: Horace
//  Description: This programme is used to completes three separate loops, based on the instructions for each.

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<time.h>
using namespace std;

void Loop1();
void Loop2(int, int,int);
void Loop3(double);
void timeDelay(int);

int main()
{
	cout << "Which loop do you want to run? " << "1. Loop 1 " << "2. Loop 2 " << "3. Loop 3 ";
	int loop;
	cin >> loop;
	if (loop == 1)
	{
		Loop1;
	}
	else if (loop == 2)
	{
		int start, end, step;
		cout << "Starting index:: ";
		cin >> start;
		cout << "Ending index: ";
		cin >> end;
		cout << "Step count: ";
		cin >> step;
		Loop2(start, end,step);
	}
	else if (loop == 3)
	{
		double value;
		cout << "Input value: ";
		cin >> value;
		Loop3(value);
	}
	return 0;
}

void Loop1()
{
	int total = 0;
	double average, k = 0;
	for (int i = 2;i <= 35;i += 3)
	{
		total += i;
		k += 1;
	}
	average = total / k;
	cout << "Sum: " << total << endl << "Average: " << average << endl;
}

void Loop2(int start, int end,int step)
{
	int total = 0;
	double average, k = 0;
	for (int i = start;i <= end;i += step)
	{
		total += i;
		k += 1;
	}
	average = total / k;
	cout << "Sum: " << total << endl << "Average: " << average << endl;

}

void Loop3(double value)
{
	double number = value;
	cout << " Output is: " << endl;
	for (double i = value;i > 0;i -= 0.5)
	{
		cout << i << ", ";
		timeDelay(1);
	}
	cout << 0;
}

void timeDelay(int sec) 
{
	for (time_t t = time(0) + sec; time(0) < t; ) {}
} 