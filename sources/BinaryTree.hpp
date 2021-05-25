#pragma once

namespace ariel
{

    template <typename T>
    class BinaryTree
    {
    private:
        // inner class
        struct Node
        {
            T val;
            Node *R_Node;
            Node *L_Node;
            Node *Parent;
            Node(const T &value) : val(value), R_Node(nullptr), L_Node(nullptr), Parent(nullptr) {}
        };

        // fields
        Node *ROOT;

    public:
        BinaryTree() : ROOT(nullptr) {}
        ~BinaryTree() {}

        BinaryTree &add_root(T data)
        {
            if (ROOT == nullptr)
            {
                Node *node = new Node(data);
                ROOT = node;
                return *this;
            }
            else
            {
                ROOT->val = data;
                return *this;
            }
        }

        BinaryTree &add_right(T val1, T val2)
        {
            Node *n = find_node(ROOT, val1);
            if (n == nullptr)
            {
                throw std::invalid_argument{"No such node"};
            }

            if (n->R_Node != nullptr) // we have val1 and it has a right son
            {
                n->R_Node->val = val2; // has right son so we updatuing its val
            }
            else // val1 dont have a right son so we will make it
            {
                Node *newNode = new Node{val2};
                n->R_Node = newNode;
                newNode->Parent = n;
            }
            return *this;
        }

        BinaryTree &add_left(T val1, T val2)
        {
            Node *n = find_node(ROOT, val1);
            if (n == nullptr)
            {
                throw std::invalid_argument{"No such node"};
            }

            if (n->L_Node != nullptr) // we have val1 and it has a right son
            {
                n->L_Node->val = val2; // has right son so we updatuing its val
            }
            else // val1 dont have a right son so we will make it
            {
                Node *newNode = new Node{val2};
                n->L_Node = newNode;
                newNode->Parent = n;
            }
            return *this;
        }

        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &tree)
        {
            return os;
        }

        Node *find_node(Node *n, T data)
        {
            if (n != nullptr)
            {
                if (n->val == data)
                {
                    return n;
                }
                else
                {
                    Node *foundNode = find_node(n->L_Node, data);
                    if (foundNode == nullptr)
                    {
                        foundNode = find_node(n->R_Node, data);
                    }
                    return foundNode;
                }
            }
            else
            {
                return nullptr;
            }
        }

        /*preorder itterator*/
    public:
        class preorder_it
        {
        private: //fields
            Node *pointer_to_current_node;

        public:
            preorder_it(Node *ptr = nullptr) : pointer_to_current_node(ptr) {}

            bool operator!=(const preorder_it &it) const
            {
                return pointer_to_current_node != it.pointer_to_current_node;
            }

            bool operator==(const preorder_it &it) const
            {
                return pointer_to_current_node == it.pointer_to_current_node;
            }

            preorder_it &operator++()
            {
                // pointer_to_current_node = pointer_to_current_node; // need to do
                return *this;
            }

            T &operator*() const
            {
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }
        };

        preorder_it begin_preorder()
        {
            return preorder_it{ROOT};
        }
        preorder_it end_preorder()
        {
            return {ROOT};
            // return {nullptr};
        }

        /*inorder itterator*/
        class inorder_it
        {
        private: //fields
            Node *pointer_to_current_node;

        public:
            inorder_it(Node *ptr = nullptr) : pointer_to_current_node(ptr) {}

            bool operator!=(const inorder_it &it) const
            {
                return pointer_to_current_node != it.pointer_to_current_node;
            }

            bool operator==(const inorder_it &it) const
            {
                return pointer_to_current_node == it.pointer_to_current_node;
            }

            inorder_it &operator++()
            {
                Node *Father;

                if (pointer_to_current_node == nullptr)
                    throw std::invalid_argument{"Empty tree"};

                else if (pointer_to_current_node->R_Node != nullptr)
                {
                    pointer_to_current_node = pointer_to_current_node->R_Node;
                    while (pointer_to_current_node->L_Node != nullptr)
                    {
                        pointer_to_current_node = pointer_to_current_node->L_Node;
                    }
                }
                else
                {
                    Father = pointer_to_current_node->Parent;
                    while (Father != nullptr && pointer_to_current_node == Father->R_Node)
                    {
                        pointer_to_current_node = Father;
                        Father = Father->Parent;
                    }
                    pointer_to_current_node = Father;
                }

                return *this;
            }

            T &operator*() const
            {
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }
        };

        inorder_it begin_inorder()
        {
            Node *temp = ROOT;
            while (temp->L_Node != nullptr)
            {
                temp = temp->L_Node;
            }
            return inorder_it{temp};
        }

        inorder_it end_inorder()
        {
            return {nullptr};
        }

        /*postorder itterator*/
        class postorder_it
        {
        private: //fields
            Node *pointer_to_current_node;

        public:
            postorder_it(Node *ptr = nullptr) : pointer_to_current_node(ptr) {}

            bool operator!=(const postorder_it &it) const
            {
                return pointer_to_current_node != it.pointer_to_current_node;
            }

            bool operator==(const postorder_it &it) const
            {
                return pointer_to_current_node == it.pointer_to_current_node;
            }

            postorder_it &operator++()
            {
                // pointer_to_current_node = pointer_to_current_node; // need to do
                return *this;
            }

            T &operator*() const
            {
                return pointer_to_current_node->val;
            }

            T *operator->() const
            {
                return &(pointer_to_current_node->val);
            }
        };

        postorder_it begin_postorder()
        {
            return postorder_it{ROOT};
        }
        postorder_it end_postorder()
        {
            return {ROOT};
            // return {nullptr};
        }

        inorder_it begin()
        {
            return inorder_it{ROOT};
        }

        inorder_it end()
        {
            return {ROOT};
        }
    };
}
