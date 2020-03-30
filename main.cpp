#include <iostream>
#include "HashTable.h"

int main() {
    HashTable ht(101);

    // insert items into the hash table
    Student s("Aaron", "Antrim");
    ht.add("A123", s);
    Student s2("Eamonn", "Lisburn");
    ht.add("E234", s2);

    // find an item
    Student s3;
    bool res = ht.find("A123", s3);

    // insert  item into the hash table
    Student s4("Cathal", "Derry");
    ht.add("A231", s4);
    Student s5("James", "Belfast");
    ht.add("A321", s5);

    // find an item
    Student s6;
    bool res2 = ht.find("A123", s6);

    // remove an item from the table
    ht.remove("A123");

    // find an item
    Student s7;
    bool res3 = ht.find("A231", s7);

    return 0;
}
