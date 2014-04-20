#ifndef _DB_ERROR_H_
#define _DB_ERROR_H_

#include <string>
#include <ctime>
#include <sstream>

using std::string;

namespace db {
namespace core {

	class Error{
	  protected:
		time_t _time;
		string _message;
	  public:
		Error(string message):_message(message) {
			_time = std::time(0);
		}
		Error(const Error &another) {
			_message=another._message;
			_time=another._time;
		}
		string what() {
			return _message;
		}
		time_t time() {
			return _time;
		}
		string datetime() {
			struct tm *t = localtime(&_time);
			std::stringstream ss;
			ss<<(t->tm_year+1900)<<"-";
			ss<<(t->tm_mon+1)<<"-";
			ss<<t->tm_mday<<" ";
			ss<<t->tm_hour<<":";
			ss<<t->tm_min<<":";
			ss<<t->tm_sec;
			delete t;
			return ss.str();
		}
		~Error() {
		}
	};

};
};

#endif
