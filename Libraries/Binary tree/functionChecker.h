#ifndef FUNCTIONCHECKER_H
#define FUNCTIONCHECKER_H

#include <array>
#include <iostream>


namespace CHECK  // namespace
{


//IsPrimitiveValue
//{

template<class T>
struct IsPrimitiveType {
    enum { value = 0 };
};

template<>
struct IsPrimitiveType<int> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<char> {
    enum { value = 1 };
};
template<>
struct IsPrimitiveType<unsigned char> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<signed char> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<short> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<long long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned long> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned int> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<unsigned short> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<double> {
    enum { value = 1 };
};

template<>
struct IsPrimitiveType<float> {
    enum { value = 1 };
};

//Just adding this one in for completion.
template<>
struct IsPrimitiveType<void> {
    enum { value = 1 };
};




// ...

/*
template<class T>
void testPrimative() {
    if (IsPrimitiveType<T>::VALUE) {
        // ...
    } else {
        // ...
    }
}
*/


//}

//Has comparison operators
//{


   typedef bool noEqual[2];
   typedef bool noLessThan[2];
   typedef bool noGreaterThan[2];

   template<typename T> noEqual& operator == (const T&, const T&);
   template<typename T> noLessThan& operator > (const T&, const T&);
   template<typename T> noGreaterThan& operator < (const T&, const T&);

  template <typename T>
  struct opEqualExists // *(T*)(0) can be replaced by *new T[1] also
  {
    enum { value = (sizeof(*(T*)(0) == *(T*)(0)) != sizeof(noEqual)) };
  };

  template <typename T>
  struct opGreaterExists // *(T*)(0) can be replaced by *new T[1] also
  {
    enum { value = (sizeof(*(T*)(0) > *(T*)(0)) != sizeof(noGreaterThan)) };
  };

   template <typename T>
  struct opLesserExists // *(T*)(0) can be replaced by *new T[1] also
  {
    enum { value = (sizeof(*(T*)(0) < *(T*)(0)) != sizeof(noLessThan)) };
  };


//}

























};//Namespace CHECK


//http://stackoverflow.com/questions/16132123/c-templates-how-to-find-whether-the-template-type-is-a-basic-type-or-a-class




//struct A {
//    void foo();
//    bool operator==(A compare);
//};



//   cout << boolalpha << has_foo<A, void (A::*)()>::value << endl; // true
//   cout << boolalpha << has_compare<A, bool (A::*)(A)>::value << endl; // true


#endif // FUNCTIONCHECKER_H_INCLUDED















