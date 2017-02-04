#ifndef MATCHERS_BEFALSY_H
#define MATCHERS_BEFALSY_H

#include "Matcher.h"

namespace Matchers {

    class BeFalsy : public Matcher
    {
    private:
        BeFalsy& operator=(const BeFalsy&);

    public:
        BeFalsy() : Matcher() {}
        BeFalsy(const BeFalsy &) = default;
        ~BeFalsy() {}

        template<typename U>
        bool matches(const U& actualValue) const
	{
	    return !bool(actualValue);
	}


    protected:
        virtual std::string failure_message_end() const
	{
	    return std::string("evaluate to false");
	}
    };

    static const BeFalsy be_falsy = BeFalsy();
}

#endif
