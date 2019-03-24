#include <iostream>
#include "binary_tree.h"
#include "queue.h"

using std::cout; using std::endl;

void BFS(BinaryTree<int>::pnode root){
    Queue<BinaryTree<int>::pnode> q;
    q.enqueue(root);
    while(!q.empty()){
        Queue<BinaryTree<int>::pnode> ql;
        while(!q.empty()){
            auto v = q.dequeue();
            ql.enqueue(v);
            cout << v->key << ", ";
        }
        cout << endl;
        while(!ql.empty()){
            auto v = ql.dequeue();
            if(v->left)
                q.enqueue(v->left);
            if(v->right)
                q.enqueue(v->right);
        }
    }
}

int main(){
    BinaryTree<int> bt;
    Queue<BinaryTree<int>::pnode> q;
    auto root = bt.getroot();
    q.enqueue(root);
    int i = 1;
    while(i < 20){
        BinaryTree<int>::pnode v;
        Queue<BinaryTree<int>::pnode> ql;
        while(!q.empty()){
            v = q.dequeue();
            bt.makeLeftChild(v, i++);
            bt.makeRightChild(v, i++);
            ql.enqueue(v->left);
            ql.enqueue(v->right);
        }
        // q.enqueue(v->left);
        // q.enqueue(v->right);
        while(!ql.empty()){
            q.enqueue(ql.dequeue());
        }
    }
    cout << root->key << endl;
    auto l = root->left, r = root->right;
    cout << l->key << ", " << r->key << endl;
    auto ll = l->left, lr = l->right, rl = r->left, rr = r->right;
    cout << ll->key << ", " << lr->key << ", " << rl->key << ", " << rr->key << endl;
    cout << "BFS: " << endl;
    BFS(root);
}