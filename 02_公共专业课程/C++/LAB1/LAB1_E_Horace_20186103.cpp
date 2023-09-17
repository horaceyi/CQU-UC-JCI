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
	int userNum;
	int square;
	int cube;
	int userNum2;
	int sum;
	int product;

	cout << "Please enter an integral:  ";
	cin >> userNum;

	square = pow(userNum, 2);
	cube = pow(userNum, 3);

	cout << userNum << "squared is  " << square << endl;
	cout << userNum << "cubed is  " << cube << "!!"<< endl;

	cout << "Please enter another integral:  ";
	cin >> userNum2;

	sum = userNum+userNum2;
	product = userNum*userNum2;

	cout << userNum << "+" << userNum2 <<"  is  "<<sum<< endl;
	cout << userNum << "*" << userNum2 << "  is  " << sum << endl;
	return 0;
}