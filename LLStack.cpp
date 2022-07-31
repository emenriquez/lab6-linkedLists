#include "LLStack.h"

//constructor : initiazlize the head and tail field from LLStack class 
// the stack should start with no items 
// the head and tail should both be initialized as null pointers
LLStack::LLStack()
{

}

/*
define the top() method, which will return the data at the top of the stack
(remember the "top" of the stack is the newest element)
If stack is empty, return "";
*/
string LLStack::top()
{
	return "fixthis";
}

/*
define the size() method, which will return the number of nodes in the stack
*/
int LLStack::size()
{
	return -1;
}

/*
- Create the new Node and initialize the fields of class Node (data and next)
- update the head, tail and count accordingly

Hint: To update head and tail properly, You have to consider two scenarios:
1. If there is no element in the stack and this is the first one going to the stack
2. If there is another head in the stack
*/
void LLStack::push(string s)
{

}

/*
First, Check if the stack is empty or not. If not, update the head,tail and count accordingly.
Don't forget to release memory using delete
Hint: To update head and tail properly, You should consider two different scenario:
1. If LLStack has more than one element
2. If LLStack has exactly one element
*/
void LLStack::pop()
{

}