#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
//	vector<string> v1(10);
//	vector<string> v2 = {"abc", "def"};
//	vector<string> v3{"a", "b", "c"};
	
//	vector<int> v;
//	for(int i = 0; i < 10; i++) {
//		v.push_back(i);
//	}
//	
//	for(auto &i : v) {
//		i *= i;
//	}
//	
//	for(auto i : v) {
//		cout << i << " ";
//	}
//	cout << endl;
	
	// Book exercise
	vector<string> v;
	string str;
	while(cin >> str) {
		v.push_back(str);
	}
	
	cout << "The upper case of all words: " << endl;
	for(auto &str : v) {
		for(auto &c : str) {
			c = toupper(c);
		}
	}
	
//	for(auto str : v) {
//		cout << str << " ";
//	}
//	cout << endl;
    for(auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
	
	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v2 = {1, 3, 3, 4, 5};
	bool flag = true;
	
	for(auto p1 = v1.cbegin(), p2 = v2.cbegin(); p1 != v1.end() && p2 != v2.end(); ++p1, ++p2) {
		if(*p1 != *p2) {
			 flag = false;
			 break;
		}
	}
	
	cout << flag << endl;
	return 0;
}
