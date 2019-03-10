// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>

using namespace std;
// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void BSTMap::insert(const std::string &key, const std::string &value) 
{
    root = insert_r(root, key, value); // call recursive insert func
}

const Entry BSTMap::search(const std::string &key) 
{
    // call recursive search func
    if(search_r(root, key) == nullptr)
    {
        return NONE;
    }
    else 
    {
        return search_r(root, key) -> entry;
    }
}

void BSTMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

BSTMap::BSTMap()
{
    root = nullptr;
}
BSTMap::~BSTMap()
{
    delete root;
}

Node::~Node()
{
    delete right;
    delete left;

}
// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node == nullptr) // when the node is 0, at bottom of tree
    { // create entry and set it equal to new node
        Entry data = Entry(key, value);
        node = new Node{data, 0, nullptr, nullptr};
        return node;
    }

    if (key == node->entry.first) // if key equals key of current node, update value of node
    {
        node->entry.second = value;
        return node;
    }
    else if(key < node->entry.first) // if key is smaller than node's key, do insert_r on left side of the node
    { 
        node->left = insert_r(node->left, key, value);
        return node;
    }
    else // if key is larger, do insert_r on the right side of the node
    {
        node->right = insert_r(node->right, key, value); 
        return node;
    }
}

Node *search_r(Node *node, const std::string &key) {
    if (node == nullptr) return nullptr; // If search returns null

    if(key == node->entry.first) // returns the node if a match is found
    {
        return node;
    }
    else if(key < node->entry.first) // if key is smaller than node's key, go left
    {
        return search_r(node->left, key);
    }
    else // if key is larger than node's key, go right
    {
        return search_r(node->right, key);
    }
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) 
{
    if (flag == DUMP_KEY)
    {    
        if(node->left)
        {
            os << node->entry.first << endl;
            dump_r(node->left, os, flag);
        }

        if(node->right)
        {
            os << node->entry.first << endl;
            dump_r(node->right, os, flag);
        }
    }
    else if (flag == DUMP_VALUE)
    {
        if(node -> left)
        {
            os << node->entry.second << endl;
            dump_r(node->left, os, flag);
        }

        if (node -> right)
        {
            os << node->entry.second << endl;
            dump_r(node->left, os, flag);
        }
    }
    else if (flag == DUMP_KEY_VALUE)
    {
        if(node->left)
        {
            os << node->entry.first << "\t" << node->entry.second << endl;
            dump_r(node->left, os, flag);
        }
    }
    else if (flag == DUMP_VALUE_KEY)
    {
        if (node == nullptr) return;

        dump_r(node->left, os, flag);
        os << node->entry.second << "\t" << node->entry.first << endl;
        dump_r(node->right, os, flag);
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
