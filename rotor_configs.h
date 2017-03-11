#ifndef ENIGMA_ROTOR_CONFIGS_H
#define ENIGMA_ROTOR_CONFIGS_H

#include <vector>

using namespace std;

vector<int> primary, secondary, tertiary, quarternary, quinary;

void set_config()
{
    //Refer https://en.wikipedia.org/wiki/Enigma_rotor_details#Rotor_wiring_tables
    //Mapped according to relative alphabetical order
    //Rotor I - 1930 / Enigma I
    primary = {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9};
    //Rotor II - 1930 / Enigma I
    secondary = {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
    //Rotor III - 1930 / Enigma I
    tertiary = {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
    //Rotor IV - December 1938 / M3 Army
    quarternary = {4, 18, 14, 21, 15, 25, 9, 0, 24, 16, 20, 8, 17, 7, 23, 11, 13, 5, 19, 6, 10, 3, 2, 12, 22, 1};
    //Rotor V - December 1938 / M3 Army
    quinary = {21, 25, 1, 17, 6, 8, 19, 24, 20, 15, 18, 3, 13, 7, 11, 23, 0, 22, 12, 9, 16, 14, 5, 4, 2, 10};
}

void delete_configs()
{
    primary.clear();
    secondary.clear();
    tertiary.clear();
    quarternary.clear();
    quinary.clear();
}

#endif //ENIGMA_ROTOR_CONFIGS_H
