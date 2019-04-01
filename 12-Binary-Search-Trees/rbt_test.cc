#include <iostream>
#include "red_black_tree.h"
#include "tree_walk.h"

using namespace std;

typedef RBNode<int> node;
typedef node *pnode;

int main(){
    RBT<int> rbt;
    // BST<int> *pbst = &rbt;
    RBT<int> *prbt = &rbt;
    // pnode ptree = static_cast<pnode>(pbst->get_root());
    pnode ptree = prbt->get_root();
    node n1(1), n2(2),n3(10), n4(16), n5(7), n6(11), n7(4), n8(22), n9(17), n10(9);
    prbt->insert(&n1);
    prbt->insert(&n2);
    prbt->insert(&n3);
    prbt->insert(&n4);
    prbt->insert(&n5);
    prbt->insert(&n6);
    prbt->insert(&n7);
    prbt->insert(&n8);
    prbt->insert(&n9);
    prbt->insert(&n10);
    cout << boolalpha << (ptree==nullptr) << endl;
    // ptree = static_cast<pnode>(pbst->get_root());
    ptree = prbt->get_root();
    cout << (ptree==nullptr) << endl;
    cout << ptree->key << endl;
    cout << "Max: " << prbt->max(ptree)->key << endl;
    auto min = prbt->min(ptree);
    for(auto i = min; i != rbt.get_nil(); i = prbt->successor(i)){
        cout << i->key << ", " << i->color << ", ";
    }
    cout << endl;
    // prbt->remove(&n6);
    // ptree = prbt->get_root();
    // min = prbt->min(ptree);
    // for(auto i = min; i != nullptr; i = prbt->successor(i)){
    //     cout << i->key << ", ";
    // }
    // cout << endl;
    
    Walk<RBNode<int>> walk(prbt->get_nil());
    cout << "In-Order walk: " << endl;
    walk.inOrder(ptree);
    cout << "Pre-Order walk: " << endl;
    walk.preOrder(ptree);
    cout << "Post-Order walk: " << endl;
    walk.postOrder(ptree);
}