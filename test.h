#ifndef DLLIMPORT
# define DLLIMPORT __declspec (dllexport)
#endif
namespace MyWin32DLL
{
   
   
   class DLLIMPORT testClass
   {
      
      private:
         int varone;
      public:
         testClass();//constructor
         void Setvar(int val);
         int Getvar();
      
      
   };
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
}
