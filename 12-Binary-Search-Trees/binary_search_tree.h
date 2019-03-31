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
    Node(){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
    Node(T k){
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        key = k;
    }
};

template<typename T>
class BST{
public:
    typedef Node<T> node;
    typedef node *pnode;
    typedef const node *cnode;
private:
    pnode root = nullptr;
    pnode do_find(cnode &x, const T &k) const{
        while(x != nullptr && k != x->key){
            if(k < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        return x;
    }

    pnode do_get_min(cnode x) const{
        #ifdef DEBUG
        std::cout << "get_min work." << std::endl;
        #endif // DEBUG
        while(x->left != nullptr){
            x = x->left;
        }
        return const_cast<pnode>(x);
    }

    pnode do_get_max(cnode x) const{
        #ifdef DEBUG
        std::cout << "get_max work." << std::endl;
        #endif // DEBUG

        while(x->right != nullptr){
            x = x->right;
        }
        return const_cast<pnode>(x);;
    }

    pnode do_get_successor(cnode x) const{
        if(x->right != nullptr){
            return do_get_min(x->right);
        }
        pnode y = x->parent;
        while(y != nullptr && x == y->right){
            x = y;
            y = y->parent;
        }
        return y;
    }

    pnode do_get_predecessor(cnode x) const{
        if(x->left != nullptr){
            return do_get_max(x->left);
        }
        pnode y = x->parent;
        while(y != nullptr && x == y->left){
            x = y;
            y = y->parent;
        }
        return y;
    }

    void do_insert(pnode z){
        pnode y = nullptr;
        pnode x = root;
        while(x != nullptr){
            y = x;
            if(z->key < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        z->parent = y;
        if(y == nullptr){
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

    void transparent(pnode u, pnode v){
        if(u->parent == nullptr){
            root = v;
        }else if(u == u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        if(v != nullptr){
            v->parent = u->parent;
        }
    }

    void do_remove(pnode z){
        if(z->left == nullptr){
            transparent(z, z->right);
        }else if(z->right == nullptr){
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
    // insert and remove may invalidate the root returned by get_root before.
    pnode get_root(){
        return root;
    }
    // tree_search
    pnode find(cnode x, const T &k){
        return do_find(x, k);
    }

    cnode find(cnode x, const T &k) const{
        return do_find(k);
    }

    pnode min(cnode x){
        return do_get_min(x);
    }
    
    cnode min(cnode x) const{
        return do_get_min(x);
    }

    pnode max(cnode x){
        return do_get_max(x);
    }
    
    cnode max(cnode x) const{
        return do_get_max(x);
    }

    pnode successor(cnode x){
        return do_get_successor(x);
    }

    cnode successor(cnode x) const{
        return do_get_successor(x);
    }

    pnode predecessor(cnode x){
        return do_get_predecessor(x);
    }

    cnode predecessor(cnode x) const{
        return do_get_predecessor(x);
    }

    void insert(pnode z){
        do_insert(z);
    }

    void remove(pnode z){
        do_remove(z);
    }
};

#endif // !BINARY_SEARCH_TREE_H