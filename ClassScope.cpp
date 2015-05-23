#include<iostream>
using namespace std;

typedef string Type;
Type initval();
class Exercise {
	public:
		typedef double Type;
		Type setVal(Type);
		Type initVal() { return 0.0; }
	private:
		int val;
};

// The Type here need to use :: to specific the class's Type
Exercise::Type Exercise::setVal(Type parm) {
	val = parm + initVal();
	return val;
}

int main() {
	return 0;
}