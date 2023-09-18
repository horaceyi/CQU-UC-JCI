#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "student.h";

// Type 2

int main()
{
	student s1;
	student s2(20190001, "EE", "Mary", 2019, 3.0);
	student s3; (20190002, "Horace");

	cout << "S1: name  " << s1.name << endl;
	cout << "S2: name" << s2.name << endl;
	cout << "S3: major:" << s3.major << endl;

	s3.setGPA(3.95);

	cout << "s3 gpa:" << s3.getGPA;
	int NStud;

	cout << "How many students?" << endl;
	cin >> NStud;
	vector<student>alls(NStud);

	alls[0] = s1;
	alls[1] = s2;
	alls[1].major = "CE";
	alls[2] = s3;

	for (int i = 1; i < NStud; i++)
	{
		cout << "ask for name:" << endl;
		cin >> alls[i].name;

	}
}