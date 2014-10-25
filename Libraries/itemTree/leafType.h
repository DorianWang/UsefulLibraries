
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


//Leaf type declaration?






#endif
