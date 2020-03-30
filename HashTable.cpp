//
// Created by shirin dora on 28/03/2020.
//

#include "HashTable.h"

HashTable::HashTable(int size, std::string r_method) {
    table = new HashEntry[size];
    max_capacity = size;
    current_capactiy = 0;

    resolution_method = r_method;
}

HashTable::~HashTable(){
    delete[] table;
}

// Pre-condition : table is not full
// Post-condition: returns key’s position or the next empty position
int HashTable::findPos(const std::string &key) const {
    int pos = hash(key);

    // find an empty slot
    if (resolution_method == "linear_probing") {
        // linear probing
        while (isActive(pos) && (table[pos].key != key)) {
            std::cout << "A collision occurred while inserting the key " << key << "\n";
            pos++;
            pos = pos % max_capacity;
        }
    } else if (resolution_method == "quadratic_probing") {
        // quadratic probing
        int offset = 1;
        int new_pos = pos;
        while( isActive(new_pos) && table[new_pos].key != key ) {
            new_pos = pos + offset*offset;	    // compute i’th slot
            offset += 1;				        // increment offset
            new_pos = new_pos % max_capacity;	// wrap if necessary
        }

        pos = new_pos;
    }

    return pos;
}

// Pre-condition: table is not full
// Post-condition: return true if the key is found (and item stored in the
//                 reference param val), otherwise returns false
bool HashTable::find(std::string key, Student &val) const {
    int pos = findPos(key);

    if (isActive(pos) && table[pos].key == key) {
        val = table[pos].item;
        return true;
    }

    return false;
}

bool HashTable::isActive(int pos) const {
    return table[pos].info == ACTIVE;
}

int HashTable::hash(const std::string &key) const {
    int pos = 0;
    for (int i = 0; i < key.length(); ++i) {
        pos += key[i];
    }

    pos = pos % max_capacity;
    return pos;
}

bool HashTable::add(const std::string & key, const Student &val) {
    int pos = findPos(key);	// determine position

    // position must  be empty or deleted
    if (!isActive(pos)) {
        // insert new HashEntry and mark as active
        table[pos] = HashEntry(key, val, ACTIVE);
        current_capactiy++;	        // increment current table capacity

        std::cout << "Key " << key << " was inserted in position " << pos << "\n";
        return true;
    }

    return false;
}

// PostCondition: mark element as deleted
bool HashTable::remove(std::string key) {
    int pos = findPos(key);	// locate position in table

    if (isActive(pos) && table[pos].key == key) {	// found it?
//        table[pos] = HashEntry(); // remove current HashEntry
        table[pos].info = DELETED;	// mark as deleted
        current_capactiy--;			// decrement current table capacity
        return true;
    }

    return false;
}

int HashTable::size() const {
    return current_capactiy;
}
