#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std; 

struct coffeeCustomer {

  string name; 
  string order; 
};

struct Node {

  coffeeCustomer customer; 
  Node* next; 
}; 

Node* addQueue(Node* tail, const coffeeCustomer& customer) {

  Node* newNode = new Node {customer, nullptr}; 

    if (tail) {

      tail->next = newNode; 
    }

  return newNode; 
}

Node* serving(Node* head) {

  if (!head) return nullptr; 

  Node* temp = head; 

  head = head->next;

  delete temp; 
  return head; 


}
