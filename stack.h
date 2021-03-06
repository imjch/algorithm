#ifndef STACK_
#define STACK_
#include <new>
#include <cstdlib>
namespace imjch_std{
    template<class T>
    class stack{
    public:
        class stack_node;
        typedef T value_type;
        typedef value_type& reference;
        typedef const reference const_reference;
        typedef value_type* pointer;
        typedef const pointer const_pointer;
        typedef size_t size_type;
        typedef stack_node node_type;

        stack() :top_node(nullptr), count(0){

        }
        ~stack(){
            destroy(top_node);
        }

        void push(const value_type& val){
                node_type* new_node = new node_type(val);
                new_node->next = top_node;
                top_node = new_node;
                ++count；
            }
        }

        reference top() {
            return pop_back();
        }

        const_reference top()const{
            return pop_back();
        }



        void pop() {
            if (!top_node)
            {
                return;
            }
            node_type* tmp = top_node;
            top_node = top_node->next;
            delete tmp;
            --count;
        }

        bool empty() {
            if (top_node == nullptr)
            {
                return true;
            }
            return false;
        }

    private:
        void destroy(node_type* node){
            if (node)
            {
                destroy(node->next);
                delete node;
            }
        }
        reference pop_back(){
            if (top_node==nullptr)
            {
                throw runtime_error("stack is empty!");
            }
            return top_node->data;
        }
        class stack_node{
        public:
            stack_node(const T& node) :data(node), next(nullptr){

            }
            T data;
            stack_node *next;
        };
        node_type* top_node;
        size_type count;
    };

}

#endif /* STACK_ */
