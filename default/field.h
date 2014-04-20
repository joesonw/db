#ifndef _DEFAULT_FIELD_H_
#define _DEFAULT_FIELD_H_
#include "../core/field.h"
#include "../core/error.h"
#include <string>


using boost::any;
using std::string;

class IntegerField:public db::core::BaseField {
  public:
	IntegerField(string name,unsigned max_length=0,bool unique=false,bool primary_key=false,bool blank=false,any default_value=NULL);
	~IntegerField();
	string to_db_value(any);
	string to_screen_value(any);
	any to_cpp_value(string);
	bool validate(any);
	any __add__(any,any);
  private:
	string any_type_cast(string);
};
#endif
