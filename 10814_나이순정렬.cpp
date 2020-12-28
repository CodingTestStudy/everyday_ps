#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#define f ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using namespace std;
vector<tuple<int,int,string>>v;
bool cmp(tuple<int,int,string>a, tuple<int,int,string>b) {
	auto [aa, bb, c] = a;
	auto [aaa, bbb, ccc] = b;
	if (aa == aaa)return bb < bbb;
	return aa < aaa;

}
int main() {
	int n; cin >> n; f;
	for (int i = 0; i < n; i++) {
		int a; string b; cin >> a >> b;
		v.push_back({ a,i,b });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto [a, b, c] : v)cout << a << " " << c << "\n";
}