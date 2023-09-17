#ifndef STUDENT_HPP
#define STUDENT_HPP

#endif
class student
{ // data only 
public:// designates what can be seen by other parts of program // default constructor 
	student()
	{
		id = 0;
		major = " ";
		name = " ";
		year = 0;
		gpa = 0.;
	}
	// user initiated constructor 
	student(int s_id, string s_major, string s_name, int s_year, float s_gpa)
	{
		id = s_id;
		major = s_major;
		name = s_name;
		year = s_year;
		gpa = s_gpa;
	}

	void setGPA(float u_gpa)
	{
		gpa = u_gpa;
	}

	float getGPA() const;


	int id;
	string major;
	string name;
	int year;
private: // not directly accessible by other parts of program 
	float gpa;
};
