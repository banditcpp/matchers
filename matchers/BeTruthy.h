#ifndef MATCHERS_BETRUTHY_H
#define MATCHERS_BETRUTHY_H

#include "Matcher.h"

namespace Matchers {

    class BeTruthy : public Matcher
    {
    private:
        BeTruthy& operator=(const BeTruthy&);

    public:
        BeTruthy() : Matcher() {}
        ~BeTruthy() {}

        template<typename U>
        bool matches(const U& actualValue) const
	{
	    return bool(actualValue);
	}


    protected:
        virtual std::string failure_message_end() const
	{
	    return std::string("evaluate to true");
	}
    };

    static const BeTruthy be_truthy = BeTruthy();
}

#endif
