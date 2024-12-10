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

coffeeCustomer create(const vector<string>& names, const vector<string>& order) {

  return {names[rand() % names.size()], order[rand() % order.size()]}; 

}

void displayShop(const string& booth, const vector<coffeeCustomer>& queue) {

  cout << booth << " queue: \n"; 

  for (const auto& c : queue) {

    cout << "[" << c.name << " (" << c.order << " )]"; 
  }
  cout << endl; 
}

int main() {

  srand(static_cast<unsigned>(time(0))); 

  vector<string> nameList = {"Alex", "Bob", "Kit", "Brian", "Grace", "Charlie", "John", "Mike"}; 
  vector<string> orderList = {"Decaf", "Dark", "Espresso", "Frappe", "Latte"}; 
  vector<string> braceletList = {"Red", "Blue", "Yellow", "Orange", "Purple"}; 
  vector<string> itemList = {"Sandwich", "Candy", "Chocolate", "Pretzel", "Caramel", "Sundae"}; 
  


  return 0; 
}
