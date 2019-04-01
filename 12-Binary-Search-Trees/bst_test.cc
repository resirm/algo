#include <iostream>
#include "binary_search_tree.h"
#include "tree_walk.h"

using namespace std;

typedef Node<int> node;
typedef node *pnode;

int main(){
    BST<int, Node<int>> bst;
    pnode ptree = bst.get_root();
    node n1(1), n2(2),n3(10), n4(16), n5(7), n6(11), n7(4), n8(22), n9(17), n10(9);
    bst.insert(&n1);
    bst.insert(&n2);
    bst.insert(&n3);
    bst.insert(&n4);
    bst.insert(&n5);
    bst.insert(&n6);
    bst.insert(&n7);
    bst.insert(&n8);
    bst.insert(&n9);
    bst.insert(&n10);
    cout << boolalpha << (ptree==nullptr) << endl;
    ptree = bst.get_root();
    cout << (ptree==nullptr) << endl;
    cout << "Min: " << bst.max(ptree)->key << endl;
    pnode min = bst.min(ptree);
    for(pnode i = min; i != nullptr; i = bst.successor(i)){
        cout << i->key << ", ";
    }
    cout << endl;
    bst.remove(&n6);
    ptree = bst.get_root();
    min = bst.min(ptree);
    for(pnode i = min; i != nullptr; i = bst.successor(i)){
        cout << i->key << ", ";
    }
    cout << endl;
    
    Walk<Node<int>> walk(nullptr);
    cout << "In-Order walk: " << endl;
    walk.inOrder(ptree);
    cout << "Pre-Order walk: " << endl;
    walk.preOrder(ptree);
    cout << "Post-Order walk: " << endl;
    walk.postOrder(ptree);
}