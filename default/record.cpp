#include "record.h"
#include "../core/error.h"

Record::Record(db::core::BaseField* field,any value):db::core::BaseRecord(field,value) {
	if (!_field->validate(value))
		throw db::core::Error("invalid argument");
}
Record::~Record() {}
db::core::BaseRecord* Record::operator+(any other) {
	if (other.type()==typeid(db::core::BaseRecord*)) {
		_value=_field->__add__(_value,(boost::any_cast<BaseRecord*>(other))->value());	
	} else {
		_value=_field->__add__(_value,other);
	}
	return this;
}
string Record::print() {
	return _field->to_screen_value(_value);
}

