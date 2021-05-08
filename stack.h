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
	Stack(const Stack& tmp) {//����������� �����
		this->stack = tmp.stack;
	}
	void set (vector<int> stack) {//�����(�������) �����
		this->stack = stack;
	}
	vector<int> get() {//����� ������
		return this->stack;
	}
	Stack operator=(const Stack& tmp) {//�������� ������������
		this->stack = tmp.stack;
		Stack A = *this;
		return A;
	}
	friend ostream& operator<< (ostream& os, const Stack& A) {//�������� ������ �� �����
		for (int i = 0; i < A.stack.size(); i++) {
			os << A.stack[i] << ' ';
		}
		return os;
	}
	void push(int n) {//���������� � ����� �����
		this->stack.push_back(n);
	}
	void pop() {//�������� �� ����� ������
		this->stack.pop_back();
	}

	~Stack() {//����������
		this->stack.clear();
	}

};
#endif