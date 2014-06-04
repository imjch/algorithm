#ifndef TREE_NODE_H_
#define TREE_NODE_H_
#include "avl_tree.h"
namespace imjch_std{
    template<class T>
    class avl_tree_node{
    public:
        typedef avl_tree_node<T>* link_type;
        avl_tree_node(const T& val) :parent(nullptr), left(nullptr), right(nullptr), value(val), height(0)
        {}
        ~avl_tree_node(){}
        link_type parent;
        link_type left;
        link_type right;
        T value;
        int height;
    };
}
#endif /* TREE_NODE_H_ */
