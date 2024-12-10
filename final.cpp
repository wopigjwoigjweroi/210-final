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

  Node* headNode = nullptr; 
  Node* tailNode = nullptr; 

  for (int i = 0; i < 3; ++i) {

    coffeeCustomer customer = create(nameList, orderList);

    if (!headNode) {

      headNode = tailNode = addQueue(nullptr, customer); 

    } else {

      tailNode = addQueue(tailNode, customer); 
    }

  }
   
  vector<coffeeCustomer> bracelets;
  
  deque<coffeeCustomer> muffins; 

  stack<coffeeCustomer> customers; 

  for (int round = 1; round <= 10; ++round) {

    cout << endl << " Round " << round << endl; 

      if (headNode) {

        cout << "Serving customer: " << headNode->customer.name << " (" << headNode->customer.order << ")\n";
        headNode = serving(headNode); 
    } else {
        cout << "Empty..\n"; 
      }

    if (rand() % 2 == 0) {

      coffeeCustomer newCustomer = create(nameList, orderList); 
      cout << "New customer has joined: " << newCustomer.name << " (" << newCustomer.order << ")\n"; 

      if (!headNode) {

        headNode = tailNode = addQueue(tailNode, newCustomer);
      } else {

        tailNode = addQueue(tailNode, newCustomer); 
      }
    }

    if (!muffins.empty()) {

      cout << "Serving customer: " << muffins.front().name << " (" << muffins.front().order << ")\n"; 
    }
    
  }


  return 0; 
}
