#include "triangles.hpp"

using namespace std;

int main(void)
{
    /* Initialize variables */
    string line;
    char delimiter = ' ';
    vector<string> tokens;
    vector<int> edges;
    int max = 0, max_idx = -1, val = 0, sum = 0, possibles = 0;

    ifstream t("triangles.txt");

    /* read line by line, store the result in a string */
    while (getline (t,line))
    {
        tokens = split(line.c_str(),delimiter);

        /* get max value of the vector */
        for(int i=0;i<3;i++)
        {
            val = atoi(tokens[i].c_str());
            edges.push_back(val);
                
            if (val > max)
            {
                max = val;
                max_idx = i;
            }
        }

        /* Test 1: check whether the sum of 2 remaining edges is greater than that of the longest edge */
        for(int i=0;i<3;i++)
        {
            if (i == max_idx)
                continue;       // Skip the longest edge

            sum += edges[i];
        }

        /* Conclude whether the triangle is possible */
        if (max < sum)
            possibles++;

        sum = 0;
        max = 0;
        edges.clear();
    }

    t.close();
    cout << possibles << endl;
    return 0;
}