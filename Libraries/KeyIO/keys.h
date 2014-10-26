

#ifndef KEYS_H
#define KEYS_H

#include <string>

//Windows virtual keys
#define ZERO_CODE 0x30
#define LOWER_A_CODE 0x41


using namespace std;

class Keypress
{

public:


//This function takes a string, and returns the index of the letter which has been
//entered. It will return -1 if the letter has not been entered.
int get_code(std::string importantKeys);
int get_code();

bool get_code(int keyCode);
short get_current_code(int keyCode);

bool get_code(bool* wasKeyPressed, bool* isKeyDown, std::string charToCheck);

};


//http://msdn.microsoft.com/en-us/library/windows/desktop/ms645617%28v=vs.85%29.aspx
//Ideas for control?












#endif
