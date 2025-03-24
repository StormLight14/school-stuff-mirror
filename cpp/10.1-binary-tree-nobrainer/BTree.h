#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
  Node(T data) : data(data), left(nullptr), right(nullptr);
  T data;
  shared_ptr<Node<T>> left;
  shared_ptr<Node<T>> right;
};

template <typename T>
class BTree {
public:
  BTree() : root(nullptr);
  void insert(const T& item);
  void remove(const T& item);
  void preOrder();
  void inOrder();
  void postOrder();
  int nodeCount();
  int leavesCount();


private:
  void preOrder(shared_ptr<Node<T>> ptr);
  void inOrder(shared_ptr<Node<T>> ptr);
  void postOrder(shared_ptr<Node<T>> ptr);
  void insert(const T& item,  shared_ptr<Node<T>> ptr);
  int nodeCount(shared_ptr<Node<T>> ptr);
  int leavesCount(shared_ptr<Node<T>> ptr);
  
  shared_ptr<Node<T>> root;
};

template <typename T>
void BTree<T>::insert(const T& item) {
  if (root == nullptr) {
    root = make_shared<Node<T>>(item);
    return;
  }

  insert(item, root);
}

template <typename T>
void BTree<T>::preorder() {
  preorder(root);
}

template <typename T>
void BTree<T>::preOrder(shared_ptr<Node<T>> ptr) {
  if (ptr) {
    cout << ptr->data << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

