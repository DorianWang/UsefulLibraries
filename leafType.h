
#ifndef LEAF_TYPE_H
#define LEAF_TYPE_H

#include <vector>
#include <string>


template <class E> class leafType
{
E dataStored;
std::string label;
//treeType <E> * parent;

public:

leafType(std::string name, E dataIn);//, treeType<E>* newParent);
E* getDataPointer();
E getData();


};


//Implementation
//{

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



//Leaf type declaration?

//}




#endif
