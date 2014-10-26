
#include <iostream>
#include <cstdlib>
#include "conio.h"
#include "keys.h"
#include "windows.h"

int Keypress::get_code(std::string importantKeys){
   Beep(800, 300);//Beep!
   int ch = _getch();
   Beep(600, 300);//Beep!
   int length = importantKeys.length();

   for(int i=0; i<length; i++){
      if(ch == importantKeys[i]){
         return i;
      }
   }
   return -1;
}// get_code

//returns 1 for enter, 2 for escape,3 for TAB etc.
//http://msdn.microsoft.com/en-us/library/windows/desktop/ms646293%28v=vs.85%29.aspx
//Please do not use.
int Keypress::get_code(){
   if (GetAsyncKeyState(VK_RETURN)){
      return 1;
   }
   else if (GetAsyncKeyState(VK_ESCAPE)){
      return 2;
   }
   else if (GetAsyncKeyState(VK_TAB)){
      return 3;
   }
   else if (GetAsyncKeyState(VK_SPACE)){
      return 4;
   }
   else if (GetAsyncKeyState(VK_BACK)){
      return 5;
   }
   if (GetAsyncKeyState(VK_LBUTTON)||GetAsyncKeyState(VK_RBUTTON)){
      return 6;
   }

    return -1;//No keys found
}

//Windows specific
bool Keypress::get_code(int keyCode)
{
   switch (keyCode){

      case 1:
         return GetAsyncKeyState(VK_RETURN);//Enter key
         break;
      case 2:
         return GetAsyncKeyState(VK_ESCAPE);//Escape key
         break;
      case 3:
         return GetAsyncKeyState(VK_TAB);//TAB key
         break;
      case 4:
         return GetAsyncKeyState(VK_SPACE);//Spacebar
         break;
      case 5:
         return GetAsyncKeyState(VK_BACK);//Backspace key
         break;
      case 6:
         return (GetAsyncKeyState(VK_LBUTTON)||GetAsyncKeyState(VK_RBUTTON));//Any mouse button
         break;
      case 7:
         return GetAsyncKeyState(VK_LBUTTON);//Left mouse button
         break;
      case 8:
         return GetAsyncKeyState(VK_RBUTTON);//Right mouse button
         break;
      case 9:
         return GetAsyncKeyState(VK_CONTROL);//Ctrl key
         break;
      case 10:
         return GetAsyncKeyState(VK_MENU);//Alt key, very strange name
         break;
      case 11:
         return GetAsyncKeyState(VK_SHIFT);//Shift key
         break;
   }

   return false;
}

short Keypress::get_current_code(int keyCode)
{
   switch (keyCode){

      case 1:
         return GetKeyState(VK_RETURN);//Enter key
         break;
      case 2:
         return GetKeyState(VK_ESCAPE);//Escape key
         break;
      case 3:
         return GetKeyState(VK_TAB);//TAB key
         break;
      case 4:
         return GetKeyState(VK_SPACE);//Spacebar
         break;
      case 5:
         return GetKeyState(VK_BACK);//Backspace key
         break;
      case 6:
         return (GetKeyState(VK_LBUTTON)||GetKeyState(VK_RBUTTON));//Any mouse button
         break;
      case 7:
         return GetKeyState(VK_LBUTTON);//Left mouse button
         break;
      case 8:
         return GetKeyState(VK_RBUTTON);//Right mouse button
         break;
      case 9:
         return GetKeyState(VK_CONTROL);//Ctrl key
         break;
      case 10:
         return GetKeyState(VK_MENU);//Alt key, very strange name
         break;
      case 11:
         return GetKeyState(VK_SHIFT);//Shift key
         break;
      case 12:
         return GetKeyState(VK_CAPITAL);
         break;
   }

   return -1;
}

bool Keypress::get_code(bool* wasKeyPressed, bool* isKeyDown, std::string charToCheck)
{
   //(SHORT == 2 BYTE)
   //http://msdn.microsoft.com/en-us/library/windows/desktop/ms646293%28v=vs.85%29.aspx
   unsigned short asyncReturn = 0;
   for (int i = 0; i < charToCheck.length(); i++){
      if (charToCheck[i] <= '9'&& charToCheck[i] >= '0'){

      }
      asyncReturn = GetAsyncKeyState(charToCheck[i] - 'a' + LOWER_A_CODE);
      //Returns 32769 if down, 1 if was pressed.
   }



}

































