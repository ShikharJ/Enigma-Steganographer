#include "user_interface.h"
#include "rotor_configs.h"
#include "rotor_manager.h"
#include "plugboard.h"

using namespace std;

UserInterface::UserInterface()
{
    string s = "files/main_screen.bin";
    print_screen(s);
    char ch;
    ch = getchar();
}

void UserInterface::clear()
{
    for (int i = 0; i < 10; i++){
        cout<<"\n\n\n";
    }
}

void UserInterface::show_main_menu()
{
    string s = "files/main_menu.bin";
    print_screen(s);

    do
    {
        _option = getchar();
    } while (!(_option != '1' or _option != '2' or _option != '3' or  _option != '4'));

    switch (_option)
    {
        case '1' : encrypt();
                   break;
        case '2' : decrypt();
                   break;
        case '3' : show_about();
                   break;
        case '4' : exit(0);
        default : cout << "\nUnexpected Error!\n";
    }
    show_main_menu();
}

void UserInterface::show_about()
{
    string s = "files/about.bin";
    print_screen(s);

    do
    {
        _option = getchar();
    } while (_option != '1');

    show_main_menu();
}

void UserInterface::encrypt()
{
    clear();

    //Default Values
    int num_rotors;
    bool use_plugboard = false;
    char input;

    //Default objection values
    string message = "";
    string returned = "";
    set_config();

    cout << "Enter the Number of Rotors (Available = 5): ";
    do
    {
        cin >> num_rotors;
    } while (!(num_rotors != 1 or num_rotors != 2 or num_rotors != 3 or  num_rotors != 4 or num_rotors != 5));

    //Initalize the RotorManager
    RotorManager *rotor_set = new RotorManager(num_rotors);

    //From right to left
    for (int i = 1; i <= num_rotors; i++) {
        int seq;
        cout << "\nEnter the sequence number for Rotor " << i << ": ";
        cin >> seq;
        if (i  == 1)
            rotor_set->set_rotor(1, seq, primary);
        else if (i == 2)
            rotor_set->set_rotor(2, seq, secondary);
        else if (i == 3)
            rotor_set->set_rotor(3, seq, tertiary);
        else if (i == 4)
            rotor_set->set_rotor(4, seq, quarternary);
        else if (i == 5)
            rotor_set->set_rotor(5, seq, quinary);

        if (i == num_rotors)
            rotor_set->print_rotor_status();
    }

    //Read in a string to encrypt

    cout << "\nEnter Message to Encrypt (No Spaces): ";
    cin >> message;

    cout << "\nUse Plug-Board [Y/N]: ";
    cin >> input;

    if (input == 'Y')
        use_plugboard = true;

    if(use_plugboard)
    {
        message = plugboard_execute(message);
    }

    for (int i = 0; i < message.length(); i++)
    {
        returned += rotor_set->process_letter(message[i]);
    }

    if (use_plugboard)
    {
        returned = plugboard_execute(returned);
    }

    cout << "\nThe Encrypted Message: " << returned;

    delete rotor_set;
    delete_configs();
    input = getchar();
    input = getchar();
    show_main_menu();
}

void UserInterface::decrypt()
{
    clear();

    //Default Values
    int num_rotors;
    bool use_plugboard = false;
    char input;

    //Default objection values
    string message = "";
    string returned = "";
    set_config();

    cout << "Enter the Number of Rotors Taken While Encrypting (Available = 5): ";
    do
    {
        cin >> num_rotors;
    } while (!(num_rotors != 1 or num_rotors != 2 or num_rotors != 3 or  num_rotors != 4 or num_rotors != 5));

    //Initalize the RotorManager
    RotorManager *rotor_set = new RotorManager(num_rotors);

    //From right to left
    for (int i = 1; i <= num_rotors; i++) {
        int seq;
        cout << "\nEnter the Sequence Numbers for Rotor Taken While Encrypting " << i << ": ";
        cin >> seq;
        if (i  == 1)
            rotor_set->set_rotor(1, seq, primary);
        else if (i == 2)
            rotor_set->set_rotor(2, seq, secondary);
        else if (i == 3)
            rotor_set->set_rotor(3, seq, tertiary);
        else if (i == 4)
            rotor_set->set_rotor(4, seq, quarternary);
        else if (i == 5)
            rotor_set->set_rotor(5, seq, quinary);

        if (i == num_rotors)
            rotor_set->print_rotor_status();
    }

    //Read in a string to decrypt
    message = "";

    cout << "Enter Message to Decrypt (No Spaces): ";
    cin >> message;

    cout << "Used Plug-Board ? [Y/N]: ";
    cin >> input;

    if (input == 'Y')
        use_plugboard = true;

    if(use_plugboard)
    {
        message = plugboard_execute(message);
    }

    for (int i = 0; i < message.length(); i++)
    {
        returned += rotor_set->process_letter(message[i]);
    }

    if (use_plugboard)
    {
        returned = plugboard_execute(returned);
    }

    cout << "\nThe Decrypted Message: " << returned;

    delete rotor_set;
    delete_configs();
    input = getchar();
    input = getchar();
    show_main_menu();
}

void UserInterface::print_screen(string s)
{
    clear();
    ifstream fin;
    fin.open(s, ios_base::in);
    char ch;

    while (fin.read(&ch, sizeof(ch)))
    {
        cout << ch;
    }

    fin.close();
}