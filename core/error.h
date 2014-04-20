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
		struct tm * _time;
		string _message;
	  public:
		Error(string message):_message(message) {
			time_t t = std::time(0);
			_time=std::localtime(&t);
		}
		string what() {
			return _message;
		}
		struct tm* time() {
			return _time;
		}
		string datetime() {
			std::stringstream ss;
			ss<<(_time->tm_year+1900)<<"-";
			ss<<(_time->tm_mon+1)<<"-";
			ss<<_time->tm_mday<<" ";
			ss<<_time->tm_hour<<":";
			ss<<_time->tm_min<<":";
			ss<<_time->tm_sec;
			return ss.str();
		}
		~Error() {
			delete _time;
			_time=0;
		}
	};

};
};

#endif
