#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#define MAX 100001
using namespace std;
int idx;
int N;
char  moo(int num) {
	if (num == 1) {
		if (idx + 1 == N)return 'm';
		else if (idx + 2 == N || idx + 3 == N)return 'o';
		idx += 3;
		return NULL;
	}
	moo(num - 1);
	if (idx + 1 == N)return 'm';
	idx++;
	for (int i = 0; i < num; i++) {
		if (idx + 1 == N)return'o';
		idx++;
	}
	return moo(num - 1);
}
int main() {
	cin >> N;
	cout << moo(30);
}