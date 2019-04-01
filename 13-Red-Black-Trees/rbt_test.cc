#include <iostream>
#include "red_black_tree.h"
#include "../12-Binary-Search-Trees/tree_walk.h"
#include <vector>

using namespace std;

typedef RBNode<int> rbnode;
typedef rbnode *prbnode;
typedef Node<int> node;
typedef node *pnode;

void order_print(BST<int, rbnode> *tree){
    auto min = tree->min(tree->get_root());
    for(auto i = min; i != tree->get_nil(); i = tree->successor(i)){
        cout << i->key << ", ";
    }
    cout << endl;
}

int main(){
    RBT<int> rbt;
    BST<int, RBNode<int>> bst;
    // BST<int> *pbst = &rbt;
    RBT<int> *prbt = &rbt;
    BST<int, RBNode<int>> *pbst = &bst;
    // pnode ptree = static_cast<pnode>(pbst->get_root());
    prbnode prbtree = prbt->get_root();
    pnode ptree = pbst->get_root();
    // vector<node> vn{node(1), node(2), node(10), node(16), node(7), node(11), node(4), node(22), node(17), node(9)};
    vector<rbnode> vrbn{rbnode(1), rbnode(2), rbnode(10), rbnode(16), rbnode(7), rbnode(11), rbnode(4), rbnode(22), rbnode(17), rbnode(9)};

    for(auto &c : vrbn){
        // pbst->insert(&c);
        prbt->insert(&c);
    }
    // rbnode n1(1), n2(2),n3(10), n4(16), n5(7), n6(11), n7(4), n8(22), n9(17), n10(9);
    // prbt->insert(&n1);
    // prbt->insert(&n2);
    // prbt->insert(&n3);
    // prbt->insert(&n4);
    // prbt->insert(&n5);
    // prbt->insert(&n6);
    // prbt->insert(&n7);
    // prbt->insert(&n8);
    // prbt->insert(&n9);
    // prbt->insert(&n10);
    cout << boolalpha << (ptree==nullptr) << endl;
    // ptree = static_cast<pnode>(pbst->get_root());
    ptree = prbt->get_root();
    cout << (ptree==nullptr) << endl;
    cout << ptree->key << endl;
    // order_print(pbst);
    order_print(prbt);
    prbtree = prbt->get_root();
    // for(auto i = prbt->get_root(); i != rbt.get_nil(); i = prbt->successor(i)){
    //     cout << i->key << ", " << i->color << ", ";
    // }
    // cout << endl;
    // prbt->remove(&n6);
    // ptree = prbt->get_root();
    // min = prbt->min(ptree);
    // for(auto i = min; i != nullptr; i = prbt->successor(i)){
    //     cout << i->key << ", ";
    // }
    // cout << endl;
    
    Walk<RBNode<int>> walk(prbt->get_nil());
    cout << "In-Order walk: " << endl;
    walk.inOrder(prbtree);
    cout << "Pre-Order walk: " << endl;
    walk.preOrder(prbtree);
    cout << "Post-Order walk: " << endl;
    walk.postOrder(prbtree);
}