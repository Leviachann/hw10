#include <iostream>

using namespace std;

class Node {
public:
  string data;
  Node *next;
  Node(const string &data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
  Node *head = nullptr;

public:
  void AddBegin(const string &data) { // O(1)
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    newNode = nullptr;
  }

  void AddEnd(const string &data) {
    Node *newNode = new Node(data);
    // bundan evvelkini tap xaish edirem.
    if (head == nullptr) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
    temp = nullptr;
    newNode = nullptr;
    // sonra onun nextine bunu yaz.
  }
  //				"Kamil", "Hakuna"
  void AddBefore(const string &x, const string &data) {
    Node *temp = head;
    while (temp->next->next->data != data) {
      temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = x;
    x->next = n;
  };
  void AddAfter(const string &x, const string &data) {
    Node *temp = head;
    while (temp->next->data != data) {
      temp = temp->next;
    }
    Node *n = temp->next;
    temp->next = x;
    x->next = n;
  };
  void DeleteEnd() {
    Node *temp = head;
    while (temp->next->next != nullptr) {
      temp = temp->next;
    }
    Node *n = temp->next;
    delete temp->next->next;
    temp->next = n;
    n->next = nullptr;
  };

  void DeleteBegin() {
    Node *temp = head->next;
    delete head;
    head = temp;
  }

  void DeleteByValue(const string &data) {
    Node *temp = head;
    while (temp->next->data != data) {
      temp = temp->next;
    }
    Node *n = temp->next->next;
    delete temp->next;
    temp->next = n;
  }
};

int main() {}