#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool is_capital(const string &str) {
	for(const auto &c : str) {
		if(c < 'A' || c > 'C') {
			return false;
		}
	}
	return true;
}

void to_lower(string &str) {
	for(auto &c : str) {
		c = tolower(c);
	}
}

// Pay considerable attention to the parenthes
string strs[10];
string (*ten_strings())[10] {
	for(auto &str : strs) {
		str = "abc";
	}
	return &strs;
}

auto ten_strings2() -> string (*)[10] {
	for(auto &str : strs) {
		str = "abc";
	}
	return &strs;
}

// Try function pointers, book exercise
int add(const int a, const int b) {
	return a + b;
}

int substract(const int a, const int b) {
	return a - b;
}

int mulitple(const int a, const int b) {
	return a * b;
}

int divide(const int a, const int b) {
	return (b == 0) ? 0 : a / b;
}

//vector<int (*)(const int, const int)> function_list;
vector<decltype(&add)> function_list;
int main() {
	string str1 = "abc";
	string str2 = "ABC";
	string str3 = "ABC";
	
	cout << "The first string is " << is_capital(str1) << endl;
	cout << "The second string is " << is_capital(str2) << endl;
	to_lower(str3);
	cout << "The third string is " << str3 << endl;
	
	string (*p)[10] = ten_strings2();
	for(const auto &str : *p) {
		cout << str << " ";
	}
	cout << endl;
	
	function_list.push_back(&add);
	function_list.push_back(&substract);
	function_list.push_back(&mulitple);
	function_list.push_back(&divide);
	
	int a = 10, b = 5;
	cout << "Add: " << (*function_list[0])(a, b) << endl;
	cout << "Substract: " << (*function_list[1])(a, b) << endl;
	cout << "Mulitple: " << (*function_list[2])(a, b) << endl;
	cout << "Divide: " << (*function_list[3])(a, b) << endl; 
	
	return 0;
}