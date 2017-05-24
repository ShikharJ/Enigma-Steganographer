#include "rotor.h"

using namespace std;

Rotor::Rotor():_sequence(0)
{
}

Rotor::Rotor(int sequence):_sequence(sequence)
{
}

void Rotor::set_rotor_key(vector<int> key)
{
    _key = key;
}

int Rotor::get_sequence()
{
    return _sequence;
}

int Rotor::turn_rotor()
{
    if (_key.size())
    {
        int first = _key[0];
        _key.erase(_key.begin());
        _key.push_back(first);
    }
    _sequence += 1;
    if (_sequence == 26)
    {
        _sequence = 0;
        return 1;
    }
    return 0;
}

void Rotor::set_rotor(int new_sequence)
{
    _sequence = new_sequence;
    for (int i = 0; i < new_sequence; i++)
    {
        if (_key.size())
        {
            int first = _key[0];
            _key.erase(_key.begin());
            _key.push_back(first);
        }
    }
}

vector<int>* Rotor::get_rotor_key()
{
    return &_key;
}

int Rotor::shift_letter(int letter)
{
    return _key[letter];
}

int Rotor::shift_letter_reverse(int letter)
{
    for (int i = 0; i < 26; i++)
    {
        if (_key[i] == letter)
            return i;
    }
    return 0;
}

Rotor::~Rotor()
{
    _key.clear();
}
