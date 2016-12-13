#include "encryption.hpp"

using namespace std;

int main(void)
{
    /* Initialize variables */
    string line;
    string checksum;
    string sector_id_str;
    char delimiter = '-';
    int sector_id_sum = 0;
    
    vector<int>::iterator max;
    string::iterator it;
    string::iterator end;
    vector<string> tokens;
    vector<int> char_count;             // contains number of alphabetical characters found on the checksum. char_count[0] is the count of 'a' chars, and so forth.

    ifstream t("rooms.txt");

    while (getline (t,line))
    {

        for (int i=0;i<26;i++)         
            char_count.push_back(0);     // Initialize character count

        tokens = split(line.c_str(),delimiter);     // Room numbers and checksum / sector field.

        /* count characters in all room numbers - skip checksum / sector field */
        for (int i=0;i<tokens.size()-1;i++)
        {
            it = tokens[i].begin();
            end = tokens[i].end();
            while (it != end)
            {
                char_count[*it - 97]++;
                it++;
            }
        }

        /* check results against the checksum string */
        end = tokens[tokens.size()-1].end();
        sector_id_str = "";

        for(it = tokens[tokens.size()-1].begin();it != end; it++)
        {
            if(*it <= 57 and *it >= 48)                 // if numerical -> Sector id 
            {
                sector_id_str += *it;
            }
            else if (*it <= 122 and *it >= 97)          // if alphabetical -> checksum
            {
                max = max_element(char_count.begin(),char_count.end());

                /*
                // For Debugging....
                char test;
                test = max - char_count.begin() + 97;
                cout << "Most common char, according to checksum: " << *it << endl;
                cout << "Most common char, accorind to vector: " << test << endl;
                */

                if (*it != max - char_count.begin() + 97)                // Break loop if this char is not the most common one in the vector.
                {
                    cout << "Breaking. " << endl;
                    break;
                }
                *max = 0;
            }
            
            if (it == end-1)
            {
                cout << "This room seems OK. Adding sector id: " << atoi(sector_id_str.c_str()) << endl;
                sector_id_sum += atoi(sector_id_str.c_str());
                cout << "Total sector id sum: " <<  sector_id_sum << endl;
            }
        }
        char_count.clear();
    }
    
    cout << "Sum of Sector ID's of real rooms: " << sector_id_sum << endl;
    return 0;
}