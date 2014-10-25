#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "UsefulHeaders.h"
#include "functionChecker.h"
#include "binaryNodeType.h"

template <typename T> class binaryTreeType
{

private:
binaryNodeType <T>* headNode;
binaryNodeType <T>* selectedNode;

int currentSize;

bool hasEqual; bool hasCompares[2]; bool userSetCompare;

bool (*userCompare)(T first, T second);//User defined function. The first entry should be on the left, and the second on the right.
//This function should return true if the two nodes are not in their correct position.

bool checkForCompare(bool* equalCheck);

//This is used when outputting everything.
void outputTreeSegment(std::vector<T>* output, binaryNodeType <T>* tempHead);

//This connects two nodes.
void addNode(binaryNodeType <T>* parent, binaryNodeType <T>* child, bool childSmaller);

;;
public:

binaryTreeType();

//http://web.eecs.umich.edu/~qstout/abs/CACM86.html
//http://penguin.ewu.edu/~trolfe/DSWpaper/
void rebalance();



//This adds a node to the tree.
int addNode(T input);

//This is a wrapper for the above addNode function.
int addNode(const T* inputArray, int length);

//output
//{
std::vector<T> outputAll();




//}

//Utilities and debugging
//{
void enterCompareFunction(bool (*input)(T first, T second));






//}

};;




//This fixes things! I think...
#include "binaryTree.inl"




#endif // BINARYTREE_H
