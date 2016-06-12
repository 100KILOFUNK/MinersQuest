#pragma once

class LinkedList {

private:
  template <class T>
  class Node{
    T elem;
    Node* next;

    Node(){ next = nullptr; }
    Node(T elem) {  this.elem = elem; this.next = nullptr};
  }

  Node* first;
  Node* last;

public:

  //getters and setters


}
