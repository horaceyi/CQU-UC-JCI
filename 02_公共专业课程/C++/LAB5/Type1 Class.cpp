#include<iostream>
#include<string>

using namespace std;

// Type 1
class student 
{
public:// designates what can be seen by other parts of program // default constructor 
	student() 
{ // initialize data as part of object construction
	id = 0; 
	major = " "; 
	name = " "; 
	year = 0; 
	gpa = 0.;
}

	int id; 
	string major; 
	string name;
	int year;
private: // not directly accessible by other parts of program 
	float gpa;
};

int main() 
{
	student s1; //create student object 
	student s2; //create another student object
// use ¡°.¡± operator 
	cout << "student s1 name and id: " << s1.name << ", " << s1.id << endl; 
	cout << "student s2 name and id: " << s2.name << ", " << s2.id << endl;
}