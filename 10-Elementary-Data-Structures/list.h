#ifndef LIST_H
#define LIST_H

#include <iostream>

/*
 * Doubly linked list.
 */

template<typename T> class Node{
public:
    T key;
    Node<T> *pre;
    Node<T> *next;
public:
    Node(){ pre = nullptr; next = nullptr; }
};

template<typename T> class List{
private:
    typedef T value_type;
    Node<T> *sentinel;
    Node<T> *delete_procedure(Node<T> *p);
    int length;
public:
    List(){ 
        length = 0;
        sentinel = new Node<T>;
        sentinel->pre = sentinel;
        sentinel->next = sentinel;
    }
    ~List(){
        auto p = sentinel->next;
        while(p != sentinel){
            p = delete_procedure(p);
        }
        delete sentinel;
    }
    void insert(T val);
    Node<T> *search(T val) const;
    bool remove(T val);
    bool empty() const;
    Node<T> *head() const;
    Node<T> *tail() const;
    int size() const;
    Node<T> *next(Node<T> *p) const;
    Node<T> *pre(Node<T> *p) const;
};

template<typename T>
bool List<T>::empty() const {
    return sentinel == sentinel->next;
}

template<typename T>
void List<T>::insert(T val){
    Node<T> *node = new Node<T>;
    node->key = val;
    node->next = sentinel->next;
    sentinel->next->pre = node;
    node->pre = sentinel;
    sentinel->next = node;
    ++length;
}

template<typename T>
Node<T> *List<T>::search(T val) const{
    Node<T> *p = sentinel->next;
    while( p != sentinel && p->key != val){
        p = p->next;
    }
    return p;
}

template<typename T>
Node<T> * List<T>::delete_procedure(Node<T> *p){
    p->next->pre = p->pre;
    p->pre->next = p->next;
    auto rp = p->next;
    delete p;
    return rp;
}

template<typename T>
bool List<T>::remove(T val){
    auto p = search(val);
    if(p != sentinel){
        delete_procedure(p);
        --length;
        return true;
    }else{
        return false;
    }
}

template<typename T>
Node<T> *List<T>::head() const {
    return empty()?nullptr:sentinel->next;
}

template<typename T>
Node<T> *List<T>::tail() const {
    return empty()?nullptr:sentinel->pre;
}

template<typename T>
int List<T>::size() const {
    return length;
}

template<typename T>
Node<T> *List<T>::next(Node<T> *p) const {
    return (p->next == sentinel)?nullptr:p->next;
}

template<typename T>
Node<T> *List<T>::pre(Node<T> *p) const {
    return (p->pre == sentinel)?nullptr:p->pre;
}

#endif // !LIST_H