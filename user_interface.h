#ifndef ENIGMA_USER_INTERFACE_H
#define ENIGMA_USER_INTERFACE_H

#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <cstdio>
#include <fstream>

using namespace std;

class UserInterface
{
    char _option;

public:
    UserInterface();
    void clear();
    void show_main_menu();
    void show_about();
    void encrypt();
    void decrypt();
    void print_screen(string s);
};

#endif //ENIGMA_USER_INTERFACE_H
