cmake_minimum_required(VERSION 3.15)
project(hash_tables)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash_tables main.cpp HashTable.cpp HashTable.h Student.h
        )