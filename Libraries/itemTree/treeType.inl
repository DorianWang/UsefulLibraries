
#include "treeType.h"
//Tree container

//Constructors and Destructors -------------------------------------------------

template <class T> treeType<T>::treeType(std::string newName)
{
   label = newName;
   numNodesMaxPer = MAX_CHILD_NODES_DEFAULT;//Any number of nodes per node, rational limit of 20 or so...
   isGood = true;
   parent = NULL;
}

//Ask for help
template <class T> treeType<T>::treeType(std::string newName, int nodeMaxChild)
{
   label = newName; isGood = true;
   if (nodeMaxChild>1){
      numNodesMaxPer = nodeMaxChild;
   }
   else
   {
      numNodesMaxPer = MAX_CHILD_NODES_DEFAULT;
   }
   parent = NULL;
}

template <class T> treeType<T>::~treeType()
{
   cleanThisNode();//Prepares node for deletion, in case it hasn't been done yet.
}

//End Constructors and Destructors ---------------------------------------------



//Node/Leaf Search -------------------------------------------------------------

template <class T> treeType<T>* treeType<T>::findNode(std::string name)
{
   int a = 0;
   for (int i = 0; i<childNodes.size(); i++){
      if (childNodes[i] -> label == name){
         return childNodes[i];
      }

   }
}

template <class T> treeType<T>* treeType<T>::findConnectedNode(std::string name)
{
   int a = 0;
   for (int i = 0; i<childNodes.size(); i++){
      if (childNodes[i] -> label == name){
         return childNodes[i];
      }
   }
   return NULL;
}

//Depth first search.
template <class T> leafType<T>* treeType<T>::findLeaf(std::string name)
{
   leafType<T>* returnValue;
   returnValue = NULL;
   returnValue = findConnectedLeaf(name);
   if (returnValue != NULL){
      return returnValue;
   }

   for (int i = 0; i < childNodes.size(); i++){
      returnValue = childNodes[i] -> findLeaf(name);
      if (returnValue != NULL){
         return returnValue;
      }
   }
   return NULL;
}

//keyWords must be placed in order of more to less specific (equipment weapon edge, for example)
//Not complete
template <class T> leafType<T>* treeType<T>::findLeaf(std::string name, std::string keyWords)
{
   stringFunc strParser;
   leafType<T>* returnValue;
   returnValue = findConnectedLeaf(name);

   if (returnValue != NULL){
      return returnValue;
   }

   std::string firstToken = strParser.parseFirstToken(keyWords, ". ");

   returnValue = findConnectedNode(firstToken);



   std::queue < treeType<T>* > nodeQueue;
   treeType<T>* tempNode;
   nodeQueue.push(this);

   while(!nodeQueue.empty()){
      tempNode = nodeQueue.front();
      nodeQueue.pop();
      returnValue = tempNode -> findConnectedNode(firstToken);

      if (returnValue != NULL){
         std::string temp = keyWords;
         if (temp != keyWords){
            //temp.erase(temp.begin(), firstToken.length() + 1);
            temp.erase(0, firstToken.length() + 1);
         }
         return findLeaf(name, temp);
      }

      for (int i=0; i < tempNode -> childNodes.size(); i++){
         nodeQueue.push (tempNode -> childNodes[i]);
      }
   }

return NULL;
}



template <class T> leafType<T>* treeType<T>::findConnectedLeaf(std::string name)
{
   for (int i = 0; i<childNodes.size(); i++){
      if (childData[i].label == name){
         return &(childData[i]);
      }
   }
   return NULL;
}

//End Node/Leaf Search ---------------------------------------------------------



//IO ---------------------------------------------------------------------------


template <class T> bool treeType<T>::addNode(std::string name)
{
   if (name == label){
      return false;//Not good. Do not add duplicates
   }

   if (childNodes.size() >= numNodesMaxPer){
      return false;
   }

   treeType<T>* temp = new treeType<T>(name);
   temp -> parent = this;
   childNodes.push_back(temp);
   return true;
}

template <class T> bool treeType<T>::addLeaf(std::string name, T data)
{
   leafType<T> newLeaf (name, data);//, this);
   childData.push_back(newLeaf);
}



//End IO -----------------------------------------------------------------------



//Node Deletion ----------------------------------------------------------------

template <class T> bool treeType<T>::deleteNode(std::string name)
{
   treeType<T>* nodeToDelete = findNode(name);
   if (nodeToDelete != NULL){
      nodeToDelete -> cleanThisNode();
      delete nodeToDelete;
      return true;
   }
   else
   {
      return false;
   }
}

template <class T> bool treeType<T>::deleteNode(treeType<T>* nodeToDelete)
{
   if (nodeToDelete != NULL){
      nodeToDelete -> cleanThisNode();
      delete nodeToDelete;
      return true;
   }
   else
   {
      isGood = false;//This is not good. It should never happen
      return false;
   }
}

//Does not actually delete node. Removes all child nodes, preventing memory leaks
template <class T> void treeType<T>::cleanThisNode()
{
   for (int i=0; i<childNodes.size(); i++){
      if (!deleteNode(childNodes[i])){
         isGood = false;//This is not good. It should never happen
      }
   }
   childData.clear();
   childNodes.clear();
}

template <class T> void treeType<T>::deleteLeaf(std::string name)
{
   for (int i = 0; i<childNodes.size(); i++){
      if (childData[i].label == name){
         childNodes.remove(i);
      }
   }
}


//End Node Deletion ------------------------------------------------------------



//Misc -----------------------------------------------------------------------

template <class T> std::string treeType<T>::listNodePath()
{
   if (parent == NULL){
      return label;//Head node
   }

   return parent -> listNodePath() + "." + label;
}

template <class T> treeType<T>* treeType<T>::getNodeAtIndex(int index)
{
   if (childNodes.size()>index&&index>=0){
      return childNodes[index];
   }
   return NULL;//NULL pointer if out of range
}

template <class T> std::string treeType<T>::getName()
{
   return label;
}

//End Misc ----------------------------------------------------------







