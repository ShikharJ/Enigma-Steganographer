#ifndef ENIGMA_ROTOR_MANAGER_H
#define ENIGMA_ROTOR_MANAGER_H

#include "rotor.h"

using namespace std;

class RotorManager
{
    vector<Rotor *> _rotors;

public:
    RotorManager();
    RotorManager(int num_rotors);
    void turn();
    void print_rotor_status();
    void set_rotor(int rotor_number, int sequence, vector<int> key);
    char process_letter(char input);
    ~RotorManager();
};

#endif //ENIGMA_ROTOR_MANAGER_H
