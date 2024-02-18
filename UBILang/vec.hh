#pragma once

#include "defs.hh"


namespace util {

class {
public:
    template <typename T>
    static void remove(vec<T>& Of, size_t Index)
    {
        Of.erase(Of.cbegin() + Index);
    }

} Vec;

}