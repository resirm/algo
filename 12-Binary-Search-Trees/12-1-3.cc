#include <iostream>
#include "tree_walk.h"
#include "../10-Elementary-Data-Structures/binary_tree.h"
#include "../10-Elementary-Data-Structures/deque.h"

using namespace std;

int main()
{
    BinaryTree<int> bt;
    Walk<int> walk;
    Deque<BinaryTree<int>::pnode> q;
    auto root = bt.getroot();
    // cout << boolalpha << !root->p << endl;
    q.enqueue(root);
    int i = 1;
    cout << "Construct tree: " << endl;
    cout << q.head()->key << ", " << endl;

    while(i < 20){
        BinaryTree<int>::pnode v;
        Deque<BinaryTree<int>::pnode> ql;
        while(!q.empty()){
            v = q.dequeue();
            bt.makeLeftChild(v, i++);
            bt.makeRightChild(v, i++);
            ql.enqueue(v->left);
            ql.enqueue(v->right);
            cout << v->left->key << ", " << v->right->key << ", ";
        }
        cout << endl;
        while(!ql.empty()){
            q.enqueue(ql.dequeue());
        }
    }
    cout << "Finished." << endl;

    cout << "preOrder: " << endl;
    walk.preOrder(root);
    cout << "inOrder: " << endl;
    walk.inOrder(root);
    cout << "postOrder: " << endl;
    walk.postOrder(root);
    
    return 0;
}