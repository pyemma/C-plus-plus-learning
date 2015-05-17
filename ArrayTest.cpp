#include<iostream>
using namespace std;

int main() {
	
	int a[5] = {1, 2, 3, 4, 5};
	
	for(int *b = begin(a); b != end(a); ++b) {
		cout << *b << " ";
	}
	cout << endl;
	
	int ai[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	for(const auto &row : ai) {
		for(auto p : row) {
			cout << p << " ";
		}
		cout << endl;
	}
	
	for(auto p = begin(ai); p != end(ai); ++p) {
		for(auto q = begin(*p); q != end(*p); ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}
	
	// p is a pointer pointing to an array of size 4, *p is the first pointer of 
	// this array
	for(int (*p)[4] = ai; p != ai + 3; ++p) {
		for(int *q = *p; q != *p + 4; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}
}