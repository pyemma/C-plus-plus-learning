#include<iostream>
#include<string>
using namespace std;

class Person {

	friend istream& read(istream&, Person&);
	friend ostream& write(ostream&, const Person&);
private:
	string name;
	string address;
public:
	string getName() const { return name; }
	string getAddress() const { return address; }
};

istream& read(istream &is, Person &person) {
	is >> person.name >> person.address;
	return is;
}

ostream& write(ostream &os, const Person &person) {
	os << person.name << " " << person.address;
	return os;
}

int main() {
	Person person;
	read(cin, person);
	write(cout, person) << endl;
}

