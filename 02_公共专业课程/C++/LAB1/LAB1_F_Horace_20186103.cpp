//  Lab1_B_Horace_20186103.cpp
//  May 11, 2019
//  Creator: Horace
//  Addition program. 
#include <iostream>
#include <string>
using namespace std;

// function main begins program execution 
int main()
{
	int Homework1;
	int Homework2;
	int Homework3;
	int Quiz1;
	int Quiz2;
	int Quiz3;
	int Midterm1;
	int Midterm2;
	int FinalExam;
	double Homework;
	double Quiz;
	double Midterm;
	double FinalExam_;
	double FinalScore;

	cout << "Please enter the score of Homework1:  ";
	cin >> Homework1;
	cout << "Please enter the score of Homework2:  ";
	cin >> Homework2;
	cout << "Please enter the score of Homework3:  ";
	cin >> Homework3;
	cout << "Please enter the score of Quiz1:  ";
	cin >> Quiz1;
	cout << "Please enter the score of Quiz2:  ";
	cin >> Quiz2;
	cout << "Please enter the score of Quiz3:  ";
	cin >> Quiz3;
	cout << "Please enter the score of Midterm1:  ";
	cin >> Midterm1;
	cout << "Please enter the score of Midterm2:  ";
	cin >> Midterm2;
	cout << "Please enter the score of FinalExam:  ";
	cin >> FinalExam;

	Homework = (Homework1+ Homework2+ Homework3)*0.3/3;
	Quiz = (Quiz1 + Quiz2 + Quiz3) * 0.1/3;
	Midterm = (Midterm1 + Midterm2) * 0.15;
	FinalExam_ = FinalExam * 0.3;
	FinalScore = Homework + Quiz + Midterm + FinalExam_;

	cout <<  "Final Score is  " << FinalScore << endl;
	return 0;
}