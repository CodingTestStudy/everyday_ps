#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace std;

int N, M;
int Num[101][101];
long long Max = -1;

int getSum(int startx, int starty, int endx, int endy) {
	int sum = 0;
	for (int i = startx; i <= endx; i++) {
		for (int j = starty; j <= endy; j++) {
			sum += Num[i][j];
		}
	}
	return sum;
}

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &Num[i][j]);
		}
	}

	//1번 모양
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			long long square1 = getSum(0, 0, i, M - 1);
			long long square2 = getSum(i + 1, 0, j, M - 1);
			long long square3 = getSum(j + 1, 0, N - 1, M - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}

	//2번 모양
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M - 1; j++) {
			long long square1 = getSum(0, 0, N - 1, i);
			long long square2 = getSum(0, i + 1, N - 1, j);
			long long square3 = getSum(0, j + 1, N - 1, M - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}

	//3번 모양
	for (int i = M - 1; i > 0; i--) {
		for (int j = 0; j < N - 1; j++) {
			long long square1 = getSum(0, i, N - 1, M - 1);
			long long square2 = getSum(0, 0, j, i - 1);
			long long square3 = getSum(j + 1, 0, N - 1, i - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}

	//4번 모양
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			long long square1 = getSum(0, 0, N - 1, i);
			long long square2 = getSum(0, i + 1, j, M - 1);
			long long square3 = getSum(j + 1, i + 1, N - 1, M - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}

	//5번 모양
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			long long square1 = getSum(0, 0, i, M - 1);
			long long square2 = getSum(i + 1, 0, N - 1, j);
			long long square3 = getSum(i + 1, j + 1, N - 1, M - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}

	//6번 모양
	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < M - 1; j++) {
			long long square1 = getSum(i, 0, N - 1, M - 1);
			long long square2 = getSum(0, 0, i - 1, j);
			long long square3 = getSum(0, j + 1, i - 1, M - 1);
			Max = max(Max, square1 * square2 * square3);
		}
	}
	cout << Max << endl;
}

int main() {
	solution();
	return 0;
}