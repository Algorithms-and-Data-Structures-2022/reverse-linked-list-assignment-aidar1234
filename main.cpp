#include <iostream>

#include "assignment/linked_list.hpp"

using namespace std;
using namespace assignment;

int main(int argc, char **argv) {

  Node *front = new Node(1);
  Node *back = new Node(2);

  //Node *m = front->next->next->next->next;

  cout << front <<endl;
  cout << back <<endl;

  Node *temp = front;
  front = back;
  back = temp;
  front->next = back;
  back->next = nullptr;

  cout << front <<endl;
  cout << back <<endl;

  return 0;
}
