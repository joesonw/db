#ifndef _DB_RECORD_H_
#define _DB_RECORD_H_
#include "field.h"
#include <iostream>
#include <sstream>
#include "error.h"

namespace db {
namespace core {
	class BaseRecord {
	  protected:
		any _value;
		db::core::BaseField* _field;
	  public:
		BaseRecord(db::core::BaseField* field,any value) {
			_field=field;
			_value=value;
		}
		virtual ~BaseRecord() {}
		virtual string print()=0;
		virtual any value() {return _value;}
		virtual BaseRecord* operator+(any)=0;
	};

};
};


#endif
