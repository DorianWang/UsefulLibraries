
#ifndef COPTIONS_H
#define COPTIONS_H

#include <cstdarg>//Variable lists

#include "windows.h"
#include "stdio.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class COptions
{

bool cursorVisibility;
bool cursorSmall;
HANDLE consoleHandle;

int currentColour;

public:

COptions();
~COptions();

int toggleColour(HANDLE cHandle);

void returnDefault(HANDLE cHandle);
void toggleCursorSize(HANDLE cHandle);
void toggleCursor(HANDLE cHandle);
void tempColourChange(bool isDiff, HANDLE cHandle, int targetColour);
void changeCursorInsert(HANDLE cHandle, bool insertMode);


bool changeCursorPos(short cursorX, short cursorY);

void cursorControl(int optionNum);//Controls all other functions. 0 for cursor visible. 1 for opposite, 2 for colour change, 5 for defaults, etc.

void changeCurrentWindowText(const char* newText);//Changes the currently selected console's name.

};

#endif
