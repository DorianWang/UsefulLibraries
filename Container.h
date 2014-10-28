
#ifndef CONTAINER_H
#define CONTAINER_H

#include "functionChecker.h"

#include <string>
#include <iostream>
#include <vector>


using namespace std;

#define MAX_LENGTH_LINKED_LIST 200000000000
//200 Billion. Do not go over this, or bad things will happen...

template <typename E> class linkedListNode
{
   public:
   linkedListNode <E>* P_Prev;//Pointer to the parent node of this one.
   linkedListNode <E>* P_Next;//Pointer to the node next in the list.

   E data;
};



template <typename D> class linkedList
{
unsigned int length;//Current length of the linked list

bool hasCompare;
bool hasEquivalence;

bool checkForCompare(bool* equalCheck);

linkedListNode <D>* headNode;
linkedListNode <D>* lastNode;//pointer to the last value in the list

linkedListNode <D>* lastNodeUsed;//pointer that was used last in any function. Set null after use.
//I might use this for a function.

linkedListNode <D>* getNodePointer(unsigned int numNode);

bool getNextNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output);
bool getPrevNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output);

void changeLength(int numToChange);


public:

linkedList();
~linkedList();

void test();

void pushBack(D addValue);
void pushFront(D addValue);

unsigned int size();

D popFront(bool* errorBool);
D popBack(bool* errorBool);

D valueAt(unsigned int numNode, bool* errorBool);

int deleteNode(unsigned int nodeNum);

int deleteNode(unsigned int nodeNum, unsigned int numNodesToDelete);
int deleteNode(D typeToDelete);
int deleteAllNodes();

bool linkNode(linkedListNode <D>* firstNode, linkedListNode <D>* secondNode);



;
};


template <typename D> void linkedList<D>::test()
{
   std::cout<< (bool)hasCompare<<" "<<(bool)hasEquivalence<<endl;
}




template <class D>  linkedList<D>::linkedList()
{
   length = 0; //empty
   headNode = NULL;
   lastNode = NULL;
   hasCompare = checkForCompare(&hasEquivalence);
}

template <class D> linkedList<D>::~linkedList()
{
   deleteAllNodes();
}

template <class D> unsigned int linkedList<D>::size()
{
   return length;
}

template <class D> void linkedList<D>::pushBack(D inputData)
{
   linkedListNode <D>* newNode = new linkedListNode <D>;

   //Empty list
   if (length == 0){
      headNode = newNode;
      lastNode = newNode;
      newNode -> data = inputData;
      newNode -> P_Prev = NULL;
      newNode -> P_Next = NULL;
      changeLength(1);
   }
   else
   {
      lastNode -> P_Next = newNode;
      newNode -> data = inputData;

      newNode -> P_Next = NULL;
      newNode -> P_Prev = lastNode;

      lastNode = newNode;
      changeLength(1);
   }
}

template <class D> void linkedList<D>::pushFront(D inputData)
{
   linkedListNode <D>* newNode = new linkedListNode <D>;
   linkedListNode <D>* P_oldFront;//Temporary storage.

   if (length == 0){
      return pushBack(inputData);
   }

   P_oldFront = headNode;

   headNode = newNode;
   newNode -> data = inputData;
   newNode -> P_Next = P_oldFront;
   newNode -> P_Prev = NULL;

   P_oldFront -> P_Prev = newNode;

   changeLength(1);
}

//This function returns the value of the first node, before deleting it.
//If this function succeeds, the errorBool will be set false.
template <class D> D linkedList<D>::popFront(bool* errorBool)
{

   if (length == 0){
      *errorBool = true;//Failure
      return 0;//failure; nothing to remove
   }

   D tempData = headNode -> data; //Temporary data storage.

   deleteNode(headNode);
   *errorBool = false;//No error.
   return tempData;

}

//Almost the same as the above.
template <class D> D linkedList<D>::popBack(bool* errorBool)
{

   if (length == 0){
      *errorBool = true;
      return 0;//failure; There is nothing to pop off
   }

   D tempData = lastNode -> data; //Temporary data storage.

   *errorBool = false;//No error.
   deleteNode(lastNode);
   return tempData;

}

//Gives the value at the node specified. Node 1 is the first node.
//Watch this to make sure it works...
template <class D> D linkedList<D>::valueAt(unsigned int numNode, bool* errorBool)
{
   if (numNode > length){
      *errorBool = true;//Error, selected node does not exist.
      return 0;
   }

   linkedListNode <D>* selectedNode = getNodePointer(numNode);

   if (selectedNode != NULL){
      *errorBool = false;//No error.
      return selectedNode -> data;
   }

   *errorBool = true;//Something broke...
   return 0;
}

