#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include "../12-Binary-Search-Trees/binary_search_tree.h"

template<typename T>
class RBNode: public Node<T>{
public:
    typedef enum {red, black} rb;
    typedef RBNode<T> *pnode;
    pnode parent;
    pnode left;
    pnode right;
    rb color;
    RBNode(T k, rb cr=rb::red):Node<T>(k),parent(nullptr),left(nullptr),right(nullptr),color(cr) { }
    RBNode():RBNode(0) {}
};

template<typename T>
class RBT: public BST<T, RBNode<T>>{
public:
    typedef RBNode<T> node;
    typedef node *pnode;
    typedef const node *cnode;
    
    
    RBT():BST<T,RBNode<T>>(){ 
        NilNode = node();
        Nil = &NilNode;
        Nil->color = node::rb::black;
        BST<T, RBNode<T>>::root = Nil;
        BST<T, RBNode<T>>::Nil = Nil;
    }
private:
    node NilNode;
    pnode Nil;

    void do_insert(pnode z) override{
        pnode y = Nil;
        pnode x = BST<T, RBNode<T>>::root;
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
            BST<T, RBNode<T>>::root = z;
        }else if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
        z->left = Nil;
        z->right = Nil;
        z->color = node::rb::red;
        insert_fixup(z);
        #ifdef DEBUG
        std::cout << "RBT insert work." << std::endl;
        #endif // DEBUG
    }

    void left_rotate(pnode x){
        pnode y = x->right;
        x->right = y->left;
        if(y->left != Nil)
            y->left->parent = x;
        y->parent = x->parent;
        if(x->parent == Nil)
            BST<T, RBNode<T>>::root = y;
        else if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void right_rotate(pnode x){
        pnode y = x->left;
        x->left = y->right;
        if(y->right != Nil)
            y->right->parent = x;
        y->parent = x->parent;
        if(x->parent == Nil)
            BST<T, RBNode<T>>::root = y;
        else if(x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    void insert_fixup(pnode z){
        while(z->parent->color == node::rb::red){
            if(z->parent == z->parent->parent->left){
                pnode y = z->parent->parent->right;
                if(y->color == node::rb::red){
                    z->parent->color = node::rb::black;
                    y->color = node::rb::black;
                    z->parent->parent->color = node::rb::red;
                    z = z->parent->parent;
                }else{
                    if(z == z->parent->right){
                        z = z->parent;
                        left_rotate(z);
                    }
                    z->parent->color = node::rb::black;
                    z->parent->parent->color = node::rb::red;
                    right_rotate(z->parent->parent);
                }
            }else{
                pnode y = z->parent->parent->left;
                if(y->color == node::rb::red){
                    z->parent->color = node::rb::black;
                    y->color = node::rb::black;
                    z->parent->parent->color = node::rb::red;
                    z = z->parent->parent;
                }else{
                    if(z == z->parent->left){
                        z = z->parent;
                        right_rotate(z);
                    }
                    z->parent->color = node::rb::black;
                    z->parent->parent->color = node::rb::red;
                    left_rotate(z->parent->parent);
                }
            }
        }
        BST<T, RBNode<T>>::root->color = node::rb::black;
    }

    void do_remove(pnode z) override{
        if(z->left == nullptr){
            this->transparent(z, z->right);
        }else if(z->right == nullptr){
            this->transparent(z, z->left);
        }else{
            pnode y = this->do_get_min(z->right);
            if(y->parent != z){
                this->transparent(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            this->transparent(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
    }


public:
    pnode get_root() override{
        return this->root;
    }
    
    void insert(pnode z){
        do_insert(z);
    }

    // void remove(pbnode z){
    //     BST<T>::remove(z);
    // }
};

#endif // !RED_BLACK_TREE_H