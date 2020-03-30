//
// Created by shirin dora on 28/03/2020.
//

#ifndef HASH_TABLES_STUDENT_H
#define HASH_TABLES_STUDENT_H

#include <iostream>

struct Student {
public:
    Student(std::string n="", std::string c="") {
        name = n;
        city = c;
    }

    std::string name;
    std::string city;
};

#endif //HASH_TABLES_STUDENT_H
