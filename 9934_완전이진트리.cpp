#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int arr[(1 << 10) + 1];
vector<int>dp[14];
int n, MAX;
void make_tree(int st, int ed, int depth) {
	int mid = (st +ed) / 2;
	dp[depth].push_back(arr[mid]);
	if (st == ed)return;
	make_tree(st, mid - 1, depth + 1);
	make_tree(mid + 1, ed, depth + 1);
		return;
}
int main() {
	 cin >> n;
	 MAX = (1 << n) - 1;
	for (int i = 0; i <MAX; i++) {
		cin >> arr[i];
	}
	
	make_tree(0,MAX-1,1);
	for (int i = 1; i <= n; i++) {
		for (auto T : dp[i])cout << T << " ";
		cout << "\n";
	}
}
