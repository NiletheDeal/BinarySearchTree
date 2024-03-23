#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

Node::Node() { //Constructor
  left = nullptr;
  right = nullptr;
  data = -1;
}

Node::~Node() { //Destructor
  left = nullptr;
  right = nullptr;
}

//Setters
void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setData(int newData) {
  data = newData;
}

//Getters
Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

int Node::getData() {
  return data;
}

