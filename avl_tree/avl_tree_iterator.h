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
        typedef std::bidirectional_iterator_tag iterator_category;

        typedef V value_type;
        typedef Ref reference;
        typedef Ptr pointer;
        typedef avl_tree_iterator<V, V&, V*> iterator;
        typedef avl_tree_iterator<V, const V&, const V*> const_iterator;
        typedef avl_tree_iterator<V, Ref, Ptr> self;
        typedef ptrdiff_t difference_type;

        avl_tree_iterator(){}
        avl_tree_iterator(link_type x):node(x){}
        avl_tree_iterator(const iterator& iter) :node(iter.node){}
        ~avl_tree_iterator(){}
        
        link_type get()
        {
            return node;
        }

        reference operator*()const
        {
            return node->value;
        }
        pointer operator->()
        {
            return &(operator*());
        }   

        bool operator!=(iterator& iter)
        {
            return this->get() != iter.get();
        }

        self& operator++()
        {
            increment();
            return *this;
        }
        self operator++(int)
        {
            self tmp = *this;
            operator++();
            return tmp;
        }
        self& operator--()
        {
            descrement();
            return *this;
        }
        self operator--(int)
        {
            self tmp = *this;
            operator--();
            return tmp;
        }

    private:
        link_type node;
        void increment()
        {
            if (node->right!=nullptr)//if node has right child;
            {
                link_type tmp = node->right;
                while (tmp->left != nullptr)
                {
                    tmp = tmp->left;
                }
                node = tmp;
            }
            else
            {
                link_type parent = node->parent;
                if (parent->left==node)//if node is the root of this tree
                {
                    node = parent;
                }
                else
                {
                    while (parent->right==node)
                    {
                        node = parent;
                        parent = parent->parent;
                    }
                    node = parent;
                }
            }
        }

        void descrement()
        {
            if (node->left != nullptr)//if node has right child;
            {
                link_type tmp = node->left;
                while (tmp->right != nullptr)
                {
                    tmp = tmp->right;
                }
                node = tmp;
            }
            else
            {
                link_type parent = node->parent;
                if (parent->right == node)//if node is the root of this tree
                {
                    node = parent;
                }
                else
                {
                    while (parent->left == node)
                    {
                        node = parent;
                        parent = parent->parent;
                    }
                    node = parent;
                }
            }
        }
    };

}
#endif