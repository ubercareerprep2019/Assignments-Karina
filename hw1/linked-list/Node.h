#pragma once

template <typename T> class Node{
 private:
  T data;
  Node<T> *next;
 public:
  Node();
  Node(T data);
  Node(T data, Node* next);
  void setData(T data);
  void setNext(Node *next);
  T getData();
  Node* getNext();
};

template <typename T>
Node<T>::Node() : next(nullptr)
{
}

template <typename T>
Node<T>::Node(T data){
  this->data = data;
  this->next = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node<T> *next){
  this->data = data;
  this->next = next;
}
template <typename T>
void Node<T>::setData(T data){
  this->data = data;
}
template <typename T>
void Node<T>::setNext(Node<T> *next){
  this->next = next;
}
template <typename T>
T Node<T>::getData(){
  return data;
}
template <typename T>
Node<T>* Node<T>::getNext(){
  return next;
}
