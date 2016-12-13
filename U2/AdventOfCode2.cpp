#include <iostream>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;

int main (void)
{
    /* Initialize variables */
    string line;
    string code;
    string::iterator it;
    int x_pos = 1;              // numpad position from left to right - 1,4,7 have x_pos of 0.
    int y_pos = 1;              // numpad position from up to down - 1,2,3 habe y_pos of 0.

    ifstream t("instructions.txt");

    /* read line by line, store the result in string */
    while (getline (t,line))
    {
        it = line.begin();
        while (it != line.end())
        {
            if(*it == 'R' and x_pos != 2)
                x_pos++;
            else if(*it == 'L' and x_pos != 0)
                x_pos--;
            else if(*it == 'U' and y_pos != 0)
                y_pos--;
            else if(*it == 'D' and y_pos != 2)
                y_pos++;

            it++;
        }
        code += y_pos*3 + x_pos + 1 + '0';      // button position into string (without C++11 support)
    }
    t.close();

    cout << "Final code: " << code << endl;
    return 0;
}