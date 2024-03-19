#include <iostream>
#include <cstring>
#include <cctype>
#include "node.h"

int main {
  cout << "Welcome to BST" << endl << endl;
  bool looping = true;
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
      cout << "Enter you input of numbers seperated by spaces" << endl;
      while(cin >> value) { 
	Node* temp = new Node();
	temp->setData(value);
	ADD(tree, temp);
      }
    }
  }
}
void ADD(Node* tree, Node* newNode);
