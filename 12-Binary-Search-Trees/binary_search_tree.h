#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

// define DEBUG by adding -DDEBUG option while using g++.
#ifdef DEBUG
#include <iostream>
#include <iomanip>
#endif

template<typename T>
class Node{
public:
    typedef Node<T> *pnode;
    pnode parent;
    pnode left;
    pnode right;
    T key;
    Node(T k=0):parent(nullptr),left(nullptr),right(nullptr),key(k) { }
    virtual ~Node() = default;
};

template<typename T, typename N>
class BST{
public:
    typedef T value_type;
    typedef N node;
    typedef node *pnode;
    typedef const node *cnode;


    BST(pnode r=nullptr){ root = r; Nil = r; }
    virtual ~BST() = default;
protected:
    pnode root;
    pnode Nil;

    virtual auto do_find(cnode x, const T &k) const -> decltype(const_cast<pnode>(x)){
        while(x != Nil && k != x->key){
            if(k < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        return const_cast<pnode>(x);
    }

    virtual auto do_get_min(cnode x) const -> decltype(const_cast<pnode>(x)){
        #ifdef DEBUG
        std::cout << "get_min work." << std::endl;
        #endif // DEBUG
        while(x->left != Nil){
            x = x->left;
        }
        return const_cast<pnode>(x);
    }

    virtual auto do_get_max(cnode x) const -> decltype(const_cast<pnode>(x)){
        #ifdef DEBUG
        std::cout << "get_max work." << std::endl;
        #endif // DEBUG

        while(x->right != Nil){
            x = x->right;
        }
        return const_cast<pnode>(x);
    }

    virtual auto do_get_successor(cnode x) const -> decltype(const_cast<pnode>(x)){
        if(x->right != Nil){
            return do_get_min(x->right);
        }
        pnode y = x->parent;
        while(y != Nil && x == y->right){
            x = y;
            y = y->parent;
        }
        return y;
    }

    virtual auto do_get_predecessor(cnode x) const -> decltype(const_cast<pnode>(x)){
        if(x->left != Nil){
            return do_get_max(x->left);
        }
        pnode y = x->parent;
        while(y != Nil && x == y->left){
            x = y;
            y = y->parent;
        }
        return y;
    }

    virtual void do_insert(pnode z){
        pnode y = Nil;
        pnode x = root;
        while(x != Nil){
            y = x;
            if(z->key < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        z->parent = y;
        if(y == Nil){
            root = z;
        }else if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
        #ifdef DEBUG
        std::cout << "insert work." << std::endl;
        #endif // DEBUG
    }

    virtual void transparent(pnode u, pnode v){
        if(u->parent == Nil){
            root = v;
        }else if(u == u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        if(v != Nil){
            v->parent = u->parent;
        }
    }

    virtual void do_remove(pnode z){
        if(z->left == Nil){
            transparent(z, z->right);
        }else if(z->right == Nil){
            transparent(z, z->left);
        }else{
            pnode y = do_get_min(z->right);
            if(y->parent != z){
                transparent(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transparent(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }

public:
    virtual pnode get_nil(){
        return Nil;
    }
    // insert and remove may invalidate the root returned by get_root before.
    virtual pnode get_root(){
        return root;
    }
    // tree_search
    virtual auto find(cnode x, const T &k) -> decltype(const_cast<pnode>(x)){
        return do_find(x, k);
    }

    virtual auto find(cnode x, const T &k) const -> decltype(const_cast<pnode>(x)){
        return do_find(x, k);
    }

    virtual auto min(cnode x) -> decltype(const_cast<pnode>(x)){
        return do_get_min(x);
    }
    
    virtual auto min(cnode x) const -> decltype(x){
        return do_get_min(x);
    }

    virtual auto max(cnode x) -> decltype(const_cast<pnode>(x)){
        return do_get_max(x);
    }
    
    virtual auto max(cnode x) const -> decltype(x){
        return do_get_max(x);
    }

    virtual auto successor(cnode x) -> decltype(const_cast<pnode>(x)){
        return do_get_successor(x);
    }

    virtual auto successor(cnode x) const -> decltype(x){
        return do_get_successor(x);
    }

    virtual auto predecessor(cnode x) -> decltype(const_cast<pnode>(x)){
        return do_get_predecessor(x);
    }

    virtual auto predecessor(cnode x) const -> decltype(x){
        return do_get_predecessor(x);
    }

    virtual void insert(pnode z){
        do_insert(z);
    }

    virtual void remove(pnode z){
        do_remove(z);
    }
};

#endif // !BINARY_SEARCH_TREE_H