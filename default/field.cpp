#include "field.h"
#include <boost/lexical_cast.hpp>
#include <typeinfo>
#include <stdexcept>
#include <sstream>
using namespace std;

IntegerField::IntegerField(string name,unsigned max_length,bool unique,bool primary_key,bool blank,any default_value):db::core::BaseField(name,max_length,unique,primary_key,blank,default_value) {
}

string IntegerField::to_db_value(any value) {
	stringstream s;
	if (value.type()!=typeid(int)) {
		s<<"IntegerField::to_db_value(any),argument is ";
		s<<any_type_cast(value.type().name());
		s<<" ,should be int";
		throw db::core::Error(s.str());
	}
	s.str("");
	int v=boost::any_cast<int>(value);
	s<<v;
	return s.str();
}

any IntegerField::to_cpp_value(string value) {
	int return_value;
	try {
		return_value=boost::lexical_cast<int>(value);
	} catch (const boost::bad_lexical_cast&) {
		throw db::core::Error("input is not valid");
	}
	return return_value;
}

IntegerField::~IntegerField() {
}

string IntegerField::any_type_cast(string type) {
	if (type=="d") {
		return "double";
	} else if (type=="f") {
		return "float";
	}
	return "unknown";
}

bool IntegerField::validate(any value) {
	if (value.type()!=typeid(int))
		return false;
	return true;
}

any IntegerField::__add__(any a,any b) {
	if (a.type()==typeid(int) && b.type()==typeid(int)) {
		int t1=boost::any_cast<int>(a);
		int t2=boost::any_cast<int>(b);
		return t1+t2;
	} else {
		throw new db::core::Error("input is no valid2");
	}
	return NULL;
}
string IntegerField::to_screen_value(any value) {
	return to_db_value(value);
}

