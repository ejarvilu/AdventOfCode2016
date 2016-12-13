#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>

using namespace std;

int main(void)
{
    std::ifstream t("instructions.txt");
    char c;
    int heading = 0;                // 0 = North, 1 = East, 2 = South, 3 = West
    int pos_x = 0;
    int pos_y = 0;
    int distance = 0;

    while(t.get(c))
    {
        // reset distance;
        distance = 0;
        if(c == 'L') 
        {
            // Find new heading
            heading--;
            if (heading == -1)
                heading = 3;
            
            // Find distance to travel - could be multiple numbers.
            t.get(c);
            while (isdigit(c))
            {
                distance =  distance*10 + c - '0';
                t.get(c);
            }

            if (heading == 0)
                pos_y += distance;
            if (heading == 1)
                pos_x += distance;
            if (heading == 2)
                pos_y -= distance;
            if (heading == 3)
                pos_x -= distance; 
        }
        else if (c == 'R')
        {
              // Find new heading
            heading++;
            if (heading == 4)
                heading = 0;
            
            // Find distance to travel
            t.get(c);
            while (isdigit(c))
            {
                distance =  distance*10 + c - '0';
                t.get(c);
            }

            if (heading == 0)
                pos_y += distance;
            if (heading == 1)
                pos_x += distance;
            if (heading == 2)
                pos_y -= distance;
            if (heading == 3)
                pos_x -= distance;        
        }
    }

    // Print out the final location.
    cout << "Total x coordinate: " << pos_x << endl;
    cout << "Total y coordinate: " << pos_y << endl;  

    return 0;
}