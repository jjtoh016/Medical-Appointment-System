#ifndef STACK_HPP_
#define STACK_HPP_

#include <iostream>
#include <string>
#include <stack>

using namespace std;

template<class StackItemType>
class Stack {

private:
  stack<StackItemType> s;

public:
  bool isEmpty() const {
      return this -> s.empty();
  }

  void push(const StackItemType & v) {
    this -> s.push(v);
  }

  void pop() {
    this -> s.pop();
  }

  void pop(StackItemType & stackTop) {
    stackTop = this -> s.top();
    this -> s.pop();
  }

  void getTop(StackItemType & stackTop) {
    stackTop = this -> s.top();
  }

  int size() {
    return this -> s.size();
  }
};

#endif