#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#define MAX 100001
using namespace std;

int dx[4] = { 1,-1 };
int arr[100001];
void bfs(int st) {
	queue < pair<int, int>>q;
	arr[st] = 0;
	q.push({ 0, st });
	while (!q.empty()) {
		auto [cost, now] = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i < 2) {
				int nx = now + dx[i];
				if (nx < 0 || nx >= MAX)continue;
				if (arr[nx] <= cost + 1)continue;
				arr[nx] = cost + 1;
				q.push({ cost + 1,nx });
			}
			else {
				int nx = now * 2;
				if (nx >= MAX)continue;
				if (arr[nx] <= cost + 1)continue;
				arr[nx] = cost + 1;
				q.push({ cost + 1,nx });
			}
		}
	}

}
int main() {
	int n, m; cin >> n >> m;
	fill(arr, arr + 100001, MAX);
	bfs(n);
	cout << arr[m];
}