//Watch this to make sure it works...
template <class D> linkedListNode <D>* linkedList<D>::getNodePointer(unsigned int numNode)
{
   if (length < numNode){ return NULL; }

   unsigned int halfTest = length / 2;
   linkedListNode <D>* currentNode;

   if (numNode < halfTest){
      currentNode = headNode;
      for (int i = 0; i < numNode - 1; i++){
         getNextNodePointer (&currentNode, &currentNode);// -> P_Next;
      }
      return currentNode;
   }

   currentNode = lastNode;
   for (int i = length; i > numNode; i--){
      getPrevNodePointer(&currentNode, &currentNode);
   }
   return currentNode;
}

//Returns false when the output is NULL, so basically when the list is done.
template <class D> bool linkedList<D>::getNextNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output)
{
   if (*inputPointer == NULL){return false;}
   *output = *inputPointer -> P_Next;
   if (*output == NULL)
   {
      return false;
   }
return true;
}

//Returns false when the output is NULL, so basically when the start is reached.
template <class D> bool linkedList<D>::getPrevNodePointer(linkedListNode <D>** inputPointer, linkedListNode <D>** output)
{
   *output = *inputPointer -> P_Prev;
   if (*output == NULL)
   {
      return false;
   }
return true;
}

template <class D> int linkedList<D>::deleteNode(unsigned int nodeNum)
{
   linkedListNode <D>* temp;

   if (length == 0){
      return 0;//nothing to delete...
   }

   temp = getNodePointer(nodeNum);

   if (temp -> P_Next != NULL){
      temp -> P_Next -> P_Prev = temp -> P_Prev;//The node after the deleted one's forward pointer is set.
   }
   if (temp -> P_Prev != NULL){
      temp -> P_Prev -> P_Next = temp -> P_Next;//The node before the deleted one's next pointer is set.
   }

   delete temp;
   return 1;
}

//Deletes the selected node, and finishes when it reaches numNodesToDelete.
//numNodesToDelete must be a number greater than 0.
template <class D> int linkedList<D>::deleteNode(unsigned int nodeNum, unsigned int numNodesToDelete)
{
   if (nodeNum + numNodesToDelete - 1 > length || numNodesToDelete < 1){
      return 0; //No nodes deleted, input invalid.
   }

   linkedListNode <D>* temp1; linkedListNode <D>* temp2;
   linkedListNode <D>* startPointer;


   //If the distance from the beginning is larger than the distance to the end
   if (nodeNum > length - nodeNum + numNodesToDelete){
      temp1 = getNodePointer(nodeNum + numNodesToDelete - 1);
      startPointer = temp1 -> P_Next;
      for (int i = 0; i < numNodesToDelete; i++){
         temp2 = temp1;
         getPrevNodePointer(&temp1, &temp1);
         delete temp2;
      }

      if (temp1 == NULL){
         headNode = startPointer;
         startPointer -> P_Prev = NULL;
      }
      else
      {
         linkNode(temp1, startPointer);
      }
         return numNodesToDelete;

   }

}

//Deletes all nodes with an equal D value. Returns the number of objects deleted.
template <class D> int linkedList<D>::deleteNode(D typeToDelete)
{
   if (!hasEquivalence){
      return -1;//No comparison is possible, or at least desired.
   }
   linkedListNode <D>* currentNode = headNode;
   std::vector <linkedListNode <D>*> deleteQueue;

   while (getNextNodePointer(&currentNode, &currentNode)){
      if (currentNode -> E == typeToDelete){
         deleteQueue.push_back(currentNode);
      }
   }


   for (int i = 0; i < deleteQueue.length(); i++){
      deleteNode (deleteQueue[i]);
   }
return deleteQueue.length();
}

//I hope this works...
template <class D> int linkedList<D>::deleteAllNodes()
{
   linkedListNode <D>* tempNode;
   for (int i = 0; i < length; i++){
      tempNode = headNode -> P_Next;
      delete headNode;
      headNode = tempNode;
   }
   length = 0;
}


template <class D> void linkedList<D>::changeLength(int numToChange)
{
   length = length + numToChange;
};

template <class D> bool linkedList<D>::linkNode(linkedListNode <D>* firstNode, linkedListNode <D>* secondNode)
{
   if (firstNode == NULL){
      if (secondNode == NULL){ return false; } //Why did this happen?
      secondNode -> P_Prev = NULL;
      headNode = secondNode; //Sets node as the head.
      return true;
   }

   if (secondNode == NULL){
      firstNode -> P_Next = NULL;
      lastNode = firstNode; //Sets node as the last node.
      return true;
   }
   firstNode -> P_Next = secondNode;
   secondNode -> P_Prev = firstNode;
return true;
}

//See binaryTree implementation
template <class D> bool linkedList<D>::checkForCompare(bool* compareCheck)
{

//Basic data type. Must have compare, or I'll eat my hat.
   if (is_class<D>::value == false){
      compareCheck[0] = true; compareCheck[1] = true;
      return true;
   }

   if (CHECK::opGreaterExists <D>::value){
      compareCheck[0] = true;
   }

   if (CHECK::opLesserExists <D>::value){
      compareCheck[1] = true;
   }

   if (CHECK::opEqualExists<D>::value){
      return true;
   }

return false;
}






;;


#endif











