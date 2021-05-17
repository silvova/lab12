#include <iostream>
#include "stack.h"


int main() {
	Stack X;
	for (int i = 0; i < 33; i++) {
		X.push(i);
	}
	std::cout << "X:" << X << '\n';
	
	Stack Y(X);
	for (int i = 0; i < 10; i++) {
		Y.pop();
	}
	std::cout << "Y:" << Y << '\n';

	std::cout << X.get(3) << '\n';
	
	Stack Z;
	Z = X;
	std::cout << "Z:" << Z << '\n';
	int array[] = { 4,3,2,1,8,7,6,5 };
	Z.set(array, 8);
	std::cout << "Z:" << Z << '\n';

	return 0;
}
