#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	// read a line from the input stream
//	while(getline(cin, str)) {
//		cout << str << endl;
//		auto size = str.size();
//		cout << "The lenght of the input is: " << size << endl;
//	}
	
//	string s1, s2;
//	cin >> s1 >> s2;
//	if(s1 != s2) {
//		cout << (s1 > s2 ? s1 : s2) << endl;
//	}
//	
//	string s3;
//	cin >> s3;
//	for(auto c : s3) {
//		cout << c << endl;
//	}
	
	// Book example
	string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;
	for(auto c : s) {
		if(ispunct(c)) {
			++punct_cnt;
		}
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;
	
	for(int i = 0; i <= s.size(); i++) {
		s[i] = toupper(s[i]);
	}
	cout << s << endl;
	return 0;;
}