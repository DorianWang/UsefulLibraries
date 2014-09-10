#ifndef FILEIO_H
#define FILEIO_H

#include <windows.h>

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdarg>
#include <cstdlib>
#include <vector>

#define MAX_BUFFER 4096
#define MAX_DATA_LENGTH 256

#ifdef BUILD_DLL
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT __declspec(dllimport)
#endif



/*  To use this exported function of dll, include this header
 *  in your project.
 */
//http://forums.codeblocks.org/index.php?topic=18328.0

//http://wiki.codeblocks.org/index.php?title=FAQ-Compiling_(general)#Q:_How_can_I_use_a_DLL_without_DEF_or_LIB_files.3F

#ifdef __cplusplus
extern "C"
{
#endif
//http://stackoverflow.com/questions/1041866/in-c-source-what-is-the-effect-of-extern-c


void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif


//http://msdn.microsoft.com/en-ca/library/ms235636.aspx
namespace MathFuncs
{

class FileIO
{
   public:
   //Variables
   std::fstream myfile;//input and output
   std::string filePath;

   bool isBinary;
   bool isOpen;

   unsigned long long fileLength;
   bool dataInLineBuffer;

   //Functions
   FileIO();
   ~FileIO();

   int returnStart();

   bool getProfile(std::string name);
   bool makeProfile(std::string name);
   bool writeDwarf();

   //opening files >>>>>

   //If isFirstTime is true, the file will be created, closed and then reopened.
   //Attempting to use a file without creating it first will not work.
   int textOpenFile(std::string fileName, bool isFirstTime);
   int dataOpenFile(std::string filePath, bool isFirstTime);
   // <<<<<

   //reading data >>>>>
   int readLine(std::string *output);
   int readWholeLine(std::string *output);

   int readIntData(int *output);
   int readData(int dataLength, int arrayLength, int* errorNum, ...);
   // <<<<<

   //moving the read/write
   int goStart(int isRead);
   int goEnd(int isRead);
   int goPos(int isRead, int position);

   //Writing data
   int writeDataToFile(const char* data, int length);
   int writeData(int dataLength, int arrayLength, ...);

   int writeLine(std::string output);
   int writeStringText(std::string output);

   //Other stuff
   std::string getFileName(bool isBinary);
   int deleteFile(std::string *fileName);
   bool checkIfOpen();

   //Line buffer stuff, to allow for storage in the object. More convienient.
   void bufferLines(std::string input);
   void bufferAddition(std::string input);
   void writeBuffer();
   void writeBuffer(bool clearData);
   void clearBuffer();
   int clearBuffer(int line);

   //Data buffer stuff
   void bufferData(const void* input, int sizeOfData, int arrayLength);

   int writeBufferData();
   int writeBufferData(int dummy);

   void clearDataBuffer();
   void clearDataBuffer(int dummy);

   //Closing the file >>>>>
   //The first one checks if the file is open before attempting to close
   //The second will, no matter what.
   int closeFile();
   void closeFile(bool asdf);
   // <<<<<

   unsigned long long getFileLength();

   ;
   private: //These should not be messed with. I'm not even sure how they work...

   int lineCounter;
   int dataCounter;

   std::vector <std::string> lineBuffer;
   std::string lineBufferBuffer;//For extra storage...

   std::vector <char> dataBuffer;

   void fileConstructor();





};

}

#endif // header
