#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main() {
	map<string, vector<string>> family;
	family["A"].push_back("a");
	family["A"].push_back("b");
	family["B"].push_back("c");
	for(const auto &p : family) {
		cout << "Family " << p.first << " has childern: ";
		for(const auto &it : p.second) {
			cout << it << " ";
		}
		cout << endl;
	}

	string str;
	int in;
	vector<pair<string, int>> pairs;
	while(cin >> str >> in) {
		pairs.push_back({str, in});
	}
	for(const auto &p : pairs) {
		cout << p.first << " " << p.second << endl;
	}
	cout << endl;

	multimap<string, string> works;
	works.insert({"A", "AAA"});
	works.insert({{"C", "CCC"}});
	works.insert({"B", "BBB"});
	// auto it = works.find("A");
	// if(it != works.end()) {
	// 	works.erase(it);
	// }
	// it = works.find("C");
	// if(it != works.end()) {
	// 	works.erase(it);
	// }
	for(auto it : works) {
		cout << it.first << " :" << it.second << endl;
	}
}