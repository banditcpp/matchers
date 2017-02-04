#ifndef MATCHERS_MATCHER_EXCEPTION_H
#define MATCHERS_MATCHER_EXCEPTION_H

#include <stdexcept>

namespace Matchers {
    class MatcherException : public std::exception
    {
    public:
	MatcherException(const std::string& fn, const unsigned lineno, const std::string& msg) : _filename(fn), _linenumber(lineno), _message(msg) {}
	virtual ~MatcherException() noexcept {}

	std::string& filename()	{ return _message; }
	unsigned linenumber()	{ return _linenumber; }
	std::string& message()	{ return _message; }

    private:
	std::string	_filename;
	unsigned	_linenumber;
	std::string	_message;
    };
}

#endif
