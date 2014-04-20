#ifndef _DEFAULT_RECORD_H_
#define _DEFAULT_RECORD_H_
#include "../core/record.h"
#include <iostream>
using std::ostream;
class Record:public db::core::BaseRecord {
  public:
	Record(db::core::BaseField*,any);	
	~Record();
	db::core::BaseRecord* operator+(any);
	string print();
};

#endif
