/*
 * A plugboard is simply used for
 * swapping of all the characters in the
 * original message to their predefined partner
 * to increase the complexity as well as the
 * total number of possible permutations of
 * the enigma cipher.
 */

#ifndef ENIGMA_PLUGBOARD_H
#define ENIGMA_PLUGBOARD_H

#include <iostream>
#include <string>

using namespace std;

string plugboard_execute(string msg);

#endif //ENIGMA_PLUGBOARD_H
