#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

istream& func(istream &is) {
	string line;
	while(getline(is, line)) {
		cout << line << endl;
	}
	is.clear();
	return is; 
}

void read(string file_name, vector<string> &vet) {
	ifstream input(file_name);
	if(input) {
		string str;
		while(input >> str) {
			vet.push_back(str);
		}
	}
	else {
		cerr << "Could not open the file!" << endl;
	}
}

void write(string file_name, vector<string> &vet) {
	ofstream output(file_name);
	if(output) {
		for(auto str : vet) {
			output << str << " ";
		}
	}
	else {
		cerr << "Could not write to the file!" << endl;
	}
}

int main() {
	func(cin);
	
	string file_name("test.txt");
	string output_name("out.txt");
	vector<string> vet;
	
	read(file_name, vet);
	write(output_name, vet);
	cout << "The content of the file: " << endl;
	for(auto str : vet) {
		cout << str << endl;
	}
	return 0;
}