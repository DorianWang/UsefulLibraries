
#include "CursorOptions.h"



//#define ENABLE_INSERT_MODE 0x0020
//#define ENABLE_EXTENDED_FLAGS 0x0080

using namespace std;

COptions::COptions()
{

cursorVisibility = true;
cursorSmall = true;
currentColour=7;
consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

}

COptions::~COptions()
{

}

void COptions::toggleCursor(HANDLE cHandle)
{

   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;

   if (cursorVisibility){
   cursorVisibility = false;
   info.bVisible = cursorVisibility;
   }
   else
   {
   cursorVisibility = true;
   info.bVisible = cursorVisibility;
   }

   SetConsoleCursorInfo(cHandle, &info);

}

void COptions::toggleCursorSize(HANDLE cHandle)
{
//doesn't do stuff
   CONSOLE_CURSOR_INFO info;


   if (cursorSmall){
   cursorSmall=false;
   info.dwSize = 100;
   }
   else
   {
   cursorSmall=true;
   info.dwSize = 20;
   }

   SetConsoleCursorInfo(cHandle, &info);
}

int COptions::toggleColour(HANDLE cHandle)
{

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    if (cursorColour>14){
    cursorColour=0;
    currentColour=0;
    }

    cursorColour+=1;
    currentColour+=1;
    SetConsoleTextAttribute(cHandle, cursorColour);

    return cursorColour;
    //0 is black, 1 is dark blue, 2 is green, 3 is cyan, 4 is dark red, 5 is magenta, 6 is gold, 7 is white, 8 is grey, 9 is blue, 10 is light green
    //11 is light blue, 12 is red, 13 is magenta, 14 is yellow, 15 is light grey, 16+ is highlighted

}// changes cursor colour

void COptions::returnDefault(HANDLE cHandle)
{

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    if (cursorColour!=15){
    currentColour=15;
    cursorColour=15;
    SetConsoleTextAttribute(cHandle, cursorColour);
    }

    if (cursorVisibility){
    toggleCursor(cHandle);
    }

    if (cursorSmall==false){
    toggleCursorSize(cHandle);
    }

}// changes cursor colour

void COptions::tempColourChange(bool isDiff, HANDLE cHandle, int targetColour)
{
   //if isDiff is true, change the colour to the target colour, otherwise, change it back

    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(cHandle, &con_info);
    int cursorColour = con_info.wAttributes;

    if(isDiff==false){
    currentColour=cursorColour;
    SetConsoleTextAttribute(cHandle, targetColour);
    }

    if(isDiff){
    cursorColour=currentColour;
    SetConsoleTextAttribute(cHandle, cursorColour);
    }

}

void COptions::cursorControl(int optionNum)
{
     bool debugDetector=true;
     if (optionNum == 0){

        if (cursorVisibility==false){
        toggleCursor(consoleHandle);
        }

        debugDetector=false;
     }//if cursor is false, make true

     if (optionNum == 1){

        if (cursorVisibility){
        toggleCursor(consoleHandle);
        }

        debugDetector=false;
     }//if cursor is true, make false

     if (optionNum==2){
        toggleColour(consoleHandle);
        debugDetector=false;
     }//change colour

     if (optionNum==3){
        returnDefault(consoleHandle);
        debugDetector=false;
     }//returns defaults

     if (optionNum==4){
        toggleCursor(consoleHandle); //force toggle
        debugDetector=false;
     }

     if (optionNum==5){
        changeCursorInsert(consoleHandle, true);//Insert mode
        debugDetector=false;
     }

     if (optionNum==6){
        changeCursorInsert(consoleHandle, false);//no Insert mode
        debugDetector=false;
     }

     if (optionNum==7){
        tempColourChange(false, consoleHandle, 15);
        debugDetector=false;
     }

     if (optionNum==8){
        tempColourChange(true,consoleHandle, 15);
        debugDetector=false;
     }

     if (optionNum==9){
        //changeWindowText("Stuff", consoleHandle);
        debugDetector=false;
     }

     //beyond this are unused

     if (optionNum==10){
        debugDetector=false;
     }



     if (debugDetector){
     cout<<"Something broke in CursorOptions.cpp"<<endl;
     }


}




bool COptions::changeCursorPos(short cursorX, short cursorY)
{

   int returningNum;
   COORD coord;
   coord.X = cursorX;
   coord.Y = cursorY;

   returningNum = SetConsoleCursorPosition(consoleHandle, coord);

   if (returningNum == 0){
      return false;
   }

   return true;
}

void COptions::changeCursorInsert(HANDLE cHandle, bool insertMode)
{
//DWORD mode = 0;
//DWORD otherThing = ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
//DWORD thing = ENABLE_EXTENDED_FLAGS;
//GetConsoleMode(cHandle, &mode);

   if (insertMode){
   SetConsoleMode(cHandle, ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS);
   }
   else
   {
   SetConsoleMode(cHandle, ENABLE_EXTENDED_FLAGS);
   }

}

void COptions::changeCurrentWindowText(const char* newText)//, HWND cHandle)
{
   HWND temp = GetActiveWindow();
   HWND temp2 = GetForegroundWindow();
   cout<<temp<<" "<<temp2<<endl;
   cout<<SetWindowText(temp2, newText)<<endl;;
}














