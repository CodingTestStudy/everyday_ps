#include <iostream>
#include <cmath>
using namespace std;
void hanoi(int n, int start, int mid, int end) {
	if (n == 1) return;
	else {
		hanoi(n - 1, start, end, mid);//1. 1번기둥의 n-1개 -> 2번 기둥으로
		//cout << start << " " << end << '\n'; //2. 1번기둥 -> 3번으로
		hanoi(n - 1, mid, start, end);//3. 2번기둥 -> 3번기둥으로
	}
}
int main() {
	//원판의 개수
	long long  n;
	cin >> n;
	cout << (1 << n) - 1 << '\n';//2^n-1...pow()로 제곱하면 오답처리됨. 왜? pow()는 실수형으로 계산되기 때문..
	hanoi(n, 1, 2, 3);
	cout << "end";
	return 0;
}