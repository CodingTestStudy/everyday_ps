#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100001
using namespace std;
int arr[100001];
int n;
void build_heap() {
	for (int i = 2; i < n; i++) {// i=2부터 시작하는이유 1은 부모가없기 때문에 비교할 대상이 없다 따라서 2부터 비교해준다.
		//i는 현재 인덱스
		while (i > 1) {
			int parent = i / 2;
			if (arr[i] > arr[parent]) {
				swap(arr[i], arr[parent]);
				i = parent;
			}
		else break;
		}
	}
}
void heapify(int cur, int num) {
	int cur_idx = cur;
	int Left = cur * 2;
	int Right = cur * 2 + 1;
	if ((Left <= num) && arr[Left] > arr[cur_idx])cur_idx = Left;
	if ((Right <= n) && arr[Right] > arr[cur_idx])cur_idx = Right;
	if (cur_idx != cur) {
		swap(arr[cur_idx], arr[cur]);
		heapify(cur_idx, num);
	}
}
int main() {
	 cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build_heap();
	for (int i = MAX; i >= 2; i--) {
		swap(arr[i], arr[1]);
		heapify(1, i - 1);
	}
}