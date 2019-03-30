#ifndef TREE_WALK_H
#define TREE_WALK_H

#include <iostream>
#include "../10-Elementary-Data-Structures/binary_tree.h"
#include <iomanip>

// template<typename T>
// class TreeNode{
// public:
//     T key;
//     TreeNode<T> *parent;
//     TreeNode<T> *left;
//     TreeNode<T> *right;
// };

template<typename T>
class Walk{
public:
    typedef Node<T> *pnode;
    void preOrder(pnode root)
    {   
        // std::cout << "Test root->p: " << std::boolalpha << !root->p << std::endl;
        pnode pre = nullptr;
        // std::cout << "Test pre: " << !pre << std::endl;
        while(root != nullptr)
        {   
            // std::cout << "True" << std::endl;
            // std::cout << std::boolalpha << !root->p << "," << !pre << std::endl;
            // if(root->p && pre && *pre == *(root->p) || !root->p && !pre)
            if(pre == root->p)
            {
                pre = root;
                // std::cout << pre->key << std::endl;
                std::cout << root->key << ", ";
                // std::cout << "Test root->left: " << bool(root->left) << std::endl;
                auto t = root;
                root = root->left ? root->left : root->right ? root->right : root->p;
                // std::cout << (t->left == root) << std::endl;
                // std::cout << "case 1" << std::endl;
            }
            else if(pre == (root->left) && root->right != nullptr)
            {
                pre = root;
                root = root->right;
                // std::cout << "case 2" << std::endl;
            }
            else
            {
                pre = root;
                root = root->p;
                // std::cout << "case 3" << std::endl;
            }
        }
        std::cout << std::endl;
    }

    void inOrder(pnode root)
    {
        pnode pre = nullptr;
        while(root != nullptr)
        {
            if(pre == root->p)
            {
                pre = root;
                if(root->left == nullptr)
                {
                    std::cout << root->key << ", ";
                }
                root = root->left ? root->left : root->right ? root->right : root->p;
            }
            else if(pre == root->left && root->right != nullptr)
            {
                pre = root;
                std::cout << root->key << ", ";
                root = root->right;
            }
            else
            {
                pre = root;
                root = root->p;
            }
        }
        std::cout << std::endl;
    }

    void postOrder(pnode root)
    {
        pnode pre = nullptr;
        while(root != nullptr)
        {
            if(pre == root->p)
            {
                pre = root;
                if(root->left == nullptr)
                {
                    std::cout << root->key << ", ";
                }
                root = root->left ? root->left : root->right ? root->right : root->p;
            }
            else if(pre == root->left && root->right != nullptr)
            {
                pre = root;
                root = root->right;
            }
            else
            {
                pre = root;
                std::cout << root->key << ", ";
                root = root->p;
            }
        }
        std::cout << std::endl;
    }
};


#endif // !TREE_WALK_H
