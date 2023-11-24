// Problem: P1120 小木棍
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1120
// Memory Limit: 128 MB
// Time Limit: 260000 ms
// 
// Coding by 2044_space_elevator

#include <iostream>
#include <algorithm>
using namespace std;


int n;
int arr[70];
bool vis[70];
int length = 1, sum;

bool dfs(int nowGS, int nowCD, int start) {
	if (nowGS * length == sum) {
		return true;
	}
	if (nowCD == length) {
		return dfs(nowGS + 1, 0, 0);
	}
	for (int i = start; i < n; i++) {
		if (vis[i]) {
			continue;
		}
		int lonG = arr[i];
		if (nowCD + lonG > length) {
			continue;
		}
		vis[i] = 1;
		if (dfs(nowGS, nowCD + lonG, i + 1)) {
			return true;
		}
		vis[i] = 0;
		if (!nowCD || nowCD + lonG == length) {
			return false;
		}
		int tmp = i;
		while (tmp < n && arr[tmp] == lonG) {
			tmp++;
		}
		i = tmp - 1;
		
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	sort(arr, arr + n, greater<int>());
	for (; ; length++) {
		if (sum % length == 0 && dfs(0, 0, 0)) {
			cout << length << endl;
			return 0;
		}
	}
}