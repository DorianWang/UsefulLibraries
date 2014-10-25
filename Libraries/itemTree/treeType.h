
#ifndef TREE_TYPE_H
#define TREE_TYPE_H


//http://stackoverflow.com/questions/14173260/creating-shared-libraries-in-c-for-osx

#define MAX_CHILD_NODES_DEFAULT 32
//^ no real reason, just logic. Can be overriden by the caller.

#include <iostream>
#include <queue>
#include <vector>
#include <string>

#include "stringFunctions.h"

#include "leafType.h"

//Resources

//http://www.cprogramming.com/tutorial/templates.html



template <typename T> class treeType
{
T tempVar;
int numNodesMaxPer;

std::string label;

treeType<T>* parent;

std::vector < treeType<T>* > childNodes;
std::vector < leafType<T> > childData;

public:

bool isGood;//Variable should always be true.
//If not, use may cause undefined behaviour.

treeType(std::string newName);
treeType(std::string newName, int nodeMaxChild);
~treeType();



treeType<T>* findNode(std::string name);//Finds a node with the name of "name";
treeType<T>* findNode(std::string name, treeType<T>*);

treeType<T>* findChildNode(std::string name);
treeType<T>* findChildNode(std::string name, treeType<T>*);

bool addNode(std::string name);
bool addLeaf(std::string name, T data);

leafType<T>* findLeaf(std::string name);
leafType<T>* findLeaf(std::string name, std::string keyWords);

leafType<T>* findConnectedLeaf(std::string name);
treeType<T>* findConnectedNode(std::string name);


bool deleteNode(std::string name);
bool deleteNode(treeType<T>* nodeToDelete);
void cleanThisNode();
void deleteLeaf(std::string name);

std::string listNodePath();
treeType<T>* getNodeAtIndex(int index);
std::string getName();
;;
};;

#include "treeType.inl"

#endif

















