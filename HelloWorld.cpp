#include<iostream>
using namespace std;

int main() {
	cout << "Hello World!" << endl;
	cout << "/*" << endl;
	cout << "*/" << endl;
	
	int value = 0;	
	while(cin >> value) {
		cout << value << " ";
	}
	cout << endl;
	return 0;
}