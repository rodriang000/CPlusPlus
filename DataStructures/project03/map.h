// map.h

#pragma once

// Includes --------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
// Type definitions ------------------------------------------------------------

typedef enum {
    DUMP_KEY,
    DUMP_VALUE,
    DUMP_KEY_VALUE,
    DUMP_VALUE_KEY,
} DumpFlag;

typedef std::pair<std::string, std::string> Entry;

// Constants -------------------------------------------------------------------

extern const Entry NONE;

// Structures ------------------------------------------------------------------

struct Node {
    Entry entry;
    int     priority;
    Node    *left;
    Node    *right;
    ~Node();
};

// Classes ---------------------------------------------------------------------

class Map {
public:
    virtual void            insert(const std::string &key, const std::string &value) {}
    virtual const Entry     search(const std::string &key) { return NONE; }
    virtual void            dump(std::ostream &os, DumpFlag flag) {}
    virtual                ~Map() {}
};

class UnsortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
    vector<Entry> entries;
};

class SortedMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
    vector<Entry> entries;
};

class BSTMap : public Map {
public:
            BSTMap();
            ~BSTMap();
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
    Node * root;
};

class RBTreeMap : public Map {
public:
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
    map<string, string> entries;
};

class TreapMap : public Map {
public:
            TreapMap();
            ~TreapMap();
            void            insert(const std::string &key, const std::string &value);
            const Entry     search(const std::string &key);
            void            dump(std::ostream &os, DumpFlag flag);
private:
    Node * root;
};

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
