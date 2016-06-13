#pragma once
#include "Item.h"
class LinkedList {

private:

  class Node{
    Item* elem; //replace int with item
    Node* next;

    Node(){ next = nullptr; }
    Node(Item* elem){ this->elem = elem; next = nullptr;  };

  };

  Node* first;
  Node* last;

public:

  //getters and setters


};
