#include "LLStack.h"

//constructor : initiazlize the head and tail field from LLStack class 
LLStack::LLStack()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

/*
- Create the new Node and initialize the fields of class Node (info and next)
- update the head, tail and count accordingly

Hint: To update head and tail properly, You have to consider two scenarios:
1. If there is no element in the stack and this is the first one going to the stack
2. If there is another head in the stack
*/
void LLStack::push(string s)
{
	// TO DO
	
	
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
	// TO DO
	
}

/*
What is always referring to the top element?
If stack is empty, return "";
*/
string LLStack::top()
{
	// TO DO
	
}

/*
What keep track of number of elements in the stack?
*/
int LLStack::size()
{
	// TO DO
}
