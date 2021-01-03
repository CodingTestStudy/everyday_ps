#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[1001];
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}
void Union(int a, int b) {
	int x = find(a);
	int y = find(b);
	if(x==y)	return;
	if (x > y)swap(x, y);
	parent[y] = x;
	return;
}
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i)cnt++;
	}
	cout << cnt;

}