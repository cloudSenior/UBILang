#pragma once

#include <vector>
#include <sstream>
#include <algorithm> 
#include <cctype>
#include <locale>



#include "defs.hh"


namespace util {

class {
public:
    static std::vector<std::string> split(std::string const& s,
        char const& delim)
    {
        std::stringstream ss(s);
        std::string item;
        std::vector<std::string> elems;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    static inline void leftTrim(str& input)
    {
        input.erase(std::find_if(input.begin(), input.end(),
                        [](unsigned char ch) { return std::isspace(ch); }),
            input.end());
    }

    static inline void rightTrim(str input)
    {
        input.erase(std::find_if(input.rbegin(), input.rend(),
                        [](unsigned char ch) { return std::isspace(ch); })
                        .base(),
            input.end());
    }

    static inline str trim(str& input)
    {
        const str whiteSpaces = " \t\n\r\f\v";

        size_t first_non_space = input.find_first_not_of(whiteSpaces);

        input.erase(0, first_non_space);

        size_t last_non_space = input.find_last_not_of(whiteSpaces);

        input.erase(last_non_space + 1);

        return input;
    }

    static inline str reverse(str& input)
    {
        input.reserve();
        return input;
    }

    static str sub(str input, uint32 start, uint32 end)
    {
        str temp = input.substr(start, end);
        return temp;
    }

    static bool isNumber(str input)
    {
        std::string::const_iterator it = input.begin();
        while (it != input.end() && std::isdigit(*it))
            ++it;
        return !input.empty() && it == input.end();
    }

} String;

}