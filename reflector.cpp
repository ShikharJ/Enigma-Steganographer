#include "reflector.h"

using namespace std;

char reflection(char letter, Rotor *last)
{
    //Default configuration for reflector swapping
    vector<pair<char, char>> reflector = {{'A', 'E'}, {'B', 'J'}, {'C', 'M'}, {'D', 'Z'}, {'F', 'L'},
                                          {'G', 'Y'}, {'H', 'X'}, {'I', 'V'}, {'K', 'W'}, {'N', 'R'},
                                          {'O', 'Q'}, {'P', 'U'}, {'S', 'T'}};

    vector<int> key = *last->get_rotor_key();
    char mapper = 'A';

    for (int i = 0; i < 13; i++)
    {
        if (reflector[i].first == letter)
        {
            mapper = reflector[i].second;
            break;
        } else if (reflector[i].second == letter)
        {
            mapper = reflector[i].first;
            break;
        }
    }

    int mappertoint = mapper - 65;
    for (int i = 0; i < 26; i++)
    {
        if (key[i] == mappertoint)
            return i + 65;
    }

    return 'A';
}
