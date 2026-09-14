#ifndef UTIL_OVERLOADS_H
#define UTIL_OVERLOADS_H

namespace Util {

// i don't really get why this can't be in the standard library
template<class... Ts>
struct Overloads : Ts... { using Ts::operator()...; };

}

#endif