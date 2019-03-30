#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include "queue.h"

template<typename T>
class Node;

template<typename T>
bool operator==(const Node<T> &n1, const Node<T> &n2);

template<typename T>
class Node{
public:
    typedef Node<T> *pnode;
    // friend bool operator==<T>(const Node<T> &n1, const Node<T> &n2);
    Node<T> &operator=(const Node<T> &n){
        p = n.p;
        left = n.left;
        right = n.right;
        key = n.key;
    }
    pnode p;
    pnode left;
    pnode right;
    T key;
public:
    Node(){
        p = nullptr;
        left = nullptr;
        right = nullptr;
        key = 0;
    }
};

template<typename T>
bool operator==(const Node<T> &n1, const Node<T> &n2){
    // std::cout << "overload ==" << std::endl;
    return n1.key == n2.key;
}

template<typename T>
class BinaryTree{
public:
    typedef typename Node<T>::pnode pnode;
private:
    pnode root;
    void insert(pnode p, T val){
        p->key = val;
        // std::cout << "Node with key: " << val << " constructed!" << std::endl;
    }
public:
    BinaryTree(){
        root = new Node<T>;
        // std::cout << "Root constructed!" << std::endl;
    }
    ~BinaryTree(){
        Queue<BinaryTree<int>::pnode> q;
        q.enqueue(root);
        while(!q.empty()){
            auto v = q.dequeue();
            if(v->left)
                q.enqueue(v->left);
            if(v->right)
                q.enqueue(v->right);
            delete v;
        }
    }
    pnode getroot() const {
        return root;
    }
    
    void makeLeftChild(pnode p, T val){
        if(!p->left){
            p->left = new Node<T>;
            insert(p->left, val);
            p->left->p = p;
        }
        else
            p->left->key = val;
    }
    void makeRightChild(pnode p, T val){
        if(!p->right){
            p->right = new Node<T>;
            insert(p->right, val);
            p->right->p = p;
        }
        else
            p->right->key = val;
    }
};


#endif // !BINARY_TREE