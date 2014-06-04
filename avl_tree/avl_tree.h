#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <memory>
#include <cmath>
#include "imjch_utility.h"
#include <map>
template <class T> class avl_tree_node;
namespace imjch_std
{
    template<class K, class V, class KeyOfValue = std::identity<V>, class Compare = std::less<K>>
    class avl_tree
    {
    public:
        typedef size_t size_type;
        typedef K key_type;
        typedef V value_type;
        typedef avl_tree_node<V> node_type;
        /*typedef value_type& reference;
        typedef const value_type& const_reference;*/
        typedef ptrdiff_t difference_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef node_type* link_type;

        avl_tree(const Compare& comp = Compare()) :node_count(0), key_compare(comp)
        {
            init();
        }
        ~avl_tree()
        {
            clean(root());
            put_node(header);
        }

        bool empty()
        {
            return node_count == 0;
        }

        size_type size()
        {
            return node_count;
        }

        // it is allowed that two node sharing the same key
        void insert_equal(const value_type& val)
        {
            insert(root(), header, val);
        }

        //it is not allowed to be repeated
        void insert_unique(const value_type& val)
        {
            if (find(val))
            {
                return;
            }
            insert(root(), header, val);
        }

        std::pair<link_type,bool> find(const value_type& val)
        {
            link_type tmp = root();
            link_type p;
            bool flag = false;
            while (tmp != nullptr)
            {
                p = tmp->parent;
                if (tmp->value == val)
                {
                    flag = true;
                    return pair<link_type,bool>(tmp, flag);
                }
                else if (key_compare(KeyOfValue()(val), key(tmp)))
                {
                    tmp = tmp->left;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            return pair<link_type, bool>(p, flag);
        }
        const value_type& get_min()
        {
            return min_node()->value;
        }

        const value_type& get_max()
        {
            return max_node()->value;
        }
        static link_type maximum(link_type x)
        {
            while (x->right != nullptr)
            {
                x = x->right;
            }
            return x;
        }

        static link_type minimum(link_type x)
        {
            while (x->left != nullptr)
            {
                x = x->left;
            }
            return x;
        }

    private:
        std::allocator<node_type> alloc;
        Compare key_compare;
        size_type node_count;
        link_type header;

        void init()
        {
            header = get_node();
            root() = nullptr;
            max_node() = header;
            min_node() = header;
        }

        int height(link_type x)
        {
            if (x == nullptr)
            {
                return -1;
            }
            return x->height;
        }

        void update_height(link_type x)
        {
            x->height = imjch_std::max(height(x->left), height(x->right)) + 1;
        }

        link_type right_rotate(link_type x)
        {
            link_type tmp;
            tmp = x->left;
            x->left = tmp->right;
            tmp->right = x;
            update_height(x);
            update_height(tmp);
            return tmp;
        }

        link_type left_rotate(link_type x)
        {
            link_type tmp;
            tmp = x->right;
            x->right = tmp->left;
            tmp->left = x;
            update_height(x);
            update_height(tmp);
            return tmp;
        }

        link_type left_right_rotate(link_type x)
        {
            x->left = left_rotate(x->left);
            return  right_rotate(x);
        }

        link_type right_left_rotate(link_type x)
        {
            x->right = right_rotate(x->right);
            return  left_rotate(x);
        }



        void insert(link_type& node, link_type& parent, const V& val)
        {
            //initialize a new node
            if (node == nullptr)
            {
                node = create_node(val);
                node->parent = parent;
                node->left = nullptr;
                node->right = nullptr;
                node->height = 0;
                ++node_count;
                //a delicated method of recording the max and min
                if (parent==header)
                {
                    max_node() = node;
                    min_node() = node;
                }
                if (parent == max_node())
                {
                    if (val>=parent->value)
                    {
                        max_node() = node;
                    }
                }
                if (parent == min_node())
                {
                    if (val<=parent->value)
                    {
                        min_node() = node;
                    }
                }
            }
            //decide which direction the new_node is 
            else if (key_compare(KeyOfValue()(val), key(node)))
            {
                insert(node->left, node, val);
                if (abs(height(node->left) - height(node->right)) > 1)
                {
                    if (val <= node->left->value)
                    {
                        node = right_rotate(node);
                    }
                    else
                    {
                        node = left_right_rotate(node);
                    }
                }
            }
            else
            {
                insert(node->right, node, val);
                if (abs(height(node->left) - height(node->right)) > 1)
                {
                    if (val >= node->right->value)
                    {
                        node = left_rotate(node);
                    }
                    else
                    {
                        node = right_left_rotate(node);
                    }
                }
            }
            node->height = imjch_std::max(height(node->left), height(node->right)) + 1;
        }

        static const key_type& key(link_type x)
        {
            return KeyOfValue()(x->value);
        }




        void clean(link_type p)
        {
            if (p != nullptr)
            {
                clean(p->left);
                clean(p->right);
                destroy_node(p);
            }
        }

        //get the root,left_most and right_most
        link_type& root()
        {
            return header->parent;
        }

        link_type& min_node()//get the node storing minimum value
        {
            return header->left;
        }

        link_type& max_node()//get the node storing maximum value
        {
            return header->right;
        }

        //manage the allocation and deallocation of memory
        link_type get_node(){
            return alloc.allocate(1);
        }
        void construct(const value_type* val, const value_type& v)
        {
            alloc.construct(val, v);
        }

        link_type create_node(const value_type& x)
        {
            link_type tmp = get_node();
            construct(&tmp->value, x);
            return tmp;
        }

        link_type clone_node(link_type x)
        {
            link_type tmp = create_node(x->value);
            tmp->left = nullptr;
            tmp->right = nullptr;
            return tmp;
        }
        void put_node(link_type p){
            alloc.deallocate(p, 1);
        }
        void destroy(value_type* v)
        {
            alloc.destroy(v);
        }
        void destroy_node(link_type p)
        {
            destroy(&p->value);
            put_node(p);
        }
    };

}

#endif /* BINARY_SEARCH_TREE_H_ */
