#include "rotor_manager.h"
#include "reflector.h"

using namespace std;

RotorManager::RotorManager()
{
}

RotorManager::RotorManager(int num_rotors)
{
    for (int i = 0; i < num_rotors; i++)
    {
        _rotors.push_back(new Rotor());
    }
}

void RotorManager::turn()
{
    auto num_rotors = _rotors.size();
    int kick = 1;

    while(kick && num_rotors)
    {
        num_rotors -= 1;
        kick = _rotors[num_rotors]->turn_rotor();
    }
}

void RotorManager::set_rotor(int rotor_number, int sequence, vector<int> key)
{
    auto num_rotors = _rotors.size();
    _rotors[num_rotors-rotor_number]->set_rotor_key(key);
    _rotors[num_rotors-rotor_number]->set_rotor(sequence%26);
}

void RotorManager::print_rotor_status()
{
    auto num_rotors = _rotors.size();
    cout << "\nRotors are at positions: ";
    for(int i = 0; i < num_rotors; i++)
    {
        cout << _rotors[i]->get_sequence() << " ";
    }
    cout << "\n";
}

char RotorManager::process_letter(char input)
{
    int letter = input - 65;
    auto num_rotors = _rotors.size();
    for(int i = 1; i <= num_rotors; i++)
    {
        letter = _rotors[num_rotors - i]->shift_letter(letter);
        if(letter > 25)
        {
            letter %= 26;
        }
    }
    letter = reflection(letter + 65, _rotors[0]);
    letter -= 65;
    for(int i = 1; i < num_rotors; i++)
    {
        letter = _rotors[i]->shift_letter_reverse(letter);
        if(letter > 25)
        {
            letter %= 26;
        }
    }
    turn();
    return letter + 65;
}

RotorManager::~RotorManager()
{
    auto num_rotors = _rotors.size();
    for (int i = 0; i < num_rotors; i++)
    {
        delete _rotors[i];
    }
    _rotors.clear();
}
