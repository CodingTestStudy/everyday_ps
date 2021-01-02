#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, int start, int mid, int end) {
	if (n == 1) return;
	else {
		hanoi(n - 1, start, end, mid);//1. 1������� n-1�� -> 2�� �������
		//cout << start << " " << end << '\n'; //2. 1����� -> 3������
		hanoi(n - 1, mid, start, end);//3. 2����� -> 3���������
	}
}
int main() {
	//������ ����
	long long  n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';//2^n-1...pow()�� �����ϸ� ����ó����. ��? pow()�� �Ǽ������� ���Ǳ� ����..
	hanoi(n, 1, 2, 3);
	cout << "end";
	return 0;
}