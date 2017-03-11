#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <iostream>
#include <vector>

using namespace std;

class Rotor
{
    int _sequence;
    vector<int> _key;

public:
    Rotor();
    Rotor(int sequence);
    void set_rotor_key(vector<int> key);
    int get_sequence();
    int turn_rotor();
    void set_rotor(int new_sequence);
    vector<int>* get_rotor_key();
    int shift_letter(int letter);
    int shift_letter_reverse(int letter);
    ~Rotor();
};

#endif //ENIGMA_ROTOR_H
