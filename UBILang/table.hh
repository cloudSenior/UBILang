#pragma once

#include "defs.hh"



namespace util {

class {
public:
    template <typename Key, typename Value>
    static bool isValidKey(table<Key, Value>& tbl, Key find)
    {

        for (table<str, lexer::command>::iterator iter = tbl.begin();
             iter != tbl.end(); ++iter) {
            if (iter->first == find)
                return true;
        }

        return false;
    }

} Table;

}