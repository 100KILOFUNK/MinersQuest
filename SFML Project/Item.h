#pragma once
#include <iostream>

class Item{
private:
  int id;

public:
  Item();
  ~Item();


  virtual std::string toString() = 0;

};
