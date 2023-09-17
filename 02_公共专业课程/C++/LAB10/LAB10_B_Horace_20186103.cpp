// Lab10_B_Horace_20186103.cpp
// July 4, 2019 
// Creator: Horace
// Description: This file determine if the first line is parallel to another line defined by two more points entered by the user. 

#include<iostream>;
#include<vector>;
#include<cstring>;
#include<cmath>
using namespace std;

class point 
{
	double x_num, y_num;
public:
	point(double x = 0, double y = 0)
	{
		x_num = x;
		y_num = y;
	};
	void set(double x = 0, double y = 0)
	{
		x_num = x;
		y_num = y;
	}
	void get(double &x, double &y) 
	{
		vector<double> coordinate(2);
		x = x_num;
		y = y_num;
	}
	friend bool operator==(point x, point y);
};

class Line 
{
	point one;
	point two;
	double x1,y1;
	double x2, y2;
public:
	Line() 
	{}
	Line(point a , point b)
	{
		one=a;
		two=b;
		one.get(x1, y1);
		two.get(x2, y2);
	}
	void get(point& a, point& b) 
	{
		a = one;
		b = two;
	}
	void set(point a, point b) 
	{
		one = a;
		two = b;
		one.get(x1, y1);
		two.get(x2, y2);
	}

	double slope() {
		double k;
		k = (y1 - y2) / (x1 - x2);
		return k;
	}

	double equation(){
		double b;
		b = y1 - slope() * x1;
		return b;
	}

	void print() 
	{
		if (x1==x2)
		{
			cout << " x= "<<x1;
		}
		else if (y1==y2)
		{
			cout << "y= " << y1; 
		}
		else 
		{
			double b = equation();
			char pm = '+';
			if (b < 0) pm = '-';
			cout << " y = " << slope() << "*x " << pm << " " << abs(b) << endl;
		}
	}

	double length() 
	{
		double dist;
		dist = pow((pow((x1 - x2), 2) + pow((y1 - y2), 2)), 1 / 2);
		return dist;
	}
	
