#include <iostream>

using namespace std;

#include "FileIODLL.h"
#include "KeyIODLL.h"

//http://www.learncpp.com/cpp-tutorial/a3-using-libraries-with-codeblocks/

int main()
{
   FileIOName::FileIO test;
   KeyIOName::Keypress KeyIO;
   test.textOpenFile("testFile.txt", false);

   int temp = -1;
   cout<<test.writeLine("This is a test!");

   while (true){
      temp = KeyIO.get_code("qwerty");

    if (temp != -1){ break; }

   }


    cout << "Hello world!" << endl;
    return 0;
}
