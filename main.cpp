#include <iostream>
#include "stack.h"

int main() {
	
	Stack X;
	int n = 0;
	int array[] = { 1,2,3,4,5,6,7,8 };
	int a;
	int i;
	
	while (true) {
		std::cout << "1 - See stack" << '\n';
		std::cout << "2 - Add 1,2,3,4,5,6,7,8 numbers to the stack" << '\n';
		std::cout << "3 - View the stack element" << '\n';
		std::cout << "4 - Add an item to the stack" << '\n';
		std::cout << "5 - Delete item of stack" << '\n';
		std::cout << "6 - shrinkToFit" << '\n';
		std::cout << "7 - Size of stack" << '\n';
		std::cout << "or enter somothing else for exit" << '\n';
		std::cout << "Select action:" << '\n';
		std::cin >> n;
		switch (n) {
		case 1:
			std::cout << "Stack:" << X << '\n';
			break;
		case 2:
			X.set(array, 8);
			break;
		case 3:
			int i;
			std::cout << "Select item of stack:" << '\n';
			std::cin >> i;
			int error;
			a = X.get(i, error);
			if (error != 1) {
				std::cout << "X[";
				std::cout << i;
				std::cout << "]=";
				std::cout << a << '\n';
			}
			else {
				std::cout << "Memory access error!" << '\n';
			}
			break;
		case 4:
			std::cout << "Enter value:" << '\n';
			std::cin >> i;
			X.push(i);
			break;
		case 5:
			X.pop();
			break;
		case 6:
			X.shrinkToFit();
			break;
		case 7:
			std::cout << "Size of stack:" << X.getSize() << '\n';
			break;
		default:
			return 0;
		}
	}
}
