// unsorted.cpp: Unsorted Map

#include "map.h"
#include <vector>
#include <algorithm>

using namespace std;
// Methods --------------------------------------------------------------------

void            UnsortedMap::insert(const std::string &key, const std::string &value) {

        // Make a new entry obj. with the key and value passed
        Entry input = Entry(key, value);

        // if no entries exist, add input and return
        if (entries.empty())
        {
            entries.push_back(input);
            return;
        }

        // Loop throug entries to see if there is already a key
        vector<Entry>::iterator iter;
        for(iter = entries.begin(); iter != entries.end(); iter++)
        {
            if (iter->first == key)
            { // if the key already exists, update the value and return
                iter->second = value;
                return;
            }
        }

        // Add input to entries
        entries.push_back(input);
}

const Entry     UnsortedMap::search(const std::string &key) {
    // Loop through the vector and see if current key matches the key passed
    vector<Entry>::iterator it;
    for(it = entries.begin(); it != entries.end(); it++)
    {
        if(it->first == key)
        { // if it matches, dereference it
            return *it;
        }
    }
    // If not found, return none
    return NONE;
}

void            UnsortedMap::dump(std::ostream &os, DumpFlag flag) {
    switch(flag){
        case DUMP_KEY:
            for(size_t i = 0; i < entries.size(); i++)
            {
                os << entries.at(i).first << endl;
            }
            break;
        case DUMP_VALUE:
            for(size_t i = 0; i < entries.size(); i++)
            {
                os << entries.at(i).second << endl;
            }
            break;
        case DUMP_KEY_VALUE:
            for(size_t i = 0; i < entries.size(); i++)
            {
                os << entries.at(i).first << "\t" << entries.at(i).second << endl;
            }
            break;
        case DUMP_VALUE_KEY:
            for(size_t i = 0; i < entries.size(); i++)
            {
                os << entries.at(i).second << "\t" << entries.at(i).first << endl;
            }
            break;
    }           
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:

