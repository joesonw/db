#include <iostream>
#include "default/field.h"
#include "default/record.h"
#include <boost/any.hpp>
using boost::any_cast;
using std::cout;
using std::endl;
int main() {
	db::core::BaseField *i=new IntegerField("");
	db::core::BaseRecord *r=new Record(i,12);
	try {
		cout<<(r+2)->print()<<endl;
	} catch (db::core::Error &e) {
		cout<<e.what()<<endl;
	}
}
