#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
#include <memory>
template <class T> class tree_node;
namespace imjch_std {
    template<class K, class V, class KeyOfValue, class Compare>
    class avl_tree{
    public:
        typedef size_t size_type;
        typedef K key_type;
        typedef V value_type;
        typedef tree_node<V> node_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef ptrdiff_t difference_type;
        typedef value_type* pointer;
        typedef const value_type* const_pointer;
        typedef node_type* link_type;

        avl_tree(const Compare& comp = Compare()) :node_count(0), compare(comp)
        {
            //init();
        }
        ~avl_tree()
        {
            clean();
            //put_node(head);
        }

        bool empty()
        {
            return node_count == 0;
        }

        size_type size()
        {
            return node_count;
        }

        // no restrict
        void insert_equal()
        {
            
        }

        //it is not allowed to be repeated
        void insert_unique(const V& v)
        {
            //todo:insert the node to the apparent place.
        }


    private:
        std::allocator<node_type> alloc;
        size_type node_count;
        //link_type head;//parent=>root,left=>minimum,right=>maximum
        Compare compare;

        static link_type& left(link_type x)
        {
            return x->left;
        }
        static link_type& right(link_type x)
        {
            return x->right;
        }
        static link_type& parent(link_type x)
        {
            return x->parent;
        }
        static reference value(link_type x)
        {
            return x->value;
        }
        static const key_type& key(link_type x)
        {
            return KeyOfValue()(value(x));
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

        void clean()
        {
            //deallocate all the nodes.
        }
//get the root,left_most and right_most
        //link_type& root()
        //{
        //    return head->parent;
        //}

        //link_type& left_most()//get the node storing minimum value
        //{
        //    return head->left;
        //}

        //link_type& right_most()//get the node storing maximum value
        //{
        //    return head->right;
        //}

        int height(link_type x)
        {
            return x->height;
        }

//manage the allocation and deallocation of memory
        link_type get_node(){
            return alloc.allocate(1);
        }
        void put_node(link_type p){
            alloc.deallocate(p);
        }
        link_type create_node(const value_type& x)
        {
            link_type tmp = get_node();
            construct(&tmp->value, x);
            return tmp;
        }
        void construct(value_type* val, value_type& v)
        {
            alloc.construct(val, v);
        }

        link_type clone_node(link_type x)
        {
            link_type tmp = create_node(x->value);
            tmp->left = nullptr;
            tmp->right = nullptr;
            return tmp;
        }
        
        void destroy_node(link_type p)
        {
            destroy(&p->value);
            put_node(p);
        }
        void destroy(value_type* v)
        {
            alloc.destroy(v);
        }
    };

}

#endif /* BINARY_SEARCH_TREE_H_ */
