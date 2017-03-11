#include "plugboard.h"
#include <vector>

using namespace std;

string plugboard_execute(string msg)
{
    //Default configuration for plugboard swapping
    vector<pair<char, char>> swapper = {{'A', 'V'}, {'B', 'X'}, {'C', 'Y'}, {'D', 'T'}, {'E', 'P'},
                                        {'F', 'S'}, {'G', 'Z'}, {'H', 'W'}, {'I', 'N'}, {'J', 'O'},
                                        {'K', 'U'}, {'L', 'R'}, {'M', 'Q'}};
    string postplugboard = "";
    for (int i = 0; i < msg.length(); i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (swapper[j].first == msg[i])
            {
                postplugboard += swapper[j].second;
            } else if (swapper[j].second == msg[i])
            {
                postplugboard += swapper[j].first;
            }
        }
    }
    return postplugboard;
}

