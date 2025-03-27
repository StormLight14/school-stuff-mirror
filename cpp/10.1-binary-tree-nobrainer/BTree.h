#include <iostream>
#include <memory>
using namespace std;

template <typename T>
struct Node {
  Node(T data) : data(data), left(nullptr), right(nullptr) {};
  T data;
  shared_ptr<Node<T>> left;
  shared_ptr<Node<T>> right;
};

template <typename T>
class BTree {
public:
  BTree() : root(nullptr) {};
  BTree(const BTree<T>&);
  BTree<T>& operator=(const BTree<T>&);
  void insert(const T& item);
  void remove(const T& item);
  void preOrder();
  void inOrder();
  void postOrder();
  int nodeCount();
  int leavesCount();
  shared_ptr<Node<T>> find(const T& item);
  shared_ptr<Node<T>> find(const T& item, shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findRightMostNode();
  shared_ptr<Node<T>> findRightMostNode(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> findParent(shared_ptr<Node<T>> ptr);

private:
  void preOrder(shared_ptr<Node<T>> ptr);
  void inOrder(shared_ptr<Node<T>> ptr);
  void postOrder(shared_ptr<Node<T>> ptr);
  void insert(const T& item,  shared_ptr<Node<T>> ptr);
  int nodeCount(shared_ptr<Node<T>> ptr);
  int leavesCount(shared_ptr<Node<T>> ptr);
  shared_ptr<Node<T>> copy_node(shared_ptr<Node<T>>);

  shared_ptr<Node<T>> root;
};

template <typename T>
BTree<T>::BTree(const BTree<T>& b) {
  root = copy_node(b.root);
}

template <typename T>
BTree<T>& BTree<T>::operator=(const BTree<T>&) {
  return BTree(*this);
}

template <typename T>
shared_ptr<Node<T>> BTree<T>::copy_node(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr == nullptr) {
    return nullptr;
  }
  auto ptr_copy = make_shared<Node<T>>(node_ptr->data);
  ptr_copy->left = copy_node(node_ptr->left);
  ptr_copy->right = copy_node(node_ptr->right);
  return ptr_copy;
}

template <typename T>
void BTree<T>::insert(const T& item) {
  if (root == nullptr) {
    root = make_shared<Node<T>>(item);
    return;
  }

  insert(item, root);
}

template <typename T>
void BTree<T>::insert(const T& item, shared_ptr<Node<T>> node_ptr) {
  if (item < node_ptr->data) { // the left branch
    if (node_ptr->left == nullptr) {
      node_ptr->left = make_shared<Node<T>>(item);
    } else {
      insert(item, node_ptr->left);
    }
  } else if (item >= node_ptr->data) { // the right branch
    if (node_ptr->right == nullptr) {
      node_ptr->right = make_shared<Node<T>>(item);
    } else {
      insert(item, node_ptr->right);
    }
  }
}

template <typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item) {
  return find(root);
}

template <typename T>
shared_ptr<Node<T>> BTree<T>::find(const T& item, shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    if (node_ptr->data == item) {
      return node_ptr;
    } else {
      return find(item, node_ptr->left);
      return find(item, node_ptr->right);
    }
  } else {
    return nullptr;
  }
}


template <typename T>
void BTree<T>::preOrder() {
  preOrder(root);
}

template <typename T>
void BTree<T>::preOrder(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    cout << node_ptr->data << " ";
    preOrder(node_ptr->left);
    preOrder(node_ptr->right);
  }
}

template <typename T>
void BTree<T>::postOrder() {
  postOrder(root);
}

template <typename T>
void BTree<T>::postOrder(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    postOrder(node_ptr->left);
    postOrder(node_ptr->right);
    cout << node_ptr->data << " ";
  }
}

template <typename T>
void BTree<T>::inOrder() {
  inOrder(root);
}


template <typename T>
void BTree<T>::inOrder(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    inOrder(node_ptr->left);
    cout << node_ptr->data << " ";
    inOrder(node_ptr->right);
  }
}

template <typename T>
int BTree<T>::nodeCount() {
  return nodeCount(root);
}

template <typename T>
int BTree<T>::nodeCount(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    return 1 + nodeCount(node_ptr->left) + nodeCount(node_ptr->right);
  }

  return 0;
}

template <typename T>
int BTree<T>::leavesCount() {
  return leavesCount(root);
}

template <typename T>
int BTree<T>::leavesCount(shared_ptr<Node<T>> node_ptr) {
  if (node_ptr) {
    if (node_ptr->left == nullptr && node_ptr->right == nullptr) {
      return 1;
    } else {
      return 0 + leavesCount(node_ptr->left) + leavesCount(node_ptr->right);
    }
  }

  return 0;
}
