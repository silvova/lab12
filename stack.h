#ifndef _stack_h_
#define _stack_h_
#include <iostream>


class Stack {
private:
	int* stack;
	int size;
	int capacity;
	
	void resize() {
		capacity *= 2;
		int* stack2 = new int[capacity];
		copyFromStack(stack2, size);
		delete [] stack;
		stack = stack2;
	}
	
	void copyFromStack(int* p2, int n) {
		for (int i = 0; i < n; i++) {
			p2[i] = stack[i];
		}
	}

	void copyToStack(int* p2, int n) {
		for (int i = 0; i < n; i++) {
			stack[i] = p2[i];
		}
	}

public:
	Stack() { //�����������
		size = 0;
		capacity = 16;
		stack = new int[capacity];
	}
	Stack(const Stack& tmp) {//����������� �����
		size = tmp.size;
		capacity = tmp.capacity;
		stack = new int[tmp.capacity];
		for (int i = 0; i < tmp.size; i++) {
			stack[i] = tmp.stack[i];
		}
	}
	void set (int* tmp, int size_tmp) {//�����(�������) �����
		if (size_tmp < size) {
			for (int i = size_tmp; i < size; i++) {
				stack[i] = 0;
			}
		} 
		else {
			while (size_tmp > capacity) {
				resize();
			}
		}
		size = size_tmp;
		copyToStack(tmp, size_tmp);
	}
	int get(int n) {//����� ������
		if (n < size-1 && n > 0) {
			return stack[n];
		}
		std::cout << "Memory access error!";
		exit(-1);
	}
	Stack operator=(const Stack& tmp) {//�������� ������������
		if (tmp.capacity > capacity) {
			int* stack2 = new int[tmp.capacity];
			delete stack;
			stack = stack2;
		}
		for (int i = tmp.size; i < size; i++) {
			stack[size] = 0;
		}
		size = tmp.size;
		capacity = tmp.capacity;
		copyToStack(tmp.stack, tmp.size);
		return *this;
	}
	friend std::ostream& operator<< (std::ostream& os, const Stack& A) {//�������� ������ �� �����
		for (int i = 0; i < A.size; i++) {
			os << A.stack[i] << ' ';
		}
		return os;
	}
	void push(int n) {//���������� � ����� �����
		if (size == capacity) {
			resize();
		}
		stack[size++] = n;
	}
	void pop() {//�������� �� ����� ������
		if (size > 0) {
			stack[size] = 0;
			size--;
		}
	}
	void shrinkToFit() {
		capacity = size;
		int* stack2 = new int[capacity];
		copyFromStack(stack2, size);
		delete [] stack;
		stack = stack2;
	}
	int getSize() {
		return size;
	}
	~Stack() {//����������
		delete [] stack;
	}
};
#endif