#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int A, B, C;
long long dfs(int a, int b, int c) {
	if (b == 1)return a;
	long long temp = dfs(a, b / 2, c);
	if (b % 2)return ((temp * temp) % c * a) % c;
	else return (temp * temp) % c;
}
int main() {
	cin >> A >> B >> C;
	cout<<dfs(A%C, B, C);
}