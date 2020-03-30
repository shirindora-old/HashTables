//
// Created by shirin dora on 28/03/2020.
//

#ifndef HASH_TABLES_HASHTABLE_H
#define HASH_TABLES_HASHTABLE_H

#include <iostream>
#include "Student.h"


class HashTable {
public:
    HashTable(int size, std::string r_method="linear_probing");
    ~HashTable();

//    void clear();
    bool add(const std::string &key, const Student &val);
    bool remove(std::string key);
    bool find(std::string key, Student &val) const;
//    void print(std::ostream &out) const;
    int  size() const;
private:
    enum Status { ACTIVE, EMPTY, DELETED };

    struct HashEntry {
        std::string key;   	// unique identifier
        Student item;    		// related information
        Status info;  		// status of address

        // constructor with defaults for each parameter
        HashEntry(std::string k="", Student st=Student(), Status ss=EMPTY) {
            key = k;
            item = st;
            info = ss;
        }
    };

    // determine if position is active
    bool isActive(int pos) const;

    // find the correct position for specified key
    int findPos(const std::string & key) const;

    // generate a hash from specified key
    int hash(const std::string & key) const;

    HashEntry* table;		        // a pointer to an array of hash entries
    int max_capacity;               // maximum number of entries that can be stored in the table
    int current_capactiy;		    // number of entries stored in the table
    std::string resolution_method;  // method used for collision resolution (Default = Linear probing)
};


#endif //HASH_TABLES_HASHTABLE_H
