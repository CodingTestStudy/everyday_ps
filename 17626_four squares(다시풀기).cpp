#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int dp[50001];

int dfs(int cur) {
	int& ret = dp[cur];
	if (ret != -1) return ret;
	if (cur <= 1) return ret = cur;
	ret = cur;

	for (int i = 1; i * i <= cur; ++i)
		ret = min(ret, dfs(cur - i * i));
	cout <<cur<<" "<< ret << endl;
	return ++ret;
}

int main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));
	cout << dfs(N);
}