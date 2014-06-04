#ifndef BINARY_SEARCH_TREE_ITERATOR_H_
#define BINARY_SEARCH_TREE_ITERATOR_H_
#include <allocators>
#include <xutility>
#include <stdexcept>
#include "avl_tree_node.h"
namespace imjch_std{
    template<class V,class Ref,class Ptr>
    class avl_tree_iterator
    {
    public:
        typedef avl_tree_node<V> node_type;
        typedef node_type* link_type;
        typedef bidirectional_iterator_tag iterator_category;

        typedef V value_type;
        typedef Ref reference;
        typedef Ptr pointer;
        typedef avl_tree_iterator<V, V&, V*> iterator;
        typedef avl_tree_iterator<V, const V&, const V*> const_iterator;
        typedef avl_tree_iterator<V, Ref, Ptr> self;

        avl_tree_iterator(){}
        avl_tree_iterator(link_type x):node(x){}
        avl_tree_iterator(const iterator& iter) :node(iter.node){}
        ~avl_tree_iterator(){}
        
        reference operator*()const
        {
            return node->value;
        }
        reference operator->()
        {
            return &(operator*());
        }   
        self& operator++()
        {

        }
        self operator++(int)
        {
            self tmp = *this;
            operator++();
            return tmp;
        }
        self& operator--()
        {
            
        }
        self operator--(int)
        {
            self tmp = *this;
            operator--();
            return tmp;
        }
    private:
        void increment()
        {
            if (node->right!=nullptr)//if node has right child;
            {
                link_type p = node->right;
                while (p->left!=nullptr)
                {
                    p = p->left;
                }
                node = p;
            }
            else
            {
                link_type parent = node->parent;
                if ()//if node is the root of this tree
                {
                    
                }
                else
                {
                    
                }
            }
        }

        void descrement()
        {
            
        }
        link_type node;
    };

}
#endif