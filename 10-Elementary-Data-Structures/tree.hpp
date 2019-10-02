#ifndef TREE_HPP
#define TREE_HPP

#include <deque>
#include <stack>

using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    shared_ptr<TreeNode<T>> left;
    shared_ptr<TreeNode<T>> right;
    shared_ptr<TreeNode<T>> parent;
    TreeNode(T v):val(v), left(nullptr), right(nullptr), parent(nullptr){}
};



#endif // !TREE_HPP