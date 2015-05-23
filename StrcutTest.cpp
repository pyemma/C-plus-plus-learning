#include<iostream>
#include<string>
using namespace std;

struct MyItem {
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	
	MyItem() = default;
	MyItem(const string &s): bookNo(s) {}
	MyItem(const string &s, unsigned n, double p):
		bookNo(s), units_sold(n), revenue(p*n) {}
	MyItem(istream &);
	
	string isbn() const { return bookNo; }
	MyItem& combine(const MyItem&);
	double avg_price() const;
};

MyItem add(const MyItem&, const MyItem&);
ostream& print(ostream&, const MyItem&);
istream& read(istream&, MyItem&);

double MyItem::avg_price() const {
	if (units_sold) {
		return revenue / units_sold;
	}
	else {
		return 0;
	}
}

MyItem& MyItem::combine(const MyItem &item) {
	units_sold += item.units_sold;
	revenue += item.revenue;
	return *this;
}

MyItem::MyItem(istream &is) {
	read(is, *this);
}

istream& read(istream &is, MyItem &item) {
	double price = 0.0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = item.units_sold * price;
	return is;
}

ostream& write(ostream &os, const MyItem &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
	<< item.avg_price() ;
	return os;
}

MyItem add(const MyItem &litem, const MyItem &ritem) {
	MyItem item = litem;
	item.combine(ritem);
	return item;
}

int main() {
	MyItem item1;
	read(cin, item1);
	write(cout, item1) << endl;	
}