#include<iostream>
using namespace std;

int main() {
	
//	unsigned char c = -1;
//	signed char c2 = 256;
//	
//	cout << "The value of c is " << c << endl;
//	cout << "The value of c2 is " << c2 << endl;
	
	// list initialization
	int a = {1};
	
	cout << "The value of a is " << a <<endl;
	
	// reference
	int i = 0, &r1 = i;
	double d = 1.0, &r2 = d;
	
	r2 = 3.14;
	cout << "The value of r2 " << r2 << endl;
	
	r2 = r1;
	cout << "The value of r2 " << r2 << endl;
	
	i = r2;
	cout << "The value of i " << i << endl;
	
	r1 = d;
	cout << "The value of r1 " << r1 << endl;
	
	cout << "The address of r2 " << &r2 << endl;
	cout << "The address of d " << &d << endl;
	
	// pointers
//	int *p = nullptr;
	
	int b = 1;
	int const *p = &b;
	
	cout << "The value of *p " << *p << endl;
	b = 2;
	cout << "The value of *p after the change " << *p << endl;
	
	// C++ alising
	using MyType = double;
	MyType dd = 10.0;
	cout << "The value of dd is " << dd << endl;
}