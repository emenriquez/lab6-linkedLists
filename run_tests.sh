#!/bin/bash
# Simple script to compile and run the linked list tests
# Usage: ./run_tests.sh

echo "Compiling Linked List Stack tests..."
g++ -std=c++11 -o test main.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful! Running tests..."
    echo ""
    ./test
else
    echo "Compilation failed. Please check your code for syntax errors."
fi
