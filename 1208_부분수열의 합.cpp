#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
long long n,s,ans;
vector<long long>v;
unordered_map<long long, long long>M;
void Left(int idx, long long sum) {
	if (idx == n / 2) {
		M[sum]++;
		return;
	}

	Left(idx + 1, sum);
	Left(idx + 1, sum + v[idx]);
}
void Right(int idx, long long sum) {
	if (idx == n) {
		ans += M[s - sum];
		return;
	}
	Right(idx + 1, sum);
	Right(idx + 1, sum + v[idx]);
}
int main() {
	cin >> n >> s; f;
	v.resize(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	Left(0, 0);
	Right(n / 2, 0);
	if (s == 0)ans--;// 아무것도 안고른경우는 안된다.
	cout << ans;
}
