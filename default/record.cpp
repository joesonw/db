#include "record.h"
#include "../core/error.h"

Record::Record(BaseField* field,any value):BaseRecord(field,value) {
	if (!_field->validate(value))
		throw db::core::Error("invalid argument");
}

Record::~Record() {}

string Record::print() {
	return _field->to_screen_value(_value);
}

db::core::BaseRecord* Record::operator+(any other) {
	std::cout<<"ww"<<std::endl;
	any result;
	try {
		if (other.type()==typeid(db::core::BaseRecord*)) {
			result=_field->__add__(_value,(boost::any_cast<db::core::BaseRecord*>(other))->value());
		} else {
			result=_field->__add__(_value,other);
		}
	} catch (db::core::Error &e) {
		throw db::core::Error(e);
	}
	return new Record(_field,result);
}
