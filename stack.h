#ifndef _stack_h_
#define _stack_h_
#include <iostream>


class Stack {
private:
	int* stack;
	int size;
	int capacity;
	
	void resize();
	void copyFromStack(int* p2, int n);
	void copyToStack(int* p2, int n);

public:
	Stack();
	Stack(const Stack& tmp);
	void set(int* tmp, int size_tmp);
	int get(int n, int& error) const;
	Stack operator=(const Stack& tmp);
	friend std::ostream& operator<< (std::ostream& os, const Stack& A);
	void push(int n);
	void pop();
	void shrinkToFit();
	int getSize() {	return size; }
	~Stack() { delete [] stack; }
};
#endif