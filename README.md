# Lab 6 - Linked List Stack

**Updated Lab Structure**: This lab has been modernized to use a simple `main.cpp` with embedded unit tests instead of external testing frameworks.

Complete the exercises in LLStack.cpp (class/function definitions - no main() function should be written).

In this lab you’ll create a Stack using linked lists. To do this the class LLStack has declared some useful variables, pointers, functions, and the class Node.

### Pointers & Variables:
1.	**Head:** This pointer will always point to the top Node of your stack, when you push use this pointer to locate the top Node.
2.	**Tail:**  This pointer will always point to the bottom Node of the stack, set this pointer when the stack pushes its first item.
3.	**Count:** Use this integer variable to store the number of items in your Stack, *increase* when you push, *decrease* when you pop.

### Functions:
1.	**LLStack:** Class constructor, initialize the pointers & variables to reflect an empty Stack.
2.	**Top:** Returns the string data from the top Node.
3.	**Size:** Returns the number of items in your Stack.
4.	**Push(string):** Push a new Node with data=string. Update, if necessary, *head*, *tail* and *count*.
5.	**Pop:** Removes the top Node of the stack and delete the Node to save memory. Update, if necessary, head, tail and count.

### Class Node:
1.	String data: This variable will store the string of the Node.
2.	Node* next: This pointer will store the address to the next Node in the Linked List.


## How to Run Tests

This lab now uses a simple testing system that works on any platform! Just compile and run:

### Option 1: Direct compilation (works everywhere)
```bash
g++ -o test main.cpp
./test
```

### Option 2: Using the provided script
```bash
./run_tests.sh
```

### Option 3: Using make
```bash
make run
```

### What the Tests Do:
- **Constructor Tests**: Verify your stack starts empty
- **Push Tests**: Check single and multiple item pushes
- **Pop Tests**: Test popping from empty, single-item, and multi-item stacks
- **Mixed Operations**: Combine push and pop operations
- **Stress Tests**: Test with many operations to ensure robustness

### Understanding the Output:
- ✓ PASS: Your implementation works correctly for this test
- ✗ FAIL: Something needs to be fixed in your implementation
- Final summary shows total progress

### Tips:
- Start by implementing the constructor, then `size()`, then `push()`, then `top()`, and finally `pop()`
- Run tests frequently to check your progress
- Each test failure gives you a hint about what to fix
- The tests are designed to help you debug step by step