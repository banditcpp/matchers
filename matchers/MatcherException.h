#ifndef MATCHERS_MATCHER_EXCEPTION_H
#define MATCHERS_MATCHER_EXCEPTION_H

namespace Matchers {
    class MatcherException : public std::exception
    {
    public:
	MatcherException(const std::string& filename, const unsigned linenumber, const std::string& message) : _filename(filename), _linenumber(linenumber), _message(message) {}
	virtual ~MatcherException() throw() {}

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
