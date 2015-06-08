#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<numeric>
#include<functional>
using namespace std;
using namespace std::placeholders;

bool isShorter(const string &str1, const string &str2) {
	return str1.size() < str2.size();
}

bool isFive(const string &str) {
	if(str.length() >= 5) {
		return true;
	}
	return false;
}

bool checkLength(const string &str, const int sz) {
		return str.length() >= sz;
}

vector<int> unique_copy_vet(const vector<int> &vet) {
	vector<int> ret;
	unique_copy(vet.begin(), vet.end(), back_inserter(ret));
	return ret;
}

int main() {
	vector<int> vet{1, 2, 3, 1, 3, 4, 5, 1};
	int val = 1;
	auto cnt = count(vet.cbegin(), vet.cend(), val);
	cout << "The number of " << val << " is " << cnt << endl;

	replace(vet.begin(), vet.end(), 1, 10);
	for(auto it = vet.cbegin(); it != vet.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	sort(vet.begin(), vet.end());
	vector<int> uq_vet = unique_copy_vet(vet);
	for(auto it = uq_vet.cbegin(); it != uq_vet.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// Remove duplicated numbers
	sort(vet.begin(), vet.end());
	auto unique_end = unique(vet.begin(), vet.end());
	vet.erase(unique_end, vet.end());
	for(auto it = vet.cbegin(); it != vet.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// join the strs within the vector
	vector<string> strs{"a", "b", "c"};
	auto str = accumulate(strs.cbegin(), strs.cend(), string(""));
	cout << "The accumulation is " << str << endl;

	vector<int> vet1;
	// vet1.reserve(10);
	fill_n(back_inserter(vet1), 10, 1);
	for(auto it = vet1.cbegin(); it != vet1.cend(); ++it) {
		cout << *it << " ";
	} 
	cout << endl;

	// sort the vector
	vector<string> strs1{"aaaa", "abd", "def", "ab", "cd", "abababab", "efegggsd"};
	sort(strs1.begin(), strs1.end());
	stable_sort(strs1.begin(), strs1.end(), isShorter);
	for(auto it = strs1.cbegin(); it != strs1.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	auto count = count_if(strs1.begin(), strs1.end(), 
		[](const string& str) -> bool { return str.length() >= 6; } );
	cout << "The number of the word with lenght greater than 6 : " << count << endl;

	count = count_if(strs1.begin(), strs1.end(), bind(checkLength, _1, 6));
	cout << "The number of the word with length greater than 6 : " << count << endl;

	auto it = partition(strs1.begin(), strs1.end(), isFive);
	strs1.erase(it, strs1.end());
	for(auto it = strs1.cbegin(); it != strs1.cend(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	auto f1 = [](const int &a, const int &b) -> int { return a + b; };
	cout << "Call to lambda1 :" << f1 (1, 2) << endl;

	int a = 2;
	auto f2 = [a](const int &b) -> int { return a + b; };
	cout << "Call to lambda2 :" << f2 (2) << endl;

	// istream_iterator<int> in_inter(cin), eof;
	// vector<int> vet2(in_inter, eof);
	// cout << "The input of the vector is: " << endl;
	// for(auto it : vet2) {
	// 	cout << it << " ";
	// }
	// cout << endl;

	// cout << "The output of the vector is: " << endl;
	// ostream_iterator<int> out_inter(cout, " ");
	// for(auto it : vet2) {
	// 	out_inter = it;
	// }
	// cout << endl;
	istream_iterator<int> in_iter(cin), eof;
	ostream_iterator<int> out_iter(cout, " ");
	vector<int> vet2(in_iter, eof);
	// sort and copy the elements in the istream to ostream
	// sort(vet2.begin(), vet2.end());
	// cout << "The result after the sort is: " << endl;
	// copy(vet2.cbegin(), vet2.cend(), out_iter);
	// cout << endl;
	cout << "The result after the unqiue copy is: " << endl;
	unique_copy(vet2.cbegin(), vet2.cend(), out_iter);
	cout << endl;

	// copy from postions 3 to 7 to a new vector in reverse order
	vector<int> vet3{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vet4;
	copy(vet3.crbegin()+2, vet3.crbegin()+7, back_inserter(vet4));
	for(auto it : vet4) {
		cout << it << " ";
	}
	cout << endl;
}