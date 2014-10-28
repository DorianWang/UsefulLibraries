#ifndef CONSOLEOPTIONS_H_INCLUDED
#define CONSOLEOPTIONS_H_INCLUDED

#include "CursorOptions.h"
#include <cstdlib>
#include <stdexcept>

class ConsoleOptions
{

public:

COptions cursorOptions;

int setConsoleSize(unsigned int width, unsigned int height);
void setConsoleTitle(std::string newName);

};

//Stuff is below


int ConsoleOptions::setConsoleSize(unsigned int width, unsigned int height)
{

   SMALL_RECT r;
   COORD      c;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   HANDLE hConOut = GetStdHandle( STD_OUTPUT_HANDLE );
   if (!GetConsoleScreenBufferInfo( hConOut, &csbi )){
      throw runtime_error( "You must be attached to a human." );
   }

      COORD maxSize1 = GetLargestConsoleWindowSize(hConOut);
//   cout<<maxSize1.X << " " <<maxSize1.Y<<endl;

   r.Left   = 0;
   r.Top    = 0;
   r.Right  = width -1;
   r.Bottom = height -1;
   SetConsoleWindowInfo( hConOut, TRUE, &r );

   c.X = width;
   c.Y = height;
   SetConsoleScreenBufferSize( hConOut, c );

   COORD maxSize = GetLargestConsoleWindowSize(hConOut);
//   cout<<maxSize.X << " " <<maxSize.Y<<endl;

}


void ConsoleOptions::setConsoleTitle(std::string newName)
{

SetConsoleTitle(newName.c_str());


//http://msdn.microsoft.com/en-us/library/windows/desktop/ms682073(v=vs.85).aspx
//http://www.cplusplus.com/forum/windows/10731/
}



//Graphics!
//http://lazyfoo.net/SDL_tutorials/lesson01/index.php
//http://lazyfoo.net/tutorials/OpenGL/index.php































#endif // CONSOLEOPTIONS_H_INCLUDED
