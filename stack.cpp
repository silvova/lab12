#include <stdio.h>
#include "stack.h"


void Stack::resize() {
	capacity *= 2;
	int* stack2 = new int[capacity];
	copyFromStack(stack2, size);
	delete[] stack;
	stack = stack2;
}

void Stack::copyFromStack(int* p2, int n) {
	for (int i = 0; i < n; i++) {
		p2[i] = stack[i];
	}
}

void Stack::copyToStack(int* p2, int n) {
	for (int i = 0; i < n; i++) {
		stack[i] = p2[i];
	}
}

Stack::Stack() { //конструктор
	size = 0;
	capacity = 16;
	stack = new int[capacity];
}

Stack::Stack(const Stack& tmp) {//конструктор копий
	size = tmp.size;
	capacity = tmp.capacity;
	stack = new int[tmp.capacity];
	for (int i = 0; i < tmp.size; i++) {
		stack[i] = tmp.stack[i];
	}
}

void Stack::set(int* tmp, int size_tmp) {//метод ввода
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

int Stack::get(int n, int& error) const {//метод вывода
	if (n < size && n >= 0) {
		error = 0;
		return stack[n];
	}
	else {
		error = 1;
		return 0;
	}
}

Stack Stack::operator=(const Stack& tmp) {//оператор присваивания
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

std::ostream& operator<< (std::ostream& os, const Stack& A) {//оператор вывода на экран
	for (int i = 0; i < A.size; i++) {
		os << A.stack[i] << ' ';
	}
	return os;
}

void Stack::push(int n) {//добавление в конец стека
	if (size == capacity) {
		resize();
	}
	stack[size++] = n;
}

void Stack::pop() {//удаление из окнца списка
	if (size > 0) {
		stack[size] = 0;
		size--;
	}
}

void Stack::shrinkToFit() {
	capacity = size;
	int* stack2 = new int[capacity];
	copyFromStack(stack2, size);
	delete[] stack;
	stack = stack2;
}