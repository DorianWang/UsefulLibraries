#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>
#include <iostream>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void DLL_EXPORT SomeFunction(const LPCSTR sometext);

#ifdef __cplusplus
}
#endif


#define ZERO_CODE 0x30
#define LOWER_A_CODE 0x41

namespace KeyIOName
{

class DLL_EXPORT Keypress
{

public:


//This function takes a string, and returns the index of the letter which has been
//entered. It will return -1 if the letter has not been entered.
int get_code(std::string importantKeys);
int get_code();

bool get_code(int keyCode);
short get_current_code(int keyCode);

};


}



#endif // __MAIN_H__
