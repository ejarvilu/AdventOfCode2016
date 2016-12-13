#ifndef __ENCRYPTION_HPP_INCLUDED__
#define __ENCRYPTION_HPP_INCLUDED__

using namespace std;

/* Include statements */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

/* Split function (from previous exercise) */
vector<string> split(const char *str, char delimiter = ' ')
{
    vector<string> result;

    do
    {
        /* skip tokens that begin with the delimiter... */
        if (*str == delimiter)
            continue;
        
        const char *begin = str;

        while(*str != delimiter && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}
#endif