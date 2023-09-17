// Lab10_C_Horace_20186103.cpp
// July 31, 2019 
// Creator: Horace
//Description:the code is equipped with +,-,*,\ ,conjugate and exponential, calculating root operations.
//There are two friend functions to operate plus between polar form and rectangular form. And output different types of results.

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

double pi = 2*asin(1);
class complex;
class ccomplexpolar;
class complex {
	double a = 0;
	double b = 0;
public:
	complex() {
		a = 1;
		b = 1;
	}
	complex(double c, double d, double j) {
		a = c;
		b = d;
	}
	//This constructor convert the polarform into rectangular form
	complex(double w, double z) {
		a = abs(z) * cos(w);
		b = abs(z) * sin(w);
	}
	double get_a() {
		return a;
	}
	double get_b() {
		return b;
	}
	complex operator+(complex i)
	{
		complex sum;
		sum.a = a + i.a;
		sum.b = b + i.b;
		return sum;
	}
	complex operator-(complex i)
	{
		complex sub;
		sub.a = a - i.a;
		sub.b = b - i.b;
		return sub;
	}
	complex operator*(complex i)
	{
		complex multiply;
		multiply.a = (a * i.a - b * i.b);
		multiply.b = (a * i.b + b * i.a);
		return multiply;
	}
	complex operator/(complex i)
	{
		complex division;
		division.a = (a * i.a + b * i.b) / (pow(i.a, 2) + pow(i.b, 2));
		division.b = (b * i.a - a * i.b) / (pow(i.a, 2) + pow(i.b, 2));
		return division;
	}
	complex conjugate()
	{
		complex conjugate;
		conjugate.a = a;
		conjugate.b = -b;
		return conjugate;
	}
	friend istream& operator>>(istream& input, complex& p)
	{
		input >> p.a >> p.b;
		return input;
	}
	friend ostream& operator<<(ostream& output, const complex& p)
	{
		if (p.a != 0) {
			if (p.b > 0) {
				output << " [ " << p.a << " + " << p.b << "i ]";
			}
			else if (p.b == 0)
			{
				output << " [ " << p.a << " ]" << endl;;
			}
			else if (p.b < 0) {
				output << " [ " << p.a << "  " << p.b << "i ]";
			}
		}
		else {
			output << "[ " << p.b << "i ]" << endl;
		}
		return output;
	}
	};
	class complexpolar {
		double z;
		double w;
	public:
		complexpolar() {
			z = 1;
			w = pi / 2;
		}
		complexpolar(complex i)
		{
			z = pow(pow(i.get_a(), 2) + pow(i.get_b(), 2), 0.5);
			if (i.get_b() >= 0) {
				w = pi / 2 - atan(i.get_a() / i.get_b());
			}
			else {
				w = 3 * pi / 2 - atan(i.get_a() / i.get_b());
			}
		}
		double get_z() {
			return z;
		}
		double get_w() {
			return w;
		}
		friend ostream& operator<<(ostream& output, const complexpolar& p)
		{
			output << abs(p.z) << " cis( " << p.w << " )";
			return output;
		}
		complexpolar exponential(complexpolar i) {
			i.z = pow((abs(i.z)), 7);
			i.w = 7*i.w;
			return i;
		}
		vector<complexpolar> root(double n) {
			vector<complexpolar>roots(n);
			for (int k = 0;k < n;k++) {
				roots[k].z = pow(abs(z), 1/n);
				roots[k].w = (w + 2 * pi * k) / n;
			}
			return roots;
		}
		friend complexpolar operator+ (complex i, complexpolar j) {
			complex alina;
			alina = complex(j.get_z(), j.get_w());
			complex zagitova = i.operator+(alina);
			complexpolar alison = complex(zagitova);
			return alison;
		}
		friend complex operator+(complexpolar j, complex i)
		{
			complex conversion = complex(j.get_w(), j.get_z());
			complex results = conversion.operator+(i);
			return results;
		}
	};
	int main() {
		cout << "Enter the real and imaginary part for the first complex number" << endl;
		complex complex1;
		cin >> complex1;
		cout << "Enter the real and imaginary part for the first complex number" << endl;
		complex complex2;
		cin >> complex2;
		complex complex3 = complex1.operator+(complex2);
		cout << "You have entered for C1: " << complex1 << " and for C2: " << complex2 << endl;
		cout << "C1 conjugate: " << complex1.conjugate() << endl;
		cout << "C2 conjugate: " << complex2.conjugate() << endl;
	
		cout << complex1 << " + " << complex2 << " = " << complex1.operator+(complex2) << endl;
		cout << complex1 << " - " << complex2 << " = "<<complex1.operator-(complex2) << endl;
		cout << complex1 << " * " << complex2 << " = "<<complex1.operator*(complex2) << endl;
		cout << complex1 << " / " << complex2 << " = "<<complex1.operator/(complex2) << endl;
		complexpolar complexpolar1 = complexpolar(complex1);
		cout << "Polar form for C1: " << complexpolar1 << endl;
		complexpolar complexpolar2 = complexpolar(complex2);
		cout << "Polar form for C1: " << complexpolar2 << endl;
		cout << "Calculations for C1: Exponentiation" << endl;
		complexpolar exponential1 = complexpolar1.exponential(complexpolar1);
		cout << complex1 << " ^7 =" << exponential1;
		complex inter = complex(exponential1.get_w(), exponential1.get_z());
		cout  << " In rectangular form is: " << inter;
		cout << endl;
		vector<complexpolar> root2(5);
		root2 = complexpolar2.root(5);
		cout << "roots for C2£º Nth Roots " << endl;
		for (int i = 0;i < 5; i++) {
			cout << "Root " << i + 1 << ": " << complex2 << " ^ ( 1 / 5 ) =" << root2[i] << endl;
		}
		for (int j = 0;j < 5;j++) {
			complex z = complex(root2[j].get_w(), root2[j].get_z());
			cout << root2[j] << " in the rectangular form is:" << z << endl;
		}
		return 0;
	}