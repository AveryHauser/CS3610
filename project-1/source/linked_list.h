
#include <iostream>
using namespace std;

template <class T>
class LinkedList {

public:
  LinkedList() : head(NULL) {}

  // You need to implement the following functions. 

  // will get rid of the whole linked list 
  ~LinkedList();

  /**
   * @brief Will add an element to the front of the linked list
   * 
   * @param data Data is of type T and added to data in listNode
  */
  void push_front(const T data);

  /**
   * @brief Deletes element on the front of the linked list
  */
  void pop_front();
  /**
   * @brief Reverses the entire inked list
  */
  void reverse();
  /**
   * @brief Outputs the whole linked list to the terminal 
  */
  void print() const;

private:
  
  struct ListNode {
    ListNode(const T data) : data(data), next(NULL) {}
    
    T data;
    ListNode* next;
  };

  ListNode* head;
};

// lets the linked_list.template be included with the least amout of problems
#include "linked_list.template"


