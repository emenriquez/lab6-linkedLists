
#ifndef LLStack_H
#define LLStack_H

#include <string>

using namespace std;

class LLStack
{

public:	
	LLStack();           // the constructor
	void push(string s); // push string s to the stack
	void pop();          // remove the top string from the stack
	string top();        // return the top string of stack
	int size();          // return size of stack

	class Node          // Yes, you can have a class inside another class, use this class for your linked list implementatin of stack 
	{
	public:
		string info;
		Node* next;
	};

private:
	Node* head;         // pointer to the head of linked list
	Node* tail;         // pointer to the tail of linked list
	int count;          // keep track of size of stack

};

#endif