	bool horizontal() 
	{
		if (slope()==0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool vertical() 
	{
		if (x1 == x2)
		{
			cout << " vertical." << endl;
			return 1;
		}
		else if (y1 == y2)
		{
			cout << " horizontal " << endl;
		}
		else
		{
			cout << " oblique."<<endl;
			return 0;
		}
	}
	bool parallel(Line L2) 
	{
		
		if (  slope()==L2.slope()  )
		{
			cout << " Line 1 and Line 2 are parallel. "<<endl;
			return 1;
		}
		else
		{
			cout << " Line 1 and Line 2 are not parallel. "<<endl;
			return 0;
		}
	}
	friend bool operator==(Line a, Line b);
};

class triangle 
{
	point a, b, c;
	Line one, two, three;
public:
	triangle() 
	{
		one.set(a,b);
		two.set(b, c);
		three.set(c, a);
	}
	triangle(point x,point y,point z) 
	{
		a = x;
		b = y;
		c = z;
		one.set(a, b);
		two.set(b, c);
		three.set(c, a);
	}
	void set(point x,point y,point z) {
		a = x;
		b = y;
		c = z;
		one.set(a, b);
		two.set(b, c);
		three.set(c, a);
	}
	void getpoint(point& x,point& y,point& z) {
		x = a;
		y = b;
		z = c;
	}
	void getline(Line& x, Line& y, Line& z) {
		x = one;
		y = two;
		z = three;
	}
	bool check() 
	{
	
		if (one.slope() == two.slope()) {
			cout << "  They CANNOT form a triangle, because the points are collinear. "<<endl;
			return false;
		}
		else
		{
			cout << "  They CANNOT form a triangle, because the points are collinear. " << endl;
			return true;
		}
	}

	double perimeter() 
	{
		double total;
		total = one.length() + two.length() + three.length();
		return total;
	}

	double area() 
	{
		double A;
		double s=perimeter()/2;
		A = pow(s * (s - one.length()) * (s - two.length()) * (s - three.length()), 0.5);
		return A;
	}
};

bool operator==(point a,point b) 
{
	if (a.x_num == b.x_num && a.y_num == b.y_num)
	{
		cout << "it is invalid."<<endl;
		return true;
	}
	else
	{
		return false;
	}

}

bool operator==(Line a, Line b) 
{
	if ((a.one == b.one && a.two == b.two) || (a.one == b.two && a.two == b.one)) 
	{
		return true ;
	}
	else
	{
		return false ;
	}
}

bool operator==(triangle first, triangle second) 
{
	vector<Line> x(3);
	vector<Line> y(3);
	first.getline(x[0], x[1], x[2]);
	second.getline(y[0], y[1], y[2]);
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		if (x[0].length() == y[i].length()) 
		{
			a = i;
			for (int j = 0; j < 3; j++)
			{
				if (x[1].length()==y[j].length() && a!=j)
				{
					b = j;
					for (int k = 0; k < 3; k++)
					{
						if (x[2].length() == y[k].length() && a != k && b !=k )
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int main() 
{
	double x, y;
	point one, two;
	bool check_1=true;
	while (check_1)
	{
		cout << " Please enter x and y for Point 1:  " << endl;
		cin >> x >> y;
		one.set(x, y);
		cout << " Please enter x and y for Point 2:  " << endl;
		cin >> x >> y;
		two.set(x, y);
		double x1, y1, x2, y2;
		one.get(x1, y1);
		two.get(x2, y2);
		check_1 = (one == two);
		if (check_1) 
		{}
		else
		{
			Line line1(one, two);
			cout << "You have entered for P1: ( " << x1 << " , " << y1 << " )";
			cout << " and for P2: (" << x2 << " , " << y2 << " )" << endl;
			cout << " The slope of Line 1 for P1 and P2 is: " << line1.slope() << endl;
			cout << " The y-intercept for Line 1 for P1 and P2 is: " << line1.equation() << endl;
			cout << " Therefore, the equation of Line 1 is ";
			line1.print();
			cout << endl;
			cout << "The distance between P1 and P2 is:  " << line1.length() << endl;
			cout << "Line 1 is ";
			line1.vertical();
			cout << endl;
			bool check_2 = true;
			while (check_2)
			{
				point three, four;
				cout << " Please enter x and y for Point 3: " << endl;
				cin >> x >> y;
				three.set(x, y);
				cout << " Please enter x and y for Point 4: " << endl;
				cin >> x >> y;
				four.set(x, y);
				double x3, y3, x4, y4;
				three.get(x3, y3);
				four.get(x4, y4);
				check_2 = (three == four);
				if (check_2)
				{}
				else
				{
					Line line2(three, four);
					cout << "You have entered for P3: ( " << x3 << " , " << y3 << " )";
					cout << " and for P2: (" << x4 << " , " << y4 << " )" << endl;
					cout << " the equation of Line 1 is ";
					line2.print();
					cout << endl;
					line1.parallel(line2);
				}
			}
		}
	}

	point five, six, seven;
	double x5, y5, x6, y6,x7,y7;
	triangle triangle_1;
	cout << " Please enter x and y for Point 5:  " << endl;
	cin >> x >> y;
	five.set(x, y);
	cout << " Please enter x and y for Point 6:  " << endl;
	cin >> x >> y;
	six.set(x, y);
	cout << " Please enter x and y for Point 7:  " << endl;
	cin >> x >> y;
	seven.set(x, y);
	five.get(x5, y5);
	six.get(x6, y6);
	seven.get(x7, y7);
	cout << "You have entered for P5: ( " << x5 << " , " << y5 << " )";
	cout << " and for P6: (" << x6 << " , " << y6 << " )" ;
	cout << " and for P7: (" << x7 << " , " << y7 << " )" << endl;
	 triangle_1.set(five,six,seven);

	if (triangle_1.check())
	{
		cout << " The perimeter of Triangle 1 is:  " << triangle_1.perimeter()<<endl;
		cout << " The area of Triangle 1 is: " << triangle_1.area() << endl;
		point eight, night, ten;
		double x8, y8, x9, y9, x10, y10;
		cout << " Please enter x and y for Point 8:  " << endl;
		cin >> x >> y;
		eight.set(x, y);
		cout << " Please enter x and y for Point 9:  " << endl;
		cin >> x >> y;
		night.set(x, y);
		cout << " Please enter x and y for Point 10:  " << endl;
		cin >> x >> y;
		ten.set(x, y);
		eight.get(x8, y8);
		night.get(x9, y9);
		ten.get(x10, y10);
		cout << "You have entered for P8: ( " << x8 << " , " << y8 << " )";
		cout << " and for P9: (" << x9 << " , " << y9 << " )";
		cout << " and for P10: (" << x10 << " , " << y10 << " )" << endl;
		triangle triangle_2(eight, night , ten);

		if (triangle_1.check())
		{
			if (triangle_2 == triangle_1)
			{
				cout << " Triangle 1 and Triangle 2 are congruent. ";
			}
			else
			{
				cout << " Triangle 1 and Triangle 2 are not congruent. ";
			}
		}
	}
	return 0  ;
}