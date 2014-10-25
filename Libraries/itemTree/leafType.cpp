
#include "leafType.h"

//Leaf type?


template <class E> leafType<E>::leafType(std::string name, E dataIn)
{
   label = name;
   dataStored = dataIn;
}

template <class E> E* leafType<E>::getDataPointer()
{
   return &dataStored;
}

template <class E> E leafType<E>::getData()
{
   return dataStored;
}
