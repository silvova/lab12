#include <iostream>
#include "stack.h"
#include <vector>

using namespace std;

int main() {
	Stack X;
	for (int i = 0; i < 15; i++) {
		X.push(i);
	}
	cout << "X:" << X << '\n';

	Stack Y(X);//�������� ������������ �����
	for (int i = 0; i < 5; i++) {
		Y.pop();
	}
	cout << "Y:" << Y << '\n';

	Stack Z;
	Z = Y;//�������� ��������� ������������
	for (int i = 10; i < 15; i++) {
		int n = 6;
		Z.push(n);
	}
	cout << "Z:" << Z << '\n';

	vector<int> R = Y.get();//�������� ������ ������
	cout << "R:";
	for (int i = 0; i < R.size(); i++) {
		cout << R[i] << " ";    
	}
	cout << '\n';
	
	Stack W;
	W.set(X.get());//�������� ������� ����� ������
	cout << "W:" << W << '\n';

	return 0;
}
