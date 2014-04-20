#ifndef _DEFAULT_RECORD_H_
#define _DEFAULT_RECORD_H_
#include "../core/record.h"
#include <iostream>
using std::ostream;
using db::core::BaseField;
class Record:public db::core::BaseRecord {
  public:
	Record(db::core::BaseField*,any);	
	~Record();
	string print();
    BaseRecord* operator+(any);	
};

#endif
