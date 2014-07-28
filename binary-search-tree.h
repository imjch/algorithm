#ifndef TREE_INCLUDE
#define TREE_INCLUDE
    template <class T>class TreeNode;
    typedef size_t index_t;

    template <class T>
    class Tree
    {
    public:
        Tree();
        ~Tree();
        void insert(const T&);
        void remove(const T&);
        T& search(index_t);
        bool contain(const T&);
    private:
        void updateParentsNodeCount(TreeNode<T>*);
        TreeNode<T>* searchNode(const T&);
        TreeNode<T>* successor(const TreeNode<T>*);
        TreeNode<T>* predecessor(const TreeNode<T>*);
        void destroy(TreeNode<T>*);
        void removeLeft(TreeNode<T>*);
        void removeRight(TreeNode<T>*);
        TreeNode<T> *root;
        size_t nodeCount;
    };

    template<class T>
    void Tree<T>::removeLeft(TreeNode<T>* node)
    {
            TreeNode<T>* preNode = predecessor(node);
            swap(preNode->item, node->item);
            if (preNode->left != NULL)
            {
                preNode->left->parent = preNode->parent;
            }
            if (preNode->left->item>preNode->parent->item)
            {
                preNode->parent->right=preNode->left;
                preNode->parent->rightCount--;
            }
            else
            {
                preNode->parent->left = preNode->left;
                preNode->parent->leftCount--;
            }
            updateParentsNodeCount(node);
            delete preNode;
    }

    template<class T>
    void Tree<T>::removeRight(TreeNode<T>* node)
    {
            TreeNode<T>* sucNode = successor(node);
            swap(sucNode->item, node->item);
            if (sucNode->right != NULL)
            {
                sucNode->right->parent = sucNode->parent;
            }
            if (sucNode->right->item>sucNode->parent->item)
            {
                sucNode->parent->right=sucNode->right;
                sucNode->parent->rightCount--;
            }
            else
            {
                sucNode->parent->left = sucNode->right;
                sucNode->parent->leftCount--;
            }
            updateParentsNodeCount(node);
            delete sucNode;
    }


    template <class T>
    bool Tree<T>::contain(const T& key)
    {
        if (searchNode(key))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    template <class T>
    T& Tree<T>::search(index_t idx)
    {
        if (idx > (root->leftCount + root->rightCount)||idx==0)
        {
            throw new overflow_error("index overflow");
        }
        TreeNode<T>* node = root;
        while (idx - node->leftCount!= 1)
        {
            if (idx > node->leftCount)
            {
                idx -= node->leftCount + 1;
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
        return node->item;
    }

    template <class T>
    void Tree<T>::updateParentsNodeCount(TreeNode<T>* node)
    {
        if (node == NULL || node->parent == NULL)
        {
            return;
        }
        if (node->item < node->parent->item)
        {
            node->parent->leftCount = node->leftCount + node->rightCount + 1;
        }
        else
        {
            node->parent->rightCount = node->leftCount + node->rightCount + 1;
        }
        updateParentsNodeCount(node->parent);
    }

    template <class T>
    TreeNode<T>* Tree<T>::successor(const TreeNode<T>* node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        TreeNode<T>* tnode = node->right;
        if (tnode == NULL)
        {
            return NULL;
        }

        while (tnode->left)
        {
            tnode = tnode->left;
        }
        return tnode;
    }

    template <class T>
    TreeNode<T>* Tree<T>::predecessor(const TreeNode<T>* node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        TreeNode<T>* tnode = node->left;
        if (tnode == NULL)
        {
            return NULL;
        }

        while (tnode->right)
        {
            tnode = tnode->right;
        }
        return tnode;
    }

    template <class T>
    void Tree<T>::remove(const T& key)
    {
        TreeNode<T>* node = searchNode(key);
        if (node == NULL)
        {
            return;
        }
        if (node->left == NULL && node->right == NULL)
        {
            if (node->item < node->parent->item)
            {
                node->parent->left = NULL;
                node->parent->leftCount--;
            }
            else
            {
                node->parent->right = NULL;
                node->parent->rightCount--;
            }
            updateParentsNodeCount(node->parent);
            delete node;
        }
        else if (node->right == NULL)
        {
            removeLeft(node);
        }
        else
        {
            removeRight(node);
        }
        nodeCount--;
    }

    template <class T>
    TreeNode<T>* Tree<T>::searchNode(const T& key)
    {
        TreeNode<T> *node = root;
        while (node != NULL)
        {
            if (node->item == key)
            {
                return node;
            }
            else if (node->item > key)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return NULL;
    }

    template <class T>
    void Tree<T>::insert(const T&val)
    {
        TreeNode<T>* newNode = new TreeNode<T>(val);
        if (root == NULL)
        {
            root = newNode;
            nodeCount++;
            return;
        }

        TreeNode<T> *tnode = root;
        TreeNode<T> *pnode = NULL;

        if (contain(val))
        {
            return;
        }

        while (tnode)
        {
            pnode = tnode;
            if (tnode->item < val)
            {
                tnode->rightCount++;
                tnode = tnode->right;
            }
            else
            {
                tnode->leftCount++;
                tnode = tnode->left;
            }
        }

        newNode->parent = pnode;
        if (pnode->item > val)
        {
            pnode->left = newNode;
        }
        else
        {
            pnode->right = newNode;
        }
        nodeCount++;
    }

    template <class T>
    void Tree<T>::destroy(TreeNode<T>* node)
    {
        if (node == NULL)
        {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    template <class T>
    Tree<T>::Tree()
        : root(NULL)
        , nodeCount(0)
    {
    }

    template <class T>
    Tree<T>::~Tree()
    {
        destroy(root);
    }



    template <class T>
    class TreeNode
    {
    public:
        TreeNode();
        TreeNode(const T&);
        ~TreeNode();
        friend class Tree<T>;
    private:
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode<T> *parent;
        T item;
        size_t leftCount;
        size_t rightCount;
    };

    template <class T>
    TreeNode<T>::TreeNode(const T&item)
        : left(NULL)
        , right(NULL)
        , parent(NULL)
        , item(item)
        , leftCount(0)
        , rightCount(0)
    {
    }

    template <class T>
    TreeNode<T>::~TreeNode()
    {
    }
