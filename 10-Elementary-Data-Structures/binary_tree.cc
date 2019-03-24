#include <iostream>
#include "binary_tree.h"
#include "queue.h"
#include "deque.h"

using std::cout; using std::endl;

void DFS(BinaryTree<int>::pnode root){
    Deque<BinaryTree<int>::pnode> q;
    q.enqueue(root);
    while(!q.empty()){
        auto v = q.tail();
        // cout << v->key << ", ";
        if(v == nullptr)
            q.rdequeue();
        else
            while(v->left){
                // cout << v->key << ", ";
                q.enqueue(v->left);
                v = q.tail();
            }
        
        if(!q.empty()){
            auto v = q.rdequeue();
            cout << v->key << ", ";
            if(v->right)
                q.enqueue(v->right);
            else
                q.enqueue(nullptr);
        }
    }
}

void BFS(BinaryTree<int>::pnode root){
    Queue<BinaryTree<int>::pnode> q;
    q.enqueue(root);
    while(!q.empty()){
        auto v = q.dequeue();
        cout << v->key << ", ";
        if(v->left)
            q.enqueue(v->left);
        if(v->right)
            q.enqueue(v->right);
    }
    cout << endl;
}

int main(){
    BinaryTree<int> bt;
    Queue<BinaryTree<int>::pnode> q;
    auto root = bt.getroot();
    q.enqueue(root);
    int i = 1;
    cout << "Construct tree: " << endl;
    while(i < 20){
        BinaryTree<int>::pnode v;
        Queue<BinaryTree<int>::pnode> ql;
        while(!q.empty()){
            v = q.dequeue();
            bt.makeLeftChild(v, i++);
            bt.makeRightChild(v, i++);
            ql.enqueue(v->left);
            ql.enqueue(v->right);
            cout << v->left->key << ", " << v->right->key << ", ";
        }
        cout << endl;
        // q.enqueue(v->left);
        // q.enqueue(v->right);
        while(!ql.empty()){
            q.enqueue(ql.dequeue());
        }
    }
    cout << "Finished." << endl;
    // cout << root->key << endl;
    // auto l = root->left, r = root->right;
    // cout << l->key << ", " << r->key << endl;
    // auto ll = l->left, lr = l->right, rl = r->left, rr = r->right;
    // cout << ll->key << ", " << lr->key << ", " << rl->key << ", " << rr->key << endl;
    cout << "BFS: " << endl;
    BFS(root);
    cout << "DFS: " << endl;
    DFS(root);
    // cout << bt.getroot()->left->key << endl;
    // bt.~BinaryTree();
    // cout << bt.getroot()->left->key << endl;
}