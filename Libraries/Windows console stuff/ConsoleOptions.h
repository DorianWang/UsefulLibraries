#ifndef CONSOLEOPTIONS_H_INCLUDED
#define CONSOLEOPTIONS_H_INCLUDED

#include "CursorOptions.h"
#include "cstdlib"
#include <cstdlib>
#include <stdexcept>

class ConsoleOptions
{

public:

COptions cursorOptions;

int test();
int setConsoleSize(unsigned int width, unsigned int height);

};































#endif // CONSOLEOPTIONS_H_INCLUDED
