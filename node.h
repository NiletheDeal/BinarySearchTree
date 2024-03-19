#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:
  Node(); //Constructor
  ~Node(); //Destructor
  //Setters
  void setRight(Node*);
  void setLeft(Node*);
  void setData(int);
  //Getters
  Node* getRight();
  Node* getLeft();
  int getData();
 private:
  Node* left;
  Node* right;
  int data;

};
#endif


