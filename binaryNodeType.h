#ifndef BINARYLEAFTYPE_H
#define BINARYLEAFTYPE_H

#include <cstdlib>



template <class E> class binaryNodeType
{
E dataStored;

public:

binaryNodeType <E>* up;

binaryNodeType <E>* left;
binaryNodeType <E>* right;


binaryNodeType(E newData);

E* getDataPointer();
E getData();

void setData (E input);
//Be careful with changing the data stored. It could cause problems with sorting.
//Basically, use at your own risk.



};

//Leaf type?


template <class E> binaryNodeType<E>::binaryNodeType(E newData)
{
   dataStored = newData;

//Pointers to NULL
   up = NULL;

   left = NULL;
   right = NULL;
}


//This may also be dangerous...
template <class E> E* binaryNodeType<E>::getDataPointer()
{
   return &dataStored;
}

template <class E> E binaryNodeType<E>::getData()
{
   return dataStored;
}


//Dangerous function. Please just delete this node, and add a new
//one instead.
template <class E> void binaryNodeType<E>::setData (E input)
{
   dataStored = input;
}





#endif // BINARYLEAFTYPE_H_INCLUDED
