#include <string>

using namespace std;

class Node          // Yes, you can have a class inside another class, use this class for your linked list implementatin of stack 
{
	public:
		string data;
		Node* next;
};

class LLStack
{
	public:	
		LLStack();           // the constructor
		string top();        // return the top string of stack
		int size();          // return size of stack
		void push(string s); // push string s to the stack
		void pop();          // remove the top string from the stack

	private:
		Node* head;         // pointer to the head of linked list
		Node* tail;         // pointer to the tail of linked list
		int count;          // keep track of size of stack

};

