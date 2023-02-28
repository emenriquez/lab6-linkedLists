#include <string>

using namespace std;

class Node {
	public:
		string data;
		Node* next;
		Node(string s);
};

class LLStack {
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

