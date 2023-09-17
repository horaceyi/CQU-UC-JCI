// Lab6_C_Horace_20186103.cpp
// June 28, 2019 
// Creator: Horace
// Description: This file contains the velocity information of four probe locations of a simulation at the times listed in the file. 

#include<iostream>
#include<cmath>
#include <fstream>
#include<vector>
#include<string>
using namespace std;

int main() 
{
	ifstream file;  
	file.open("VelocityProbe_new.txt");  
	string temp1;  
	int counter = 0;  
	while (!file.eof()) 
	{ 
		getline(file, temp1);
		counter++;
	}  
	file.close();
	counter -= 5;
	ifstream file_;
	file_.open("VelocityProbe_new.txt");
	if (!file_.is_open())
	{
		cout << "Could not open file" << endl;
		return 1;
	}
	vector<double> x(4), y(4), z(4),D(4),
		Time(counter),V1(counter), V2(counter), V3(counter), V4(counter),
		vx1(counter), vy1(counter), vz1(counter),
	vx2(counter), vy2(counter), vz2(counter),
	vx3(counter), vy3(counter), vz3(counter),
	vx4(counter), vy4(counter), vz4(counter);
	string temp; 
	file_ >> temp >> temp >> x[0] >> x[1] >> x[2] >> x[3];
	file_ >> temp >> temp >> y[0] >> y[1] >> y[2] >> y[3];
	file_ >> temp >> temp >> z[0] >> z[1] >> z[2] >> z[3];
	file_ >> temp >> temp;
	for (int i = 0; i < counter; i++)
	{
		file_ >> Time[i];
		file_ >> vx1[i];file_ >> vy1[i];file_ >> vz1[i];
		file_ >> vx2[i];file_ >> vy2[i];file_ >> vz2[i];
		file_ >> vx3[i];file_ >> vy3[i];file_ >> vz3[i];
		file_ >> vx4[i];file_ >> vy4[i];file_ >> vz4[i];
	}
	file_.close();
	for (int j = 0; j < 4; j++)
	{
		D[j] = sqrt(pow(x[j], 2) + pow(y[j], 2) + pow(z[j], 2));
	}
	for (int k = 0; k < counter; k++)
	{
		V1[k] = sqrt(pow(vx1[k], 2) + pow(vy1[k], 2) + pow(vz1[k], 2));
		V2[k] = sqrt(pow(vx2[k], 2) + pow(vy2[k], 2) + pow(vz2[k], 2));
		V3[k] = sqrt(pow(vx3[k], 2) + pow(vy3[k], 2) + pow(vz3[k], 2));
		V4[k] = sqrt(pow(vx4[k], 2) + pow(vy4[k], 2) + pow(vz4[k], 2));
	}
	ofstream outFile;
	outFile.open("OutputC.txt");
	outFile << "Distance" << "\t\t" << D[0] << "\t\t" << D[1] << "\t\t" << D[2] << "\t\t" << D[3] << endl;
	outFile << "Time"<<"\t\tV1\t\tV2\t\tV3\t\tV4\n";
	for (int m = 0; m < counter; m++)
	{
		outFile << Time[m] << "\t\t" << V1[m] << "\t\t" << V2[m] << "\t\t" << V3[m] << "\t\t" << V4[m] << endl;
	}
	outFile.close();
	return 0;
}