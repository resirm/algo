#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

template<typename T>
class Node{
public:
    typedef Node<T> *pnode;
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

    }
    pnode getroot() const {
        return root;
    }
    
    void makeLeftChild(pnode p, T val){
        if(!p->left){
            p->left = new Node<T>;
            insert(p->left, val);
        }
        else
            p->left->key = val;
    }
    void makeRightChild(pnode p, T val){
        if(!p->right){
            p->right = new Node<T>;
            insert(p->right, val);
        }
        else
            p->right->key = val;
    }
    void BFS(pnode r){

    }
};


#endif // !BINARY_TREE