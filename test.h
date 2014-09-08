

namespace MyWin32DLL
{
   
   
   class testClass
   {
      
      private:
         int varone;
      public:
         __declspec(dllexport) testClass();//constructor
         __declspec(dllexport) void Setvar(int val);
         __declspec(dllexport) int Getvar();
      
      
   };
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
}
