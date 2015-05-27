#include<iostream>
#include<vector>
#include<list>
#include<forward_list>
#include<stack>
using namespace std;

// Do not return reference to local variables
vector<int>::const_iterator fun(const vector<int> &vet, int number) {
	auto iter = vet.cbegin();
	for(; iter != vet.cend(); ++iter) {
		if(*iter == number) {
			break;
		}
	}
	return iter;
}

// Construct a vector from a list
vector<string> fun2(const list<const char*> &list) {
	vector<string> vet(list.begin(), list.end());
	return vet;
}

// Remove the odd number in list and even number in vector
void fun3(list<int> &list, vector<int> &vet) {
	auto iter1 = list.begin();
	while(iter1 != list.end()) {
		if(*iter1 % 2 != 0) {
			iter1 = list.erase(iter1);
		}
		else {
			++iter1;
		}
	}

	auto iter2 = vet.begin();
	while(iter2 != vet.end()) {
		if(*iter2 % 2 == 0) {
			iter2 = vet.erase(iter2);
		}
		else {
			++iter2;
		}
	}
}

// Remove the even number in a forward_list (single linked list)
void fun4(forward_list<int> &li) {
	auto prev = li.before_begin();
	auto curr = li.begin();
	while(curr != li.end()) {
		if(*curr % 2 == 0) {
			curr = li.erase_after(prev);
		}
		else {
			prev = curr;
			++curr;
		}
	}
}

// Replace the apperance of oldVal in s bu newVal
void fun5(string &s, const string &oldVal, const string &newVal) {
	auto iter = s.begin();
	auto oldSize = oldVal.size();
	auto newSize = newVal.size();
	while(iter + oldSize <= s.end()) {
		string str(iter, iter + oldSize);
		if(str == oldVal) {
			iter = s.erase(iter, iter + oldSize);
			iter = s.insert(iter, newVal.begin(), newVal.end());
			iter += newSize;
		}
		else {
			++iter;
		}
	}
}

void fun5(const string &s) {
	string numerical = "0123456789";
	string alphabetic = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	auto pos = 0;
	while((pos = s.find_first_of(numerical, pos)) != string::npos) {
		cout << s[pos] << " ";
		++pos;
	}
	cout << endl;

	pos = 0;
	while((pos = s.find_first_of(alphabetic, pos)) != string::npos) {
		cout << s[pos] << " ";
		++pos;
	}
	cout << endl;
}

// Parenthese validation using stack.
bool fun6(const string &s) {
	stack<char> charStack;
	for(auto ch : s) {
		if(ch == '(' || ch == '{' || ch == '[') {
			charStack.push(ch);
		}
		else {
			if(charStack.empty()) {
				return false;
			}
			else {
				char left = charStack.top();
				if((ch == '(' && left != ')') || (ch == '{' && left != '}') || (ch == '[' && left != ']')) {
					return false;
				} 
				charStack.pop();
			}
		}
	}
	if(charStack.empty()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	vector<int> vet = {1, 2, 3, 4, 5, 6};
	int number = 7;
	auto iter = fun(vet, number);
	if(iter != vet.cend())
		cout << *iter << endl;
	else
		cout << "The element is not found" << endl;

	// declaration list would hidden the list defined in the header
	list<const char*> list1 = {"a", "b", "c"};
	vector<string> strs = fun2(list1);
	for(auto str : strs) {
		cout << str << " ";
	}
	cout << endl;

	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	vector<int> vet2(begin(ia), end(ia));
	list<int> list2(begin(ia), end(ia));
	fun3(list2, vet2);
	for(auto i : list2) {
		cout << i << " ";
	}
	cout << endl;
	for(auto i : vet2) {
		cout << i << " ";
	}
	cout << endl;

	forward_list<int> li(begin(ia), end(ia));
	fun4(li);
	for(auto i : li) {
		cout << i << " ";
	}
	cout << endl;

	string s = "Tho and Thoa and a Th haha Tho";
	string oldVal = "Tho";
	string newVal = "Though";
	fun5(s, oldVal, newVal);

	cout << s << endl;

	string s2 = "ab2c3d7R4E6";
	fun5(s2);

	string s3 = "()}";
	cout << fun6(s3) << endl;

	return 0;
}