#include <iostream>

using namespace std;

#include "D:\DorianCode\UsefulDLL\FileIO\FileIODLL\FileIODLL.h"

int main()
{
   FileIOName::FileIO test;
   test.textOpenFile("testFile.txt", false);

   cout<<test.writeLine("This is a test!");
    cout << "Hello world!" << endl;
    return 0;
}
