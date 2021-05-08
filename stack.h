#ifndef _stack_h_
#define _stack_h_
#include <vector>
#include <iostream>
using namespace std;
class Stack {
private:
	vector<int> stack;
public:
	Stack() {}
	Stack(const Stack& tmp) {//конструктор копий
		this->stack = tmp.stack;
	}
	void set (vector<int> stack) {//метод(функция) ввода
		this->stack = stack;
	}
	vector<int> get() {//метод вывода
		return this->stack;
	}
	Stack operator=(const Stack& tmp) {//оператор присваивания
		this->stack = tmp.stack;
		Stack A = *this;
		return A;
	}
	friend ostream& operator<< (ostream& os, const Stack& A) {//оператор вывода на экран
		for (int i = 0; i < A.stack.size(); i++) {
			os << A.stack[i] << ' ';
		}
		return os;
	}
	void push(int n) {//добавление в конец стека
		this->stack.push_back(n);
	}
	void pop() {//удаление из окнца списка
		this->stack.pop_back();
	}

	~Stack() {//деструктор
		this->stack.clear();
	}

};
#endif