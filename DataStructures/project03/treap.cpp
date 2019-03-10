// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>
using namespace std;
// Prototypes ------------------------------------------------------------------

static Node *insert_r(Node *node, const std::string &key, const std::string &value);
extern Node *search_r(Node *node, const std::string &key);
extern void    dump_r(Node *node, std::ostream &os, DumpFlag flag);
static Node *rotate_right(Node *p);
static Node *rotate_left(Node *p);
static int get_random();

// Methods ---------------------------------------------------------------------

void TreapMap::insert(const std::string &key, const std::string &value) {
    root = insert_r(root, key, value);
}

const Entry TreapMap::search(const std::string &key) {
    
	if (search_r(root,key) == nullptr)
    {
        return NONE;
    }
    else
    {
        return search_r(root, key)->entry;
    }	
}

void TreapMap::dump(std::ostream &os, DumpFlag flag) {
    dump_r(root, os, flag);
}

TreapMap::TreapMap()
{   
    root = nullptr;
}
TreapMap::~TreapMap(){
    delete root;
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
    if(node == nullptr){
		// at bottom of tree, so insert a new node with the data
        Entry data = Entry(key, value);
		// Create a random priority for the node
        int priority = get_random();
        node = new Node{data, priority, nullptr, nullptr};
        return node;
    }

    if(key == node->entry.first) // if node's key equals key of current node, update the value
    {
        node->entry.second = value;
        return node;
    }
    else if (key < node->entry.first) // if the key is smaller than current node value, call insert_r on node's left
    {
        node->left = insert_r(node->left, key, value);

        if (node->priority < node->left->priority) // if priority of node is less than its left child, do a right rotation
        {
            node = rotate_right(node);
        }
    }
    else // if the key is greater than the current node value, call insert_r on node's right
    {
        node->right = insert_r(node->right, key, value);

        if(node->priority < node->right->priority) // if priority of node is less than its right child, rotate left
        {
            node = rotate_left(node);
        }
    }

    return node;
}

Node *rotate_right(Node *p) {

    // the node's left child becomes parent with the node itself becoming the right child
    Node *c = p->left;
    Node *T2 = c->right;

    c->right = p;
    p->left = T2;
    return c;
}

Node *rotate_left(Node *p) {

    // the node's left child becomes parent with the node itself becoming the left child
    Node *c = p->right;
    Node* T2 = c->left;

    c->left = p;
    p->right = T2;
    return c;
}

int get_random() { // generate random num
    int random;
    srand( time(0));
    random = rand() % 100 + 1;
return random;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
