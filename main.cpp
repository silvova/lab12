#include <iostream>
#include "stack.h"

int main() {
	Stack X;
	for (int i = 0; i < 15; i++) {
		X.push(i);
	}
	Stack Y(X);//проверка оператора присваивания
	std::cout << "X:" << X << '\n';
	for (int i = 0; i < 5; i++) {
		Y.pop();
	}
	for (int i = 10; i < 15; i++) {
		int n = 6;
		X.push(n);
	}
	std::cout << "X:" << X << '\n';
	std::cout << "Y:" << Y << '\n';
	Y.set(X.get());
	std::cout << "Y:" << Y << '\n';
	return 0;
}