#ifndef MATCHERS_MUST_H
#define MATCHERS_MUST_H

#include "ValueProxy.h"

namespace Matchers
{
    struct ValueMarker
    {
        const char* filename;
        int lineNumber;
    };

    template<typename T>
    const ValueProxy<T> operator,(const T& value, const ValueMarker& marker)
    {
        return ValueProxy<T>(marker.filename, marker.lineNumber, value);
    }

    template<typename T>
    const MatchProxy<T> operator,(const ValueProxy<T>& value, bool negate)
    {
        return negate ? value.to_not : value.to;
    }

    template<typename T, typename MatcherType>
    void operator,(const MatchProxy<T>& matchProxy, const MatcherType& matcher)
    {
        matchProxy(matcher);
    }
}

#define must     , Matchers::ValueMarker{__FILE__, __LINE__},false,
#define must_not , Matchers::ValueMarker{__FILE__, __LINE__},true,

#endif
