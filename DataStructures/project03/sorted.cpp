// sorted.cpp: Sorted Map

#include "map.h"

#include <algorithm>

// Type Definitions ------------------------------------------------------------

typedef std::vector<Entry>::iterator IT;

// Prototypes ------------------------------------------------------------------

const Entry binary_search(const IT &start, const IT &end, const std::string &key);

// Methods ---------------------------------------------------------------------

void SortedMap::insert(const std::string &key, const std::string &value) { //std::cout << "insert\n";

    // create entry from passed values
    Entry data = Entry(key, value);

    // if entries is empty give it starting data
    if(entries.empty())
    {
        entries.push_back(data);
        return;
    }
    
    // loop across the entries
    for(IT i = entries.begin(); i != entries.end(); i++)
    {
        if(i->first == key) // if current key is equal to key of element in question, update the value 
        {
            i->second = value;
            return;
        }
        else if (i->first >= key) // if key is smaller than current key, insert data before the current element
        {
            entries.insert(i, data);
            return;
        }
    }

    // key is larger than any existing entries; tack it to the back
    entries.push_back(data);
    return;
}

const Entry SortedMap::search(const std::string &key) {
    // Call binary search function
    if ( binary_search(entries.begin(), entries.end(), key) == NONE)
    {
        return NONE;
    }
    else
    {
        return binary_search(entries.begin(), entries.end(), key);

    }
}

void SortedMap::dump(std::ostream &os, DumpFlag flag) {
    
	if(flag == DUMP_KEY)
    {
        for(size_t i = 0; i< entries.size(); i++)
        {
            os << entries.at(i).first << endl;
        }
    }
    else if(flag == DUMP_VALUE)
    {
        for(size_t i = 0; i < entries.size(); i++)
        {
            os << entries.at(i).second << endl;
        }
    }
    else if (flag == DUMP_KEY_VALUE)
    {
        for(size_t i = 0; i < entries.size(); i++)
        {
            os << entries.at(i).first << "\t" << entries.at(i).second << endl;
        }
    }
    else if (flag == DUMP_VALUE_KEY)
    {
        for(size_t i = 0; i < entries.size(); i++)
        {
            os << entries.at(i).second << "\t" << entries.at(i).first << endl;    
        }
    }
}

// Internal Functions ----------------------------------------------------------

const Entry binary_search(const IT &start, const IT &end, const std::string &target) { 
   
	// declare iterators for front, midpoint, and back of entries
    IT front = start, mid, back = end;

    if (front == back) return NONE;

    while(front <= back)
    { 
        mid = front + (distance(front, back) / 2); // get midpoint

        if(target == (*mid).first) // if target == midpoint, return the midpoint
        { 
            return *mid;
        }
        else if (target > (*mid).first)  // if target is greater than midpoint, bump the midpoint up one
        { 
            front = mid + 1;
        }
        else // if target is smaller, bump the midpoint back one
        { 
            back = mid - 1;
        }
    }  
    return NONE;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
