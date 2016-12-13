#ifndef __TRIANGLES_HPP_INCLUDED__
#define __TRIANGLES_HPP_INCLUDED__

/* Include statements */
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

/* Split function */
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