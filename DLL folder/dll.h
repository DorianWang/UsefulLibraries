#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
# define DLLIMPORT __declspec (dllexport)
#else /* Not BUILDING_DLL */
# define DLLIMPORT __declspec (dllimport)
#endif /* Not BUILDING_DLL */

#include "FileIO.h"
#include "test.h"


namespace MyWin32DLL
{

class DLLIMPORT DllClass
{
  public:
    DllClass();
    virtual ~DllClass(void);

  private:

};



}

#endif /* _DLL_H_ */










//http://www.codeproject.com/Articles/655071/Basic-Cplusplus-Win-DLL
//http://www.codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL
//http://msdn.microsoft.com/en-ca/library/1ez7dh12.aspx
//http://www.ni.com/white-paper/3056/en/
//http://msdn.microsoft.com/en-ca/library/ms235636.aspx
//http://stackoverflow.com/questions/767579/exporting-classes-containing-std-objects-vector-map-etc-from-a-dll








