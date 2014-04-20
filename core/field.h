#ifndef _DB_FIELD_H_
#define _DB_FIELD_H_
#include <string>
#include <boost/any.hpp>
#include <string>

using boost::any;
using std::string;


namespace db {
namespace core {

	class BaseField {
	  protected:
		string _name;
		unsigned _max_length;
		bool _unique;
		bool _primary_key;
		bool _blank;
		any _default_value;

	  public:
		BaseField(string name,unsigned max_length=0,bool unique=false,bool primary_key=false,bool blank=false,any default_value=NULL):_name(name),_max_length(max_length),_unique(unique),_primary_key(primary_key),_blank(blank),_default_value(default_value) {}
		string name();
		unsigned max_length();
		bool unique();
		bool primary_key();
		bool blank();
		any default_value();
		//interfaces;
		virtual ~BaseField() {}
		virtual string to_db_value(any)=0;
		virtual any to_cpp_value(string)=0;
		virtual string to_screen_value(any)=0;
		virtual bool validate(any)=0;
		virtual any __add__(any,any)=0;
	};
};
};

#endif
