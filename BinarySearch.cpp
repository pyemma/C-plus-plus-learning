#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v = {1, 2, 3, 3, 5, 6};
	int search;
	
	cout << "Input the number you want to search: "; 
	cin >> search;
	
	auto start = v.cbegin();
	auto end = v.cend();
	auto mid = start + (end - start) / 2;
	while(mid != end && *mid != search) {
		if(*mid < search) 
			end = mid;
		else
			start = mid + 1;
		mid = start + (end - start) / 2;
	}
	
	cout << "The cloest number to " << search << " in the array is at " << mid - v.begin() << endl;
}