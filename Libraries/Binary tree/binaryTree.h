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





//Implementation
//{






template <class T> binaryTreeType<T>::binaryTreeType()
{

   currentSize = 0; //empty
   headNode = NULL;
   selectedNode = NULL;

   hasEqual = false; userSetCompare = false;

   hasEqual = checkForCompare(hasCompares);
}


template <class T> void binaryTreeType<T>::addNode(binaryNodeType <T>* parent, binaryNodeType <T>* child, bool childSmaller)
{
   child -> up = parent;

   if (childSmaller){
      //Left
      parent -> left = child;
   }
   else
   {
      parent -> right = child;
   }

}


template <class T> int binaryTreeType<T>::addNode(T input)
{
   binaryNodeType <T>* newNode = new binaryNodeType<T>(input);

   //If there is no head node, set new node as head.
   if (headNode == NULL){
      headNode = newNode;
      return 1;
   }

   //If there is a head node, starts recursion at the head.
   selectedNode = headNode;

   //Uses the user set function first.
   if (userSetCompare){
      while(true){
         if (userCompare(newNode -> getData(), selectedNode -> getData())){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               addNode(selectedNode, newNode, false);
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               addNode(selectedNode, newNode, true);
               return 1;
            }
         }
      }
   }

   //Directly compares pointers
   if (!hasCompares[0]&&!hasCompares[1]){
      while (true){
         if (selectedNode > newNode){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               selectedNode -> right = newNode;
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               selectedNode -> left = newNode;
               return 1;
            }
         }

      }
   }
   else if (hasCompares[0])
   {
      while (true){

         if (!(selectedNode -> getData() > newNode -> getData())){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               addNode(selectedNode, newNode, false);
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               addNode(selectedNode, newNode, true);
               return 1;
            }
         }

      }
   }
   else
   {
      while (true){

         if (selectedNode -> getData() < newNode -> getData()){
            if (selectedNode -> right != NULL){
               selectedNode = selectedNode -> right;
            }
            else
            {
               addNode(selectedNode, newNode, false);
               return 1;
            }
         }
         else
         {
            if (selectedNode -> left != NULL){
               selectedNode = selectedNode -> left;
            }
            else
            {
               addNode(selectedNode, newNode, true);
               return 1;
            }
         }

      }
   }

}

template <class T> int binaryTreeType<T>::addNode(const T* inputArray, int length)
{
   for (int i = 0; i < length; i++){
      addNode(inputArray[i]);
   }
}




template <class T> void binaryTreeType<T>::enterCompareFunction(bool (*input)(T first, T second))
{
userCompare = input;

userSetCompare = true;
}


//Returns true for equality compare.
//compareCheck must be an array of size two, the first for greater than, and the second
//for lesser than.
template <class T> bool binaryTreeType<T>::checkForCompare(bool* compareCheck)
{

//Basic data type. Must have compare, or I'll eat my hat.
   if (is_class<T>::value == false){
      std::cout<<"Is not a class!"<<std::endl;
      compareCheck[0] = true; compareCheck[1] = true;
      return true;
   }

   if (CHECK::opGreaterExists <T>::value){
      compareCheck[0] = true;
   }

   if (CHECK::opLesserExists <T>::value){
      compareCheck[1] = true;
   }

   if (CHECK::opEqualExists<T>::value){
      return true;
   }

return false;
}



template <class T> std::vector<T> binaryTreeType<T>::outputAll()
{
   selectedNode = headNode;
   std::vector <T> output;
   if (selectedNode == NULL){
      return output;
   }
   outputTreeSegment(&output, selectedNode);

   return output;
}


//http://stackoverflow.com/questions/4226606/inserting-into-a-vector-at-the-front
//Change into a queue?
//TODO: change things
template <class T> void binaryTreeType<T>::outputTreeSegment(std::vector <T>* output, binaryNodeType <T>* tempHead)
{

   if (tempHead -> left != NULL){
      //Do left node.
      outputTreeSegment(output, tempHead -> left);
   }

   //Add selected node to vector
   (*output).push_back(tempHead -> getData());
   std::cout<<tempHead -> getData();

   if (tempHead -> right != NULL){
      //Do right node.
      outputTreeSegment(output, tempHead -> right);
   }

// End/return
}


//}











#endif // BINARYTREE_H
