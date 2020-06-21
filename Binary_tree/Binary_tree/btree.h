#pragma once

template <class T>
class btree {

private:
    template <class T>
    struct node
    {
        T key_value;
        node<T>* left;
        node<T>* right;
    };
    void destroy_tree(node<T>* leaf) {
        if (leaf != nullptr)
        {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }
    void insert(T key, node<T>* leaf) {
        if (key < leaf->key_value)
        {
            if (leaf->left != nullptr)
                insert(key, leaf->left);
            else
            {
                leaf->left = new node<T>;
                leaf->left->key_value = key;
                leaf->left->left = nullptr;    //Sets the left child of the child node to null
                leaf->left->right = nullptr;   //Sets the right child of the child node to null
            }
        }
        else if (key >= leaf->key_value)
        {
            if (leaf->right != nullptr)
                insert(key, leaf->right);
            else
            {
                leaf->right = new node<T>;
                leaf->right->key_value = key;
                leaf->right->left = nullptr;
                leaf->right->right = nullptr;
            }
        }
    }
    node<T>* search(T key, node<T>* leaf) {
        if (leaf != nullptr)
        {
            if (key == leaf->key_value)
                return leaf;
            if (key < leaf->key_value)
                return search(key, leaf->left);
            else
                return search(key, leaf->right);
        }
        else return nullptr;
    }

    node<T>* root;

public:
    btree(){
        root = nullptr;
    }
    ~btree() {
        destroy_tree();
    };

    void insert(T key) {
        if (root != nullptr)
            insert(key, root);
        else
        {
            root = new node<T>;
            root->key_value = key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }
    bool isHave(T key) {
        return (search(key, root) != nullptr);
    }
    node* search(T key) {
        return search(key);
    }
    void destroy_tree() {
        destroy_tree(root);
    }
};