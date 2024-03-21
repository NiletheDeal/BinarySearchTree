#include <iostream>
#include <cstring>
#include <cctype>
#include "node.h"

void ADD(Node*& root, Node* newNode, Node* tree);
void print(Node* tree, int count);
bool search(Node* tree, int s);
int main(){
  cout << "Welcome to BST" << endl << endl;
  bool looping = true;
  bool adding = true;
  char command[10];
  char input[3200];
  int value = -1;
  Node* tree = NULL;
  while(looping == true) {
    cout <<"ADD, REMOVE, SEARCH, PRINT, or QUIT?" << endl;
    cin.get(command, 10);
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(command, "ADD") == 0) {
      adding = true;
      cout << "Enter you input of numbers seperated by spaces and put a -1 at end of the list" << endl;
      while(adding == true) {
	cin >> value;
	if(value == -1) {
	  adding = false;
	}
	else {
	  Node* temp = new Node();
	  temp->setData(value);
	  ADD(tree, temp, tree);
	}
      }
      cin.clear();
      cin.ignore(10000, '\n');
    }
    else if(strcmp(command, "SEARCH") == 0) {
      cout << "Enter the number you are searching " << endl;
      int searchInt;
      cin >> searchInt;
      cin.clear();
      cin.ignore(10000, '\n');
      bool inTree = search(tree, searchInt);
      if(inTree == true) {
	cout << "That number is in the tree" << endl;
      }
      else {
	cout << "That number isn't in the tree" << endl;
      }
    }
    else if(strcmp(command, "PRINT") == 0) {
      print(tree, 0);
    }
  }
}
void ADD(Node*& root, Node* newNode, Node* tree ) {
  
  if(root == NULL) {
    root = newNode;
  }
  else {
    int treeD = tree->getData();
    int addD = newNode->getData();
    if(treeD > addD) {
      if(tree->getLeft() == NULL) {
	tree->setLeft(newNode);
      }
      else {
	ADD(root, newNode, tree->getLeft());
      }
    }
    else if(treeD <= addD) {
      if(tree->getRight() == NULL) {
	tree->setRight(newNode);
      }
      else {
	ADD(root, newNode, tree->getRight());
      }
    }
  }
}
void print(Node* tree, int count) {//print out tree
  if(tree->getRight() != NULL) {//get to the right child
    print(tree->getRight(), count+1);
  }
  for(int i = 0; i < count; i++) {//tabs over
    cout << '\t';
  }
  cout << tree->getData() << endl;//print out value
  //left side
  if(tree->getLeft() != NULL) {//get to the left child
    print(tree->getLeft(), count+1);
  }
}
bool search(Node* tree, int s) {
  if(tree == NULL) {
    return false;
  }
  else {
    int treeD = tree->getData();
    if(treeD == s) {
      return true;
    }
    else if(treeD > s) {
      return search(tree->getLeft(), s);
    }
    else if(treeD < s) {
      return search(tree->getRight(), s);
    }
  }
  return false;
}
