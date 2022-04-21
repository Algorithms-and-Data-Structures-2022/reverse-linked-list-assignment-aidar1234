#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (size_ == 0 || size_ == 1) {
      return;
    }
    if (size_ == 2) {
      Node *temp = front_;
      front_ = back_;
      back_ = temp;
      front_->next = back_;
      back_->next = nullptr;
      return;
    }
    if (size_ > 2) {
      back_ = front_;
      Node *n1 = back_;
      Node *n2 = n1->next;
      Node *n3 = n2->next;

      while (n3 != nullptr) {
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        n3 = n3->next;
      }
      n2->next = n1;
      front_ = n2;
      back_->next = nullptr;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ == 0 || size_ == 1) {
      return;
    }
    reverse_recursive_helper(front_->next, front_);
    Node *temp = front_;
    front_ = back_;
    back_ = temp;
    back_->next = nullptr;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr != nullptr) {
      reverse_recursive_helper(curr->next, curr);
    }
    else {
      return;
    }
    curr->next = prev;
  }

}  // namespace assignment
