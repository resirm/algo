#ifndef TREE_WALK_H
#define TREE_WALK_H

#include <iostream>
// #include "../10-Elementary-Data-Structures/binary_tree.h"
#include <iomanip>
#include "binary_search_tree.h"

// template<typename T>
// class TreeNode{
// public:
//     T key;
//     TreeNode<T> *parent;
//     TreeNode<T> *left;
//     TreeNode<T> *right;
// };

// for binary_tree.h, parent pointer is *.p, and for binary_search_tree it's *.parent 

template<typename T>
class Walk{
public:
    typedef Node<T> *pnode;
    void preOrder(pnode root)
    {   
        pnode pre = nullptr;
        while(root != nullptr)
        {   
            if(pre == root->parent)
            {
                pre = root;
                std::cout << root->key << ", ";       // print node at first meet
                auto t = root;
                root = root->left ? root->left : root->right ? root->right : root->parent;
            }
            else if(pre == (root->left) && root->right != nullptr)
            {
                pre = root;
                root = root->right;
            }
            else
            {
                pre = root;
                root = root->parent;
            }
        }
        std::cout << std::endl;
    }

    void inOrder(pnode root)
    {
        pnode pre = nullptr;
        while(root != nullptr)
        {
            if(pre == root->parent)
            {
                pre = root;
                if(root->left == nullptr)
                {
                    std::cout << root->key << ", ";      // print left leaf and right leaf and inner with right but without left
                }
                root = root->left ? root->left : root->right ? root->right : root->parent;
            }
            else if(pre == root->left && root->right != nullptr)
            {
                pre = root;
                std::cout << root->key << ", ";    // print inner node with left and right
                root = root->right;
            }
            else
            {
                if(pre == root->left && root->right == nullptr)
                    std::cout << root->key << ", ";      // print inner with left but without right
                pre = root;
                root = root->parent;
            }
        }
        std::cout << std::endl;
    }

    void postOrder(pnode root)
    {
        pnode pre = nullptr;
        while(root != nullptr)
        {
            if(pre == root->parent)
            {
                pre = root;
                if(root->left == nullptr && root->right == nullptr)
                {
                    std::cout << root->key << ", ";  // print leaf node
                }
                root = root->left ? root->left : root->right ? root->right : root->parent;
            }
            else if(pre == root->left && root->right != nullptr)
            {
                pre = root;
                root = root->right;
            }
            else
            {
                std::cout << root->key << ", ";    // print inner node
                pre = root;
                root = root->parent;
            }
        }
        std::cout << std::endl;
    }
};


#endif // !TREE_WALK_H
